// Sum of Two Integers ------> Key Concept: Binary Addition
// When adding two numbers in binary:

// XOR (^) gives the sum without carry
// AND (&) finds positions where both bits are 1 (carry positions)
// Left shift (<< 1) moves carry to the next position

// <--------------SOLUTION-------------->

// class Solution {
// public:
//     int getSum(int a, int b) {
//         while(b!=0) {
//             unsigned int carry = (unsigned int)(a&b) << 1;

//             a = a^b;
//             b = carry;
//         }
//         return a;
//     }
// };

// Number of 1 Bits

// <--------------BASIC SOLUTION-------------->
// class Solution {
    // public:
    //     int hammingWeight(int n) {
        //         int count=0;
        //         while(n>0) {
            //             int rem = n%2;
            //             if(rem==1) count++;
            //             n = n/2;
            
            //         }
            //         return count;
            //     }
            // };
            
            
// <--------------OPTIMISED SOLUTION-------------->

// ############ KEY INSIGHT ############
//              n = n & (n-1)
// “Using n & (n−1) removes the lowest set bit each iteration,
//  so the loop runs only for the number of set bits.”
// class Solution {
// public:
//     int hammingWeight(int n) {
//         int count = 0;
//         while(n!=0) {
//             n = n & (n-1);
//             count++;
//         }
//         return count;
//     }
// };




// Counting Bits

// <--------------BASIC SOLUTION-------------->
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans;
//         for(int j=0; j<=n; j++) {
//             int i = j;
//             int count=0;
//             while(i!=0) {
//                 i = i & (i-1);
//                 count++;
//             }
//             ans.push_back(count);
//         }
//         return ans;
//     }
// };
            
// <--------------OPTIMISED SOLUTION-------------->

// ############ KEY INSIGHT ############
// for odd the number of bits are 1 + (number of bits in oddnum/2)
// for even number the number of bits are equal to evennum/2

// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans;
//         ans.push_back(0);
//         for(int i=1; i<=n; i++) {
//             ans.push_back(ans[i/2] + i%2);
//         }
//         return ans;
//     }
// };


// MISSING NUMBER
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int sum1 = 0;
//         int sum2 = 0;
//         int n = nums.size();
//         for(int i=0; i<n; i++) {
//             sum1 = sum1 + nums[i];
//         }
//         while(n>=0) {
//             sum2 += n;
//             n--;
//         }
//         return sum2 - sum1;
//     }
// };

// OPTIMAL SOLUTION
// ###############   0^a = a & a^a = 0
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int xor1 = 0;   // xor for elements in nums
//         int xor2 = 0;
//         for(int i=0; i<n; i++) {
//             xor1 = xor1 ^ nums[i];
//             xor2 = xor2 ^ (i+1);
//         }
//         return xor1^xor2;
//     }
// };