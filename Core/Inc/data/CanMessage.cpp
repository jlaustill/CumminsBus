//
// Created by jlaustill on 12/31/21.
//

#include "CanMessage.h"

[[maybe_unused]] CanMessage::CanMessage(int canId): canId(canId) {
    data = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
    length = 8;
}

[[maybe_unused]] CanMessage::CanMessage(const std::array<byte, 4> &newIdData): canId(newIdData) {
    data = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
    length = 8;
}

void CanMessage::updateDataByBytes(const std::array<byte, 8> &newData) {
    for (byte i = 0; i < this->length; i++) {
        this->data[i] = newData[i];
    }
}