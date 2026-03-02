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
