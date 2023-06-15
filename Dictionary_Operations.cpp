#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// Function to add a new keyword and its meaning to the dictionary
void addKeyword(map<string, string>& dictionary) {
    string keyword, meaning;
    cout << "Enter keyword: ";
    cin >> keyword;
    cout << "Enter meaning: ";
    cin.ignore();
    getline(cin, meaning);

    dictionary[keyword] = meaning;
    cout << "Keyword added successfully." << endl;
}

// Function to delete a keyword from the dictionary
void deleteKeyword(map<string, string>& dictionary) {
    string keyword;
    cout << "Enter keyword to delete: ";
    cin >> keyword;

    auto iter = dictionary.find(keyword);
    if (iter != dictionary.end()) {
        dictionary.erase(iter);
        cout << "Keyword deleted successfully." << endl;
    }
    else {
        cout << "Keyword not found in the dictionary." << endl;
    }
}

// Function to update the meaning of an existing keyword
void updateKeyword(map<string, string>& dictionary) {
    string keyword, meaning;
    cout << "Enter keyword to update meaning: ";
    cin >> keyword;
    cout << "Enter new meaning: ";
    cin.ignore();
    getline(cin, meaning);

    auto iter = dictionary.find(keyword);
    if (iter != dictionary.end()) {
        iter->second = meaning;
        cout << "Keyword meaning updated successfully." << endl;
    }
    else {
        cout << "Keyword not found in the dictionary." << endl;
    }
}

// Function to display the dictionary data in ascending order
void displayAscending(const map<string, string>& dictionary) {
    cout << "Dictionary in ascending order:" << endl;
    for (const auto& entry : dictionary) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

// Function to display the dictionary data in descending order
void displayDescending(const map<string, string>& dictionary) {
    cout << "Dictionary in descending order:" << endl;
    for (auto it = dictionary.rbegin(); it != dictionary.rend(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

// Function to find the maximum number of comparisons required to find a keyword in the dictionary
int findMaxComparisons(const map<string, string>& dictionary, const string& keyword) {
    auto iter = dictionary.find(keyword);
    if (iter != dictionary.end()) {
        int position = distance(dictionary.begin(), iter) + 1;
        return max(position, (int)dictionary.size() - position + 1);
    }
    return -1; // Keyword not found
}

int main() {
    map<string, string> dictionary;
    int choice;

    do {
        cout << "1. Add new keyword\n";
        cout << "2. Delete keyword\n";
        cout << "3. Update keyword meaning\n";
        cout << "4. Display dictionary in ascending order\n";
        cout << "5. Display dictionary in descending order\n";
        cout << "6. Find maximum comparisons for a keyword\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addKeyword(dictionary);
                break;

            case 2:
                deleteKeyword(dictionary);
                break;

            case 3:
                updateKeyword(dictionary);
                break;

            case 4:
                displayAscending(dictionary);
                break;

            case 5:
                displayDescending(dictionary);
                break;

            case 6: {
                string keyword;
                cout << "Enter keyword to find maximum comparisons: ";
                cin >> keyword;
                int maxComparisons = findMaxComparisons(dictionary, keyword);
                if (maxComparisons != -1) {
                    cout << "Maximum comparisons required: " << maxComparisons << endl;
                }
                else {
                    cout << "Keyword not found in the dictionary." << endl;
                }
                break;
            }

            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 7);

    return 0;
}
