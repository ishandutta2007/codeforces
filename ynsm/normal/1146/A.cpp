#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int main()
{
	string s;
	cin >> s;
	int a, b;
	a = b = 0;
	for(int i = 0; i < s.size(); i++)
		if(s[i] == 'a')
			a++;
		else
			b++;
	cout << s.size() - max(b - a + 1, 0);
	return 0;
}