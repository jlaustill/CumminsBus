//
// Created by jlaustill on 12/26/21.
//

#ifndef CUMMINSBUSSNIFFER_CONSOLE_H
#define CUMMINSBUSSNIFFER_CONSOLE_H

#include "main.h"
#include <cstdio>
#include <string>

class Console {
public:
    static void logln(const std::string& message);
    static void log(const std::string &message);
    static void setUart(UART_HandleTypeDef newConsoleUart);

private:
    static void sendData(const std::string& data);
    static UART_HandleTypeDef uart;

};

#endif //CUMMINSBUSSNIFFER_CONSOLE_H
