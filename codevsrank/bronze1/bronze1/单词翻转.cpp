//#define NOW
#ifdef NOW
#include <iostream>
#include <string>
using namespace std;

void resever_word(string str1) {
	int len = str1.size();
	int i = 0;
	while (i<len / 2) {
		str1[i] = str1[len - i - 1] ^ str1[i];
		str1[len - i - 1] = str1[i] ^ str1[len - i - 1];
		str1[i] = str1[i] ^ str1[len - i - 1];
		i++;
	}
	int fr = 0, er = 0;
	for (int j = 0; j<len; j++)
	{
		er = j;
		if (str1[er] == ' ' || er == len - 1)
		{
			if (er == len - 1)
				er++;
			int k = 0;
			while (k<(er - fr) / 2) {
				str1[fr + k] = str1[er - k - 1] ^ str1[fr + k];
				str1[er - k - 1] = str1[fr + k] ^ str1[er - k - 1];
				str1[fr + k] = str1[fr + k] ^ str1[er - k - 1];
				k++;
			}
			fr = er + 1;
		}
	}
	cout << str1 << endl;
}

int main()
{
	string str;
	getline(cin, str);
	resever_word(str);
	return 0;
}
#endif