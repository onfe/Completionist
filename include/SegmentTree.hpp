#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include "SegmentTreeNode.hpp"
#include "type.hpp"


class SegmentTree {
  /*
   * Builds a heap based Segment Tree, given a length
   * of indicies to represent.
   */
  uint32_t length;
  uipv_t heap;

public:
  SegmentTree(uint32_t len = 0);

  void init(uint32_t len);

  void init(std::vector<uint32_t> elements);

  uip_t getMax(uint32_t idxFirst, uint32_t idxLast);

private:
  // Create the heap and parent nodes recursively
  uip_t build (
    uint32_t heapidx,
    uint32_t idx1,
    uint32_t idx2,
    std::vector<uint32_t> weights
  );

  uip_t qmax(
    uint32_t heapidx,
    uint32_t idx1,
    uint32_t idx2,
    uint32_t firstidx,
    uint32_t lastidx
  );

  int calcHeap(int len);
};
