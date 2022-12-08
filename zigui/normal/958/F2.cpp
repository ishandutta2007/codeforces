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

int N, M;
int A[200020], B[200020];
int C[200020];

int main() {
	scanf("%d%d", &N, &M);
	for(int i=1;i<=N;i++) {
		scanf("%d", A+i);
	}
	int sum = 0, ok = 0;
	for(int i=1;i<=M;i++) {
		scanf("%d", B+i);
		ok += (B[i] == 0);
		sum += B[i];
	}
	int ans = 1e9;
	for(int i=1, j=1;i<=N;i++) {
		while(j <= N && ok < M) {
			C[A[j]]++;
			if(C[A[j]] == B[A[j]]) ++ok;
			j++;
		}
		if(ok == M) {
			ans = min(ans, j - i - sum);
		}
		if(C[A[i]] == B[A[i]]) --ok;
		C[A[i]]--;
	}
	if(ans == 1e9) puts("-1");
	else printf("%d\n", ans);
	return 0;
}