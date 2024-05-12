class Solution {

private:

    int PrefixSize = 0; // количество начальных нулей
    int SuffixSize = 0; // максимальное количетство нулей, отличных от начальных и конечных
    int EndingSize = 0; // количество конечных нулей. Также выступает в качестве буффера для EndingSize преследуя цель максимизации

public:
    int maxDistToClosest(vector<int>& seats) {
        
        
        for(int seat : seats){ // обрабатываем случай ведущих нулей, например: [0,0,0,0,0,1,0,0,0]
            if(seat){break;}
            ++PrefixSize;
        }

        
        for(int i = PrefixSize + 1; i<seats.size(); ++i){

            if(!seats[i]){ // место свободно, заносим информацию в буффер
                ++EndingSize;
            }
            else{
                SuffixSize = max(SuffixSize, EndingSize);
                EndingSize = 0; // обнуляем буффер для после
            }

        }

        SuffixSize = ((SuffixSize%2) ? SuffixSize/2 + 1: SuffixSize/2); // расстояние между Алексом и ближайшим к нему человеком, при условии, что Алекс сидит между двумя людьми
        return max({PrefixSize,SuffixSize ,EndingSize}); // https://en.cppreference.com/w/cpp/algorithm/max – см. 3-4
    }
};