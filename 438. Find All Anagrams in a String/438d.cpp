class Solution {

    // вместо long long* можно использовать тип auto, если затруднительно указать тип
    long long* getKoef() {
        static long long koef[1 + 'z'] = {};
        if (koef[0] == 0) {
            mt19937 gen(2202);
            for (char c = 'a'; c <= 'z'; c++) {
                //koef[c] = uniform_int_distribution<unsigned>(0, 50)(gen); // при таком распределении можно удачно увидеть коллизию: 61 / 65 testcases passed
                // -- sum будет равен нулю для двух строк, которые не являются анаграммами. При этом, если поменять seed у gen, то упадет на ином тесте, например,
                // при seed = 3456 упадет на  59 / 65 testcases passed, что говорит о вероятностном исходе верного ответа

                // Отметим, что uniform_int_distribution генерирует последовательность с повторяющимеся числами из заданного диапозона
                koef[c] = uniform_int_distribution<long long>(1e14, 2e14)(gen);
            }
        }
        return koef;
    }

public:

    vector<int> findAnagrams(string_view s, string_view p) {
        
        if (s.size() < p.size()) {return {};}
        
        vector<int> ans;
        const long long* koef = getKoef(); // слагаемые полиноминиального хэша

        // хэш-функция подстроки S длины |p|
        long long sum = 0; // char of p -, chars of s +, multiply by koef 

        /* // https://e-maxx.ru/algo/string_hashes
        Само значение хэша желательно хранить в самом большом числовом типе - int64, он же long long. 
        Очевидно, что при длине строки порядка 20 символов уже будет происходить переполнение значение. 
        Ключевой момент - что мы не обращаем внимание на эти переполнения, как бы беря хэш по модулю 2^64.
        */
        for (char c : p) {
            sum -= koef[c];
            cout << koef[c] << ' ';
        }

        cout << '\n';
        
        for (int i = 0; i < (int)p.size(); i++) {
            const char c = s[i];
            sum += koef[c];
            cout << koef[c] << ' ';
        }
        
        if (sum == 0) {ans.push_back(0);}
        
        for (int i = (int)p.size(); i < (int)s.size(); i++) {
            
            const char toRemove = s[i - (int)p.size()];
            const char toAdd = s[i];
            
            sum -= koef[toRemove];
            sum += koef[toAdd];
            
            if (sum == 0) {
                ans.push_back(i - (int)p.size() + 1);
            }
            
        }
            return ans;
    }
    
};
