#ifndef TRANSLATECONSTANT_H
#define TRANSLATECONSTANT_H

#pragma once
#include <string>
typedef struct {
  int key;
  std::string value;
} constantDictionary;

class TranslateConstant {
 public:
  TranslateConstant();
  ~TranslateConstant();
  std::string get_translated_constant(int the_constant);
  std::string get_translated_digital_mode(int the_constant);

 private:
  // const constantDictionary _map_constant_to_string[< int, std::string> ];
  // const constantDictionary  _digital_mode_to_string[];
};

#endif
