#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define szz(x) (int)(x).size()
#define Fi first
#define Se second

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int IT_MAX = 1 << 17;

const int MX = 1000005;

int N, K;
set <pii> S;
int p[500010];
int nxt[500010], pre[500010];

int main() {
	scanf("%d%d", &K, &N);
	for(int i=1;i<=N;i++)scanf("%d", p+i);
	sort(p+1, p+1+N);
	for(int i=1;i<=N;i++)p[i] = p[i+1] - p[i]; --N;
	for(int i=1;i<N;i++)nxt[i] = i+1; nxt[N] = -1;
	for(int i=2;i<=N;i++)pre[i] = i-1; pre[1] = -1;
	for(int i=1;i<=N;i++)S.insert(pii(p[i], i));
	int ans = 0;
	for(int i=1;i<=K;i++){
		pii t = *S.begin();
		S.erase(S.begin());
		if(pre[t.Se] == -1 && nxt[t.Se] == -1);
		else if(pre[t.Se] == -1){
			S.erase(S.find(pii(p[nxt[t.Se]], nxt[t.Se])));
			if(nxt[nxt[t.Se]] != -1)pre[nxt[nxt[t.Se]]] = -1;
		}
		else if(nxt[t.Se] == -1){
			S.erase(S.find(pii(p[pre[t.Se]], pre[t.Se])));
			if(pre[pre[t.Se]] != -1)nxt[pre[pre[t.Se]]] = -1;
		}
		else{
			S.erase(S.find(pii(p[nxt[t.Se]], nxt[t.Se])));
			S.erase(S.find(pii(p[pre[t.Se]], pre[t.Se])));
			p[t.Se] = -p[t.Se] + p[nxt[t.Se]] + p[pre[t.Se]];
			pre[t.Se] = pre[pre[t.Se]];
			nxt[pre[t.Se]] = t.Se;
			nxt[t.Se] = nxt[nxt[t.Se]];
			pre[nxt[t.Se]] = t.Se;
			S.insert(pii(p[t.Se], t.Se));
		}
		ans += t.Fi;
	}
	printf("%d\n", ans);
	return 0;
}