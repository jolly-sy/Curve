package chunkserver

import (
	"context"
	"fmt"
	"strconv"
	"strings"

	cmderror "github.com/opencurve/curve/tools-v2/internal/error"
	cobrautil "github.com/opencurve/curve/tools-v2/internal/utils"
	basecmd "github.com/opencurve/curve/tools-v2/pkg/cli/command"
	"github.com/opencurve/curve/tools-v2/proto/proto/common"
	"github.com/opencurve/curve/tools-v2/proto/proto/topology"
	"github.com/opencurve/curve/tools-v2/proto/proto/topology/statuscode"
	"golang.org/x/exp/slices"
	"google.golang.org/grpc"
)

const (
	kHealthy = 0
	// 解析结果失败
	kParseError = -1
	// peer数量小于预期
	kPeersNoSufficient = -2
	// 副本间的index差距太大
	kLogIndexGapTooBig = -3
	// 有副本在安装快照
	kInstallingSnapshot = -4
	// 少数副本不在线
	kMinorityPeerNotOnline = -5
	// 大多数副本不在线
	kMajorityPeerNotOnline = -6
	kOtherErr              = -7
)

type GetChunkServerInfoRpc struct {
	Info           *basecmd.Rpc
	Request        *topology.GetChunkServerInfoRequest
	TopologyClient topology.TopologyServiceClient
}

func (rpc *GetChunkServerInfoRpc) NewRpcClient(cc grpc.ClientConnInterface) {
	rpc.TopologyClient = topology.NewTopologyServiceClient(cc)
}

func (rpc *GetChunkServerInfoRpc) Stub_Func(ctx context.Context) (interface{}, error) {
	return rpc.TopologyClient.GetChunkServer(ctx, rpc.Request)
}

// check copysets on chunkserver by chunkserver id
func (cksCmd *ChunkServerCmd) GetCsAddrBycsId(csId uint32) (*cmderror.CmdError, string) {
	request := &topology.GetChunkServerInfoRequest{
		ChunkServerID: &csId,
	}
	cksCmd.getChunkServerInfoRpc = &GetChunkServerInfoRpc{
		Request: request,
	}
	cksCmd.getChunkServerInfoRpc.Info = basecmd.NewRpc(cksCmd.addrs, cksCmd.timeout, cksCmd.retryTimes, "GetChunkServer")
	res, err := basecmd.GetRpcResponse(cksCmd.getChunkServerInfoRpc.Info, cksCmd.getChunkServerInfoRpc)
	if err.TypeCode() != cmderror.CODE_SUCCESS {
		return err, ""
	}
	response := res.(*topology.GetChunkServerInfoResponse)
	if response.GetStatusCode() != 0 {
		fmt.Println("response.GetStatusCode() != 0", response.GetStatusCode())
		return cmderror.ErrBsGetChunkServer(statuscode.TopoStatusCode(response.GetStatusCode())), ""
	}
	csInfo := response.GetChunkServerInfo()
	if csInfo.GetStatus() == *topology.ChunkServerStatus_RETIRED.Enum() {
		fmt.Println("chunkserver has retired!")
		return err, ""
	}
	ip := csInfo.GetHostIp()
	p := csInfo.GetPort()
	port := strconv.FormatUint(uint64(p), 10)
	csAddr := ip + ":" + port
	//fmt.Println("query csAddr is", csAddr)
	return err, csAddr
}

type GetCopySetsInChunkServerRpc struct {
	Info           *basecmd.Rpc
	Request        *topology.GetCopySetsInChunkServerRequest
	TopologyClient topology.TopologyServiceClient
}

func (gcpsRpc *GetCopySetsInChunkServerRpc) NewRpcClient(cc grpc.ClientConnInterface) {
	gcpsRpc.TopologyClient = topology.NewTopologyServiceClient(cc)
}

