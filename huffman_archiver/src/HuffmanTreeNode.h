//
//  HuffmanTreeNode.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef huffman_archiver_HuffmanTreeNode_h
#define huffman_archiver_HuffmanTreeNode_h

#include "Declarations.h"

class HuffmanTreeNode
{
public:
    HuffmanTreeNode(uchar symbol = 0,
                    long frequency = 0,
                    HuffmanTreeNode* left_child = 0,
                    HuffmanTreeNode* right_child = 0):
    m_symbol(symbol),
    m_frequency(frequency),
    m_left_child(left_child),
    m_right_child(right_child) {}
    
    bool isInner() {return !(m_left_child && m_right_child);}
    
    long frequency() const {return m_frequency;}
    
    HuffmanTreeNode* leftChild() {return m_left_child;}
    
    HuffmanTreeNode* rightChild() {return m_right_child;}
    
    uchar symbol() const {return m_symbol;}
    
private:
    HuffmanTreeNode(HuffmanTreeNode&);
    HuffmanTreeNode& operator=(HuffmanTreeNode const&);
    
    const uchar m_symbol;
    const long m_frequency;
    HuffmanTreeNode* m_left_child;
    HuffmanTreeNode* m_right_child;
};


#endif
