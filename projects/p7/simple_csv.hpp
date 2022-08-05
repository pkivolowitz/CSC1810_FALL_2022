#pragma once
#include <vector>
#include <string>

const uint32_t SS_TRIM = 0x01;
const uint32_t SS_NOQUOTES = 0x02;
const uint32_t SS_NOTRIMMING = 0x04;

std::vector<std::string> SimpleSplit(std::string &, char delimeter, uint32_t sso);
