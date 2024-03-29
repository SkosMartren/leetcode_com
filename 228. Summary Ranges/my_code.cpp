class Solution {
public:
    vector<string> summaryRanges(const vector<int>& nums) {

        vector<string> ans; 
        ans.reserve(nums.size()); // худший случай: [1, 3, ..., 2n + 1] -- не будет ни одного склеивания

        for (int i = 0; i < nums.size(); ++i) {

            const int start_ranges = nums[i];

            // while (i + 1 < nums.size() && nums[i + 1]  - nums[i] == 1) { ++i; } // error:
            //  nums[i] < nums[i+1] --> в 1 + nums[i] переполнения не будет, в то
            // время как в nums[i + 1]  - nums[i]  будет, например 
            // Runtime Error 24 / 32 testcases passed nums = [-2147483648,-2147483647,2147483647]
            // при подсчете 2147483647 - (-2147483647)
            // правильнее даже будет так: 
            // while (i + 1 < nums.size() && nums[i] == nums[i + 1] - 1) { ++i; }
            // <-->
            // for (;i + 1 < nums.size() && nums[i + 1]  - 1 == nums[i]; ++i);
            while (i + 1 < nums.size() && nums[i + 1] == 1 + nums[i]) { ++i; } // в крайнем случае после выхода из этого цикла i указывает на nums.back() -- т.е. на индекс i == nums.size() - 1

            if (start_ranges != nums[i]) { // "Each range [a,b] in the list should be output as: "a->b" if a != b "a" if a == b"
                ans.push_back(to_string(start_ranges) + "->" + to_string(nums[i]));
            }
            else {
                ans.push_back(to_string(start_ranges));
            }

        }

        ans.shrink_to_fit();
        return ans;
    }

};
/*
nums.size() = 6
* == i
^ == i + 1

i   :         *
idxs: 0 1 2 3 4 5
nums: 0 1 2 4 5 6
                ^

i   :           *
idxs: 0 1 2 3 4 5
nums: 0 1 2 4 5 6
                  ^
*/
