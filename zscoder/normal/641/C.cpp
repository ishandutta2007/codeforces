#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int ans[1000001];
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q; scanf("%d %d", &n, &q);
	int t, x;
	int odd, even;
	odd = 0; even = 0;
	for(int i = 0; i < q; i++)
	{
		scanf("%d", &t);
		if(t == 1)
		{
			scanf("%d", &x);
			if(x < 0) x += n;
			odd = (odd+x)%n;
			even = (even+x)%n;
		}
		else
		{
			if((odd&1) == 0)
			{
				odd = (odd+1)%n;
				even = (even+n-1)%n;
			}
			else
			{
				odd = (odd+n-1)%n;
				even = (even+1)%n;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(i&1)
		{
			int move = (i+odd)%n;
			if(move == 0) move = n;
			ans[move] = i;
		}
		else
		{
			int move = (i+even)%n;
			if(move == 0) move = n;
			ans[move] = i;
		}
	}
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}