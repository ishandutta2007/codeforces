#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = ll(1e18);

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;

#define pb push_back
/*A
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ones = 0;
	int zero = 0;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '1')
		{
			ones++;
		}
		else
		{
			zero++;
		}
	}
	cout << abs(ones - zero);
	return 0;
}
*/

int a[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int dist = 0;
	if(a[0] == 0)
	{
		dist = 0;
	}
	else
	{
		dist = n - a[0];
	}
	//cout << dist << endl;
	int possible = true;
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
		{
			if((a[i] + dist - i)%n != 0)
			{
				possible = false;
				break;
			}
		}
		else
		{
			if((a[i] - dist - i)%n != 0)
			{
				possible = false;
				break;
			}
		}
	}
	if(possible)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}

/*C
int main()
{
	ios_base::sync_with_stdio(false);
	
	
	return 0;
}
*/

/*D
int main()
{
	ios_base::sync_with_stdio(false);
	
	
	return 0;
}
*/

/*E
int main()
{
	ios_base::sync_with_stdio(false);
	
	
	return 0;
}
*/