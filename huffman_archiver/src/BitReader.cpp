//
//  BitReader.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 29/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "BitReader.h"

BitReader::BitReader(istream* input_stream):
m_byte(new uchar),
m_current_position(0),
m_input_stream(input_stream)
{
}

BitReader::~BitReader()
{
    delete m_byte;
}

bool BitReader::GetBit()
{
    if (!HasNext())
        Fill();
    return (*m_byte & (1 << m_current_position++));
}

long BitReader::ReadLong()
{
    uchar max_byte = 0xFF;
    long result = 0;
    char buf = 0;
    for (int i = 0; i < 4; ++i)
    {
        m_input_stream->get(buf);
        result += (static_cast<long> (buf) & max_byte) << (i * kBitsInByte);
    }
    return result;
}


void BitReader::Fill()
{
    m_current_position = 0;
    *m_byte = m_input_stream->get();
}