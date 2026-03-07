// 3. Longest Substring Without Repeating Characters

// <--------------------BRUTE FORCE APPROACH-------------------->
// class Solution {
    // public:
    //     int lengthOfLongestSubstring(string s) {
        //         int n = s.size();
        //         int maxLen = 0;
        
        //         for(int i=0; i<s.size(); i++) {
            //             int hash[255] = {0};
            //             for(int j=i; j<n; j++) {
                //                 if(hash[s[j]] == 1) break;
                //                 hash[s[j]] = 1;
                //                 int len = j-i+1;
                //                 maxLen = max(maxLen, len);
                //             }
                //         }
                //         return maxLen;
                //     }
                // };
                
                
                // <--------------------OPTIMISED APPROACH-------------------->
                // class Solution {
                    // public:
                    //     int lengthOfLongestSubstring(string s) {
                        //         if(s.size()==0) return 0;
                        //         vector<int> hash(256, -1);
                        
                        //         int start=0;
                        //         int end=0;
                        //         int maxLen = 0;
                        //         while(end < s.size()) {
                            //             if(hash[s[end]] != -1) start = max(hash[s[end]]+1, start);
                            //             int len = end-start+1;
                            //             maxLen = max(maxLen, len);
                            //             hash[s[end]] = end; 
                            //             end++;
                            //         }
                            //         return maxLen;
                            //     }
                            // };                
                            
                            
                            
// 424. Longest Repeating Character Replacement
                            
// <--------------------BRUTE FORCE APPROACH-------------------->
// class Solution {
    // public:
    //     int characterReplacement(string s, int k) {
        //         int maxLen = 0;
        //         for(int i=0; i<s.size(); i++) {
            //             int hash[26] = {0};
            //             int maxFreq = 0;
            //             for(int j=i; j<s.size(); j++) {
                //                 hash[s[j] - 'A']++;
                //                 maxFreq = max(maxFreq, hash[s[j] - 'A']);
                //                 int changes = (j-i+1) - maxFreq;
                //                 if(changes <= k) maxLen = max(j-i+1, maxLen);
                //                 else break;
                //             }
                //         }
                //         return maxLen;
                
                //     }
                // };
                
                
                
// <--------------------OPTIMISED APPROACH-------------------->
// class Solution {
    // public:
    //     int characterReplacement(string s, int k) {
        //         int start=0;
        //         int end=0;
        //         int maxLen=0;
        //         int maxFreq = 0;
        //         vector<int> hash(26, 0);
        
        //     while(end < s.size()) {
            //     hash[s[end] - 'A']++;
            //     maxFreq = max(maxFreq, hash[s[end] - 'A']);
            
            //     // just shrink by 1, don't recalculate maxFreq
            //     if((end - start + 1 - maxFreq) > k) {
                //         hash[s[start] - 'A']--;
                //         start++;
                //     }
                
                //     maxLen = max(end - start + 1, maxLen);
                //     end++;
                //     }
                //     return maxLen;
                //     }
                // };
                
                
// 76. Minimum Window Substring

// <--------------------BRUTE FORCE APPROACH-------------------->
// class Solution {
//     public:
//     string minWindow(string s, string t) {
//         int minLen = INT_MAX;
//         int sIndex = 0;
//         for(int i=0; i<s.size(); i++) {
//             int hash[256] = {0};
//             int count=0;
//             for(int j=0; j<t.size(); j++) hash[t[j]]++;
//             for(int j=i; j<s.size(); j++) {
//                 if(hash[s[j]] > 0) count++;
//                 hash[s[j]]--;
//                 if(count == t.size()) {
//                     if(j-i+1 < minLen) { 
//                         minLen = j-i+1;
//                         sIndex = i;
//                         break;
//                     }
//                 }
//             }
                                        
//         }
//         return minLen == INT_MAX ? "" : s.substr(sIndex, minLen);
//     }
// };
                                                                                
                                        
// <--------------------OPTIMISED APPROACH-------------------->
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int hash[256] = {0};
//         int left=0;
//         int right=0;
//         int minLen = INT_MAX;
//         int sIndex = -1;
//         int count = 0;
//         for(int i=0; i<t.size(); i++) hash[t[i]]++;
//         while(right < s.size()) {

//             if(hash[s[right]]  > 0) count++;
//             hash[s[right]]--;

//             while(count == t.size()) {
//                 if(right-left+1 < minLen) {
//                     minLen = right - left + 1;
//                     sIndex = left;
//                 }
//                 hash[s[left]]++;
//                 if(hash[s[left]] > 0) count--;
//                 left++;
//             }
//             right++;
//         }
//         return minLen == INT_MAX ? "" : s.substr(sIndex, minLen);

//     }
// };