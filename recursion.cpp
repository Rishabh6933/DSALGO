/*

8. String to Integer (atoi)
Recursive Implementation of atoi()

class Solution {
public:

    int helper(string& s, int i, long result, int sign) {
        if(i == s.size() || !isdigit(s[i])) return (int)(result*sign);

        result = result * 10 + (s[i]-'0');

        if(result*sign > INT_MAX) return INT_MAX;
        if(result*sign < INT_MIN) return INT_MIN;

        return helper(s, i+1, result, sign);

    }
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i] == ' ') i++;

        int sign = 1;
        if(i<s.size() && s[i] == '+') i++;
        else if(i<s.size() && s[i] == '-') {
            i++;
            sign = -1;
        }

        return helper(s, i, 0, sign);
    }
};



50. Pow(x, n)
class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0) return 1;
        if(n < 0) return 1.0 / myPow(x, -n);

        double half = myPow(x, n/2);
        if(n%2 == 0) return half * half;
        else return half * half * x;
    }
};



1922. Count Good Numbers
class Solution {
public:
const long long MOD = 1e9 + 7;
    long long pow(long long x, long long n) {
        if(n == 0) return 1;
        if(n == 1) return x % MOD;

        long long half = pow(x, n/2);

        if(n%2==0) return (half*half) % MOD;
        else return (half*half*x) % MOD; 
    }
    long long countGoodNumbers(long long n) {
        return (pow(5, (n+1)/2) * pow(4, n/2)) % MOD;
    }
};


22. Generate Parentheses

<----------------------BASIC APPROACH---------------------->
class Solution {
public:

    bool isValid(string& curr) {
        int count = 0;

        for(char ch : curr) {
            if(ch == '(') count++;
            else count--;

            if(count < 0) return false;
        }
        return count == 0;
    }

    void solve(string& curr, int n) {
        if(curr.size() == 2*n) {
            if(isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }

    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(curr, n);

        return result;
    }
};



<----------------------OPTIMISED APPROACH---------------------->

class Solution {
public:
    void solve(string& curr, int n, int open, int close) {
        if(curr.size() == 2*n) {
            result.push_back(curr);
            return;
        }

        if(open < n) {
            curr.push_back('(');
            solve(curr, n, open+1, close);
            curr.pop_back();
        }

        if(open > close) {
            curr.push_back(')');
            solve(curr,n, open, close+1);
            curr.pop_back();
        }
    }

    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string curr = "";

        int open = 0;
        int close = 0;
        solve(curr, n, open, close);

        return result;
    }
};












*/