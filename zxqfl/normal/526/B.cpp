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

int arr[10000];
int total = 0;
int N;

int cdown(int x)
{
	if (x > N) return 0;
	return arr[x] + max(cdown(x * 2), cdown(x * 2 + 1));
}

int cstart(int x)
{
	return max(cdown(x * 2), cdown(x * 2 + 1));
}

void solve(int x, int t)
{
	if (x > N) return;
	int a = cdown(x * 2);
	int b = cdown(x * 2 + 1);
	total += t - a;
	total += t - b;
	solve(x * 2, a - arr[x*2]);
	solve(x * 2 + 1, b - arr[x*2+1]);
}

int main()
{
	rint(N);
	N = (1 << (N + 1)) - 1;
	for (int i = 2; i <= N; i++)
		rint(arr[i]);
	solve(1, cstart(1));
	printf("%d\n", total);
}