#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl; //Debug

const ll INF = 1000000000;
const ll MOD = 1000000007;

/*bool compare(ii a, ii b)
{
	if(a.first < b.first)
	{
		return true;
	}
	else if(a.first > b.first)
	{
		return false;
	}
	else
	{
		if(a.second > b.second)
		{
			return false;
		}
		return true;
	}
}*/

//freopen("input.txt", "r", stdin);
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	cin >> s;
	if(s.at(0) == 'm')
	{
		if(n <= 29)
		{
			cout << 12;
		}
		else if(n == 30)
		{
			cout << 11;
		}
		else
		{
			cout << 7;
		}
	}
	else
	{
		if(n <= 4)
		{
			cout << 52;
		}
		else if(n == 7)
		{
			cout << 52;
		}
		else
		{
			cout << 53;
		}
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
/*F
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/
/*G
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/
/*H
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/