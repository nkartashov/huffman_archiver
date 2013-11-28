//
//  HuffmanCoderDecoderBase.cpp
//  huffman_archiver
//
//  Created by Nikita Kartashov on 08/11/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "HuffmanCoderDecoderBase.h"

HuffmanCoderDecoderBase::HuffmanCoderDecoderBase(string const& input_path,
                                                 string const& output_path):
m_input_stream(new ifstream(input_path.c_str(), ios::in | ios::binary)),
m_output_stream(new ofstream(output_path.c_str(), ios::out | ios::binary)),
m_tree(new HuffmanTree()),
m_symbol_frequencies(vector<long>(kMaxNumberDifferentSymbols)),
m_symbols_count(0)
{
}

HuffmanCoderDecoderBase::~HuffmanCoderDecoderBase()
{
    delete m_tree;
}

void HuffmanCoderDecoderBase::setReaderToBeginning()
{
    m_input_stream->clear();
    m_input_stream->seekg(0, ifstream::beg);
}

void HuffmanCoderDecoderBase::close()
{
    m_input_stream->close();
    m_output_stream->close();
}