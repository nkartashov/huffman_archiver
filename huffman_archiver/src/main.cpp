#include <iostream>
#include <fstream>

#include "HuffmanTreeCoder.h"
#include "HuffmanTreeDecoder.h"


using std::string;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;



const string kCompressKey = "-c";
const string kDecompressKey = "-d";
const string kInputKey = "-i";
const string kOutputKey = "-o";



enum Modes
{
    kCompressionMode = 0,
    kDecompressionMode,
    kInputFileEmpty
};



int main(int argc, char** argv)
{
    Modes work_mode;
    
    if(argc != 6)
    {
        cout << "Error: Incorrect number of arguments" << endl;
        return 0;
    }

    string input_file_path;
    string output_file_path;

    int i = 1;
    while (i < 6)
    {
        if(string(argv[i]) == kCompressKey)
            work_mode = kCompressionMode;
        
        if(string(argv[i]) == kDecompressKey)
            work_mode = kDecompressionMode;
        
        if(string(argv[i]) == kInputKey)
        {
            input_file_path = argv[++i];
        }
        
        if(string(argv[i]) == kOutputKey)
        {
            output_file_path = argv[++i];
        }
        ++i;
    }
    
    ifstream* input_stream = new ifstream(input_file_path.c_str(), ios::in | ios::binary);
    ofstream* output_stream = new ofstream(output_file_path.c_str(), ios::out | ios::binary);
    
    if (!input_stream->is_open())
    {
        cout << "Unable to open input file " << input_file_path << endl;
        return 1;
    }
    
    if (!output_stream->is_open())
    {
        cout << "Unable to open output file " << output_file_path << endl;
        return 1;
    }

    input_stream->seekg(0, istream::end);
    if (input_stream->tellg() == 0)
    {
        work_mode = kInputFileEmpty;
    }
    input_stream->seekg(0, istream::beg);
    
    switch (work_mode)
    {
        case kCompressionMode:
        {
            HuffmanTreeCoder coder(input_stream, output_stream);
            coder.Compress();
            break;
        }
        case kDecompressionMode:
        {
            HuffmanTreeDecoder decoder(input_stream, output_stream);
            decoder.Decompress();
            break;
        }
        case kInputFileEmpty:
        {
            break;
        }
        default:
            cout << "Something somewhere has gone horribly wrong" << endl;
            break;
    }

    input_stream->close();
    output_stream->close();
    
    return 0;
}
