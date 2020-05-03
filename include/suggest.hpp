#pragma once
#include <stdint.h>

#include "PhraseList.hpp"
#include "SegmentTree.hpp"
#include "type.hpp"


pvc_t suggest (
  PhraseList& pl,
  SegmentTree& st,
  std::string& prefix,
  uint32_t numResults
);
