#include <iostream>
#include <vector>

// https://leetcode.com/problems/surrounded-regions :
void xSurroundedRegions(std::vector<std::vector<char>> &board);

// https://leetcode.com/problems/4sum-ii :
int fourSumCount(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C, std::vector<int> &D);

// https://leetcode.com/problems/permutations:
std::vector<std::vector<int>> permute(const std::vector<int>& nums);

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<std::vector<char>> board = {
            {'O','X','X','O','X'},
            {'X','O','O','X','O'},
            {'X','O','X','O','X'},
            {'O','X','O','O','O'},
            {'X','X','O','X','O'}
    };
    xSurroundedRegions(board);

    std::vector<int> a = {1, 2}, b = {-2, -1}, c = {-1, 2}, d = {0, 2};
    fourSumCount(a, b, c, d);

    permute({1,2,3});
}