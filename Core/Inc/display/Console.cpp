//
// Created by jlaustill on 12/26/21.
//

#include "Console.h"

void Console::logln(const std::string &message) {
    Console::sendData(message);
    Console::sendData("\n\r");
}

void Console::log(const std::string &message) {
    Console::sendData(message);
}

UART_HandleTypeDef Console::uart;

void Console::sendData(const std::string &data) {
    const auto* m = reinterpret_cast<const uint8_t*>(data.c_str());
    HAL_UART_Transmit(&Console::uart, m, data.length(), 100);
}

void Console::setUart(UART_HandleTypeDef newConsoleUart) {
    Console::uart = newConsoleUart;
}

