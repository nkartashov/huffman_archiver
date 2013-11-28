//
//  HuffmanTree.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "HuffmanTree.h"

HuffmanTree::HuffmanTree() {}

HuffmanTree::~HuffmanTree()
{
    if (m_root)
        DeleteTree(m_root);
}

void HuffmanTree::DeleteTree(HuffmanTreeNode* node)
{
    if (!node->isInner())
    {
        DeleteTree(node->leftChild());
        DeleteTree(node->rightChild());
    }
    delete node;
}

void HuffmanTree::BuildHuffmanTree(vector<long> frequencies)
{
    for (int i = 0; i < frequencies.size(); i++)
        if (frequencies[i])
            m_nodes_queue.push(new HuffmanTreeNode(static_cast<uchar>(i), frequencies[i]));
    
    HuffmanTreeNode* leftChild = 0;
    HuffmanTreeNode* rightChild = 0;
    long new_frequency = 0;
    while (m_nodes_queue.size() > 1)
    {
        leftChild = m_nodes_queue.top();
        m_nodes_queue.pop();
        rightChild = m_nodes_queue.top();
        m_nodes_queue.pop();
        new_frequency = leftChild->frequency() + rightChild->frequency();
        m_nodes_queue.push(new HuffmanTreeNode(0, new_frequency, leftChild, rightChild));
    }
    m_root = m_nodes_queue.top();
    m_nodes_queue.pop();
}

vector<BitCode> HuffmanTree::GetSymbolCodes()
{
    vector<BitCode> result(kMaxNumberDifferentSymbols);
    if (m_root->isInner())
    {
        result.push_back(BitCode(0));
    }
    else
    {
        TraverseNode(m_root, BitCode(), result);
    }
    return result;
}

void HuffmanTree::TraverseNode(HuffmanTreeNode* node, BitCode code, vector<BitCode>& symbol_codes)
{
    if (node->isInner())
        symbol_codes[node->symbol()] = code;
    else
    {
        BitCode leftChildCode = BitCode(code);
        leftChildCode.push_back(0);
        TraverseNode(node->leftChild(), leftChildCode, symbol_codes);
        BitCode rightChildCode = BitCode(code);
        rightChildCode.push_back(1);
        TraverseNode(node->rightChild(), rightChildCode, symbol_codes);
    }
}
