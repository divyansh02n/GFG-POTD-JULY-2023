## 17. Longest Repeating Subsequence


The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence200)


### QUESTION
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.
For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.
 

### Example 1:

- Input: str = `axxzxy`
  
- Output: `2`

  
- Explanation: The given array with indexes looks like  

      a x x z x y 
      0 1 2 3 4 5
- The longest subsequence is `xx`. 
- It appears twice as explained below.
                


### Your Task:
You don't need to read or print anything. Your task is to complete the LongestRepeatingSubsequence() which takes str as input parameter and returns the 
length of the longest repeating subsequnece.
 

### Time and Auxiliary Space Complexity

- **Expected Time Complexity**: ` O(n2)`
- **Expected Space Complexity**: `O(n2)`


### Constraints :
 1 <= |str| <= 103




# My Approach

1. The function `LongestRepeatingSubsequence` takes the input string `str` as an argument and returns an integer representing the length of the longest repeating
   subsequence.

2. It initializes variables `n`, `i`, and `j`. `n` stores the size of the input string `str`, while `i` and `j` are used as loop counters.

3. It creates a 2D vector `t` of size `(n+1) x (n+1)` to store the results of subproblems. The value `t[i][j]` represents the length of the longest repeating
   subsequence in the substrings `str[0...i-1]` and `str[0...j-1]`.

4. The outer loop runs from `i=1` to `i=n`, and the inner loop runs from `j=1` to `j=n`.

5. Within the loops, the code checks if the characters at indices `i-1` and `j-1` of the string `str` are equal, and if `i` is not equal to `j`. This condition
   ensures that we are considering different positions for the repeating subsequences. If both conditions are met, it means we can extend a
   repeating subsequence, and the length of the repeating subsequence is incremented by one. Therefore, `t[i][j] = 1 + t[i-1][j-1]`.
   

6. If the characters at `i-1` and `j-1` are not equal or if `i` is equal to `j`, it means we cannot extend the repeating subsequence, so we consider two cases:

            a. We skip the character at position `i` and keep the subsequence the same length, so `t[i][j] = t[i-1][j]`.
            b. We skip the character at position `j` and keep the subsequence the same length, so `t[i][j] = t[i][j-1]`.
   
8. The maximum of the above two cases is taken as the value of `t[i][j]`, representing the length of the longest repeating subsequence in the
    substrings `str[0...i-1]` and `str[0...j-1]`.

9. After the loops are completed, the function returns `t[n][n]`, which represents the length of the longest repeating subsequence in the entire
   input string `str`.

   
### Code (C++)
```cpp
	class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size(), i, j;
		    vector<vector<int>> t(n+1, vector<int>(n+1, 0));
		    for(i=1;i<n+1;i++){
		        for(j=1;j<n+1;j++){

		            if(str[i-1]==str[j-1] and i!=j)
		                t[i][j] = 1 + t[i-1][j-1];
		            else
		                t[i][j] = max(t[i][j-1], t[i-1][j]);
		        }
		    }
		    return t[n][n];
		}
};
```

### Time and Auxiliary Space Complexity of above code

- **Time Complexity**: `O(n^2)`, where `n` is the size of the input string `str`.
      - Explanation :
  
           1. The time complexity of the given code is `O(n^2)`, where `n` is the size of the input string
             `str`. This is because the code uses a nested loop structure to fill the 2D table `t`,
              where both loops run from `1 to n`. For each element of the table, constant time
              operations are performed, such as checking character equality and updating the
              table values with `max` function.
  
  
- **Space Complexity**: `O(n^2)`.

           - Explanation :
  
           1. The space complexity of the given code is also O(n^2). This is because the code uses a
              2D vector t of size `(n+1) x (n+1)` to store the results of subproblems. Each cell
              of the table requires constant space. Therefore, the total space required for the
              table is `(n+1) x (n+1) = O(n^2)`. As there are no other significant additional
              data structures used in the code that depend on the input size,
              the space complexity remains `O(n^2)`.
           
