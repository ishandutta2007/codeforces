#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl; //Debug

const int INF = 1000000000;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<long long> vll;

/*
bool compare(ii a, ii b)
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
		if(a.second < b.second)
		{
			return true;
		}
		return false;
	}
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	if(t < 10)
	{
		for(int i = 0; i < n; i++)
		{
			cout << t;
		}
	}
	else
	{
		if(n == 1)
		{
			cout << -1;
		}
		else
		{
			for(int i = 0; i < n-1; i++)
			{
				cout << 1;
			}
			cout << 0;
		}
	}
	return 0;
}

/*
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/