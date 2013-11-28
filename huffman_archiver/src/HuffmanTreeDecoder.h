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
#include "ByteBuffer.h"

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::ios;

class HuffmanTreeDecoder: public HuffmanCoderDecoderBase
{
public:
    HuffmanTreeDecoder(string& inputFile, string& outputFile);
    ~HuffmanTreeDecoder() {}
    
    void Decompress();
    
private:
    HuffmanTreeDecoder(HuffmanTreeDecoder const&);
    HuffmanTreeDecoder& operator=(HuffmanTreeDecoder const&);
    
    void ReadHeader();
    long ReadLong();
    void DecodeSymbols();
};

#endif
