class Solution {

private:

public:
    int findMaxConsecutiveOnes(vector<int>& nums, int CountUpdZero = 0) {
        
        int L_Idx_Longest_Subarray = -1; 
        int R_Idx_Longest_Subarray = -1;        
        
        int Ans = 0;

        for(int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow < nums.size(); ++RightBorderWindow){ // сдвиг правого указателя

            if(nums[RightBorderWindow] == 0){--CountUpdZero;}

            while(CountUpdZero < 0){ // сдвиг левого указателя
                if(nums[LeftBorderWindow++] == 0){++CountUpdZero;}
            }

            
            if(Ans < RightBorderWindow - LeftBorderWindow  + 1){

                L_Idx_Longest_Subarray = LeftBorderWindow;
                R_Idx_Longest_Subarray = RightBorderWindow;

                Ans = RightBorderWindow - LeftBorderWindow + 1;
            }
        }
        
        if(L_Idx_Longest_Subarray == -1){return 0;}
        else {assert(Ans == R_Idx_Longest_Subarray - L_Idx_Longest_Subarray + 1);}

        return Ans;        

    }
};
