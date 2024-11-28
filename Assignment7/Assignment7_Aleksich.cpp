#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype>   

using namespace std;

//Declaring function protoypes
void sortNames(string names[], int size);
bool searchName(const string names[], int size, const string& target);
string findLongestName(const string names[], int size);
int countVowels(const string names[], int size);

int main(){

    int n;

    //User inputs # of names
    cout << "Enter the number of names: ";
    cin >> n;
    cin.ignore();

    //Sets array of strings
    string* names = new string[n];

    //User inputs the names
    cout << "Enter " << n << " names:\n";
    for (int i = 0; i < n; ++i){
        getline(cin, names[i]);
    }

    //Sorts names
    sortNames(names, n);

    //Displays list of names
    cout << "\nSorted names:\n";
    for (int i = 0; i < n; ++i){
        cout << names[i] << endl;
    }

    //Searches for a specific name in the list
    string target;
    cout << "\nEnter a name to search for: ";
    getline(cin, target);
    bool found = searchName(names, n, target);
    if (found){
        cout << target << " is in the list.\n";
    } 
    else{
        cout << target << " is not in the list.\n";
    }

    //Finds the longest name
    string longestName = findLongestName(names, n);
    cout << "\nThe longest name is: " << longestName << endl;

    //Counts the total amount of vowels in the name
    int totalVowels = countVowels(names, n);
    cout << "\nTotal number of vowels in all names: " << totalVowels << endl;

    delete[] names;

    return 0;
}

//Function to sort names alphabetically
void sortNames(string names[], int size){
    sort(names, names + size);
}

//Function to search for a specific name
bool searchName(const string names[], int size, const string& target){
    for (int i = 0; i < size; ++i){
        if (names[i] == target){
            return true;
        }
    }

    return false;
}

//Function to find the longest name
string findLongestName(const string names[], int size){
    string longest = names[0];
    for (int i = 1; i < size; ++i){
        if (names[i].length() > longest.length()){
            longest = names[i];
        }
    }

    return longest;
}

//Function to count total vowels in all names
int countVowels(const string names[], int size){
    int count = 0;
    for (int i = 0; i < size; ++i){
        for (char ch : names[i]){
            char lowerCh = tolower(ch);
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u'){
                ++count;
            }
        }
    }

    return count;
}
