#include <vector>
#include <array>
#include <algorithm>
#include <stdint.h>
#include <iostream>

#include "PhraseList.hpp"

#include "Phrase.hpp"
#include "FindPrefix.hpp"
#include "type.hpp"

PhraseList::PhraseList(std::uint32_t slen) {
  this->pl.reserve(slen);
}

void PhraseList::insert(std::uint32_t weight, std::string phrase) {
  this->pl.push_back({weight, phrase});
}

void PhraseList::finish(bool sorted) {
  if (!sorted) {
    std::cout << "Sorting.";
    std::sort(this->pl.begin(), this->pl.end());
    std::cout << this->pl[0].phrase;
  }
}

pvcip_t PhraseList::query(std::string pf) {
  return std::equal_range(this->pl.begin(), this->pl.end(), pf, FindPrefix());
}
