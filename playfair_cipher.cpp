#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

std::string encrypt(const std::string& message, const std::string& key);
std::array<char, 25> gen_key_table(const std::string& key);
void print_key_table(const std::array<char, 25>& key_table);
std::pair<int, int> find_pos(char letter, const std::array<char, 25>& key_table);
int idx(int row, int col);
std::pair<int, int> idx(int i);
bool in_same_column(const std::pair<int, int> pos1, const std::pair<int, int> pos2);
bool in_same_row(const std::pair<int, int> pos1, const std::pair<int, int> pos2);

int main()
{
	std::string message, key;
	std::cout << "Enter message: ";
	std::cin >> message;
	std::cout << "Enter key: ";
	std::cin >> key;

	std::string ciphertext = encrypt(message, key);
	std::cout << "Ciphertext: " << ciphertext << "\n";

	return 0;
}

std::string encrypt(const std::string& message, const std::string& key)
{
	std::array<char, 25> key_table = gen_key_table(key);
	std::cout << "\nKey table: " << "\n";
	print_key_table(key_table);

	std::string plaintext = message.size() % 2 == 0 ? message : message + 'Z';
	std::cout << "\nPlaintext: " << plaintext << "\n";

	std::string ciphertext = plaintext;
	for(auto i = 0u; i <= plaintext.size() - 2; i += 2)
	{
		char letter1 = plaintext[i];
		char letter2 = plaintext[i + 1];
		std::pair<int, int> letter1_pos = find_pos(letter1, key_table);
		std::pair<int, int> letter2_pos = find_pos(letter2, key_table);
		std::cout << letter1 << " pos: " << letter1_pos.first << ", " << letter1_pos.second << "\n";
		std::cout << letter2 << " pos: " << letter2_pos.first << ", " << letter2_pos.second << "\n";
		if(in_same_column(letter1_pos, letter2_pos))
		{
			ciphertext[i] = key_table[idx(letter1_pos.first + 1, letter1_pos.second)];
			ciphertext[i+1] = key_table[idx(letter2_pos.first + 1, letter2_pos.second)];
		}
		else if(in_same_row(letter1_pos, letter2_pos))
		{
			ciphertext[i] = key_table[idx(letter1_pos.first, letter1_pos.second + 1)];
			ciphertext[i+1] = key_table[idx(letter2_pos.first, letter2_pos.second + 1)];
		}
		else
		{
			ciphertext[i] = 'Q';
			ciphertext[i+1] = 'Q';
		}
	}
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

void print_key_table(const std::array<char, 25>& key_table)
{
	for(int i = 0; i < 5; i++)
	{
		std::cout << key_table[idx(i, 0)];
		for(int j = 1; j < 5; j++)
		{
			std::cout << " " << key_table[idx(i, j)];
		}
		std::cout << "\n";
	}
}

std::pair<int, int> find_pos(char letter, const std::array<char, 25>& key_table)
{
	int i = std::find(key_table.begin(), key_table.end(), letter) - key_table.begin();
	return idx(i);
}

int idx(int row, int col)
{
	if(row == 5) row = 0;
	if(col == 5) col = 0;
	return row * 5 + col;
}

std::pair<int, int> idx(int i)
{
	return std::make_pair(i / 5, i % 5);
}

bool in_same_column(const std::pair<int, int> pos1, const std::pair<int, int> pos2)
{
	return pos1.second == pos2.second;
}
bool in_same_row(const std::pair<int, int> pos1, const std::pair<int, int> pos2)
{
	return pos1.first == pos2.first;
}
