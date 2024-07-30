/*
arr = [1,2,3,5,11], k = 3, x = 4
Expected [2,3,5]

arr = [1,2,3,(4),5,11]

*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        if (arr.size() == k) {
            return arr;
        }
        
        // Find the position where x would be inserted to keep the array sorted
        auto it = ranges::upper_bound(arr, x);
        int idx = it - arr.begin();
        
        // Initialize left and right pointers
        int left = idx - 1;
        int right = idx;

        // Find the k closest elements
        while (k > 0) {
            if (left < 0) {
                ++right;
            } else if (right >= arr.size()) {
                --left;
            } else if (x - arr[left] <= arr[right] - x) {
                --left;
            } else {
                ++right;
            }
            --k;
        }

        // Return the k closest elements
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};