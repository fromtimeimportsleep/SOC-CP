#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        int req_index = (n+1)/2;

        if (n1 > n2) {return findMedianSortedArrays(nums2,nums1);}
         
        if (n1 == 0){   //Edge case
            if (n2 % 2 == 0) {return (nums2[n2/2] + nums2[n2/2-1])/2.0;}
            else {return nums2[n2/2];}
        }

        int left1 = 0;
        int right1 = n1;
        int partition_1, partition_2;
        int l1, r1, l2, r2;
        
        
        while (left1 <= right1) {   

            partition_1 = (left1+right1)/2;
            partition_2 = req_index-partition_1;
    
            if (partition_1 == 0) {l1 = INT_MIN;} else {l1 = nums1[partition_1-1];}
            if (partition_2 == 0) {l2 = INT_MIN;} else {l2 = nums2[partition_2-1];}
            if (partition_1 >= n1) {r1 = INT_MAX;} else {r1 = nums1[partition_1];}            
            if (partition_2 >= n2) {r2 = INT_MAX;} else {r2 = nums2[partition_2];}
            
            //binary search
            if (l1 <= r2 && l2 <= r1) { // first half of list is found
                if (n % 2 == 0) {return (max(l1, l2) + min(r1, r2)) / 2.0;}
                else {return max(l1, l2);}
            }
            else {
                if (l1 > r2) {right1 = partition_1 - 1;}
                else {left1 = partition_1 + 1;}
            }
        }
        return 0;            
    }
};
