//Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
#include <bits/stdc++.h>
using namespace std;
void backtrack(vector<int> &nums, vector<int> &permu, vector<vector<int>> &result, map<int, int> temp)
{
    if (permu.size() == nums.size())
    {
        result.push_back(permu);
        // If the temporary permutation size becomes equal to the size of nums
        return;
    }
    for (auto i : temp)
    // We are iterating over unique elements only(avoiding duplication)
    {
        if (i.second > 0)
        // If the count of that element in the map is not 0
        {
            permu.push_back(i.first);
            // Pushing the element
            temp[i.first] -= 1;
            // Reducing the frequency of the pushed element
            backtrack(nums, permu, result, temp);
            // Calling the backtrack function
            permu.pop_back();
            // Popping out the last element from the temporary permutation
            temp[i.first] += 1;
            // replenishing the frequency of the elements in the nums
            // for finding future permutations
        }
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<int> permu;
    // Temporary permutation storage
    vector<vector<int>> result;
    // For storing unique permuatations
    map<int, int> count;
    // This map stores the frequency of all the elements in the nums
    for (auto i : nums)
    {
        count[i]++;
    }
    backtrack(nums, permu, result, count);
    return result;
}

// Other Optimized Solution

void RecursiveCalls(vector<vector<int>> &result, vector<int> &temp, vector<bool> isVisited, vector<int> &nums)
{
    if (temp.size() == nums.size())
    {
        result.push_back(temp);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (isVisited[i])
            continue;
        // If the number is already visited before
        if (i && nums[i - 1] == nums[i] && !isVisited[i - 1])
            // This statement is used for not including dupicates
            continue;
        // If the current num is not equal to previous no
        isVisited[i] = true;
        // Making the num visited
        temp.push_back(nums[i]);
        RecursiveCalls(result, temp, isVisited, nums);
        temp.pop_back();
        isVisited[i] = false;
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> temp;
    vector<bool> isVisited(nums.size(), false);
    sort(nums.begin(), nums.end());
    RecursiveCalls(result, temp, isVisited, nums);
    return result;
}