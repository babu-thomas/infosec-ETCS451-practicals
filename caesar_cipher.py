# Caesar Cipher encryption and decryption

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
    text = 'So Secret. Much Fun. WOW'
    shift = 2
    ciphertext = encrypt(text, shift)
    print(ciphertext)
    print(decrypt(ciphertext, shift))


if __name__ == '__main__':
    main()