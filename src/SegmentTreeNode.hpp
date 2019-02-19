#pragma once

class SegmentTreeNode {
  int s, min, max, from, to, pval;
  bool pending;

public:
  SegmentTreeNode() {
    s = 0;
    min = 0;
    max = 0;
    from = 0;
    to = 0;
    pval = 0;
    pending = false;
  }

  int size() {
    return to - from + 1;
  }
};
