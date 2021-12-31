//
// Created by jlaustill on 12/31/21.
//

#ifndef STM32CUBEMX_CPP_TAKE3_CANID_H
#define STM32CUBEMX_CPP_TAKE3_CANID_H


#include <iostream>
#include <sstream>
#include <array>
#include "main.h"

class [[maybe_unused]] CanId {
public:
    [[maybe_unused]] [[maybe_unused]] explicit CanId(const std::array<byte, 4> &newIdData);

    [[maybe_unused]] explicit CanId(int newId);

    [[maybe_unused]] int updateIdByBytes(const std::array<byte, 4> &newIdData);
    [[maybe_unused]] int updateIdByInt(int newId);
    [[maybe_unused]] int computeNewIdFromBytes(const std::array<byte, 4> &newIdData);

    [[maybe_unused]] std::string to_int_string();
    [[maybe_unused]] std::string to_hex_string();

    [[maybe_unused]] [[nodiscard]] std::array<byte, 4> getIdBytes() const;

    int id = 0;
    bool isExtended = false;

};



#endif //STM32CUBEMX_CPP_TAKE3_CANID_H
