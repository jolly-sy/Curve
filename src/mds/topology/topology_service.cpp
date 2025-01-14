/*
 *  Copyright (c) 2020 NetEase Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*
 * Project: curve
 * Created Date: Mon Aug 20 2018
 * Author: xuchaojie
 */

#include "src/mds/topology/topology_service.h"


namespace curve {
namespace mds {
namespace topology {

// RPC encapsulation for corresponding methods in topology_service manager
void TopologyServiceImpl::RegistChunkServer(
    google::protobuf::RpcController* cntl_base,
    const ChunkServerRegistRequest* request,
    ChunkServerRegistResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [ChunkServerRegistRequest] "
              << request->DebugString();

    topology_->RegistChunkServer(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [ChunkServerRegistResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [ChunkServerRegistResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::ListChunkServer(
    google::protobuf::RpcController* cntl_base,
    const ListChunkServerRequest* request,
    ListChunkServerResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [ListChunkServerRequest] "
              << request->DebugString();

    topology_->ListChunkServer(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [ListChunkServerResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [ListChunkServerResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::GetChunkServer(
    google::protobuf::RpcController* cntl_base,
    const GetChunkServerInfoRequest* request,
    GetChunkServerInfoResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [GetChunkServerInfoRequest] "
              << request->DebugString();

    topology_->GetChunkServer(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [GetChunkServerInfoResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [GetChunkServerInfoResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::DeleteChunkServer(
    google::protobuf::RpcController* cntl_base,
    const DeleteChunkServerRequest* request,
    DeleteChunkServerResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [DeleteChunkServerRequest] "
              << request->DebugString();

    topology_->DeleteChunkServer(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [DeleteChunkServerResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [DeleteChunkServerResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::SetChunkServer(
    google::protobuf::RpcController* cntl_base,
    const SetChunkServerStatusRequest* request,
    SetChunkServerStatusResponse* response,
    google::protobuf::Closure* done) {

    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [SetChunkServerStatusRequest] "
              << request->DebugString();

    topology_->SetChunkServer(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [SetChunkServerStatusResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [SetChunkServerStatusResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::RegistServer(
    google::protobuf::RpcController* cntl_base,
    const ServerRegistRequest* request,
    ServerRegistResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [ServerRegistRequest] "
              << request->DebugString();

    topology_->RegistServer(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [ServerRegistResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [ServerRegistResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::GetServer(
    google::protobuf::RpcController* cntl_base,
    const GetServerRequest* request,
    GetServerResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [GetServerRequest] "
              << request->DebugString();

    topology_->GetServer(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [GetServerResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [GetServerResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::DeleteServer(
    google::protobuf::RpcController* cntl_base,
    const DeleteServerRequest* request,
    DeleteServerResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [DeleteServerRequest] "
              << request->DebugString();

    topology_->DeleteServer(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [DeleteServerResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [DeleteServerResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::ListZoneServer(
    google::protobuf::RpcController* cntl_base,
    const ListZoneServerRequest* request,
    ListZoneServerResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [ListZoneServerRequest] "
              << request->DebugString();

    topology_->ListZoneServer(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [ListZoneServerResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [ListZoneServerResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::CreateZone(
    google::protobuf::RpcController* cntl_base,
    const ZoneRequest* request,
    ZoneResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [CreateZone_ZoneRequest] "
              << request->DebugString();

    topology_->CreateZone(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [CreateZone_ZoneResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [CreateZone_ZoneResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::DeleteZone(
    google::protobuf::RpcController* cntl_base,
    const ZoneRequest* request,
    ZoneResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [DeleteZone_ZoneRequest] "
              << request->DebugString();

    topology_->DeleteZone(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [DeleteZone_ZoneResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [DeleteZone_ZoneResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::GetZone(google::protobuf::RpcController* cntl_base,
    const ZoneRequest* request,
    ZoneResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [GetZone_ZoneRequest] "
              << request->DebugString();

    topology_->GetZone(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [GetZone_ZoneResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [GetZone_ZoneResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::ListPoolZone(
    google::protobuf::RpcController* cntl_base,
    const ListPoolZoneRequest* request,
    ListPoolZoneResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [ListPoolZoneRequest] "
              << request->DebugString();

    topology_->ListPoolZone(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [ListPoolZoneResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [ListPoolZoneResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::CreatePhysicalPool(
    google::protobuf::RpcController* cntl_base,
    const PhysicalPoolRequest* request,
    PhysicalPoolResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [CreatePhysicalPool_PhysicalPoolRequest] "
              << request->DebugString();

    topology_->CreatePhysicalPool(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [CreatePhysicalPool_PhysicalPoolResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [CreatePhysicalPool_PhysicalPoolResponse] "
                  << response->DebugString();
    }
}

void  TopologyServiceImpl::UpgradePhysicalPool(
        google::protobuf::RpcController* cntl_base,
        const UpgradePhysicalPoolRequest* request,
        UpgradePhysicalPoolResponse* response,
        google::protobuf::Closure* done) {
        brpc::ClosureGuard done_guard(done);

        brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

        LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [UpgradePhysicalPoolRequest] "
              << request->DebugString();

        topology_->UpgradePhysicalPool(request, response);

        if (kTopoErrCodeSuccess != response->statuscode()) {
            LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [UpgradePhysicalPool_UpgradePhysicalPoolResponse] "
                   << response->DebugString();
        } else {
            LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [UpgradePhysicalPool_UpgradePhysicalPoolResponse] "
                  << response->DebugString();
        }
}

void TopologyServiceImpl::DeletePhysicalPool(
    google::protobuf::RpcController* cntl_base,
    const PhysicalPoolRequest* request,
    PhysicalPoolResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [DeletePhysicalPool_PhysicalPoolRequest] "
              << request->DebugString();

    topology_->DeletePhysicalPool(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [DeletePhysicalPool_PhysicalPoolResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [DeletePhysicalPool_PhysicalPoolResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::GetPhysicalPool(
    google::protobuf::RpcController* cntl_base,
    const PhysicalPoolRequest* request,
    PhysicalPoolResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [GetPhysicalPool_PhysicalPoolRequest] "
              << request->DebugString();

    topology_->GetPhysicalPool(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [GetPhysicalPool_PhysicalPoolResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [GetPhysicalPool_PhysicalPoolResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::ListPhyPoolsInPoolset(
    google::protobuf::RpcController* cntl_base,
    const ListPhyPoolsInPoolsetRequest* request,
    ListPhysicalPoolResponse* response, google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [ListPhysicalPoolInPoolsetRequest] "
              << request->DebugString();

    topology_->ListPhyPoolsInPoolset(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [ListPhysicalPoolResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [ListPhysicalPoolResponse] "
                  << response->DebugString();
    }
    }

void TopologyServiceImpl::ListPhysicalPool(
    google::protobuf::RpcController* cntl_base,
    const ListPhysicalPoolRequest* request,
    ListPhysicalPoolResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [ListPhysicalPoolRequest] "
              << request->DebugString();

    topology_->ListPhysicalPool(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [ListPhysicalPoolResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [ListPhysicalPoolResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::CreatePoolset(
    google::protobuf::RpcController* cntl_base,
    const PoolsetRequest* request,
    PoolsetResponse* response,
    google::protobuf::Closure* done) {
        brpc::ClosureGuard done_guard(done);

        brpc::Controller* cntl =
            static_cast<brpc::Controller*>(cntl_base);

        LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [CreatePoolset_PoolsetRequest] "
              << request->DebugString();

        topology_->CreatePoolset(request, response);

        if (kTopoErrCodeSuccess != response->statuscode()) {
            LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [CreatePoolset_PoolsetResponse] "
                   << response->DebugString();
        } else {
            LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [CreatePoolset_PoolsetResponse] "
                  << response->DebugString();
        }
    }

void TopologyServiceImpl::ListPoolset(
    google::protobuf::RpcController* cntl_base,
    const ListPoolsetRequest* request,
    ListPoolsetResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [ListpoolsetRequest] "
              << request->DebugString();

    topology_->ListPoolset(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [ListpoolsetResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [ListpoolsetResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::GetPoolset(
    google::protobuf::RpcController* cntl_base,
    const PoolsetRequest* request, PoolsetResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [GetPoolset_PoolsetRequest] "
              << request->DebugString();

    topology_->GetPoolset(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [GetPoolset_PoolsetResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [GetPoolset_PoolsetResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::DeletePoolset(
    google::protobuf::RpcController* cntl_base,
    const PoolsetRequest* request,
    PoolsetResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [DeletePoolset_PoolsetRequest] "
              << request->DebugString();

    topology_->DeletePoolset(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [DeletePoolset_PoolsetResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [DeletePoolset_PoolsetlResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::CreateLogicalPool(
    google::protobuf::RpcController* cntl_base,
    const CreateLogicalPoolRequest* request,
    CreateLogicalPoolResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [CreateLogicalPoolRequest] "
              << request->DebugString();

    topology_->CreateLogicalPool(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [CreateLogicalPoolResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [CreateLogicalPoolResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::DeleteLogicalPool(
    google::protobuf::RpcController* cntl_base,
    const DeleteLogicalPoolRequest* request,
    DeleteLogicalPoolResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [DeleteLogicalPoolRequest] "
              << request->DebugString();

    topology_->DeleteLogicalPool(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [DeleteLogicalPoolResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [DeleteLogicalPoolResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::GetLogicalPool(
    google::protobuf::RpcController* cntl_base,
    const GetLogicalPoolRequest* request,
    GetLogicalPoolResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [GetLogicalPoolRequest] "
              << request->DebugString();

    topology_->GetLogicalPool(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [GetLogicalPoolResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [GetLogicalPoolResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::ListLogicalPool(
    google::protobuf::RpcController* cntl_base,
    const ListLogicalPoolRequest* request,
    ListLogicalPoolResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [ListLogicalPoolRequest] "
              << request->DebugString();

    topology_->ListLogicalPool(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [ListLogicalPoolResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [ListLogicalPoolResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::SetLogicalPool(
    google::protobuf::RpcController* cntl_base,
    const SetLogicalPoolRequest* request,
    SetLogicalPoolResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [SetLogicalPoolRequest] "
              << request->DebugString();

    topology_->SetLogicalPool(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [SetLogicalPoolResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [SetLogicalPoolResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::SetLogicalPoolScanState(
    google::protobuf::RpcController* cntl_base,
    const SetLogicalPoolScanStateRequest* request,
    SetLogicalPoolScanStateResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);
    brpc::Controller* cntl = static_cast<brpc::Controller*>(cntl_base);

    auto localAddr = cntl->local_side();
    auto remoteAddr = cntl->remote_side();
    LOG(INFO)
        << "Received request[log_id=" << cntl->log_id()
        << "] from " << remoteAddr << " to " << localAddr
        << ". [SetLogicalPoolScanStateRequest] " << request->DebugString();

    topology_->SetLogicalPoolScanState(request, response);

    std::ostringstream errMsg;
    errMsg << "Send response[log_id=" << cntl->log_id()
           << "] from " << localAddr << " to " << remoteAddr
           << ". [SetLogicalPoolScanStateResponse] " << response->DebugString();

    auto retCode = response->statuscode();
    if (retCode == kTopoErrCodeSuccess) {
        LOG(INFO) << errMsg.str();
    } else {
        LOG(ERROR) << errMsg.str();
    }
}

void TopologyServiceImpl::GetChunkServerListInCopySets(
    google::protobuf::RpcController* cntl_base,
    const GetChunkServerListInCopySetsRequest* request,
    GetChunkServerListInCopySetsResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    topology_->GetChunkServerListInCopySets(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [GetChunkServerListInCopySetsResponse] "
                   << response->DebugString();
    }
}

void TopologyServiceImpl::GetCopySetsInChunkServer(
                      google::protobuf::RpcController* cntl_base,
                      const GetCopySetsInChunkServerRequest* request,
                      GetCopySetsInChunkServerResponse* response,
                      google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [GetCopySetsInChunkServerRequest] "
              << request->DebugString();

    topology_->GetCopySetsInChunkServer(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [GetCopySetsInChunkServerResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [GetCopySetsInChunkServerResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::GetCopySetsInCluster(
    google::protobuf::RpcController* cntl_base,
    const GetCopySetsInClusterRequest* request,
    GetCopySetsInClusterResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);
    brpc::Controller* cntl = static_cast<brpc::Controller*>(cntl_base);

    auto localAddr = cntl->local_side();
    auto remoteAddr = cntl->remote_side();
    LOG(INFO)
        << "Received request[log_id=" << cntl->log_id()
        << "] from " << remoteAddr << " to " << localAddr
        << ". [GetCopySetsInCluster] " << request->DebugString();

    topology_->GetCopySetsInCluster(request, response);

    std::ostringstream errMsg;
    errMsg << "Send response[log_id=" << cntl->log_id()
           << "] from " << localAddr << " to " << remoteAddr
           << ". [GetCopySetsInCluster] " << response->DebugString();

    if (response->statuscode() == kTopoErrCodeSuccess) {
        LOG(INFO) << errMsg.str();
    } else {
        LOG(ERROR) << errMsg.str();
    }
}

void TopologyServiceImpl::GetCopyset(
    google::protobuf::RpcController* cntl_base,
    const GetCopysetRequest* request,
    GetCopysetResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);
    brpc::Controller* cntl = static_cast<brpc::Controller*>(cntl_base);

    auto localAddr = cntl->local_side();
    auto remoteAddr = cntl->remote_side();
    LOG(INFO)
        << "Received request[log_id=" << cntl->log_id()
        << "] from " << remoteAddr << " to " << localAddr
        << ". [GetCopyset] " << request->DebugString();

    topology_->GetCopyset(request, response);

    std::ostringstream errMsg;
    errMsg << "Send response[log_id=" << cntl->log_id()
           << "] from " << localAddr << " to " << remoteAddr
           << ". [GetCopyset] " << response->DebugString();

    if (response->statuscode() == kTopoErrCodeSuccess) {
        LOG(INFO) << errMsg.str();
    } else {
        LOG(ERROR) << errMsg.str();
    }
}

void TopologyServiceImpl::GetClusterInfo(
    google::protobuf::RpcController* cntl_base,
    const GetClusterInfoRequest* request,
    GetClusterInfoResponse* response,
    google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [GetClusterInfoRequest]";

    topology_->GetClusterInfo(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [GetClusterInfoResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [GetClusterInfoResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::SetCopysetsAvailFlag(
                      google::protobuf::RpcController* cntl_base,
                      const SetCopysetsAvailFlagRequest* request,
                      SetCopysetsAvailFlagResponse* response,
                      google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);
    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [SetCopysetsAvailFlagRequest] "
              << request->DebugString();

    topology_->SetCopysetsAvailFlag(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [SetCopysetsAvailFlagResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [SetCopysetsAvailFlagResponse] "
                  << response->DebugString();
    }
}

void TopologyServiceImpl::ListUnAvailCopySets(
                      google::protobuf::RpcController* cntl_base,
                      const ListUnAvailCopySetsRequest* request,
                      ListUnAvailCopySetsResponse* response,
                      google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);
    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
              << "] from " << cntl->remote_side()
              << " to " << cntl->local_side()
              << ". [ListUnAvailCopySetsRequest] "
              << request->DebugString();

    topology_->ListUnAvailCopySets(request, response);

    if (kTopoErrCodeSuccess != response->statuscode()) {
        LOG(ERROR) << "Send response[log_id=" << cntl->log_id()
                   << "] from " << cntl->local_side()
                   << " to " << cntl->remote_side()
                   << ". [ListUnAvailCopySetsResponse] "
                   << response->DebugString();
    } else {
        LOG(INFO) << "Send response[log_id=" << cntl->log_id()
                  << "] from " << cntl->local_side()
                  << " to " << cntl->remote_side()
                  << ". [ListUnAvailCopySetsResponse] "
                  << response->DebugString();
    }
}

}  // namespace topology
}  // namespace mds
}  // namespace curve


















