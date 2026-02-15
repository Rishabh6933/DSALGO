

// // 2Sum
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<pair<int, int>> indexed_nums;
//         for(int i =0; i<nums.size(); i++) {
//             indexed_nums.push_back({nums[i], i});
//         }
//         sort(indexed_nums.begin(), indexed_nums.end());
        
//         int start = 0;
//         int end = nums.size()-1;
//         int sum = 0;

//         while(start < end) {
//             sum = indexed_nums[start].first + indexed_nums[end].first;
//             if(sum > target)
//                 end--;
//             else if(sum < target)
//                 start++;
//             else 
//                 return {indexed_nums[start].second, indexed_nums[end].second};
//         }
//         return {};
//     }
// };




// Best time to buy and sell stocks
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxPro = 0;
//         int mini = prices[0];
//         for(int i = 1; i<prices.size(); i++) {
//             maxPro = max(maxPro, prices[i]-mini);
//                                       SELL-BUY
//             mini = min(mini,prices[i]);
//         }
//         return maxPro;
//     }
// };



// Contains Duplicate
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for(int x: nums) mp[x]++;
//         for(int x: nums)
//             if(mp[x] >= 2 ) return true;
//         return false;
//     }
// };



// Product of Array Except Self


    //     i/p =    1   2   3   4       NUMS
    // approach=    1   1   2   6       prefix (LEFT)
    //             24   12  4   1       suffix (RIGHT)
    //             24   12  8   6       answer  = prefix * suffix

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n,1);
//         vector<int> left(n,1);
//         vector<int> right(n,1);
 
//         // PREFIX   
//         for(int i=1; i<n; i++) {
//             left[i] = left[i-1] * nums[i-1];
//         }

//         // SUFFIX
//         for(int i=n-2; i>=0; i--) {
//             right[i] = right[i+1] * nums[i+1];
//         }

//         // ANSWER
//         for(int i=0; i<n; i++) {
//             ans[i] = left[i] * right[i];
//         }
//         return ans;
//     }
// };


// Maximum Subarray
// <----------------------KADANE'S ALGORITHM---------------------->
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         int maximum = INT_MIN;
//         for(int i=0; i<n; i++) {
//             sum += nums[i];
//             maximum = max(sum, maximum);
//             if(sum < 0) sum = 0;
//         }
//         return maximum;
//     }
// };


// Maximum Product Subarray

// solve for 
        // 1. only +ve
        // 2. even negative, +ve 
        // 3. odd negative, +ve 
        // 4. has zeros

// only 3 and 4 will cause problem so handle them
    // for odd negative number we will calculate the product from left side of the negative number i.e prefix
    // and from right side of the negative number i.e suffix

    // for zeros we will befircate the array into different parts from that position and calculate the product


// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int maximum = INT_MIN;
//         int prefix = 1;
//         int suffix = 1;

//         for(int i =0; i<n; i++) {
//             if(prefix == 0) prefix = 1;
//             if(suffix == 0) suffix = 1;

//             prefix *= nums[i];
//             suffix *= nums[n-i-1];
//             maximum = max(prefix, max(suffix, maximum));
//         }
//         return maximum;
//     }
// };


// Find Minimum in Rotated Sorted Array
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int n = nums.size();
//         int low=0; 
//         int high=n-1;
//         int ans = INT_MAX;
//         while(low <= high) {
//             int mid = (low+high)/2;
//             if(nums[low] <= nums[high]) {
//                 ans = min(nums[low], ans);
//                 return ans;
//             }
//             if( nums[low] <= nums[mid]) {
//                 ans = min(nums[low], ans);
//                 low = mid + 1;
//             }
//             else {
//                 ans = min(nums[mid], ans);
//                 high = mid - 1;
//             }
//         }
//         return ans;
//     }
// };


// Search in Rotated Sorted Array
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int left = 0;
//         int right = n-1;
//         while(left <= right) {
//             int mid = (left+right)/2;
//             if(nums[mid] == target) return mid;

//             if(nums[left] <= nums[mid]) {
//                 // left half sorted
//                 if(target >= nums[left] && target <= nums[mid]) {
//                     right = mid-1;
//                 }
//                 else {
//                     left = mid+1; 
//                 }
//             }
//              else {
//                 // right half sorted
//                 if(target >= nums[mid] && target <= nums[right]) {
//                     left = mid+1;
//                 }
//                 else {
//                     right = mid-1;
//                 }
//             }

//         }
//         return -1;   
//     }
// };