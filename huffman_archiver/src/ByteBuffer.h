//
//  ByteBuffer.h
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#ifndef huffman_archiver_ByteBuffer_h
#define huffman_archiver_ByteBuffer_h

#include "Constants.h"
#include "Declarations.h"

class ByteBuffer
{
public:
    ByteBuffer();
    
    ~ByteBuffer();
    
    void SetBit(bool bit);
    bool GetBit();
    bool HasNext() {return m_current_position < kBitsInByte;}
    uchar Flush();
    void Fill(uchar byte);

private:
    ByteBuffer(ByteBuffer const&);
    ByteBuffer const& operator=(ByteBuffer const&);
    
    uchar* m_byte;
    int m_current_position;
};


#endif