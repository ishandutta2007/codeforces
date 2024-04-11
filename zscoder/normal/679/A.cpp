#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans = 0; int tmp = 0;
	for(int i = 0; i < 4; i++)
	{
		cout << primes[i] << endl;
		fflush(stdout);
		string s;
		cin >> s;
		if(s.length() == 3) 
		{
			tmp = primes[i];
			ans++;
		}
	}
	if(!ans)
	{
		cout << "prime" << endl;
		fflush(stdout);
		return 0;
	}
	else if(ans > 1)
	{
		cout << "composite" << endl;
		fflush(stdout);
		return 0;
	}
	else
	{
		for(int i = 0; primes[i]*tmp <= 100; i++)
		{
			cout << primes[i]*tmp << endl;
			fflush(stdout);
			string s;
			cin >> s;
			if(s.length() == 3)
			{
				cout << "composite" << endl;
				fflush(stdout);
				return 0;
			}
		}
		cout << "prime" << endl;
		fflush(stdout);
		return 0;
	}
	return 0;
}