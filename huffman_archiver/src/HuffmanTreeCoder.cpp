//
//  HuffmanTreeCoder.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "HuffmanTreeCoder.h"


HuffmanTreeCoder::HuffmanTreeCoder(istream* input_stream, ostream* output_stream):
HuffmanCoderDecoderBase(input_stream, output_stream),
m_symbol_codes(vector<BitCode>())
{
    m_symbols_count = CalculateNumberOfSymbols();
    setReaderToBeginning();
}

long HuffmanTreeCoder::CalculateNumberOfSymbols()
{
    m_input_stream->seekg(0, istream::end);
    return m_input_stream->tellg();
}


void HuffmanTreeCoder::Compress()
{
    SetSymbolCodes();
    setReaderToBeginning();
    WriteHeader();
    EncodeSymbols();
}

void HuffmanTreeCoder::CalculateSymbolFrequencies()
{
    uchar buffer = 0;
    for (long i = 0; i < m_symbols_count; i++)
    {
        buffer = m_input_stream->get();
        ++m_symbol_frequencies[buffer];
    }
}

void HuffmanTreeCoder::SetSymbolCodes()
{
    CalculateSymbolFrequencies();
    m_tree->BuildHuffmanTree(m_symbol_frequencies);
    m_symbol_codes = m_tree->GetSymbolCodes();
}

void HuffmanTreeCoder::WriteHeader()
{
    WriteLong(m_symbols_count);
    for (int i = 0; i < kMaxNumberDifferentSymbols; ++i)
    {
        WriteLong(m_symbol_frequencies[i]);
    }
}

void HuffmanTreeCoder::WriteLong(long value)
{
    long max_char = 0xFF;
    for (int i = 0; i < 4; ++i)
    {
        m_output_stream->put((max_char << (i * kBitsInByte) & value) >> (i * kBitsInByte));
    }
}

void HuffmanTreeCoder::EncodeSymbols()
{
    ByteBuffer byte_buffer;
    uchar buffer = 0;
    BitCode symbol_code;
    int test = 0;
    for (long i = 0; i < m_symbols_count; i++)
    {
        buffer = m_input_stream->get();
        symbol_code = m_symbol_codes[buffer];
        for (size_t j = 0; j < symbol_code.size(); ++j)
        {
            if (!byte_buffer.HasNext())
            {
                test = (int) byte_buffer.Flush();
                m_output_stream->put((char) test);
            }
            byte_buffer.SetBit(symbol_code[j]);
        }
    }
    m_output_stream->put(byte_buffer.Flush());
}
