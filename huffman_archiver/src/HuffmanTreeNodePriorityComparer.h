//
//  HuffmanTreeNodePriorityComparer.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef huffman_archiver_HuffmanTreeNodePriorityComparer_h
#define huffman_archiver_HuffmanTreeNodePriorityComparer_h

#include "HuffmanTreeNode.h"

class HuffmanTreeNodePriorityComparer
{
public:
    bool operator()(const HuffmanTreeNode* left, const HuffmanTreeNode* right) const
    {
        return left->frequency() > right->frequency();
    }
};
#endif
