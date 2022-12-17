#include <bits/stdc++.h>

#define rloop(i, x) for (int i = (x); i >= 0; i--)
#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define INF ((int) 1e9)
#define mp make_pair
#define pb push_back
#define rint(N) scanf("%d", &(N))

#define MAXN 1000
#define MAXK 1000001

typedef long long ll;
using namespace std;

int N, M, K, P;
int field[MAXN][MAXN];

ll* calc(vector<int>& V, int ls)
{
	priority_queue<ll> Q;
	for (int x : V)
		Q.push(x);

	ll* ans = new ll[K+1];
	ll val = 0;
	loop(i, K+1)
	{
		//printf("for %d Q.top() = %d\n", i, Q.top());
		ans[i] = val;
		val += Q.top();
		ll nv = Q.top() - P * ls;
		Q.pop();
		Q.push(nv);
	}
	return ans;
}

int main()
{
	rint(N), rint(M), rint(K), rint(P);

	loop(i, N)
		loop(j, M)
			rint(field[i][j]);

	vector<int> V1;
	vector<int> V2;

	rep(N)
		V1.push_back(0);
	rep(M)
		V2.push_back(0);

	loop(i, N)
	{
		loop(j, M)
		{
			V1[i] += field[i][j];
			V2[j] += field[i][j];
		}
	}


	ll* a = calc(V1, M);
	ll* b = calc(V2, N);
	ll best;
	loop(i, K+1)
	{
		ll v1 = a[i];
		ll v2 = b[K-i];
		//printf("a[%d] = %d\nb[%d] = %d\n", i, v1, K-i, v2);
		if (i == 0)
			best = v1 + v2 - (ll) P * i * (K-i);
		else
			best = max(best, v1 + v2 - (ll) P * i * (K-i));
	}

	printf("%I64d\n", best);
}