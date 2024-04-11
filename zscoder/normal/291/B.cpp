#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	string s;
	getline(cin, s);
	vector<string> ans;
	bool inside = true;
	bool quotes = false;
	string x;
	string y;
	for(int i = 0; i < s.length(); i++)
	{
		//cout << i << " " << s[i] << " ";
		if(quotes)
		{
			//cout << "1" << endl;
			if(s[i] == '"')
			{
				ans.pb(x);
				x = "";
				inside = false;
				quotes = false;
			}
			else
			{
				y = " ";
				y[0] = s[i];
				x.append(y);
			}
		}
		else if(inside)
		{
			//cout << "2" << endl;
			if(s[i] == '"')
			{
				quotes = true;
				x = "";
			}
			else if(s[i] == ' ')
			{
				if(x.length() > 0)
				{
					ans.pb(x);
					x = "";
				}
			}
			else
			{
				y = " ";
				y[0] = s[i];
				x.append(y);
				if(i == s.length() - 1)
				{
					ans.pb(x);
				}
			}
		}
		else
		{
			//cout << "3" << endl;
			x = "";
			if(s[i] == '"')
			{
				quotes = true;
				inside = true;
			}
			else if(s[i] == ' ')
			{
				inside = true;
			}
		}
	}
	//cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)
	{
		cout << "<";
		cout << ans[i];
		cout << ">\n";
	}
	return 0;
}

/*
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/