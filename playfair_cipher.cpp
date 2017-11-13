#include <iostream>
#include <string>
#include <array>
#include <unordered_map>

std::array<char, 25> gen_key_table(const std::string& key);

int main()
{
	std::string key;
	std::cout << "Enter key: ";
	std::cin >> key;

	std::array<char, 25> key_table = gen_key_table(key);
	for(auto& i: key_table)
	{
		std::cout << i << " ";
	}

	return 0;
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