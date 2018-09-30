/*
 * Problem: https://leetcode.com/problems/4sum-ii
 *
 * This can be solved in 2 steps:
 * 1. For each pair of values (A_i, B_j) from A and B count the number of occurrences of A_i + B_j and store the results
 * in a hash map/table. -- O(n^2).
 * 2. For each pair of values (C_i, D_j) look up -(C_i + D_j) in the map and sum up the values to get the total number
 * of ways to get zero 4 sum. -- O(n^2)
 */

#include <vector>
#include <unordered_map>

int fourSumCount(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C, std::vector<int> &D) {
    std::unordered_map<int, int> abSums;
    abSums.reserve(A.size() * B.size());
    for (const int a : A) {
        for (const int b : B) {
            abSums[a + b]++;
        }
    }
    int zeroSumFourletsCount = 0;
    for (const int c : C) {
        for (const int d : D) {
            auto res = abSums.find(-(c + d));
            if (res != abSums.end()) zeroSumFourletsCount+=res->second;
        }
    }
    return zeroSumFourletsCount;
}
