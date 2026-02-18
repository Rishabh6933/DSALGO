// 401. Binary Watch
// class Solution {
// public:
//     vector<string> readBinaryWatch(int turnedOn) {
//         vector<string> ans;
//         for(int h=0; h<=11; h++) {
//             for(int m=0; m<=59; m++) {
//                 if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
//                     string time = to_string(h) + ':';
//                     if(m<10) time += "0";
//                     time += to_string(m);
//                     ans.push_back(time);
//                 }
//             }
//         }
//         return ans;
//     }
// };


// 693. Binary Number with Alternating Bits

// <--------------APPROACH 1-------------->
// class Solution {
    // public:
    //     bool hasAlternatingBits(int n) {
        //         int currbit = n%2;
        //         n = n/2;
        //         while(n>0) {
            //             if(currbit == n%2) return false;
            //             currbit = n%2;
//             n = n/2;
//         }
//         return true;
//     }
// };


// <--------------APPROACH 2-------------->
// This will produce a number with all set bits equal to 1
//                 result = n ^ (n>>1)
// and then we will do (result & (result+1))
// this will make it equal to zero then then the given number have
// alternating bits

//              n     =      1   0   1   0   1
//             n>>1   =      0   1   0   1   0
// result=n ^ (n>>1)  =      1   1   1   1   1
//          (result+1)=      0   0   0   0   1  
// result & (result+1)=      0   0   0   0   0     



// class Solution {
// public:
//     bool hasAlternatingBits(int n) {
//         long long result = n ^ (n>>1);
//         if((result & (result+1)) == 0) return true;
//         return false;
//     }
// };