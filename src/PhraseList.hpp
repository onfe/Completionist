#pragma once
#include <vector>
#include <array>
#include <algorithm>
#include <stdint.h>
#include <iostream>
#include "Phrase.hpp"
#include "FindPrefix.hpp"
#include "type.hpp"


class PhraseList {
public:
  pvc_t pl;

public:
  PhraseList(std::uint32_t slen = 65535) {
    this->pl.reserve(slen);
  }

  void insert(std::uint32_t weight, std::string phrase) {
    this->pl.push_back({weight, phrase});
  }

  void finish(bool sorted = false) {
    if (!sorted) {
      std::cout << "Sorting.";
      std::sort(this->pl.begin(), this->pl.end());
      std::cout << this->pl[0].phrase;
    }
  }

  pvcip_t query(std::string pf) {
    return std::equal_range(this->pl.begin(), this->pl.end(), pf, FindPrefix());
  }
};
