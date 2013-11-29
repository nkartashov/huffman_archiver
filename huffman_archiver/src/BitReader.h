//
//  BitReader.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 29/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __huffman_archiver__BitReader__
#define __huffman_archiver__BitReader__

#include <iostream>

#include "Declarations.h"
#include "Constants.h"

using std::istream;

class BitReader
{
public:
    BitReader(istream*);
    
    ~BitReader();
    
    void Fill();
    
    bool GetBit();
    long ReadLong();
    
private:
    BitReader(BitReader const&);
    BitReader const& operator=(BitReader const&);
    
    bool HasNext() {return m_current_position < kBitsInByte;}
    
    uchar* m_byte;
    int m_current_position;
    
    istream* m_input_stream;
};


#endif /* defined(__huffman_archiver__BitReader__) */
