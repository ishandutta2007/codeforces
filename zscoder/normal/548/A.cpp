#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int MOD = 1e9 + 7;
const ll INF = ll(1e18);

#define pb push_back

int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	int k;
	cin >> s;
	cin >> k;
	bool possible = true;
	int n = s.length();
	int len = n/k;
	if(n % k != 0)
	{
		cout << "NO";
		return 0;
	}
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < len; j++)
		{
			if(s[i*len + j] != s[i*len + len - 1 - j])
			{
				possible = false;
				break;
			}
		}
	}
	if(possible)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}

/*B
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}*/

/*C
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}*/

/*D
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}*/

/*E
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}*/