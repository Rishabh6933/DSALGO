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