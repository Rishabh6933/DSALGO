/*

3. Longest Substring Without Repeating Characters

<--------------------BRUTE FORCE APPROACH-------------------->
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0; i<s.size(); i++) {
            int hash[255] = {0};
            for(int j=i; j<n; j++) {
                if(hash[s[j]] == 1) break;
                hash[s[j]] = 1;
                int len = j-i+1;
                maxLen = max(maxLen, len);
                }
            }
            return maxLen;
    }
};
                
                
<--------------------OPTIMISED APPROACH-------------------->
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    if(s.size()==0) return 0;
    vector<int> hash(256, -1);
    
    int start=0;
    int end=0;
    int maxLen = 0;
    while(end < s.size()) {
        if(hash[s[end]] != -1) start = max(hash[s[end]]+1, start);
        int len = end-start+1;
        maxLen = max(maxLen, len);
        hash[s[end]] = end; 
        end++;
    }
    return maxLen;
    }
};                
                            
                            
                            
424. Longest Repeating Character Replacement
                            
<--------------------BRUTE FORCE APPROACH-------------------->
class Solution {
    public:
        int characterReplacement(string s, int k) {
                int maxLen = 0;
                for(int i=0; i<s.size(); i++) {
                        int hash[26] = {0};
                        int maxFreq = 0;
                        for(int j=i; j<s.size(); j++) {
                                hash[s[j] - 'A']++;
                                maxFreq = max(maxFreq, hash[s[j] - 'A']);
                                int changes = (j-i+1) - maxFreq;
                                if(changes <= k) maxLen = max(j-i+1, maxLen);
                                else break;
                            }
                        }
                        return maxLen;
                
                    }
                };
                
                
                
<--------------------OPTIMISED APPROACH-------------------->
class Solution {
    public:
        int characterReplacement(string s, int k) {
                int start=0;
                int end=0;
                int maxLen=0;
                int maxFreq = 0;
                vector<int> hash(26, 0);
        
            while(end < s.size()) {
                hash[s[end] - 'A']++;
                maxFreq = max(maxFreq, hash[s[end] - 'A']);
            
                // just shrink by 1, don't recalculate maxFreq
                if((end - start + 1 - maxFreq) > k) {
                        hash[s[start] - 'A']--;
                        start++;
                    }
                
                    maxLen = max(end - start + 1, maxLen);
                    end++;
                    }
                    return maxLen;
                    }
                };
                
                
76. Minimum Window Substring

<--------------------BRUTE FORCE APPROACH-------------------->
class Solution {
    public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        int sIndex = 0;
        for(int i=0; i<s.size(); i++) {
            int hash[256] = {0};
            int count=0;
            for(int j=0; j<t.size(); j++) hash[t[j]]++;
            for(int j=i; j<s.size(); j++) {
                if(hash[s[j]] > 0) count++;
                hash[s[j]]--;
                if(count == t.size()) {
                    if(j-i+1 < minLen) { 
                        minLen = j-i+1;
                        sIndex = i;
                        break;
                    }
                }
            }
                                        
        }
        return minLen == INT_MAX ? "" : s.substr(sIndex, minLen);
    }
};
                                                                                
                                        
<--------------------OPTIMISED APPROACH-------------------->
class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int left=0;
        int right=0;
        int minLen = INT_MAX;
        int sIndex = -1;
        int count = 0;
        for(int i=0; i<t.size(); i++) hash[t[i]]++;
        while(right < s.size()) {

            if(hash[s[right]]  > 0) count++;
            hash[s[right]]--;

            while(count == t.size()) {
                if(right-left+1 < minLen) {
                    minLen = right - left + 1;
                    sIndex = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0) count--;
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(sIndex, minLen);

    }
};


242. Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int count[26] = {0};

        for(int i=0; i<s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int i=0; i<26; i++) {
            if(count[i] != 0) return false;
        }

        return true;
    }
};


49. Group Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp;
        for(auto& word : strs) {
            vector<int> freq(26, 0);
            for(auto& c : word) {
                freq[c - 'a']++;
            }
            mpp[freq].push_back(word);
        }

        vector<vector<string>> result;
        for(auto& pair : mpp) {
            result.push_back(pair.second);
        }
        return result;
    }
};



20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') st.push(')');
            else if(s[i] == '[') st.push(']');
            else if(s[i] == '{') st.push('}');
            else if(st.empty() || st.top() != s[i]) return false;
            else st.pop();
        }
        return st.empty();
    }
};


125. Valid Palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left < right) {
            if(!isalnum(s[left])) {
                left++;
                continue;
            }
            if(!isalnum(s[right])) {
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;

        }
        return true;
    }




class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int maxLen = INT_MIN;
        int n = s.size();
        int st=0, end=0;
        
        for(int i=0; i<n; i++) {
            int left = i;
            int right = i;
            while(left>=0 && right<n && s[left] == s[right]) {
                left--;
                right++;
            }
            int len = right-left-1;
            if(len > maxLen) {
                maxLen = len;
                st=left+1;
                end=right-1;
            }

        }

        for(int i=0; i<n; i++) {
            int left = i;
            int right = i+1;
            while(left>=0 && right<n && s[left] == s[right]) {
                left--;
                right++;
            }
            int len = right-left-1;
            if(len > maxLen) {
                maxLen = len;
                st=left+1;
                end=right-1;
            }
        }
    return s.substr(st,maxLen);
    }
};





};














*/