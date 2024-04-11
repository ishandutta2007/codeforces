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

const int MX = 1<<17;

int D[MX];
int N;
ll K;

bool is_answer(int d){
	ll tot = 0;
	for(int i = 1; i <= N; i++){
		tot += (d-D[i]%d)%d;
	}
	return tot <= K;
}

int main()
{
		N = 100; K = 1e11;
	scanf("%d%lld", &N, &K);
	for(int i = 1; i <= N; i++){
		D[i] = 1e9;
		scanf("%d", D+i);
	}
	ll ans = 0;
	for(int d = 1; d <= 100000; d++){
		if(is_answer(d) ) ans = d;
	}
	vector<int> L;
	ll sum = 0, a = 0, b = 0;
	for(int i = 1; i <= N; i++) sum += D[i];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= 10000; j++){
			L.push_back(D[i] / j + 1);
			if( D[i]%j == 0){
				if( is_answer(D[i]/j) ) ans = max(ans, (ll)D[i]/j);
			}
		}
	}
	sort(L.begin(), L.end());
	L.resize(unique(L.begin(), L.end()) - L.begin());
	for(int d : L){
		if(d == 0) continue;
		ll a = 0;
		for(int i = 1; i <= N; i++){
			a += (D[i]/d+1);
		}
		if( d <= (K+sum)/a ) ans = max(ans, (K+sum)/a);
	}
	printf("%lld\n", ans);
}