//
//  HuffmanCoderDecoderBase.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 08/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "HuffmanCoderDecoderBase.h"

HuffmanCoderDecoderBase::HuffmanCoderDecoderBase(ifstream* input_stream,
                                                 ofstream* output_stream):
m_input_stream(input_stream),
m_output_stream(output_stream),
m_tree(new HuffmanTree()),
m_symbol_frequencies(vector<long>(kMaxNumberDifferentSymbols)),
m_symbols_count(0)
{
}

HuffmanCoderDecoderBase::~HuffmanCoderDecoderBase()
{
    if (m_tree)
        delete m_tree;
}

void HuffmanCoderDecoderBase::setReaderToBeginning()
{
    m_input_stream->clear();
    m_input_stream->seekg(0, ifstream::beg);
}