#include "../lib/functions.hpp"

void setIP(string interface, string ip) {
    string cmd = "sudo ifconfig ";
    cmd += interface + " " + ip;

    system(cmd.c_str());
}