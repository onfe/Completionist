#include "SegmentTreeNode.hpp"

SegmentTreeNode::SegmentTreeNode() {
  s = 0;
  min = 0;
  max = 0;
  from = 0;
  to = 0;
  pval = 0;
  pending = false;
}

int SegmentTreeNode::size() {
  return to - from + 1;
}
