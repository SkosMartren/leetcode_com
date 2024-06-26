class Solution {
public:
    int maxPower(string_view s) {

        int LenSub = 1;

        //l - левый указатель 
        //r - правый указатель

        // можно без "-1" в условие выхода
        for (int l = 0, r = l + 1; l < s.size() - 1; ++l) { // for (int l = 0, r = l; l < s.size(); ++l) { // good!

            if (s[l] == s[r]) {

                while (r < s.size() && s[l] == s[r]) { ++r; }

                LenSub = max(LenSub, r - l); // почему не r - l + 1? Потому что r указывает за "substring that contains only one unique character."

                l = r - 1; // "- 1" так как после выхода их if значение l инкрементируется в цикле for, при этом в начале следующей итреации цикла l должен быть на том месте, где с прошлой итерации остался r указатель         
            }
        }

        return LenSub;
    }
};
