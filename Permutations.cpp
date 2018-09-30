/*
 * Problem: https://leetcode.com/problems/permutations
 *
 * Lets lousily define permutations recursively as following:
 * B.C. permutations of [] are: [[]]
 * I.S. permutations os [a_1, a_2, ..., a_n] are: insert a_n into all possible places of all permutations of
 * [a_1, a_2, ... a_{n-1}]
 */

#include <vector>

std::vector<std::vector<int>> permute(const std::vector<int>& nums, size_t i) {
    if (i == 0) {
        std::vector<int> new_perm;
        new_perm.reserve(nums.size());
        new_perm.push_back(nums[0]);
        return {new_perm};
    }
    std::vector<std::vector<int>> perms = permute(nums, i - 1);
    std::vector<std::vector<int>> res;
    res.reserve(i * perms.size());
    for (std::vector<int> &perm : perms) {
        size_t perm_size = perm.size();
        for (size_t j = 0; j < perm_size; j++) {
            std::vector<int> new_perm;
            new_perm.reserve(nums.size());
            new_perm.insert(new_perm.end(), perm.begin(), perm.begin() + j);
            new_perm.push_back(nums[i]);
            new_perm.insert(new_perm.end(),  perm.begin() + j, perm.end());
            res.push_back(std::move(new_perm));
        }
        perm.push_back(nums[i]);
        res.push_back(std::move(perm));
    }
    return res;
}

std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
    if (nums.empty()) {
        return {{}};
    }
    return permute(nums, nums.size() - 1);
}


