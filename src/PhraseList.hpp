#pragma once
#include <vector>
#include <array>
#include <algorithm>
#include <stdint.h>
#include <iostream>
#include "phrase.hpp"
#include "FindPrefix.hpp"

typedef std::vector<phrase_t> pvc_t;
typedef pvc_t::iterator pvci_t;
typedef std::pair<pvci_t, pvci_t> pvcip_t;

class PhraseList {
  pvc_t pl;

public:
  PhraseList(std::uint32_t slen = 65535) {
    this->pl.reserve(slen);
  }

  void insert(std::uint32_t weight, std::string phrase) {
    phrase_t prs = phrase_t(weight, phrase);
    this->pl.push_back(prs);
  }

  void finish(bool sorted = false) {
    if (!sorted) {
      std::sort(this->pl.begin(), this->pl.end());
    }
  }

  pvcip_t query(std::string pf) {
    return std::equal_range(this->pl.begin(), this->pl.end(), pf, FindPrefix());
  }
};
