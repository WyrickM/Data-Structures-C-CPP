/*
Programmer: Mantz Wyrick
Class: CptS 122 Lab Section 5
Programming Assignment: Programming Assignment #6
Date: 10/22/18
Description:
	In this assignment you will be using a BST to convert English characters
	to Morse code strings. Morse code is a famous coding scheme that assigns
	a series of dots and dashes to each letter of the alphabet, each digit,
	and a few special characters. In sound-oriented systems, the dot represents
	a short sound and the dash represents a long sound. Other representations of
	dots and dashes are used with light-oriented systems and signal-flag systems
	(from Deitel and Deitel C How to Program).

Collaborators: Class, Lab 5, and Deitel & Deitel, Camden Lambe
*/

/*
testing to see if this works with Visual Studio 2019 ---> It works. 
If i open old Visual studio 2015 files here they do not work in 
Visual Studio 2015 because the Visual Studio 2019 upadtes the code
and changes it a little.
*/

//I have to change the Convert.txt file to english script for the program to work.

#include "BST.h"
#include "BSTNode.h"


//used templates
int main(void)
{
	BST<char, string> tree;

	string morseCode = "";
	char newChar = '\0', lineArr[100] = "";
	string strArr[100];
	int index = 0, index2 = 0;
	fstream convert;
	
	convert.open("Convert.txt");						//opens convert file
	tree.inOrderPrint();								//prints the morse code look up tree to the screen
	cout << endl <<endl;
	while (!convert.eof())								//loop to get the letter character
	{
		convert.get(newChar);
		newChar = toupper(newChar);
		if (newChar != ' ')
		{
			morseCode = tree.searchTree(newChar);
		}
		strArr[index] = morseCode;
		index++;
	}
	convert.close();									//closing the stream because it is a ifstream right now and need to change it to ofstream
	cout << endl;
	convert.open("Convert.txt");						//opening the file to to convert the file to morse code
	while(index2 != (index+1))							//loop that goes through the array to get the morse code strings to be able to convert the file
	{
		if (strArr[index2] == "\n")
		{
			convert << endl;							//changes file by putting a new line
			cout << endl;								//prints a newline to the screen
		}
		else
		{
			convert << strArr[index2] << "  ";			//changes the file
			cout << strArr[index2] << "  ";				//prints the morese code to the screen of the specific character
		}
		index2++;
	}
	convert.close();									//closing the convert file finally

	return 0;
}