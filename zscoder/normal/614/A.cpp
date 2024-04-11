#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = ll(1e18);

int main()
{
	ios_base::sync_with_stdio(false);
	ll l, r, k;
	cin >> l >> r >> k;
	ll prod = 1;
	int count = 0;
	for(int i = 0; i <= 1000; i++)
	{
		if(l <= prod && prod <= r)
		{
			cout << prod << " ";
			count++;
		}
		if(prod <= r/k)
		{
			prod *= k;
		}
		else
		{
			break;
		}
	}
	if(!count)
	{
		cout << -1 << endl;
	}
	return 0;
}