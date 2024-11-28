#include<iostream>
#include<cstring>
#include<string>
using namespace std;

//Function to sort names alphabetically
void AlphaNames(string names[], int size) {
	//lowestND keeps track of the earliest name alphabetically with each pass
	int lowestND;
	//The outer loop should execute once for each element in the array
	for (int index = 0; index < size; index++) {
		lowestND = index;
		for (int j = index; j < size; j++) {
			//if the element we are checking comes earlier, the address of that element becomes lowestND
			if (names[lowestND] > names[j]) {
				lowestND = j;
			}
		}
		//swap the earliest alphabetical name with the first element we have not sorted yet
		swap(names[index], names[lowestND]);
	}
	//output the new sorted array
	cout << "\nSorted list of names: \n";
	for (int k = 0; k < size; k++) {
		cout << names[k] << endl;
	}
}
//function for searching for a specific name
bool nameSearch(string names[], int size, const string target) {
	for (int i = 0; i < size; i++) {
		if (names[i] == target) {
			return true;
		}
	}

	return false;
}
//fuction for searching for the longest name
void longestName(string names[], int size) {
	int longestND = 0;
	//loop through each element in the array, if the element we are checking is longer than the longest we have found so far, copy its address
	for (int i = 0; i < size; i++) {
		if (names[longestND].length() < names[i].length()) {
			longestND = i;
		}
	}
	cout << "\nThe longest name in the list is " << names[longestND] << endl;
}
//function for counting the vowels
int Vowelnum(string names[], int size) {
	int vowels = 0;
	for (int i = 0; i < size; i++) {
		//loops through each letter in the current name counting both upper and lowercase
		for (int j = 0; j < names[i].length(); j++) {
			switch (names[i][j]) {
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				vowels++;
			}
		}
	}
	return vowels;
}
//Function to shorten all the names in the list to a certain length
//Demonstrates use of the copy string manipulator
void Shorter (string names[], int size, int nameLength) {
	char Shorter[30];
	cout << "\nThe list of shortened names is:\n";
	//for each name in the array, copy the first nth letters to the c-string and output the c-string
	for (int i = 0; i < size; i++) {
		names[i].copy(Shorter, nameLength);
		Shorter[nameLength] = '\0';
		cout << Shorter << endl;
	}

}

int main() {
	int n, ShorterLength;
	string searchWord;
	//recieve number of names
	cout << "Please enter the number of names you would like to input: ";
	cin >> n;
	//create an array with the proper length
	string* names = new string[n];
	//get the correct amount of names and copy each one to the array
	for (int i = 0; i < n; i++) {
		cout << "Enter name " << i + 1 << ": ";
		cin >> names[i];
	}
	//sort the names
	AlphaNames(names, n);
	//search for a name
	cout << "\nPlease enter a name to search: ";
	cin >> searchWord;
	if (nameSearch(names, n, searchWord) == true) {
		cout << searchWord << " is in the list\n";
	}
	else {
		cout << searchWord << " is not in the list\n";
	}
	//search for the longest name
	longestName(names, n);
	//count the vowels
	cout << "\nThere are " << Vowelnum(names, n) << " vowels in the list\n";
	//shorten the names
	cout << "\nPlease enter the number of characters you would like to shorten the names to: ";
	cin >> ShorterLength;
	Shorter(names, n, ShorterLength);
	return 0;
}
