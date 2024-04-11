#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef long long ll;

string s;
ll a[N] , n , T;
int x;

int main()
{
	ios::sync_with_stdio(false);
	cin >> x >> T;
	cin >> s;
	if(s.size() == 1)
	{
		if((1ll << (s[0] - 'a')) != T)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	for(int i = 0; i < s.size() - 2; i++)
		a[++n] = s[i] - 'a';
	ll temp = abs((1ll << (s[s.size() - 1] - 'a')) - (1ll << (s[s.size() - 2] - 'a')) - T);
	sort(a + 1 , a + n + 1);
	for(int i = n; i >= 1; i--)
	{
		ll tmp = abs(temp) , t = (1ll << a[i]);
		temp = abs(tmp - t);
	}
	if(temp == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}