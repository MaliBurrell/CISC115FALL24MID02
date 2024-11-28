//Solomon Archer
#include <iostream>
#include <string>
#include <algorithm> // For sort function
#include <cctype> // For tolower function

using namespace std;

//sort names alphabetically 
void sortNames(string names[], int size) {
    sort(names, names + size);
}

//search names in list 
bool searchName(const string names[], int size, const string& target) {
    for (int i = 0; i < size; ++i) {
        if (names[i] == target) {
            return true;
        }
    }
    return false;
}

//find longest name 
string findLongestName(const string names[], int size) {
    string longestName = names[0];
    for (int i = 1; i < size; ++i) {
        if (names[i].length() > longestName.length()) {
            longestName = names[i];
        }
    }
    return longestName;
}

//count total vowels 
int countVowels(const string names[], int size) {
    int vowelCount = 0;
    string vowels = "aeiouAEIOU";
    for (int i = 0; i < size; ++i) {
        for (char ch : names[i]) {
            if (vowels.find(ch) != string::npos) {
                ++vowelCount;
            }
        }
    }
    return vowelCount;
}

int main() {
    //ask for number of names 
    int n;
    cout << "Enter the number of names: ";
    cin >> n;

    //allocate array of strings
    string* names = new string[n];

    // get names from user
    cout << "Enter " << n << " names:" << endl;
    cin.ignore(); // ignore the newline character after the previous input
    for (int i = 0; i < n; ++i) {
        cout << "Enter name " << i+1 << ": \n";
        getline(cin, names[i]);
        
    }

 
    sortNames(names, n);

    string target;
    cout << "Enter a name to search for: ";
    getline(cin, target);
    bool found = searchName(names, n, target);

    string longestName = findLongestName(names, n);
    int totalVowels = countVowels(names, n);

    // Output results
    cout << "\nSorted List of Names:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << names[i] << endl;
    }

    cout << "\nSearch Result: ";
    if (found) {
        cout << "\"" << target << "\" is in the list." << endl;
    }
    else {
        cout << "\"" << target << "\" is not in the list." << endl;
    }

    cout << "Longest Name: " << longestName << endl;
    cout << "Total Vowel Count: " << totalVowels << endl;

    // clear allocated memory
    delete[] names;

    return 0;
} 