func (gcpsRpc *GetCopySetsInChunkServerRpc) Stub_Func(ctx context.Context) (interface{}, error) {
	return gcpsRpc.TopologyClient.GetCopySetsInChunkServer(ctx, gcpsRpc.Request)
}

func (cksCmd *ChunkServerCmd) GetCopySetsOnChunkServer(csAddr string) (*cmderror.CmdError, []*common.CopysetInfo) {
	split := strings.Split(csAddr, ":")
	ip := split[0]
	port_string := split[1]
	p, _ := strconv.ParseUint(port_string, 10, 64)
	port := uint32(p)
	request := &topology.GetCopySetsInChunkServerRequest{
		HostIp: &ip,
		Port:   &port,
	}
	cksCmd.getCopySetsInChunkServerRpc = &GetCopySetsInChunkServerRpc{
		Request: request,
	}

	cksCmd.getCopySetsInChunkServerRpc.Info = basecmd.NewRpc(cksCmd.addrs, cksCmd.timeout, cksCmd.retryTimes, "GetCopySetsInChunkServer")
	result, err := basecmd.GetRpcResponse(cksCmd.getCopySetsInChunkServerRpc.Info, cksCmd.getCopySetsInChunkServerRpc)
	if err.TypeCode() != cmderror.CODE_SUCCESS {
		return err, nil
	}
	response := result.(*topology.GetCopySetsInChunkServerResponse)
	if response.GetStatusCode() != 0 {
		return cmderror.ErrGetCopySetsInChunkServer(statuscode.TopoStatusCode(response.GetStatusCode()), csAddr), nil
	}
	//cksCmd.cs2CpyInfos[csAddr] =

	return cmderror.ErrSuccess(), response.GetCopysetInfos()
}

type GetChunkServerListInCopySetsRpc struct {
	Info           *basecmd.Rpc
	Request        *topology.GetChunkServerListInCopySetsRequest
	TopologyClient topology.TopologyServiceClient
}

func (rpc *GetChunkServerListInCopySetsRpc) NewRpcClient(cc grpc.ClientConnInterface) {
	rpc.TopologyClient = topology.NewTopologyServiceClient(cc)
}

func (rpc *GetChunkServerListInCopySetsRpc) Stub_Func(ctx context.Context) (interface{}, error) {
	return rpc.TopologyClient.GetChunkServerListInCopySets(ctx, rpc.Request)
}

func (cksCmd *ChunkServerCmd) GetChunkServerListOfCopySets(lpid uint32, cpsIds []uint32) (*cmderror.CmdError, []*topology.CopySetServerInfo) {

	request := &topology.GetChunkServerListInCopySetsRequest{
		LogicalPoolId: &lpid,
		CopysetId:     cpsIds,
	}
	cksCmd.getCksInCopySetsRpc = &GetChunkServerListInCopySetsRpc{
		Request: request,
	}
	cksCmd.getCksInCopySetsRpc.Info = basecmd.NewRpc(cksCmd.addrs, cksCmd.timeout, cksCmd.retryTimes, "GetChunkServerListInCopySets")
	res, err := basecmd.GetRpcResponse(cksCmd.getCksInCopySetsRpc.Info, cksCmd.getCksInCopySetsRpc)
	if err.TypeCode() != cmderror.CODE_SUCCESS {
		return err, nil
	}
	response := res.(*topology.GetChunkServerListInCopySetsResponse)
	if response.GetStatusCode() != 0 {
		return cmderror.ErrGetChunkServerListInCopySetsRpc(statuscode.TopoStatusCode(response.GetStatusCode()), lpid), nil
	}
	csInfos := response.GetCsInfo()
	return cmderror.ErrSuccess(), csInfos
}

