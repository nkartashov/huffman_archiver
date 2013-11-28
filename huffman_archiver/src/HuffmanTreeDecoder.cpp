//
//  HuffmanTreeDecoder.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 07/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "HuffmanTreeDecoder.h"


HuffmanTreeDecoder::HuffmanTreeDecoder(ifstream* input_stream, ofstream* output_stream):
HuffmanCoderDecoderBase(input_stream, output_stream)
{
}

void HuffmanTreeDecoder::Decompress()
{
    ReadHeader();
    m_tree->BuildHuffmanTree(m_symbol_frequencies);
    DecodeSymbols();
    
    //close();
}

void HuffmanTreeDecoder::ReadHeader()
{
    m_symbols_count = ReadLong();
    for (int i = 0; i < kMaxNumberDifferentSymbols; ++i)
    {
        m_symbol_frequencies[i] = ReadLong();
    }
}

long HuffmanTreeDecoder::ReadLong()
{
    uchar max_byte = 0xFF;
    long result = 0;
    char buf = 0;
    for (int i = 0; i < 4; ++i)
    {
        m_input_stream->get(buf);
        result += (static_cast<long> (buf) & max_byte)<< (i * kBitsInByte);
    }
    return result;
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
        uchar buffer = 0;
        ByteBuffer byte_buffer;
        byte_buffer.Fill(m_input_stream->get());
        long decoded_symbols = 1;
        HuffmanTreeNode* node = m_tree->root();
        while (decoded_symbols <= m_symbols_count)
        {
            if (byte_buffer.HasNext())
            {
                if (byte_buffer.GetBit())
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
            else
            {
                buffer = m_input_stream->get();
                byte_buffer.Fill(buffer);
            }
        }
    }

}