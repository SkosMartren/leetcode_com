class Solution {

    unsigned* getKoef() {
        static unsigned koef[1 + 'z'] = {};
        if (koef[0] == 0) {
            mt19937 gen(2202);
            for (char c = 'a'; c <= 'z'; c++) {
                koef[c] = uniform_int_distribution<unsigned>(1e9, 2e9)(gen);
            }
        }
        return koef;
    }

public:

    vector<int> findAnagrams(string_view s, string_view p) {
        
        if (s.size() < p.size()) {return {};}
        
        vector<int> ans;
        unsigned* koef = getKoef();
        
        unsigned sum = 0; // char of p -, chars of s +, multiply by koef 
        
        for (char c : p) {
            sum -= koef[c];
        }
        
        for (int i = 0; i < (int)p.size(); i++) {
            char c = s[i];
            sum += koef[c];
        }
        
        if (sum == 0) {ans.push_back(0);}
        
        for (int i = (int)p.size(); i < (int)s.size(); i++) {
            
            const char toRemove = s[i - (int)p.size()];
            const char toAdd = s[i];
            
            sum -= koef[toRemove];
            sum += koef[toAdd];
            
            if (sum == 0) {ans.push_back(i - (int)p.size() + 1);}
        }
        
            return ans;
    }
    
};
