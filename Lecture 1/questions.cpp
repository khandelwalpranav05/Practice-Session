#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

// 11. Container With Most Water

int maxArea(vector<int>& height) {

	int left = 0;
	int right = height.size() - 1;

	int maxWater = 0;

	while (left < right) {

		int minHeight = min(height[left], height[right]);

		int gap = right - left;

		int currWater = gap * minHeight;
		maxWater = max(currWater, maxWater);

		if (height[left] == height[right]) {

			if (height[left + 1] > height[right - 1]) {
				left++;
			} else {
				right--;
			}

		} else if (height[left] < height[right]) {
			left++;
		} else {
			right--;
		}

	}

	return maxWater;
}

// 283. Move Zeroes

void moveZeroes(vector<int>& nums) {

	int left = 0;
	int right = 0;

	while (right < nums.size()) {
		if (nums[right] == 0) {
			right++;
		} else {
			nums[left] = nums[right];
			left++;
			right++;
		}
	}

	while (left < nums.size()) {
		nums[left] = 0;
		left++;
	}
}

// 122. Best Time to Buy and Sell Stock II

int maxProfit(vector<int>& prices) {
	if (prices.size() == 0) {
		return 0;
	}

	int profit = 0;

	for (int i = 0; i < prices.size() - 1; i++) {

		int currProfit = prices[i + 1] - prices[i];

		currProfit = max(0, currProfit);

		profit += currProfit;
	}

	return profit;
}

// 991. Broken Calculator

int brokenCalc(int X, int Y) {
	if (X >= Y) {
		return (X - Y);
	}

	if (Y & 1) {
		return 1 + brokenCalc(X, Y + 1);
	} else {
		return 1 + brokenCalc(X, Y / 2);
	}
}

// 75. Sort Colors

void sortColors(vector<int>& nums) {

	int arr[3] = {0};

	for (int num : nums) {
		arr[num]++;
	}

	int idx = 0;

	for (int i = 0; i < nums.size(); i++) {
		while (arr[idx] == 0) {
			idx++;
		}

		nums[i] = idx;
		arr[idx]--;
	}
}

// 209. Minimum Size Subarray Sum

int minSubArrayLen(int s, vector<int>& nums) {

	int minValue = INT_MAX;

	int n = nums.size();

	int left = 0;
	int right = 0;

	int sum = 0;

	while (right < n) {
		sum += nums[right];

		while (sum >= s) {
			int currLength = right - left + 1;
			minValue = min(minValue, currLength);
			sum -= nums[left];
			left++;
		}

		right++;
	}

	return minValue == INT_MAX ? 0 : minValue;
}

// 392. Is Subsequence

bool isSubsequence(string s, string t) {
	if (s.length() == 0) {
		return true;
	}

	int idx = 0;

	for (int i = 0; i < t.length(); i++) {
		if (t[i] == s[idx]) {
			idx++;
		}

		if (idx == s.length()) {
			return true;
		}
	}

	return false;
}

// 55. Jump Game GREEDY

bool canJump(vector<int>& nums) {

	int curr = -1;

	for (int i = 0; i < nums.size(); i++) {
		curr = max(nums[i], curr);

		if (curr == 0) {
			if (i == nums.size() - 1) {
				return true;
			} else {
				return false;
			}
		}

		curr--;
	}

	return true;
}

// 55. Jump Game DP

bool helper(vector<int> &nums, int si, vector<int> &dp) {
	if (si >= nums.size() - 1) {
		return true;
	}

	if (dp[si] != -1) {
		return dp[si];
	}

	int jump = nums[si];

	if (jump == 0) {
		return false;
	}

	bool possible = false;

	for (int i = 1; i <= jump; i++) {
		bool recursionResult = helper(nums, si + i, dp);

		if (recursionResult) {
			possible = true;
		}
	}

	dp[si] = possible;

	return possible;
}

bool canJump(vector<int>& nums) {
	if (nums.size() == 1) return true;

	int n = nums.size() + 1;

	vector<int> dp(n, -1);

	return helper(nums, 0, dp);
}

// 169. Majority Element

int majorityElement(vector<int>& nums) {

	int count = 1;
	int ele = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		if (count == 0) {
			ele = nums[i];
		}

		if (nums[i] == ele) {
			count++;
		} else {
			count--;
		}
	}

	return ele;
}

int main() {


	return 0;
}