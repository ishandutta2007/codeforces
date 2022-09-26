#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.length() - 1; i++)
	{
		if(s[i] == s[i + 1])
		{
			ans++;
			s[i + 1] = (s[i]-'a'+1)%26+'a';
			if(s[i+1] == s[i+2])
			{
				s[i+1] = (s[i+1]-'a'+1)%26+'a';
			}
		}
	}
	cout << s;
	return 0;
}