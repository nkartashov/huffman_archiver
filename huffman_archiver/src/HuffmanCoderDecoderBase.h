//
//  HuffmanInputOutputBase.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 08/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef huffman_archiver_HuffmanInputOutputBase_h
#define huffman_archiver_HuffmanInputOutputBase_h

#include <string>
#include <fstream>
#include <ios>

#include "HuffmanTree.h"

using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

class HuffmanCoderDecoderBase
{
public:
    HuffmanCoderDecoderBase(ifstream*, ofstream*);
    ~HuffmanCoderDecoderBase();
    
protected:
    void setReaderToBeginning();
    
    ifstream* m_input_stream;
    ofstream* m_output_stream;
    
    HuffmanTree* m_tree;
    vector<long> m_symbol_frequencies;
    long m_symbols_count;
};

#endif
