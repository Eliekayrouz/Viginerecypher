#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string ViginereEncrypt(string text, string key) {
	string result = "";
	int keyLength = key.length();
	int keyIndex = 0;

	for (int i = 0; i < text.length();i++) {

		char c = text[i];
		if (isalpha(c)) {
			char base = isupper(c) ? 'A' : 'a';
			char k = key[keyIndex % keyLength];
			int shift = (toupper(k) - 'A') % 26;
			char encrypted = (c - base + shift) % 26 + base;
			result += encrypted;
			keyIndex++;



		}
		else {
			result += c;
		}
		
	}
	return result;
}
string VigenereDecrypt(string text, string key) {
	string result = "";
	int keyLength = key.length();
	int keyIndex = 0;

	for (int i = 0;i < text.length();i++) {
		char c = text[i];
		if (isalpha(c)) {
			char base = isupper(c) ? 'A' : 'a';
			char k = key[keyIndex % keyLength];
			int shift = (toupper(k) - 'A');
			char decrypted = (c - base - shift + 26) % 26 + base;
			result += decrypted;
			keyIndex++;


		}
		else {
			result += c;
		}

	}
	return result;
}

string P_Encrypt(string text) {
	string row1 = "";
	string row2 = "";
	for (int i = 0;i < text.length();i++) {
		if (i % 2 == 0) {
			row1 += text[i];
		}
		else {
			row2 += text[i];
		}
	}
	return row1 + row2;
}
string P_Decrypt(string text) {
	int mid = (text.length() + 1) / 2;
	string row1 = text.substr(0, mid);
	string row2 = text.substr(mid);
	string result = "";

	for (int i = 0;i < row1.length();i++) {
		if(i<row1.length()) {
			result += row1[i];

		}
		if (i < row2.length()) {
			result += row2[i];
		}
	}
	return result;
}


int main() {

	int choice;
	cout << "Vigenere Cipher with permutation" << endl;
	cout << "1. Encrypt\n2.Decrypt\nSelect mode :" << endl;
	cin >> choice;
	cin.ignore();

	string inputString, key;
	cout << "Enter the string: ";
	getline(cin, inputString);
	cout << "Enter the Secret key: ";
	getline(cin, key);

	if (choice == 1) {
		string encrypted = ViginereEncrypt(inputString, key);
		string permuted = P_Encrypt(encrypted);
		cout << "Encrypted string: " << permuted << endl;



	}
	else if (choice == 2) {
		string permuted = P_Decrypt(inputString);
		string decrypted = VigenereDecrypt(permuted, key);
		cout << "Decrypted string: " << decrypted << endl;
	}
	else {
		cout << "Invalid choice" << endl;
	}
	return 0;
}





	





