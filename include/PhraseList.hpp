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
  PhraseList(std::uint32_t slen = 65535);

  void insert(std::uint32_t weight, std::string phrase);

  void finish(bool sorted = false);

  pvcip_t query(std::string pf);
};
