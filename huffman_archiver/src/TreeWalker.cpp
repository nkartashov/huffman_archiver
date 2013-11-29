//
//  TreeWalker.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 29/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "TreeWalker.h"


TreeWalker::TreeWalker(HuffmanTreeNode* root): m_root(root), m_current_node(m_root)
{
}

int TreeWalker::NextBit(bool bit)
{
    int result = -1;
    
    if (bit)
        m_current_node = m_current_node->rightChild();
    else
        m_current_node = m_current_node->leftChild();
    if (!m_current_node->isInner())
        return result;
        
    result = m_current_node->symbol();
    m_current_node = m_root;
    return result;
}