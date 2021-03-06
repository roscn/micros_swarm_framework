/**
Software License Agreement (BSD)
\file      packet_parser.h
\authors Xuefeng Chang <changxuefengcn@163.com>
\copyright Copyright (c) 2016, the micROS Team, HPCL (National University of Defense Technology), All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that
the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the
   following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
   following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of micROS Team, HPCL, nor the names of its contributors may be used to endorse or promote
   products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WAR-
RANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, IN-
DIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef PACKET_PARSER_H_
#define PACKET_PARSER_H_

#include <iostream>
#include <time.h>
#include <vector>
#include <map>

#include "micros_swarm/singleton.h"
#include "micros_swarm/packet_type.h"
#include "micros_swarm/serialize.h"
#include "micros_swarm/check_neighbor.h"
#include "micros_swarm/runtime_handle.h"
#include "micros_swarm/msg_queue_manager.h"

#include "gsdf_msgs/CommHeader.h"
#include "gsdf_msgs/CommContent.h"
#include "gsdf_msgs/CommPacket.h"
#include "gsdf_msgs/RobotBase.h"
#include "gsdf_msgs/JoinSwarm.h"
#include "gsdf_msgs/LeaveSwarm.h"
#include "gsdf_msgs/SwarmList.h"
#include "gsdf_msgs/VirtualStigmergyQuery.h"
#include "gsdf_msgs/VirtualStigmergyPut.h"
#include "gsdf_msgs/VirtualStigmergyPuts.h"
#include "gsdf_msgs/BlackBoardQuery.h"
#include "gsdf_msgs/BlackBoardAck.h"
#include "gsdf_msgs/BlackBoardPut.h"
#include "gsdf_msgs/SCDSPSOGet.h"
#include "gsdf_msgs/SCDSPSOPut.h"
#include "gsdf_msgs/NeighborBroadcastKeyValue.h"
#include "gsdf_msgs/BarrierSyn.h"
#include "gsdf_msgs/BarrierAck.h"

namespace micros_swarm{

    class PacketParser{
        public:
            PacketParser();
            ~PacketParser();
            void parse(const std::vector<uint8_t>& data);
            void parse(const std::vector<char>& data);
            void parse(uint8_t* data, int len);
            void parse(char* data, int len);
        private:
            boost::shared_ptr<micros_swarm::RuntimeHandle> rth_;
            boost::shared_ptr<CheckNeighborInterface> cni_;
            boost::shared_ptr<micros_swarm::MsgQueueManager> mqm_;
    };
};

#endif
