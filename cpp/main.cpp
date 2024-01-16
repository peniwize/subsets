/*!
    \file "main.cpp"

    Author: Matt Ervin <matt@impsoftware.org>
    Formatting: 4 spaces/tab (spaces only; no tabs), 120 columns.
    Doc-tool: Doxygen (http://www.doxygen.com/)

    https://leetcode.com/problems/subsets/
*/

//!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/main.md
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"

class Solution {
public:
    /*
        Given an integer array nums of unique elements, 
        return all possible subsets (the power set).

        The solution set must not contain duplicate subsets.
        Return the solution in any order.

        -----------------------------------------------------

        This is just an algorithm that produces all possible
        combinations (without replacement) of the set.
        For an example set of three unique items, this is
        3C0 + 3C1 + 3C2 + 3C3:
        [a b c] => [ []
                     [a]
                     [a b]
                     [a b c]
                     [a c]
                     [b]
                     [b c]
                     [c]
                   ]
    
        2^0:                             [- - -] 
        2:1:             [- - -]                         [a - -] 
        2^2:     [- - -]         [- b -]         [- - -]         [- b -] 
        2^3: [- - -] [- - c] [- - -] [- - c] [- - -] [- - c] [- - -] [- - c]
                |       |       |       |       |       |       |       |
                V       V       V       V       V       V       V       V
                []     [c]     [b]     [bc]    [a]     [ac]    [ab]   [abc]

        There are 2^(n+1)-1 nodes in the tree.

        Time = O(2^(n+1)-1)/2) => O(2^n)  [1/2 number of nodes in tree]

        Space = O(n) [number of levels in tree)
    */
    void allCombinations(
        vector<int> const& nums
        , vector<vector<int>>& result
        , vector<int>& combo
        , vector<int>::size_type numsIdx = 0
    ) {
        if (nums.size() > numsIdx) {
            for (vector<int>::size_type idx = numsIdx; nums.size() > idx; ++idx) {
                combo.push_back(nums[idx]);
                result.push_back(combo);
                allCombinations(nums, result, combo, idx + 1);
                combo.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int> const& nums) {
        vector<vector<int>> result{{}};
        vector<int> combo{};
        allCombinations(nums, result, combo);
        return result;
    }
};

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

TEST_CASE("Case 1")
{
    cerr << "Case 1" << '\n';
    auto const nums = vector<int>{1,2,3};
    auto expected = vector<vector<int>>{{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}};
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto result =  Solution{}.subsets(nums);
        for (auto& set : expected) {
            sort(set.begin(), set.end());
        }
        sort(expected.begin(), expected.end());
        for (auto& set : result) {
            sort(set.begin(), set.end());
        }
        sort(result.begin(), result.end());
        CHECK(result == expected);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 1")
{
    cerr << "Case 1" << '\n';
    auto const nums = vector<int>{0};
    auto expected = vector<vector<int>>{{},{0}};
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto result =  Solution{}.subsets(nums);
        for (auto& set : expected) {
            sort(set.begin(), set.end());
        }
        sort(expected.begin(), expected.end());
        for (auto& set : result) {
            sort(set.begin(), set.end());
        }
        sort(result.begin(), result.end());
        CHECK(result == expected);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

/*
    End of "main.cpp"
*/
