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
using std::istream;
using std::ostream;
using std::ios;

class HuffmanCoderDecoderBase
{
public:
    HuffmanCoderDecoderBase(istream*, ostream*);
    ~HuffmanCoderDecoderBase();
    
protected:
    void setReaderToBeginning();
    
    istream* m_input_stream;
    ostream* m_output_stream;
    
    HuffmanTree* m_tree;
    vector<long> m_symbol_frequencies;
    long m_symbols_count;
};

#endif
