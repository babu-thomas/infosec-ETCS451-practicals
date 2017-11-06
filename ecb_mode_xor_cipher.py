# Electronic codebook mode of XOR cipher. XORs the key with the plaintext block by block.

# Example usage-
# Encryption
# $ python3 ecb_mode_xor_cipher.py '10101010' '001'
# Output-
# 10001110
# Decryption
# $ python3 ecb_mode_xor_cipher.py '10001110' '001'
# Output-
# 10101010

# usage: python3 ecb_mode_xor_cipher.py [-h] text key
#
# positional arguments:
#   text           the text to be encrypted or decrypted. Pass encrypted message to decrypt.
#   key            key to be used for encryption and decryption
# optional arguments:
#   -h, --help     show this help message and exit


import itertools

def encrypt_decrypt(text, key):
    return ''.join([str(int(x, 2) ^ int(y, 2)) for x, y in zip(text, itertools.cycle(key))])


def main():
    import argparse


    parser = argparse.ArgumentParser()
    parser.add_argument('text',
        help='the text to be encrypted or decrypted. Pass encrypted message to decrypt.')
    parser.add_argument('key', help='key to be used for encryption and decryption')

    args = parser.parse_args()
    print(encrypt_decrypt(args.text, args.key))


if __name__ == '__main__':
    main()