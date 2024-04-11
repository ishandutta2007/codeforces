#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>


#define SS ;
typedef long long ll;
using namespace std;
int s[5000];
int main() {
	string ss;
	cin >> ss;
	for (size_t i = 0; i < ss.size(); i++) {
		s[i] = ss[i] - 'a';
	}
	int l = ss.size();
	int count[26] = { 0 };
	for (int shif = 0; shif < l; shif++) {
		int b[26][26] = { 0 };
		int c[26] = { 0 };
		for (auto j = 0; j < l; j++)
		{
			int index = j + shif;
			if (index >= l)
				index -= l;
			b[s[j]][s[index]]++;
		}
		for (int j = 0; j < 26; j++)
			for (int k = 0; k < 26; k++)
			{
				if (b[j][k] == 1)
					c[j]++;
			}
		for (int j = 0; j < 26; j++)
		{
			if (count[j] < c[j])
				count[j] = c[j];
		}
	}
	int q = 0;
	for (size_t j = 0; j < 26; j++)
	{
		q += count[j];
	}
	cout << setprecision(8) << double(q) / l << endl;
	SS;
	return 0;
}