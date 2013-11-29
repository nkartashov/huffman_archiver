//
//  TreeWalker.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 29/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __huffman_archiver__TreeWalker__
#define __huffman_archiver__TreeWalker__

#include <iostream>

#include "HuffmanTreeNode.h"

class TreeWalker
{
public:
    
    TreeWalker(HuffmanTreeNode*);

    int NextBit(bool);
    
private:
    TreeWalker(TreeWalker const&);
    TreeWalker const& operator=(TreeWalker const&);
    
    HuffmanTreeNode* m_root;
    HuffmanTreeNode* m_current_node;
};

#endif /* defined(__huffman_archiver__TreeWalker__) */
