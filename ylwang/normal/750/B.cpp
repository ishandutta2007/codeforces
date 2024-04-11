#include<bits/stdc++.h>

using namespace std;

int n, now, k = 1;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		string s;
		cin >> x >> s;
		if(now == 0 && s[0] != 'S')
		{
			cout << "NO" << endl;
			return 0;
		}
		if(now == 20000 && s[0] != 'N')
		{
			cout << "NO" << endl;
			return 0;
		}
		if(s[0] == 'S')
		{
			now += x;
		}
		else if(s[0] == 'N')
		{
			now -= x;
		}
		if(now < 0 || now > 20000) 
		{
			cout << "NO" << endl;
			return 0;
		}
		// cout << now << endl;
	}
	if(now != 0) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}