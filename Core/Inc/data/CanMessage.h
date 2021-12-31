//
// Created by jlaustill on 12/31/21.
//

#ifndef STM32CUBEMX_CPP_TAKE3_CANMESSAGE_H
#define STM32CUBEMX_CPP_TAKE3_CANMESSAGE_H
#include "main.h"
#include "./CanId.h"


class CanMessage {
public:
    [[maybe_unused]] explicit CanMessage(int canId);
    [[maybe_unused]] explicit CanMessage(const std::array<byte, 4> &newIdData);

    [[maybe_unused]] CanId canId;

    [[maybe_unused]] void updateDataByBytes(const std::array<byte, 8> &newData);

    [[maybe_unused]] [[nodiscard]] std::array<byte, 8> data;
    [[maybe_unused]] byte length;
};


#endif //STM32CUBEMX_CPP_TAKE3_CANMESSAGE_H
