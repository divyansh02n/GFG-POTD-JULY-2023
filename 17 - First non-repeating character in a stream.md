## 17. First non-repeating character in a stream

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1)


### QUESTION
Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.
 

### Example 1:

- Input: A = `aabc`
  
- Output: `a#bb`

  
- Explanation: For every character first non repeating character is as follow-  

      a    - first non-repeating character is    ----->   a
      aa   - no non-repeating character so       ----->   #
      aab  - first non-repeating character is    ----->   b
      aabc - first non-repeating character is    ----->   b
                

### Example 2:

- Input: A = `zz`
  
- Output: `z#`

- Explanation: For every character first non-repeating character is as follow -

      "z"  - first non-repeating character is    ----->  'z'
      "zz" - no non-repeating character so       ----->  '#'  
 

### Your Task:
You don't need to read or print anything. Your task is to complete the function FirstNonRepeating() which takes A as input parameter and returns a string after processing the input stream.
 

### Time and Auxiliary Space Complexity

- **Expected Time Complexity**: `O(26 * n)`
- **Expected Space Complexity**: `O(26)`


### Constraints :
 - 1 <= n <= 105




# My Approach

1. Initialize an empty string s to store the result.

2. Create a map (mp) to keep track of the frequency of each character in the input string A. The map will have characters as keys and their respective counts as values.

3. Initialize two pointers, i and j, to 0. The pointer j will move from left to right, iterating through the characters of the input string A.

4. At each step, increment the frequency of the character at index j in the map mp.

5. Inside the while loop, another nested while loop is used to find the first non-repeating character. It moves the index i from its current position to the position of the first non-repeating character (where the frequency in the map mp is 1), or it may not move at all if there is no such character.

6. After finding the first non-repeating character (if any), it checks if the current character at index j has a frequency greater than 1 and i has not moved. If so, it means the current character is repeating, and in that case, the code appends '#' to the result string s. Otherwise, it appends the first non-repeating character to s.

7. Increment the pointer j to move to the next character in the input string and continue the process until j reaches the end of the string.

8. Finally, return the result string s.

### Code (C++)
```cpp
class Solution {
public:
string FirstNonRepeating(string A){
    // Code here
    string s;
    map<char, int> mp;
    int i = 0, j = 0;
    while(j < A.size())
    {
            mp[A[j]]++;
            while(mp[A[i]] != 1 && i < j) i++;
            if(mp[A[j]] != 1 && i == j) s+='#';
            else s+=A[i];
            j++;
    }
    return s;
}
 
};
```

### Time and Auxiliary Space Complexity of above code

- **Time Complexity**: `O(N)`, as the outer while loop iterates through the string A once where N is the length of the input string.

      - Explanation :
  
           1. The outer while loop iterates through the string A once, so its time complexity is O(N), where N is the
              length of the input string.
  
           2. The inner while loop moves the index i from its current position to the position of the first
              non-repeating character, or it may not move at all if there is no such character. In the worst case,
              the inner loop could iterate through the entire string (in the case when all characters are repeating).
              However, in each iteration of the outer loop, the index j will be incremented, and we will not revisit
              elements, so the inner loop's overall complexity for the entire program is still O(N).
  
- **Space Complexity**: `O(N)`, since the size of the map and the string both grow linearly with the input size

           - Explanation :
  
           1. The code uses a map (mp) to store the frequency of each character in the input string. In the worst
              case, all characters in the string are distinct, so the map will have N entries (N being the length
              of the input string).
  
           2. The code also uses a string (s) to store the result.
