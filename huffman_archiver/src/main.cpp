#include <iostream>
#include <fstream>

#include "HuffmanTreeCoder.h"
#include "HuffmanTreeDecoder.h"


using std::string;
using std::cout;
using std::endl;\

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



int main(int argc, char** argv) {    
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
    
    ifstream* in = new ifstream(input_file_path.c_str(), ios::in | ios::binary);
    ofstream* out = new ofstream(output_file_path.c_str(), ios::out | ios::binary);
    
    if (!in->is_open())
    {
        cout << "Unable to open input file " << input_file_path << endl;
        return 1;
    }
    
    if (!out->is_open())
    {
        cout << "Unable to open output file " << output_file_path << endl;
        return 1;
    }

    in->seekg(0, istream::end);
    if (in->tellg() == 0)
    {
        work_mode = kInputFileEmpty;
    }
    in->seekg(0, istream::beg);
    
    switch (work_mode)
    {
        case kCompressionMode:
        {
            HuffmanTreeCoder coder(in, out);
            coder.Compress();
            break;
        }
        case kDecompressionMode:
        {
            HuffmanTreeDecoder decoder(in, out);
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

    in->close();
    out->close();
    
    return 0;
}
