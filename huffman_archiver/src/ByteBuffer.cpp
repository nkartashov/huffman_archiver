//
//  ByteBuffer.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "ByteBuffer.h"


ByteBuffer::ByteBuffer(): m_byte(new uchar), m_current_position(0)
{
}

ByteBuffer::~ByteBuffer()
{
    delete m_byte;
}

void ByteBuffer::SetBit(bool bit)
{
    if (bit)
        *m_byte = *m_byte | (static_cast<int> (bit) << m_current_position++);
    else
        *m_byte = *m_byte & ~(1 << m_current_position++);
}

bool ByteBuffer::GetBit()
{
   return (*m_byte & (1 << m_current_position++));
}

uchar ByteBuffer::Flush()
{
    m_current_position = 0;
    return *m_byte;
}

void ByteBuffer::Fill(uchar byte)
{
    m_current_position = 0;
    *m_byte = byte;
}