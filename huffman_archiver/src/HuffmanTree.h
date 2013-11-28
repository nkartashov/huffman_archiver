//
//  HuffmanTree.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef huffman_archiver_HuffmanTree_h
#define huffman_archiver_HuffmanTree_h

#include <vector>
#include <queue>

#include "Constants.h"
#include "HuffmanTreeNode.h"
#include "HuffmanTreeNodePriorityComparer.h"

using std::vector;
using std::priority_queue;

class HuffmanTree
{
public:
    HuffmanTree();
    ~HuffmanTree();
    
    void DeleteTree(HuffmanTreeNode*);
    
    void BuildHuffmanTree(vector<long> frequencies);
    vector<BitCode> GetSymbolCodes();
    
    HuffmanTreeNode* root() {return m_root;}
    
    bool isTrivial() {return m_root->isInner();}

private:
    HuffmanTree(HuffmanTree const&);
    HuffmanTree const& operator=(HuffmanTree const&);
    
    void TraverseNode(HuffmanTreeNode* node, BitCode code, vector<BitCode>& symbol_codes);
    
    HuffmanTreeNode* m_root;
    priority_queue<HuffmanTreeNode*,
    vector<HuffmanTreeNode*>,
    HuffmanTreeNodePriorityComparer> m_nodes_queue;
};

#endif
