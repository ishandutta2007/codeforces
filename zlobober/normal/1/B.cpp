#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

pair<int, int> parseB(string S)
{
	int p = S.find("C");
	return make_pair(atoi(S.substr(1, p - 1).c_str()), atoi(S.substr(p + 1, S.size() - p - 1).c_str()));
}

string str(int x)
{
	char buf[20];
	sprintf(buf, "%d", x);
	return string(buf);
}

string B(pair<int, int> pr)
{
	return "R" + str(pr.first) + "C" + str(pr.second);
}

pair<int, int> parseA(string S)
{
	int l = -1;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] > 'Z' || S[i] < 'A')
		{
			l = i;
			break;
		}
	}
	int x = 0;
	int q = 26;
	for (int i = 0; i < l - 1; i++)
		x += q, q *= 26;
	int t = 0;
	for (int i = 0; i < l; i++)
		t = t * 26 + S[i] - 'A';
	x += t + 1;
	int y = atoi(S.substr(l).c_str());
	return make_pair(y, x);
}

string A(pair<int, int> pr)
{
	swap(pr.first, pr.second);
	string S = "";
	int l = 0;
	int u = 1;
	int q = 26;
	while (l + q < pr.first)
		l += q, q *= 26, u++;
	pr.first -= l + 1;
	S.resize(u);
	for (int i = 0; i < u; i++)
		S[u - i - 1] = pr.first % 26 + 'A', pr.first /= 26;
	S += str(pr.second);
	return S;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string S;
		cin >> S;
		pair<int, int> pr;
		if (S[0] == 'R' && S.find("C") != string::npos && S[1] >= '0' && S[1] <= '9')
		{
			pr = parseB(S);
			cerr << pr.first << ' ' << pr.second << endl;
			cout << A(pr) << endl;
		}
		else
		{
			pr = parseA(S);
			cerr << pr.first << ' ' << pr.second << endl;
			cout << B(pr) << endl;
		}
	}
	
}