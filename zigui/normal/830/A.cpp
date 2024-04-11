#include<stdio.h>
#include<set>
#include<assert.h>
#include<queue>
#include<assert.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

const double EPS = 1e-8;
const double PI = acos(-1);

const int MX = 2005;

int D[MX], E[MX];

int main()
{
	int N, K, P;
	scanf("%d%d%d", &N, &K, &P);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);
	for(int i = 1; i <= K; i++) scanf("%d", E+i);
	sort(D+1, D+N+1);
	sort(E+1, E+K+1);
	ll ans = 1e18;
	for(int i = 1; i+N-1 <= K; i++){
		ll mx = 0;
		for(int j = 1; j <= N; j++){
			mx = max(mx, (ll)abs(D[j] - E[i+j-1]) + abs(E[i+j-1] - P));
		}
		ans = min(ans, mx);
	}
	printf("%lld\n", ans);
}