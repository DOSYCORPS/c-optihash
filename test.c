#include <stdio.h>
#include "optihash.h"

int main(int argumentsCount, char **arguments) {
        /*
                This example uses input data from a file, so a
                FILE object is required.
        */
        FILE *inputFile;

        /*
                This is the index of the current byte of input
                from inputFile. It's initialized as 0 and casted
                to a pointer.
        */
        unsigned long inputIndex = 0;
        unsigned long *inputIndexPointer = &inputIndex;

        /*
                This array stores entropy during hashing the
                input data. It should be the same byte size as
                digestCount and initialized with all values
                defined as 254 before hashing.
        */
        unsigned short entropy[32];

        /*
                This integer is the size in bytes of the
                input array.
        */
        unsigned short inputCount = 1024;

        /*
                These integer is the size in bytes of the
                digest. This example uses optihash256Bit with 32
                bytes.
        */
        unsigned short digestIndex = 32;

        /*
                This integer is a salt for additional
                randomization during hashing and finalization.

                It should be initialized as digestIndex and
                casted to a pointer.
        */
        unsigned short salt = digestIndex;
        unsigned short *saltPointer = &salt;

        /*
                This array stores bytes from the input file.
                The default block size is 1024 bytes and should
                be consistent with inputCount. It should be
                adjusted based on expected input sizes and
                performance revquirements.
        */
        unsigned char input[1024];

        /*
                This array stores hashed digest data in
                ascending sort order after finalization.
        */
        unsigned char digest[32];

        if (argumentsCount != 0) {
                inputFile = fopen(arguments[1], "rb");

                if (inputFile != (void *) 0) {
                        /*
                                This defines entropy with 254 before hashing.
                        */
                        while (digestIndex != 0) {
                                digestIndex--;
                                entropy[digestIndex] = 254;
                        }

                        /*
                                This defines the original digestIndex value as
                                salt to use as an index again during
                                finalization.
                        */
                        digestIndex = salt;

                        /*
                                This loop hashes the input in chunks the size of
                                inputCount.

                                The integral constant 1024 should be modified to
                                match the initialized value of inputCount.
                        */
                        while (inputCount == 1024) {
                                inputCount = fread(input, 1, 1024, inputFile);

                                /*
                                        This creates entropy using input until the end
                                        of inputFile is reached.
                                */
                                optiHash256Bit(inputIndexPointer, entropy, saltPointer, inputCount, input);
                        }

                        if (feof(inputFile) != 0) {
                                /*
                                        The file stream is closed after the end of
                                        inputFile is reached.
                                */
                                fclose(inputFile);

                                /*
                                        This creates additional entropy with a final
                                        pass through entropy.

                                        The finalized hash digest is stored in digest.
                                */
                                optiHashFinalize(entropy, digestIndex, salt, digest);

                                /*
                                        This outputs each byte from digest in
                                        hexadecimal format.
                                */
                                while (digestIndex != 0) {
                                        digestIndex--;
                                        printf("%02x", digest[digestIndex]);
                                }
                        } else {
                                printf("Error hashing file \"%s\".", arguments[1]);
                        }
                } else {
                        printf("Error reading file \"%s\".", arguments[1]);
                }
        } else {
                printf("Error hashing file without required file name argument.");
        }

        return 0;
}
