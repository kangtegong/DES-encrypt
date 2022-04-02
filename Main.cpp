#include <iostream>
#include "DES.h"
#include "Colors.h"
#include <bitset>
#include <algorithm>
#include <array>
#include <iomanip>

using namespace std;

int main() {
    //TODO: 1- getopt to parse arguments 
    //      2- write usage 
    //      3- build ECG, CGC,..., etc to support long documents 
    //      4- the code currently support 64 bit long as input
	cout << "컴퓨터보안 DES encryption 과제" <<endl; 
	cout << "enter your plaintext : ";
	
	string plainText;
	cin >> plainText;

	cout << "enter your key : ";
	string key;
	cin >> key;

	//string plainText = "0123456789ABCDEF";
	//string key = "133457799BBCDFF1";
	DES des (plainText, key);
	std::cout << BOLDBLUE << setw(6) << "round" <<
					setw(8) << "left" <<
					setw(12) << "right" <<
					setw(14) << "Round Key" << RESET << endl;
	des.cipher(des.getPlainText(), des.getKey64());

	/* DISPLAY THE CIPHER PROCESS */
	cout << "Plain  Text: " << WHITE << des.bin2hex(des.getPlainText()) << RESET << endl;
	cout << "Key        : " << WHITE << des.bin2hex(des.getKey64()) << RESET << endl;
	cout << "Cipher Text: " << BOLDRED << des.bin2hex(des.getCipherText()) << RESET << endl;
	cout << "Plain  Text: " << WHITE << des.getPlainText() << RESET << endl;
	cout << "Key        : " << WHITE << des.getKey64() << RESET << endl;
	cout << "Cipher Text: " << BOLDRED << des.getCipherText() << RESET << endl;


	// in order to apply des on a long message longer thatn 64 bit
	// we need to use one of the five mode of operation for block cipher (DES< AES, ..)
	// (ECB, CBC, CFB, OFB. ..).
}
