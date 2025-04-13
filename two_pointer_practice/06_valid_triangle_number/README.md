# Valid Triangle Number

## Problem
Given an integer array, return the number of triplets that can form a triangle (a + b > c).

## Approach
Sort the array. For each pair (i, j), use two-pointer to find the furthest `k` such that `nums[i] + nums[j] > nums[k]`.

## Complexity
Time: O(n^2), Space: O(1)
