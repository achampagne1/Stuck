#include "encryption.h"

using namespace EncryptionNamespace;

Encryption::Encryption() {

}

void Encryption::run() {
	std::string data = loadFile.load("test.txt").str();
	std::string dataSum = "";
	int p = 53, q = 59;
	int n = p * q;
	int phi = (p - 1) * (q - 1);
	srand(time(0));
	int e = 2 + (rand() % (phi-1)); //later check if e is not a factor of n
	int privateKey = (2* phi + 1) / e;
	for (int i = 0; i < data.length(); i++)
		dataSum.append(std::to_string(int(data[i])));

	std::vector<std::string> brokenDataSum = breakUpString(dataSum);  
	int encrypted = encryptOrDecrypt(89, 3, 3127);
	int decrypted = encryptOrDecrypt(encrypted, 2011, 3127);
	std::cout <<encrypted<<" "<<decrypted << std::endl;
}

std::vector<std::string> Encryption::breakUpString(std::string input) {
	std::vector<std::string> output;
	int loopLength = floor(input.length()/ 8.0);
	for (int i = 0; i < loopLength; i++)
		output.push_back(input.substr(i * 8, 8));
	int lastLetters = input.length() - loopLength * 8;
	output.push_back(input.substr(loopLength*8, lastLetters));
	return output;
}

int Encryption::encryptOrDecrypt(int input, int e, int n) {
	return recursiveSquaringWithModding(input,e,n);
}

int Encryption::recursiveSquaringWithModding(int input, int e, int n) {
	int output = 1;
	if (e > 1) {
		//recursive stuff;
		if (e % 2 == 0)
			output = (int)pow(recursiveSquaringWithModding(input, e/2, n),2)%n;
		else {
			e--;
			output = (int)pow(recursiveSquaringWithModding(input, e / 2, n), 2)%n * input%n;
		}
		return output%n;
	}
	else {
		return input;
	}
}