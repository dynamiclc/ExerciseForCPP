//
// main.cpp
// HelloWorld
//
// Created by Cong Liu on 1/20/14.
// Copyright (c) 2014 domainname. All right reserved.
//

//============================================================================
// Distinct Subsequences
// Given a string S and a string T, count the number of distinct subsequences
// of T in S.
//
// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters, i.e., "ACE" is a
// subsequence of "ABCDE" while "AEC" is not.
//
// Here is an example:
// S = "rabbbit", T = "rabbit"
//
// Return 3.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		int lengthS = (int) S.size();
		int lengthT = (int) T.size();

		// Special cases
		if (0 == lengthS || 0 == lengthT) {
			return 0;
		}

		// Allocate memory for dp matrix index 0 should never be used
		int dp[10 + 1][10 + 1];

		// Boundary values at [1][1]
		if (T[1] == S[1]) {
			dp[1][1] = 1;
		} else {
			dp[1][1] = 0;
		}

		// Boundary values for row one
		for (int j = 2; j <= lengthS; j++) {
			if (T[1] == S[j]) {
				dp[1][j] = dp[1][j - 1] + 1;
			} else {
				dp[1][j] = dp[1][j - 1];
			}
		}

		// Boundary values for dp[i][j] where j < i
		for (int i = 2; i <= lengthT; i++) {
			for (int j = 1; j < i; j++) {
				dp[i][j] = 0;
			}
		}

		// Transition
		for (int i = 2; i <= lengthT; i++) {
			for (int j = i; j <= lengthS; j++) {
				if (T[i] == S[j]) {
					dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
				} else {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}

		// Return final answer
		return dp[lengthT][lengthS];
	}
};

int main(int argc, const char *argv[]) {
	Solution *s = new Solution();
	cout << "The number of distinct subsequence is "
		 << s->numDistinct("rabbbit", "rabbit")
		 << ".\n";
	delete s;
	return 0;
}
