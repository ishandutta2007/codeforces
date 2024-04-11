#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

#define HASFILES 1

#define TASK ololo

string good(string x)
{
	string q;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '-' || x[i] == '_' || x[i] == ';')
			continue;
		if (x[i] >= 'A' && x[i] <= 'Z')
			x[i] += 'a' - 'A';
		q.push_back(x[i]);
	}
	return q;
}

int main(int argc, char **argv)
{
	string a, b, c;
	string arr[6];
	cin >> a >> b >> c;
	a = good(a);
	b = good(b);
	c = good(c);
	string cur[] = {a, b, c};
	
	sort(cur, cur + 3);
	int i = 0;
	do
	{
		arr[i++] = cur[0] + cur[1] + cur[2];
	} while (next_permutation(cur, cur + 3));
	int n;
	cin >> n;
	string t;
	bool tt;
	for (int i = 0; i < n; i++)
	{
		tt = 0;
		cin >> t;
		t = good(t);
		for (int q = 0; q < 6; q++)
			if (t == arr[q])
			{
				cout << "ACC";
				tt = 1;
				break;
			}
		if (!tt)
			cout << "WA";
		cout << endl;
	}
}