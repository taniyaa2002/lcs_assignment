#include <stdio.h>
#include <string.h>

// Function to compute the length of the longest common subsequence (LCS) of two strings
int computeLCSLength(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a 2D array to store LCS lengths for subproblems
    int lcsTable[len1 + 1][len2 + 1];
    
    // Fill the lcsTable using a bottom-up dynamic programming approach
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0 || j == 0) {
                lcsTable[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
            } else {
                lcsTable[i][j] = (lcsTable[i - 1][j] > lcsTable[i][j - 1]) ? lcsTable[i - 1][j] : lcsTable[i][j - 1];
            }
        }
    }
    
    // The length of the LCS is in the cell lcsTable[len1][len2]
    return lcsTable[len1][len2];
}

int main() {
    char firstString[100], secondString[100];

    printf("Enter the first string: ");
    scanf("%s", firstString);
    printf("Enter the second string: ");
    scanf("%s", secondString);
    
    int lcsLength = computeLCSLength(firstString, secondString);
    
    printf("The length of the Longest Common Subsequence is: %d\n", lcsLength);
    
    return 0;
}
