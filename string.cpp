// Remove outermost Parenthesesclass Solution {
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         int counter = 0;
//         string ans;
//         for(int i=0; i<s.length() ; i++) {
//             if(s[i] == '(') {
//                 if(counter > 0) ans+=s[i];
//                 counter++;
//             }
//             else {
//                 counter--;
//                 if(counter > 0) ans+=s[i];
//             }
//         }
//         return ans;
//     }
// };


// 151. Reverse Words in a String
// string reverseWords(string s) {
//     // STEP 1: Reverse entire string
//     reverse(s.begin(), s.end());  
//     // "the sky is blue" → "eulb si yks eht"
    
//     string ans = "";
//     int n = s.size();
    
//     // STEP 2: Extract and reverse each word
//     for(int i = 0; i < n; i++) {
//         string word = "";
        
//         // Collect characters until space
//         while(i < n && s[i] != ' ') {
//             word += s[i];
//             i++;
//         }
//         // Now word = "eulb" (or "si", "yks", "eht")
        
//         // Reverse the word back
//         reverse(word.begin(), word.end());
//         // "eulb" → "blue"
        
//         // Add to answer if word is not empty
//         if(word.size() > 0)
//             ans += " " + word;  // " blue", " is", " sky", " the"
//     }
    
//     // Remove the leading space
//     return ans.substr(1);  // " blue is sky the" → "blue is sky the"
// }
// ```


// 1903. Largest Odd Number in String
// class Solution {
// public:
//     string largestOddNumber(string num) {
//         int n = num.size();
//         for(int i=n-1; i>=0; i--) {
//             if(num[i] == '1' || num[i] == '3' || num[i] == '5' || num[i] == '7' || num[i] == '9') {
//                 return num.substr(0,i+1);
//             }
//         }
//         return "";
//     }
// };



// 14. Longest Common Prefix
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.empty())    return "";
//         int n = strs.size();
//         sort(strs.begin(), strs.end());
//         string first = strs[0];
//         string last = strs[n-1];
//         string ans;
//         int mini = min(first.size(), last.size());

//         for(int i=0; i<mini; i++) {
//             if(first[i] == last[i]) ans += first[i]; 
//             else break;
//         }
//         return ans;
//     }
// };




// 205. Isomorphic Strings
// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if(s.size() != t.size()) return false;

//         vector<int> map1(256, -1);
//         vector<int> map2(256, -1);

//         for(int i=0; i<s.size(); i++) {
//             if(map1[s[i]] == -1 && map2[t[i]] == -1) {
//                 map1[s[i]] = t[i];
//                 map2[t[i]] = s[i];
//             }
//             else if(map1[s[i]] != t[i] || map2[t[i]] != s[i]) return false;
//         }
//         return true;
//     }
// };





// 796. Rotate String

// ## NOTE ---> Just roatate the string one by one and check if it is equal to goal or not     

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.size() != goal.size()) return false; 
//         for(int i=0; i<s.size(); i++) {
//             if(s == goal) return true;
//             rotate(s.begin(), s.begin() + 1, s.end());
//         }
//         return false;
//     }
// };

// ## NOTE ---> If you concatenate a string with itself,
//              it will contain all rotations as a substring in it

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.size() != goal.size()) return false; 
//         if((s+s).find(goal) != string::npos) return true;
//         return false;
//     }
// };




// 242. Valid Anagram
// Basic approach is you can sort the string and compare whether it is same or not

// Optimised approach is just make a array and perform a sort of hasing increment and decrement
// for every element in the string s and t respectively
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) return false;
//         int count[26] = {0};

//         for(int i=0; i<s.size(); i++) {
//             count[s[i] - 'a']++;
//             count[t[i] - 'a']--;
//         }

//         for(int i=0; i<26; i++) {
//             if(count[i] != 0) return false;
//         }

//         return true;
//     }
// };


// 451. Sort Characters By Frequency
// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> freq;
//         // count frequency
//         for(char c : s) {
//             freq[c]++;
//         }

//         // create buckets
//         vector<vector<char>> bucket(s.size() + 1);

//         for(auto &p : freq) {
//             bucket[p.second].push_back(p.first);
//         }

//         // create result
//         string result;
    
//         for(int i=s.size(); i>0; i--) {
//             for(char c : bucket[i]) {
//                 result.append(i,c);
//             }
//         }
//         return result;
//     }
// };


// <--------------------ANOTHER APPROACH-------------------->
// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char, int> freq;
//         for(char c : s) freq[c]++;

//         vector<pair<char, int>> chars(freq.begin(), freq.end());
//         sort(chars.begin(), chars.end(), [](auto& a, auto& b) {
//             return a.second > b.second;
//         });

//         string result;
//         for(auto& p : chars){
//             result.append(p.second, p.first);
//         }
//         return result;
//     }
// };


