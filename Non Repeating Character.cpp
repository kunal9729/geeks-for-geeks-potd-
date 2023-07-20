


class Solution {
public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(std::string S) {
        // Create a frequency map to store the count of each character in the string.
        std::unordered_map<char, int> charFrequency;
        
        // Create a queue to store characters that appear only once.
        std::queue<char> uniqueChars;
        
        // Traverse the input string.
        for (char ch : S) {
            // Increment the count of the current character in the frequency map.
            ++charFrequency[ch];
            
            // If this is the first occurrence of the character, add it to the queue.
            if (charFrequency[ch] == 1)
                uniqueChars.push(ch);
                
            // Check if the characters at the front of the queue have more than one occurrence.
            // If yes, remove them from the queue since they are no longer unique.
            while (!uniqueChars.empty() && charFrequency[uniqueChars.front()] > 1)
                uniqueChars.pop();
        }
        
        // If the queue is not empty, return the first non-repeating character from the queue.
        // Otherwise, return '$' to indicate that there are no non-repeating characters.
        return !uniqueChars.empty() ? uniqueChars.front() : '$';
    }
};
