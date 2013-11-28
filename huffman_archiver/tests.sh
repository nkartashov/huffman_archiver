#!/bin/bash
make
bin/arj -i test.bin -o encodedtest.bin -c
bin/arj -i encodedtest.bin -o result.bin -d
diff result.bin test.bin
rm result.bin
#bin/arj -i emptyFile.txt -o result.txt -c
#bin/arj -i result.txt -o newEmptyFile.txt -d