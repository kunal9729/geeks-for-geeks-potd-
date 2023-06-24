//User function Template for C++

class Solution {
public:
    int klengthpref(string arr[], int n, int k, string str) {
        int count = 0;  // Initialize a count variable to keep track of matching strings
        
        // Iterate through the array of strings
        for (int i = 0; i < n; i++) {
            int match = 1;  // Flag to indicate if the current string matches the target string
            
            // Compare each character of the current string with the corresponding character of the target string
            for (int j = 0; j < k; j++) {
                if (arr[i][j] != str[j]) {
                    match = 0;  // Set the flag to 0 if characters don't match
                }
            }
            
            count += match;  // Increment the count if the current string matches the target string
        }
        
        return count;  // Return the total count of matching strings
    }
};

