//
//  BitWriter.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 29/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "BitWriter.h"

BitWriter::BitWriter(ostream* output_stream):
m_byte(new uchar),
m_current_position(0),
m_output_stream(output_stream)
{
}

BitWriter::~BitWriter()
{
    delete m_byte;
}

void BitWriter::Flush()
{
    m_current_position = 0;
    m_output_stream->put(*m_byte);
}

void BitWriter::WriteBitCode(BitCode code)
{
    for (size_t j = 0; j != code.size(); ++j)
    {
        if (!HasNext())
        {
            Flush();
        }
        SetBit(code[j]);
    }
}

void BitWriter::WriteLong(long value)
{
    long max_char = 0xFF;
    for (int i = 0; i < 4; ++i)
    {
        m_output_stream->put((max_char << (i * kBitsInByte) & value) >> (i * kBitsInByte));
    }
}

void BitWriter::SetBit(bool bit)
{
    if (bit)
        *m_byte = *m_byte | (static_cast<int> (bit) << m_current_position++);
    else
        *m_byte = *m_byte & ~(1 << m_current_position++);
    
}