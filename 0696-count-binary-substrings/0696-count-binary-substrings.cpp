class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevGroupLength = 0, currGroupLength = 1, result = 0;
        
        for (int i = 1; i < s.length(); i++) {
            // If the current character is the same as the previous one, increment the current group length
            if (s[i] == s[i - 1]) {
                currGroupLength++;
            } else {
                // Otherwise, add the minimum of the previous group and the current group to the result
                result += min(prevGroupLength, currGroupLength);
                // Update the previous group length and reset the current group length
                prevGroupLength = currGroupLength;
                currGroupLength = 1;
            }
        }
        
        // After the loop, account for the last group
        result += min(prevGroupLength, currGroupLength);
        
        return result;
    }
};
