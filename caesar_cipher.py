# Caesar Cipher encryption and decryption

# usage: python3 caesar_cipher.py [-h] [-d] text shift
# 
# positional arguments:
#   text           the text to be encrypted or decrypted. Encrypts unless --decrypt is passed.
#   shift          shift value for cipher. Specifies how much to shift
#                  individual characters of message

# optional arguments:
#   -h, --help     show this help message and exit
#   -d, --decrypt  decrypt the given text instead of encrypting


def encrypt(text, shift):
    if shift == 0:
        return text

    def transform(char):
        first_letter = 'a' if char.islower() else 'A'
        return chr((ord(char) - ord(first_letter) + shift) % 26 + ord(first_letter))

    return ''.join([transform(char) if char.isalpha() else char for char in text])


def decrypt(text, shift):
    if shift == 0:
        return text

    def transform(char):
        first_letter = 'a' if char.islower() else 'A'
        return chr((ord(char) - ord(first_letter) - shift) % 26 + ord(first_letter))

    return ''.join([transform(char) if char.isalpha() else char for char in text])


def main():
    import argparse


    parser = argparse.ArgumentParser()
    parser.add_argument('text',
        help='the text to be encrypted or decrypted. Encrypts unless --decrypt is passed')
    parser.add_argument('shift',
        help='shift value for cipher. Specifies how much to shift individual characters of message',
        type = int)
    parser.add_argument('-d', '--decrypt', help='decrypt the given text instead of encrypting',
                        action='store_true')

    args = parser.parse_args()
    if(args.decrypt):
        print(decrypt(args.text, args.shift))
    else:
        print(encrypt(args.text, args.shift))


if __name__ == '__main__':
    main()