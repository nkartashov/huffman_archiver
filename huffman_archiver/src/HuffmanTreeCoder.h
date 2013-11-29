//
//  HuffmanTreeCoder.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef huffman_archiver_HuffmanTreeCoder_h
#define huffman_archiver_HuffmanTreeCoder_h

#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <ios>

#include "Declarations.h"
#include "Constants.h"
#include "HuffmanCoderDecoderBase.h"
#include "HuffmanTree.h"
#include "HuffmanTreeNodePriorityComparer.h"
#include "BitWriter.h"


using std::ostream;
using std::istream;
using std::string;
using std::vector;
using std::priority_queue;
using std::ios;



class HuffmanTreeCoder: public HuffmanCoderDecoderBase
{
public:
    HuffmanTreeCoder(istream*, ostream*);
    ~HuffmanTreeCoder() {}
    
    void Compress();

    
private:
    HuffmanTreeCoder(HuffmanTreeCoder const&);
    HuffmanTreeCoder& operator=(HuffmanTreeCoder const&);
    
    long CalculateNumberOfSymbols();
    void CalculateSymbolFrequencies();
    void SetSymbolCodes();
    void EncodeSymbols();
    void WriteHeader();
    
    vector<BitCode> m_symbol_codes;
};



#endif
