class Solution {
public:

    vector<int> twoSum(const vector<int>& a, int target) {

        int j = (int)a.size() - 1;

        for (int i = 0; i < (int)a.size(); i++) {

            while (j >= 0 && a[i] + a[j] > target) {j--;}

            assert(i < j);

            if (a[i] + a[j] == target) {return { i + 1, j + 1 };}
        }

        throw invalid_argument("no sum target");
    }

};
