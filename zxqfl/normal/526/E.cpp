#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, queries;
ll arr[1000010];
int jmp[2000010];
int ijmp[2000010];
int* fjmp[2000010];
int place[2000010];
int taken[2000010];
bool seen[1000010];
// int rval[2000010];
ll B;

int main()
{
	rint(N); rint(queries);
	ji(N) rlong(arr[i]);
	jk(queries)
	{
		// ji(N*2) rval[i] = i % N;
		rlong(B);
		memset(seen, 0, sizeof seen);
		int ans = N;

		{
			queue<ll> Q;
			for (int i = N-2; i >= 0; i--) Q.push(arr[i]);
			ll csum = 0;
			ji(N-1) csum += arr[i];
			for (int i = N-1; i >= 0; i--)
			{
				csum += arr[i];
				Q.push(arr[i]);
				while (csum > B)
				{
					csum -= Q.front();
					Q.pop();
				}
				jmp[i] = i + Q.size();
				jmp[i + N] = i + N + Q.size();
			}
			for (int i = 2*N - 1; i >= 0; i--) if (jmp[i] < N * 2)
				ijmp[jmp[i]] = i;
		}
		ji(N * 2) fjmp[i] = place + i;
		for (int i = N * 2 - 1; i >= 0; i--)
		{
			int o = jmp[i];
			if (o >= N * 2 || o >= i + N)
			{
				fjmp[i][0] = i;
				taken[i] = 0;
			}
			else
			{
				taken[i] = taken[o] + 1;
				int* x = fjmp[o];
				while (x[0] >= i + N)
				{
					x[0] = ijmp[x[0]];
					taken[i]--;
				}
				fjmp[i] = x;
				// printf("%d %d %d\n", i, taken[i], fjmp[i][0]);
			}
			if (i < N)
				ans = min(ans, taken[i] + 1);
		}
		printf("%d\n", ans);
	}
}