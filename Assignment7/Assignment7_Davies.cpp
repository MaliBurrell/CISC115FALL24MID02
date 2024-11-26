#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to sort names alphabetically
void sortNames(string names[], int size) {
    sort(names, names + size);
}

// Function to search for a specific name
bool searchName(const string names[], int size, const string& target) {
    for (int i = 0; i < size; i++) {
        if (names[i] == target) {
            return true;
        }
    }
    return false;
}

// Function to find the longest name
string findLongestName(const string names[], int size) {
    string longest = names[0];
    for (int i = 1; i < size; i++) {
        if (names[i].length() > longest.length()) {
            longest = names[i];
        }
    }
    return longest;
}

// Function to count the total number of vowels in all names
int countVowels(const string names[], int size) {
    int vowelCount = 0;
    for (int i = 0; i < size; i++) {
        for (char c : names[i]) {
            c = tolower(c); // Make the character lowercase for comparison
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelCount++;
            }
        }
    }
    return vowelCount;
}

int main() {
    int n;
    
    // Input the number of names
    cout << "Enter the number of names: ";
    cin >> n;
    cin.ignore(); // Ignore leftover newline character from input

    // Dynamically allocate memory for names
    string* names = new string[n];

    // Input the names
    cout << "Enter " << n << " names:" << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, names[i]);
    }

    // Sort the names
    sortNames(names, n);

    // Search for a specific name
    string target;
    cout << "Enter a name to search for: ";
    getline(cin, target);
    bool found = searchName(names, n, target);

    // Find the longest name
    string longestName = findLongestName(names, n);

    // Count the total number of vowels
    int totalVowels = countVowels(names, n);

    // Output the results
    cout << "\nSorted list of names:" << endl;
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }

    cout << "\nSearch result: ";
    if (found) {
        cout << target << " is in the list." << endl;
    } else {
        cout << target << " is not in the list." << endl;
    }

    cout << "Longest name: " << longestName << endl;
    cout << "Total number of vowels: " << totalVowels << endl;

    // Free the allocated memory
    delete[] names;

    return 0;
}