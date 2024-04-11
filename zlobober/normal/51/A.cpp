#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Q
{
	int a[4];
	Q(int _a, int _b, int _c, int _d)
	{
		a[0] = _a, a[1] = _b, a[2] = _c, a[3] = _d;
		

	}
	friend bool operator ==(Q a, Q b)
	{
		for (int i = 0; i < 4; i++)
		{
			int t = a.a[0];
			a.a[0] = a.a[1];
			a.a[1] = a.a[3];
			a.a[3] = a.a[2];
			a.a[2] = t;
			for (int j = 0; j < 4; j++)
				if (a.a[j] != b.a[j])
					goto next;
			return true;
next:;
		}
		return false;
	}
	Q(){}
};

int main()
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	vector<Q> V;
	char buf[10];
	Q nw;
	for (int i = 0; i < n; i++)
	{
		cin >> buf;
		nw.a[0] = buf[0] - '0';
		nw.a[1] = buf[1] - '0';
		cin >> buf;
		nw.a[2] = buf[0] - '0';
		nw.a[3] = buf[1] - '0';
		cin >> buf;
		for (int t = 0; t < V.size(); t++)
			if (V[t] == nw)
				goto nex;
		V.push_back(nw);
nex:;
	}
	cout << V.size();
}