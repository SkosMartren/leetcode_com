// https://leetcode.com/problems/add-strings/solutions/2808140/c-grade-1-addition-technique/
class Solution {
public:
    string addStrings(string num1, string num2) {
 int i = num1.size() - 1;
    int j = num2.size() - 1;

    // carry -- для переноса элемента из низшего в высший разряд
    int carry = 0;
    string ans = "";

    while (i >= 0 || j >= 0 || carry) {

        int sum = 0;

        if (i >= 0) {
            sum += (num1[i] - '0');
            --i;
        }

        if (j >= 0) {
            sum += (num2[j] - '0');
            --j;
        }

        sum += carry;

        carry = sum / 10;


        ans += to_string(sum % 10);
    }

    reverse(ans.begin(), ans.end());
    return ans;
    }
};
