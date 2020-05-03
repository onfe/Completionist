#pragma once

class SegmentTreeNode {
  int s, min, max, from, to, pval;
  bool pending;

public:
  SegmentTreeNode();

  int size();
};
