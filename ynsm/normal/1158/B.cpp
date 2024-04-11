#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, k;
int main()
{
	scanf("%d%d", &n, &k);
	if(k == 1)
		k = n;
	else
		k = (n - k) / 2 + 1;
	for(int i = 0; i < n; i++)
		printf("%d",(i % k == 0));
	return 0;
}