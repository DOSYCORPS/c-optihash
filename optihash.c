/*
	Each bit size variant is intentionally
	repetitive while only changing the entropy index
	mask integral constant for the
	benefit of memory efficiency and modularity.

	Bit size variants less than optiHash256
        shouldn't be used for security purposes.
*/

void optiHash8192Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[(*inputIndexPointer) & 1023] = (entropy[(*inputIndexPointer) & 1023] + (*salt)) & 2047;

                /*
                        This increments a input index to use as the
                        total size in bytes of all hashed input during
                        hashing and finalization.
                */
                (*inputIndexPointer)++;
        }

        return;
}

void optiHash4096Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[(*inputIndexPointer) & 511] = (entropy[(*inputIndexPointer) & 511] + (*salt)) & 2047;

                /*
                        This increments a input index to use as the
                        total size in bytes of all hashed input during
                        hashing and finalization.
                */
                (*inputIndexPointer)++;
        }

        return;
}

void optiHash2048Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[(*inputIndexPointer) & 255] = (entropy[(*inputIndexPointer) & 255] + (*salt)) & 2047;

                /*
                        This increments a input index to use as the
                        total size in bytes of all hashed input during
                        hashing and finalization.
                */
                (*inputIndexPointer)++;
        }

        return;
}

void optiHash1024Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[(*inputIndexPointer) & 127] = (entropy[(*inputIndexPointer) & 127] + (*salt)) & 2047;

                /*
                        This increments a input index to use as the
                        total size in bytes of all hashed input during
                        hashing and finalization.
                */
                (*inputIndexPointer)++;
        }

        return;
}

void optiHash512Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[(*inputIndexPointer) & 63] = (entropy[(*inputIndexPointer) & 63] + (*salt)) & 2047;

                /*
                        This increments a input index to use as the
                        total size in bytes of all hashed input during
                        hashing and finalization.
                */
                (*inputIndexPointer)++;
        }

        return;
}

void optiHash256Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[(*inputIndexPointer) & 31] = (entropy[(*inputIndexPointer) & 31] + (*salt)) & 2047;

                /*
                        This increments a input index to use as the
                        total size in bytes of all hashed input during
                        hashing and finalization.
                */
                (*inputIndexPointer)++;
        }

        return;
}

void optiHash128Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[(*inputIndexPointer) & 15] = (entropy[(*inputIndexPointer) & 15] + (*salt)) & 2047;

                /*
                        This increments a input index to use as the
                        total size in bytes of all hashed input during
                        hashing and finalization.
                */
                (*inputIndexPointer)++;
        }

        return;
}

void optiHash64Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[(*inputIndexPointer) & 7] = (entropy[(*inputIndexPointer) & 7] + (*salt)) & 2047;

                /*
                        This increments a input index to use as the
                        total size in bytes of all hashed input during
                        hashing and finalization.
                */
                (*inputIndexPointer)++;
        }

        return;
}

void optiHash32Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[(*inputIndexPointer) & 3] = (entropy[(*inputIndexPointer) & 3] + (*salt)) & 2047;

                /*
                        This increments a input index to use as the
                        total size in bytes of all hashed input during
                        hashing and finalization.
                */
                (*inputIndexPointer)++;
        }

        return;
}

void optiHash16Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[(*inputIndexPointer) & 1] = (entropy[(*inputIndexPointer) & 1] + (*salt)) & 2047;

                /*
                        This increments a input index to use as the
                        total size in bytes of all hashed input during
                        hashing and finalization.
                */
                (*inputIndexPointer)++;
        }

        return;
}

void optiHash8Bit(unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input) {
        /*
                This loop hashes input data with a decrementing
                high index.
        */
        while (inputIndex != 0) {
                inputIndex--;

                /*
                        This recalculates salt with a fast hashing
                        formula that sums input at the curent index and
                        bit variants of the current salt. It never
                        exceeds USHRT_MAX before masking with 16383 to
                        avoid integral promotions and remainder
                        calculations.

                        101 is added to the masked result to add entropy
                        and escape zeroland.
                */
                (*salt) = ((input[inputIndex] + ((*salt) >> 1) + (*salt)) & 16383) + 101;

                /*
                        Entropy is calculated at the current input index
                        by adding salt to previous entropy and masking
                        with 2047.
                */
                entropy[0] = (entropy[0] + (*salt)) & 2047;
        }

        return;
}

void optiHashFinalize(unsigned short *entropy, unsigned short entropyHighIndex, unsigned short salt, unsigned char *digest) {
	unsigned short entropyLowIndex = 0;

	/*
		This loop finalizes the hash digest by iterating
		through entropy with both decrementing high and
		incrementing low indices.
	*/
	while (entropyHighIndex != 0) {
		entropyHighIndex--;

		/*
			This defines the current high index of entropy
			as salt.
		*/
		entropy[entropyHighIndex] = salt;

		/*
			This redefines salt with a fast hashing formula
			that sums entropy at both indices and salt. It
                        never exceeds USHRT_MAX before masking with
                        8191.

			1001 is added to the masked result to add
			entropy and escape zeroland.
		*/
		salt = ((entropy[entropyHighIndex] + entropy[entropyLowIndex] + ((entropyHighIndex + salt) >> 1) + entropyHighIndex) & 8191) + 1001;

		/*
			This defines a finalized byte from salt masked
			between 0x0 and 0xFF. This can be overwritten
			multiple times during finalization.
		*/
		digest[entropyHighIndex] = salt & 255;

		/*
			This defines the current low index of entropy
			as salt.
		*/
		entropy[entropyLowIndex] = salt;
		entropyLowIndex++;
	}

	return;
}
