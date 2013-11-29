//
//  HuffmanTreeDecoder.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef huffman_archiver_HuffmanTreeDecoder_h
#define huffman_archiver_HuffmanTreeDecoder_h

#include <fstream>
#include <string>
#include <vector>
#include <ios>

#include "Constants.h"
#include "HuffmanCoderDecoderBase.h"
#include "HuffmanTree.h"
#include "BitReader.h"

using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::ios;

class HuffmanTreeDecoder: public HuffmanCoderDecoderBase
{
public:
    HuffmanTreeDecoder(istream*, ostream*);
    ~HuffmanTreeDecoder() {}
    
    void Decompress();
    
private:
    HuffmanTreeDecoder(HuffmanTreeDecoder const&);
    HuffmanTreeDecoder& operator=(HuffmanTreeDecoder const&);
    
    void ReadHeader();
    void DecodeSymbols();
};

#endif
