# include <iostream>
# include <string>
# include <set>
using namespace std;
set <string> x;
const int MN = 1e4 + 44;
bool r2[MN], r3[MN];
int main()
{
	string a;
	cin >> a;
	int n = a.size();
	a = a + "[{}(=*);";
	r2[n] = r3[n] = r2[n - 2] = r3[n - 3] = true;
	for (int i = n - 4; i >= 0; --i)
	{
		r2[i] = r3[i + 2] || (r2[i + 2] && (a[i] != a[i + 2] || a[i + 1] != a[i + 3]));
		r3[i] = r2[i + 3] || (r3[i + 3] && (a[i] != a[i + 3] || a[i + 1] != a[i + 4] || a[i + 2] != a[i + 5]));
	}
	for (int i = 5; i < a.size(); ++i)
		for (int k = 2; k + i <= a.size() && k < 4; ++k)
			if (r2[i + k] || r3[i + k])
			{
				string curr;
				for (int l = 0; l < k; ++l)
					curr += a[i + l];
				x.insert(curr);
			}
	cout << x.size() << '\n';
	for (auto s : x)
		cout << s << '\n';
}