// source:UpdatePeerNotOnlineCopysets(chunkserverAddr);
func (cksCmd *ChunkServerCmd) RecordOffLineCps(csAddr string) *cmderror.CmdError {
	err1, copysetInfos := cksCmd.GetCopySetsOnChunkServer(csAddr)
	if err1.TypeCode() != cmderror.CODE_SUCCESS {
		return err1
	}
	// fmt.Println("GetCopySetsOnChunkServer success")
	if len(copysetInfos) == 0 {
		fmt.Println("copysetInfo is empty")
		return err1
	}
	lpid := copysetInfos[0].GetLogicalPoolId()
	var cpsIds []uint32
	for _, cpsInfo := range copysetInfos {
		cpsIds = append(cpsIds, cpsInfo.GetCopysetId())
	}
	// fmt.Println("cpsIds is", cpsIds)

	err2, csInfos := cksCmd.GetChunkServerListOfCopySets(lpid, cpsIds)
	if err2.TypeCode() != cmderror.CODE_SUCCESS {
		return err1
	}
	for _, csInfo := range csInfos {
		var peersAddrs []string
		locs := csInfo.GetCsLocs()
		for _, loc := range locs {
			ip := loc.GetHostIp()
			p := loc.GetPort()
			port := strconv.FormatUint(uint64(p), 10)
			peerAddr := ip + ":" + port
			peersAddrs = append(peersAddrs, peerAddr)
		}
		cpsId := csInfo.GetCopysetId()
		gidTmp := cobrautil.GenGroupId(lpid, cpsId)
		gid := strconv.FormatUint(gidTmp, 10)
		res := cksCmd.CheckPeersOnLineStatus(gid, peersAddrs)
		if res == kMinorityPeerNotOnline {
			// fmt.Println("RecordOffLineCps find cksCmd.minorPeersNotOnline", gid)
			cksCmd.minorPeersNotOnline = append(cksCmd.minorPeersNotOnline, gid)
		} else if res == kMajorityPeerNotOnline {
			cksCmd.majorPeersNotOnline = append(cksCmd.majorPeersNotOnline, gid)
		} else {
			fmt.Println("CheckPeerOnlineStatus met error!, groupId is", gid)
			continue
		}
		cksCmd.total = append(cksCmd.total, gid)
	}
	return cmderror.ErrSuccess()
}

// peerAddr format: ip:port
func (cksCmd *ChunkServerCmd) CheckPeersOnLineStatus(gid string, peersAddrs []string) int {
	// fmt.Println("CheckPeersOnLineStatus in")
	offLineCnt := 0
	for _, peerAddr := range peersAddrs {
		isOnline := cksCmd.CheckIfCpsOnline(gid, peerAddr)
		if !isOnline {
			// fmt.Println("a cpys is not online, gid is", gid)
			offLineCnt++
		}
	}
	if offLineCnt > 0 {
		majority := len(peersAddrs)/2 + 1
		if offLineCnt < majority {
			return kMinorityPeerNotOnline
		} else {
			// fmt.Println("find kMajorityPeerNotOnline")
			return kMajorityPeerNotOnline
		}
	}
	return kHealthy
}

func (cksCmd *ChunkServerCmd) CheckIfCpsOnline(gid string, csAddr string) bool {
	_, ok := cksCmd.visitedCs2GroupIds[csAddr]
	if ok {
		gids := cksCmd.visitedCs2GroupIds[csAddr]
		if len(gids) == 0 {
			return false
		}
		index := slices.Index(cksCmd.visitedCs2GroupIds[csAddr], gid)
		if index != -1 {
			return true
		} else {
			return false
		}
	}
	err, raft_stat_info := cksCmd.GetAndParseCpsData(csAddr)
	if err.TypeCode() != cmderror.CODE_SUCCESS {
		return false
	}
	for _, m := range raft_stat_info {
		cksCmd.visitedCs2GroupIds[csAddr] = append(cksCmd.visitedCs2GroupIds[csAddr], m[GROUPID])
	}
	index := slices.Index(cksCmd.visitedCs2GroupIds[csAddr], gid)
	if index != -1 {
		return true
	} else {
		return false
	}
}
