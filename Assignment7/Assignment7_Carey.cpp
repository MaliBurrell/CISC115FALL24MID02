#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Void function to sort names in alphabetical order
void namesSort(string names[], int size) {
    int earliestName; // keeps track of earliest name in loop using alphabetical order
    // loop cycles one time for each element that is in this array
    for (int index = 0; index < size; index++) {
        earliestName = index;

        for (int i = index; i < size; i++) {

            if (names[earliestName] > names[i]) {
                earliestName = i; // earliestName becomes the new address if the element we are checking comes earlier than expected
            }
        }
        swap(names[index], names[earliestName]); // first name in alphabetical order gets swapped with first name in index that isn't sorted
    }
    // output for the array we just sorted
    cout << "\nList of named sorted: \n";
    for (int j = 0; j < size; j++) {
            cout << names[j] << endl;
    }
}
// Bool function for finding specific names
bool searchName(string names[], int size, const string& target){
    // loop cycles through each element until one returns true; false if otherwise
    for (int k = 0; k < size; k++) {
        if (names[k] == target){
            return true;
        }
    }
    return false;
}
// Void function to find the longest name in the array
void nameLong(string names[], int size){
    int addressOfLongName = 0;
    // loop cycles until a name longer than the longest name in array is found, then copies its address
    for (int k = 0; k < size; k++){
        if (names[k].length() > names[addressOfLongName].length()) {
            addressOfLongName = k;
        }
    }
    cout << "\nThe longest name in this list is: \n" << names[addressOfLongName] << endl;
}
// function to count # of vowels in the list
int countingVowels(string names[], int size){
    int vowels = 0;
    // loop cycles through every name featured in the list
    for (int k = 0; k < size; k++){
        // loop cycles through every name and counts vowels
        for (int i = 0; i < names[k].length(); i++){
            switch (names[k][i]) {
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
// Void to function to shorten names in list to a certain length
void shortenName(string names[], int size, int lengthOfName) {
    char shortName[20];
    cout << "\nThe list of names that have been shortened is: \n";
    // copy nth letters to and output c-string for each name in array
    for (int k = 0; k < size; k++){
        names[k].copy(shortName, lengthOfName);
        shortName[lengthOfName] = '\0';
        cout << shortName << endl;
    }
}

int main() {
    int n, nameLengthShort;
    string wordSearch;
    // program recieves # of names
    cout << "Enter how many names you want to input: ";
    cin >> n;
    // create array with proper word length
    string* names = new string[n];
    // program recieves # of names and copies each one to the array
    for (int k = 0; k < n; k++){
        cout << "Enter a name " << k + 1 << ": ";
        cin >> names[k];
    }
    // name sorting
    namesSort(names, n);
    // name search
    cout << "\nPlease enter what name you like to search: ";
    cin >> wordSearch;
    if (searchName(names, n, wordSearch) == true) {
        cout << wordSearch << " is in the list\n";
    }
    else {
        cout << wordSearch << " isn't in the list\n";
    }
    // longest name search
    nameLong(names, n);
    // vowel count
    cout << "\nThere are " << countingVowels(names, n) << " vowels in this list\n";
    // shorten names
    cout << "\nEnter the amount of letters you want to shorten the names to: ";
    cin >> nameLengthShort;
    shortenName(names, n, nameLengthShort);
    return 0;
}