// 1614. Maximum Nesting Depth of the Parentheses
// class Solution {
// public:
//     int maxDepth(string s) {
//         int count = 0;
//         int result = 0;
//         for(char c : s) {
//             if(c == '(' ) {
//                 count++;
//                 if(count > result) result = count;
//             }
//             else if(c == ')') count--;
//         }
//         return result;
//     }
// };


// 13. Roman to Integer
// class Solution {
// public:
//     int romanToInt(string s) {
//         int result=0;
//         int value[128] = {0};
//         value['I'] = 1;
//         value['V'] = 5;
//         value['X'] = 10;
//         value['L'] = 50;
//         value['C'] = 100;
//         value['D'] = 500;
//         value['M'] = 1000;

//         for(int i=0; i<s.size(); i++) {
//             if(i+1 < s.size() && value[s[i]] < value[s[i+1]]) {
//                 result += (value[s[i+1]] - value[s[i]]);
//                 i++;
//             }
//             else
//                 result += value[s[i]];
//         }
//         return result;
//     }
// };



// 8. String to Integer (atoi)
// class Solution {
// public:
//     int myAtoi(string s) {
//         long result = 0;
//         int i=0;
//         while(i<s.size() && (s[i] == ' ')) {
//              i++;
//         }

//         int sign = +1;

//         if(i<s.size() && (s[i] == '-' || s[i] == '+')) {
//             sign = (s[i] == '-') ? -1 : 1;
//             i++;
//         }

//         while(i < s.size() && isdigit(s[i])) {
//             result = result*10 + s[i] - '0';

//             if(result * sign > INT_MAX) return INT_MAX;
//             if(result * sign < INT_MIN) return INT_MIN;
//             i++;
//         }
//         return (int)(result*sign);
//     }
// };



// 5. Longest Palindromic Substring
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         // Edge case: single character or empty string is already a palindrome
//         if(s.size() <= 1) return s;
        
//         int maxLen = INT_MIN;  // Track the length of longest palindrome found
//         int n = s.size();
//         int st = 0, end = 0;   // Track start and end indices of longest palindrome
        
//         // PART 1: Check for ODD-length palindromes (center is a single character)
//         // Example: "aba" has center at 'b'
//         for(int i = 0; i < n; i++) {
//             // Start with center at position i
//             int left = i;
//             int right = i;
            
//             // Expand outward while characters match and within bounds
//             // left moves leftward (--), right moves rightward (++)
//             while(left >= 0 && right < n && s[left] == s[right]) {
//                 left--;   // Move left pointer outward
//                 right++;  // Move right pointer outward
//             }
//             // After loop: left and right have gone ONE step beyond the palindrome
            
//             // Calculate actual palindrome length
//             // Why (right - left - 1)?
//             // - right is 1 position AFTER the palindrome ends
//             // - left is 1 position BEFORE the palindrome starts
//             // - So actual length = right - left - 1
//             int len = right - left - 1;
            
//             // Update if we found a longer palindrome
//             if(len > maxLen) {
//                 maxLen = len;
//                 st = left + 1;   // Actual start is left + 1 (left went too far)
//                 end = right - 1; // Actual end is right - 1 (right went too far)
//             }
//         }

//         // PART 2: Check for EVEN-length palindromes (center is between two characters)
//         // Example: "abba" has center between the two 'b's
//         for(int i = 0; i < n; i++) {
//             // Start with center between positions i and i+1
//             int left = i;
//             int right = i + 1;
            
//             // Expand outward while characters match and within bounds
//             while(left >= 0 && right < n && s[left] == s[right]) {
//                 left--;   // Move left pointer outward
//                 right++;  // Move right pointer outward
//             }
//             // After loop: left and right have gone ONE step beyond the palindrome
            
//             // Calculate actual palindrome length (same formula as odd-length)
//             int len = right - left - 1;
            
//             // Update if we found a longer palindrome
//             if(len > maxLen) {
//                 maxLen = len;
//                 st = left + 1;   // Actual start (adjust for overstep)
//                 end = right - 1; // Actual end (adjust for overstep)
//             }
//         }
        
//         // Extract and return the longest palindrome substring
//         // substr(start_position, length)
//         return s.substr(st, maxLen);
//     }
// };



// 1781. Sum of Beauty of All Substrings
// class Solution {
// public:
//     int beautySum(string s) {
//         int ans=0;
//         int n = s.size();
//         for(int i=0; i<n; i++) {
//             int freq[26] = {0};
//             for(int j=i; j<n; j++) {
//                 freq[s[j] - 'a']++;
//                 int m_f = 0;
//                 int l_f = INT_MAX;
//                 for(int i=0; i<26; i++) {
//                     if(freq[i] > 0){
//                         m_f = max(m_f, freq[i]);
//                         l_f = min(l_f, freq[i]);
//                     }
//                 }
//                 ans += (m_f - l_f);
//             }
//         }
//     return ans;
//     }
// };