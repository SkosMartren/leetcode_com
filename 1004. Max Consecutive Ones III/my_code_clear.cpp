class Solution {
public:
    int longestOnes(vector<int>& nums, int CountUpdZero) {       

        int L_Idx_Longest_Subarray = -1; 
        int R_Idx_Longest_Subarray = -1;        
        
        int Ans = 0;

        for(int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow < nums.size(); ++RightBorderWindow){ // сдвиг правого указателя

            if(nums[RightBorderWindow] == 0){--CountUpdZero;}

            while(CountUpdZero < 0){ // сдвиг левого указателя
                if(nums[LeftBorderWindow++] == 0){++CountUpdZero;}
            }

            // В отрезке [LeftBorderWindow, RightBorderWindow] содержится максимум CountUpdZero нулей
            if(Ans < RightBorderWindow - LeftBorderWindow  + 1){

                L_Idx_Longest_Subarray = LeftBorderWindow;
                R_Idx_Longest_Subarray = RightBorderWindow;

                Ans = RightBorderWindow - LeftBorderWindow + 1;
            }
        }
        
        if(L_Idx_Longest_Subarray == -1){ /*Когда такое происходит??*/ return 0;}
        else {assert(Ans == R_Idx_Longest_Subarray - L_Idx_Longest_Subarray + 1);}

        return Ans;
    }
};
