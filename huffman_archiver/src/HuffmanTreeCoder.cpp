//
//  HuffmanTreeCoder.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "HuffmanTreeCoder.h"


HuffmanTreeCoder::HuffmanTreeCoder(istream* input_stream, ostream* output_stream):
m_input_stream(input_stream),
m_output_stream(output_stream),
m_tree(new HuffmanTree()),
m_symbol_frequencies(vector<long>(kMaxNumberDifferentSymbols)),
m_symbols_count(0),
m_symbol_codes(vector<BitCode>())
{
    m_symbols_count = CalculateNumberOfSymbols();
    setReaderToBeginning();
}

HuffmanTreeCoder::~HuffmanTreeCoder()
{
    if (m_tree)
        delete m_tree;
}

void HuffmanTreeCoder::setReaderToBeginning()
{
    m_input_stream->clear();
    m_input_stream->seekg(0, istream::beg);
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
    BitWriter writer(m_output_stream);
    writer.WriteLong(m_symbols_count);
    for (int i = 0; i < kMaxNumberDifferentSymbols; ++i)
    {
        writer.WriteLong(m_symbol_frequencies[i]);
    }
}

void HuffmanTreeCoder::EncodeSymbols()
{
    uchar buffer = 0;
    BitCode symbol_code;
    BitWriter writer(m_output_stream);
    for (long i = 0; i < m_symbols_count; i++)
    {
        buffer = m_input_stream->get();
        symbol_code = m_symbol_codes[buffer];
        writer.WriteBitCode(symbol_code);
    }
    //To output the last byte
    writer.Flush();
}
