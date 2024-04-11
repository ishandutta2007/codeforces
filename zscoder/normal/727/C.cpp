#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int MOD = 1e9 + 7;

int ask(int i, int j)
{
	cout << "? " << i + 1 << ' ' << j + 1 << '\n';
	fflush(stdout);
	int x; cin >> x;
	return x;
}

int a[5001];
int n;
void out()
{
	cout << "! ";
	for(int i = 0; i < n; i++)
	{
		cout << a[i];
		if(i < n - 1) cout << ' ';
	}
	cout << '\n';
	fflush(stdout);
}

ll sum[5011];

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	if(n&1)
	{
		ll totsum = 0;
		for(int i = 0; i < n; i++)
		{
			sum[i] = ask(i, (i+1)%n);
			totsum += sum[i];
		}
		totsum>>=1;
		for(int i = 0; i < n; i++)
		{
			ll sum2 = 0; int ptr = (i+1)%n;
			for(int j = 0; j < n/2; j++)
			{
				sum2 += sum[ptr];
				ptr+=2; ptr%=n;
			}
			a[i] = totsum - sum2;
		}
		out();
	}
	else
	{
		n--;
		ll totsum = 0;
		for(int i = 0; i < n; i++)
		{
			sum[i] = ask(i, (i+1)%n);
			totsum += sum[i];
		}
		totsum>>=1;
		for(int i = 0; i < n; i++)
		{
			ll sum2 = 0; int ptr = (i+1)%n;
			for(int j = 0; j < n/2; j++)
			{
				sum2 += sum[ptr];
				ptr+=2; ptr%=n;
			}
			a[i] = totsum - sum2;
		}
		n++;
		a[n - 1] = ask(0, n - 1) - a[0];
		out();
	}
}