//
// Created by jlaustill on 12/31/21.
//

#include "CanId.h"

[[maybe_unused]] CanId::CanId(const std::array<byte, 4> &newIdData) {
    this->computeNewIdFromBytes(newIdData);
}

[[maybe_unused]] CanId::CanId(const int newId) {
    this->updateIdByInt(newId);
}

int CanId::computeNewIdFromBytes(const std::array<byte, 4> &newIdData) {
    this->isExtended = false;
    int newId = (newIdData[0] << 3) + (newIdData[1] >> 5);
    if ((newIdData[1] & 0x08) ==  0x08) {
        /* extended newId
        */
        this->isExtended = true;
        newId = (newId << 2) + (newIdData[1] & 0x03);
        newId = (newId << 8) + newIdData[2];
        newId = (newId << 8) + newIdData[3];
    }

    this->id = newId;
    return newId;
}

[[maybe_unused]] std::array<byte, 4> CanId::getIdBytes() const {
    uint16_t workingId;

    workingId = (uint16_t)(this->id & 0x0FFFF);

    if (this->isExtended) {
        byte fourthByte = (byte)(workingId & 0xFF);
        byte thirdByte = (byte)(workingId >> 8);
        workingId = (uint16_t)(id >> 16);
        byte secondByte = (byte)(workingId & 0x03);
        secondByte += (byte)((workingId & 0x1C) << 3);
        secondByte |= 0x08;
        byte firstByte = (byte)(workingId >> 5);
        return { firstByte, secondByte, thirdByte, fourthByte };
    } else {
        byte firstByte = (byte)(workingId >> 3);
        byte secondByte = (byte)((workingId & 0x07) << 5);
        byte thirdByte = 0;
        byte fourthByte = 0;
        return { firstByte, secondByte, thirdByte, fourthByte };
    }
}

[[maybe_unused]] int CanId::updateIdByBytes(const std::array<byte, 4> &newIdData) {
    return computeNewIdFromBytes(newIdData);
}

int CanId::updateIdByInt(const int newId) {
    this->id = newId;
    if (newId > 2040) {
        this->isExtended = true;
    } else {
        this->isExtended = false;
    }
    return this->id;
}

std::string CanId::to_int_string() {
    return std::to_string(id);
}

std::string CanId::to_hex_string() {
    std::ostringstream result;
    result << "0x" << std::hex << id;
    return result.str();
}
