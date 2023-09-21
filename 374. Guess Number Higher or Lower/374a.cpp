/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n; // [low, high] 
        while (low < high) {
            int mid = low + (high - low) / 2;
            int ans = guess(mid);
            if (ans < 0) {
                high = mid - 1;
            }
            else if (ans > 0) {
                low = mid + 1;
            }
            else {
                assert(ans == 0);
                return mid;
            }
        }
        assert(low == high);
        return low;
    }
};
