#pragma once

#include "ns3/internet-module.h"
#include "ns3/flow-monitor-module.h"

namespace ns3{

void TraceMacRx(Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet);

void TraceMacTx(Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet);

void TraceQueueItemDrop(Ptr<OutputStreamWrapper> stream, Ptr<const QueueItem> item);

void ConfigureTracing (const string& outputDir, const NodeContainer& server,
                       const NodeContainer& client, const NodeContainer& isps,
                       const NodeContainer& ixs);

void GetThroughout(void);
}
