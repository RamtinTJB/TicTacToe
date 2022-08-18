#ifndef TIC_TAC_TOE_INPUT_H
#define TIC_TAC_TOE_INPUT_H

#include <iostream>
#include <string>

std::string get_entry(const std::string& prompt);
int get_int(const std::string& prompt);
int get_int_range(const std::string& prompt, int begin, int end);
bool get_bool(const std::string& prompt);

#endif
