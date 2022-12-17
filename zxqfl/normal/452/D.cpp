#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((ll) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
	int K, N[3], T[3];

	rint(K);
	loop(i, 3) rint(N[i]);
	loop(i, 3) rint(T[i]);

	priority_queue<pi, vector<pi>, greater<pi> > Q;
	int t;
	for (int t = 0;; t++)
	{
		while (!Q.empty() && Q.top().first == t)
		{
			pi p = Q.top();
			Q.pop();
			N[p.second]++;
		}

		while (K && N[0] && N[1] && N[2])
		{
			loop(i, 3)
			{
				N[i]--;
				Q.push(mp(t + T[i], i));
			}
			K--;
		}
		if (K == 0)
		{
			printf("%d\n", t + T[0] + T[1] + T[2]);
			return 0;
		}
	}	
}