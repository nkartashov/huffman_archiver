//
//  BitWriter.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 29/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef __huffman_archiver__BitWriter__
#define __huffman_archiver__BitWriter__

#include <iostream>

#include "Declarations.h"
#include "Constants.h"

using std::ostream;

class BitWriter
{
public:
    BitWriter(ostream*);
    ~BitWriter();
    
    void Flush();
    void WriteBitCode(BitCode code);
    void WriteLong(long value);
    
private:
    BitWriter(BitWriter const&);
    BitWriter const& operator=(BitWriter const&);
    
    bool HasNext() {return m_current_position < kBitsInByte;}
    void SetBit(bool bit);
    
    uchar* m_byte;
    int m_current_position;
    ostream* m_output_stream;
};

#endif /* defined(__huffman_archiver__BitWriter__) */
