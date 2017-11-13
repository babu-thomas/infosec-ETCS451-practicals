#include <iostream>
#include <string>
#include <array>
#include <unordered_map>

std::string encrypt(const std::string& message, const std::string& key);
std::array<char, 25> gen_key_table(const std::string& key);

int main()
{
	std::string message, key;
	std::cout << "Enter message: ";
	std::cin >> message;
	std::cout << "Enter key: ";
	std::cin >> key;
	
	std::string ciphertext = encrypt(message, key);

	return 0;
}

std::string encrypt(const std::string& message, const std::string& key)
{
	std::array<char, 25> key_table = gen_key_table(key);

	std::string plaintext = message.size() % 2 == 0 ? message : message + 'Z';
	std::cout << plaintext;

	std::string ciphertext;
	return ciphertext;
}

std::array<char, 25> gen_key_table(const std::string& key)
{
	std::array<char, 25> key_table;
	std::string alphabet = "ABCDEFGHIJKLMNOPRSTUVWXYZ";
	std::unordered_map<char, bool> included_alphabets;
	for(auto& i: alphabet)
	{
		included_alphabets[i] = false;
	}
	int k_idx = 0;
	for(auto i = 0u; i < key.size(); i++)
	{
		char letter = key[i];
		if(!included_alphabets[letter])
		{
			key_table[k_idx++] = letter;
			included_alphabets[letter] = true;
		}
	}
	for(auto& letter: alphabet)
	{
		if(!included_alphabets[letter])
		{
			key_table[k_idx++] = letter;
			included_alphabets[letter] = true;
		}
	}
	return key_table;
}