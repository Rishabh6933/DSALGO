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