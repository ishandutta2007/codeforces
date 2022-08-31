#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

//#define TASK ""

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n, 1);
	string S;
	cin >> S;
	bool f = 0;
	while(1)
	{
		f = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (S[i] == '=')
			{
				if (v[i] != v[i + 1])
					v[i] = v[i + 1] = max(v[i], v[i + 1]), f =1 ;
			}
			else if (S[i] == 'R')
			{
				if (v[i + 1] <= v[i])
					v[i + 1] = v[i] + 1, f = 1;
			}
			else if (S[i] == 'L')
			{
				if (v[i + 1] >= v[i])
					v[i] = v[i + 1] + 1, f = 1;
			}
		}
		if (!f)
			break;
	}
	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';
	return 0;
}