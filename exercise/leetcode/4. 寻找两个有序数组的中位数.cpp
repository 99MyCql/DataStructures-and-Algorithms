/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> n1;
    vector<int> n2;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        int n1_start = 0, n1_end = n1.size(), n2_start = 0, n2_end = n2.size();
        int n1_mid = 0, n2_mid = 0;
        bool n1_mid_find = false, n2_mid_find = false; // n1, n2是否找到中位数
        if (n1_start == n1_end) {
            return n2_end%2 == 0? (n2[n2_end/2-1]+n2[n2_end/2])/2.0 : n2[n2_end/2];
        }
        if (n2_start == n2_end) {
            return n1_end%2 == 0? (n1[n1_end/2-1]+n1[n1_end/2])/2.0 : n1[n1_end/2];
        }
        while (!n1_mid_find || !n2_mid_find) {
            if (!n1_mid_find) n1_mid = (n1_start + n1_end) / 2;
            if (!n2_mid_find) n2_mid = (n2_start + n2_end) / 2;
            if (n1[n1_mid] < n2[n2_mid]) {
                n1_start = n1_mid;
                n2_end = n2_mid;
            }
            else {
                n1_end = n1_mid;
                n2_start = n2_mid;
            }
            if (n1_end - n1_start <= 1) {
                n1_mid_find = true;
            }
            if (n2_end - n2_start <= 1) {
                n2_mid_find = true;
            }
        }
        printf("%d %d", n1[n1_mid], n2[n2_mid]);

        if ((n1.size() + n2.size())%2 == 0) {
            return (n1[n1_mid] + n2[n2_mid]) / 2.0;
        }
        else {
            return n1[n1_mid] < n2[n2_mid] ? n1[n1_mid] : n2[n2_mid];
        }
    }
};


#include <queue>
#include <functional>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        bool isOdd = true;
        if ((m+n)%2 == 0) isOdd = false;

        int k = (m+n)/2;
        if (isOdd) k++;

        if (m == 0) {
            if (isOdd) return nums2[k-1];
            return (nums2[k-1]+nums2[k])/2.0;
        }
        if (n == 0) {
            if (isOdd) return nums1[k-1];
            return (nums1[k-1]+nums1[k])/2.0;
        }

        int s1 = 0, s2 = 0;
        while (k > 1) {
            int p = k/2, i = s1+p-1, j = s2+p-1;
            if (i >= m) {
                i = m-1;
            }
            if (j >= n) {
                j = n-1;
            }
            if (nums1[i] <= nums2[j]) {
                k -= (i-s1+1);
                s1 = i+1;
                if (s1 == m) {
                    if (isOdd) return nums2[s2+k-1];
                    return (nums2[s2+k-1]+nums2[s2+k])/2.0;
                }
            } else {
                k -= (j-s2+1);
                s2 = j+1;
                if (s2 == n) {
                    if (isOdd) return nums1[s1+k-1];
                    return (nums1[s1+k-1]+nums1[s1+k])/2.0;
                }
            }
        }

        // 为了能够处理一些边界情况
        // 比如：
        // nums1:[], nums2:[1]
        // nums1:[1,2], nums2:[-1,3]
        priority_queue< int, vector<int>, greater<int> > q;
        for (int i = 0; i < 2 && s1+i < m; i++) {
            q.push(nums1[s1+i]);
        }
        for (int i = 0; i < 2 && s2+i < n; i++) {
            q.push(nums2[s2+i]);
        }
        if (isOdd) return q.top();
        int a = q.top();
        q.pop();
        int b = q.top();
        return (a+b)/2.0;
    }
};