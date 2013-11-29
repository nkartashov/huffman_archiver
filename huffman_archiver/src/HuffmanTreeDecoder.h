//
//  HuffmanTreeDecoder.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef huffman_archiver_HuffmanTreeDecoder_h
#define huffman_archiver_HuffmanTreeDecoder_h

#include <iostream>
#include <string>
#include <vector>
#include <ios>

#include "Constants.h"
#include "HuffmanTree.h"
#include "BitReader.h"

using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::ios;

class HuffmanTreeDecoder
{
public:
    HuffmanTreeDecoder(istream*, ostream*);
    ~HuffmanTreeDecoder();
    
    void Decompress();
    
private:
    HuffmanTreeDecoder(HuffmanTreeDecoder const&);
    HuffmanTreeDecoder& operator=(HuffmanTreeDecoder const&);
    
    void setReaderToBeginning();
    
    void ReadHeader();
    void DecodeSymbols();
    
    istream* m_input_stream;
    ostream* m_output_stream;
    
    HuffmanTree* m_tree;
    vector<long> m_symbol_frequencies;
    long m_symbols_count;
};

#endif
