//
//  HuffmanTreeDecoder.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "HuffmanTreeDecoder.h"

#include <iostream>

using namespace std;

HuffmanTreeDecoder::HuffmanTreeDecoder(istream* input_stream, ostream* output_stream):
HuffmanCoderDecoderBase(input_stream, output_stream)
{
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
        HuffmanTreeNode* node = m_tree->root();
        while (decoded_symbols <= m_symbols_count)
        {
            if (reader.GetBit())
                node = node->rightChild();
            else
                node = node->leftChild();
            if (node->isInner())
            {
                m_output_stream->put(node->symbol());
                node = m_tree->root();
                ++decoded_symbols;
            }
        }
    }

}