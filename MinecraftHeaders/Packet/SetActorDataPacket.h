#pragma once

#include <vector>
#include <memory>

#include "../Core/Packet.h"
#include "../Core/DataItem.h"
#include "../Actor/ActorRuntimeID.h"
#include "../dll.h"

class SetActorDataPacket : public Packet {
public:
  ActorRuntimeID rid;
  std::vector<std::unique_ptr<DataItem>> items;

  inline ~SetActorDataPacket() {}
  MCAPI virtual MinecraftPacketIds getId() const;
  MCAPI virtual std::string getName() const;
  MCAPI virtual void write(BinaryStream &) const;
  MCAPI virtual PacketReadResult read(ReadOnlyBinaryStream &);
};

static_assert(offsetof(SetActorDataPacket, rid) == 40);