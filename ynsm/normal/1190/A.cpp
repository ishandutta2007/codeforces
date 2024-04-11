#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 100500;

ll n, m, k, tmp, sh, pos, ans, a[N];
int main()
{
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%lld", &a[i]);
		a[i]--;
	}
	pos = k;
	for(int i = 0,j = 0; i < m; i = j){
		pos = (a[j] - sh) / k * k + k;
		tmp = 0;
		while(j < m && a[j] - sh < pos)
			j++, tmp++;
		sh += tmp;
		ans++;
	}
	printf("%lld", ans);
	return 0;
}