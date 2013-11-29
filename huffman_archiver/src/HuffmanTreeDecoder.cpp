//
//  HuffmanTreeDecoder.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "HuffmanTreeDecoder.h"


HuffmanTreeDecoder::HuffmanTreeDecoder(istream* input_stream, ostream* output_stream):
m_input_stream(input_stream),
m_output_stream(output_stream),
m_tree(new HuffmanTree()),
m_symbol_frequencies(vector<long>(kMaxNumberDifferentSymbols)),
m_symbols_count(0)
{
}

HuffmanTreeDecoder::~HuffmanTreeDecoder()
{
    if (m_tree)
        delete m_tree;
}

void HuffmanTreeDecoder::setReaderToBeginning()
{
    m_input_stream->clear();
    m_input_stream->seekg(0, istream::beg);
}

void HuffmanTreeDecoder::Decompress()
{
    ReadHeader();
    m_tree->BuildHuffmanTree(m_symbol_frequencies);
    DecodeSymbols();
}

void HuffmanTreeDecoder::ReadHeader()
{
    BitReader reader(m_input_stream);
    m_symbols_count = reader.ReadLong();
    for (int i = 0; i < kMaxNumberDifferentSymbols; ++i)
    {
        m_symbol_frequencies[i] = reader.ReadLong();
    }
}

void HuffmanTreeDecoder::DecodeSymbols()
{
    if (m_tree->isTrivial())
    {
        for (int i = 0; i < m_symbols_count; ++i)
            m_output_stream->put(m_tree->root()->symbol());
    }
    else
    {
        BitReader reader(m_input_stream);
        reader.Fill();
        long decoded_symbols = 1;
        int buffer = 0;
        TreeWalker walker(m_tree->root());
        while (decoded_symbols <= m_symbols_count)
        {
            buffer = walker.NextBit(reader.GetBit());
            if (buffer != -1)
            {
                m_output_stream->put((uchar) buffer);
                ++decoded_symbols;
            }
        }
    }

}