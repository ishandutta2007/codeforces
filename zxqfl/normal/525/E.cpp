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

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, K;
ll S;
ll fact[100];

struct dstr
{
	int ways[26];
	dstr()
	{
		ji(26) ways[i] = 0;
	}
	void integrate()
	{
		jjs(i, 1, 26) ways[i] += ways[i-1];
	}
	int& operator [](int x)
	{
		return ways[x];
	}
};

map<ll, dstr> solve(int* arr, int sz)
{
	map<ll, dstr> ans;
	int tar = 1;
	ji(sz) tar *= 3;
	int st[sz];
	jjl(msk, tar)
	{
		int crnt = msk;
		ji(sz)
		{
			st[i] = crnt % 3;
			crnt /= 3;
		}
		ll csum = 0;
		int ccount = 0;
		bool ok = true;
		ji(sz) if (st[i] == 2)
		{
			if (arr[i] >= 100 || fact[arr[i]] < 0)
				ok = false;
			else
			{
				csum += fact[arr[i]];
				if (csum > S)
					ok = false;
			}
			ccount++;
		}
		else if (st[i] == 1)
			csum += arr[i];
		if (!ok)
			continue;
		ans[csum][ccount]++;
	}
	return ans;
}

int main()
{
	rint(N); rint(K);
	rlong(S);
	fact[0] = 1;
	jjs(i, 1, 100)
	{
		if (fact[i-1] < 0 || i * fact[i-1] > S)
			fact[i] = -1;
		else
			fact[i] = i * fact[i-1];
	}
	int arr[N];
	ji(N) rint(arr[i]);
	int A = N / 2;
	auto M1 = solve(arr, A);
	auto M2 = solve(arr + A, N - A);
	foreach(q, M2) q.second.integrate();
	ll ans = 0;
	foreach(pr, M1)
	{
		ll tar = S - pr.first;
		if (!M2.count(tar))
			continue;
		auto& o = M2[tar];
		ji(K+1)
		{
			ans += (ll) pr.second[i] * o[K-i];
		}
	}
	printf("%lld\n", ans);
}