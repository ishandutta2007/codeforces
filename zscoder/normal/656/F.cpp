#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s; cin>>s;
	int ans = 1;
	for(int i = 1; i < 7; i++)
	{
		ans += s[i] - '0';
		if(s[i] == '0') ans += 9;
	}
	cout << ans;
	return 0;
}