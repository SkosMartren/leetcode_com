class Solution {
public:
	bool isPalindrome(string s) {

		int l = 0;
		int r = s.size() - 1;

		// так как работаем с двумя указателями, должен выполнятся инваринат: l < r
		while (l < r) {

			// "Alphanumeric characters include letters and numbers."
			// отрбрасываем от левой границы окна символы, отличные от чисел / алфавитных символов нижнего и верхнего регистра. Например: ' ', ':', '%' и т.д.
			while (l < r && !isalnum(s[l])) { ++l; }

			// "Alphanumeric characters include letters and numbers."
			// отрбрасываем от правой границы окна символы, отличные от чисел / алфавитных символов нижнего и верхнего регистра. Например: ' ', ':', '%' и т.д.
			while (l < r && !isalnum(s[r])) { --r; }

			/* // equiv:

			for(; l < r && !isalnum(s[l]); ++l);

			for(; l < r && !isalnum(s[r]); --r);

			*/

			// "...converting all uppercase letters into lowercase letters..."
			if (tolower(s[l]) != tolower(s[r])) { return false; }
			
			++l; --r; // очередной сдвиг указателей

			/* //equiv:
   
   			while(isalnum(s[l]) && isalnum(s[r])){
      
      			// "...converting all uppercase letters into lowercase letters..."
			if (tolower(s[l]) != tolower(s[r])) { return false; }
			++l; --r; // очередной сдвиг окна
			}
   			
      			*/

		}

		return true;
	}
};
