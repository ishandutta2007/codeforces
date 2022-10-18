#include <bits/stdc++.h>

using namespace std;

int t;
int cnt[27];

int main()
{
	cin >> t;
	while(t--)
	{
		memset(cnt , 0 , sizeof cnt);
		int n;
		string s;
		cin >> n >> s;
		for(int i = 0; i < n; i++)
			cnt[s[i] - 'a']++;
		for(int i = 0; i < 26; i++)
			if(i + 'a' != 't' && i + 'a' != 'r'  && i + 'a' != 'y'  && i + 'a' != 'g'  && i + 'a' != 'u' && i + 'a' != 'b')
				for(int j = 1; j <= cnt[i]; j++)
					cout << char(i + 'a');
		while(cnt['b' - 'a'])
		{
			cout << 'b';
			cnt['b' - 'a']--;
		}
		while(cnt['u' - 'a'])
		{
			cout << 'u';
			cnt['u' - 'a']--;
		}
		while(cnt['g' - 'a'])
		{
			cout << 'g';
			cnt['g' - 'a']--;
		}
		while(cnt['y' - 'a'])
		{
			cout << 'y';
			cnt['y' - 'a']--;
		}
		while(cnt['r' - 'a'])
		{
			cout << 'r';
			cnt['r' - 'a']--;
		}
		while(cnt['t' - 'a'])
		{
			cout << 't';
			cnt['t' - 'a']--;
		}
		cout << endl;
	}
	return 0;
}