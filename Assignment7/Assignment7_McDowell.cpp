#include<iostream>
#include<cstring>
#include<string>
using namespace std;

//Function to sort the names alphabetically
void namesSort(string names[], int size) {
	//lowestNameAddress keeps tracks of the index of the earliest name alphabetically with each pass
	int lowestNameAddress;
	//The outer loop will loop once for each element in the array
	for (int index = 0; index < size; index++) {
		lowestNameAddress = index;
		//The inner function will loop through one less element in the array for each outer loop
		//e.g. It will go through all elemenets on the first pass, all but the first on the second, all but the first two elements on the third, etc.
		for (int j = index; j < size; j++) {
			//lowestNameAddress is the address of the earliest string int the alphabet we have found on this loop
			//if the element we are checking comes earlier, the address of that element becomes lowestNameAddress
			if (names[lowestNameAddress] > names[j]) {
				lowestNameAddress = j;
			}
		}
		//swap the earliest alphabetical name with the first element we have not sorted yet
		swap(names[index], names[lowestNameAddress]);
	}
	//output the new sorted array
	cout << "\nSorted list of names: \n";
	for (int k = 0; k < size; k++) {
		cout << names[k] << endl;
	}
}
//function for searching for a specific name
bool namesSearch(string names[], int size, const string target) {
	//loop through each element, if an element matches, return true, otherwise return false
	for (int i = 0; i < size; i++) {
		if (names[i] == target) {
			return true;
		}
	}

	return false;
}
//fuction for searching for the longest name
void longestName(string names[], int size) {
	int longestNameAddress = 0;
	//loop through each element in the array, if the element we are checking is longer than the longest we have found so far, copy its address
	for (int i = 0; i < size; i++) {
		if (names[longestNameAddress].length() < names[i].length()) {
			longestNameAddress = i;
		}
	}
	cout << "\nThe longest name in the list is " << names[longestNameAddress] << endl;
}
//function for counting the vowels in the list of names
int vowelCount(string names[], int size) {
	int vowels = 0;
	//loops through each name in the list
	for (int i = 0; i < size; i++) {
		//loops through each letter in the current name and adds one to the counter if it is a vowel
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
void nameShorten(string names[], int size, int nameLength) {
	char nameShort[30];
	cout << "\nThe list of shortened names is:\n";
	//for each name in the array, copy the first nth letters to the c-string and output the c-string
	for (int i = 0; i < size; i++) {
		names[i].copy(nameShort, nameLength);
		nameShort[nameLength] = '\0';
		cout << nameShort << endl;
	}

}

int main() {
	int n, nameShortenLength;
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
	namesSort(names, n);
	//search for a name
	cout << "\nPlease enter a name to search: ";
	cin >> searchWord;
	if (namesSearch(names, n, searchWord) == true) {
		cout << searchWord << " is in the list\n";
	}
	else {
		cout << searchWord << " is not in the list\n";
	}
	//search for the longest name
	longestName(names, n);
	//count the vowels
	cout << "\nThere are " << vowelCount(names, n) << " vowels in the list\n";
	//shorten the names
	cout << "\nPlease enter the number of characters you would like to shorten the names to: ";
	cin >> nameShortenLength;
	nameShorten(names, n, nameShortenLength);
	return 0;
}