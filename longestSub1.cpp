#include <iostream>
#include <vector>

using namespace std;

string longestCommonSubstring(const string& str1, const string& str2, vector<vector<int>>& dp) {
    int m = str1.length();
    int n = str2.length();

    // Create a 2D table to store lengths of common substrings
    dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0;  // Length of the longest common substring
    int endIndex = 0;   // Ending index of the longest common substring

    // Fill the table and track the maximum length and its ending index
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Extract the longest common substring
    string result = str1.substr(endIndex - maxLength + 1, maxLength);
    return result;
}

void printTable(const string& str1, const string& str2, const vector<vector<int>>& dp) {
    int m = str1.length();
    int n = str2.length();

    cout << "  ";
    for (int j = 0; j < n; ++j) {
        cout << str2[j] << " ";
    }
    cout << endl;

    for (int i = 1; i <= m; ++i) {

        cout << str1[i-1] << " ";


        for (int j = 1; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string str1, str2;
    vector<vector<int>> dp;  // 2D table

    // Prompt user until conditions are met
    do {
        cout << "Enter the first string: ";
        cin >> str1;

        cout << "Enter the second string: ";
        cin >> str2;

        if (str1.length() != str2.length() || str1.find_first_of(str2) == string::npos) {
            cout << "Error: Please ensure strings are of the same length and have at least one common character." << endl;
        }
    } while (str1.length() != str2.length() || str1.find_first_of(str2) == string::npos);

    string commonSubstring = longestCommonSubstring(str1, str2, dp);

    // Print the 2D table
    printTable(str1, str2, dp);

    // Print the result
    cout << "Longest Common Substring: " << commonSubstring << endl;
    cout << "Length of Common Substring: "<< commonSubstring.length()<<endl;

    return 0;
}
