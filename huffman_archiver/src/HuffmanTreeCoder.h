//
//  HuffmanTreeCoder.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef huffman_archiver_HuffmanTreeCoder_h
#define huffman_archiver_HuffmanTreeCoder_h

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <ios>

#include "Declarations.h"
#include "Constants.h"
#include "HuffmanTree.h"
#include "HuffmanTreeNodePriorityComparer.h"
#include "BitWriter.h"


using std::ostream;
using std::istream;
using std::string;
using std::vector;
using std::priority_queue;
using std::ios;



class HuffmanTreeCoder
{
public:
    HuffmanTreeCoder(istream*, ostream*);
    ~HuffmanTreeCoder();
    
    void Compress();

private:
    HuffmanTreeCoder(HuffmanTreeCoder const&);
    HuffmanTreeCoder& operator=(HuffmanTreeCoder const&);
    
    void setReaderToBeginning();
    
    long CalculateNumberOfSymbols();
    void CalculateSymbolFrequencies();
    void SetSymbolCodes();
    void EncodeSymbols();
    void WriteHeader();
    
    istream* m_input_stream;
    ostream* m_output_stream;
    
    HuffmanTree* m_tree;
    vector<long> m_symbol_frequencies;
    long m_symbols_count;
    
    vector<BitCode> m_symbol_codes;
};



#endif
