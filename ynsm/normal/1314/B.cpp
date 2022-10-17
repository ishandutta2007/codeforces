#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 1e6 + 100, inf = 1e9;
 
int n, k, a[N], t[4][N];
void mx(int &a, int b){
	if(a < b)
		a = b;
}
void solve(int v, int l, int r){
	for(int i = 0; i < 4; i++)
		t[i][v] = -inf;
	if(r - l == 1){                       
		t[a[l] << 1 | a[r]][v] = a[l] | a[r];
		t[a[r] << 1 | a[l]][v] = a[l] | a[r];
		return;	
	}
	int m = (l + r) >> 1;
	solve(v << 1, l, m);
	solve(v << 1 | 1, m + 1, r);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			int w1 = i >> 1;
			int l1 = i & 1;
			int w2 = j >> 1;
			int l2 = j & 1;
			mx(t[w1 << 1 | l1][v], (w1 | w2) + (l1 | l2) + (l1 | w2) + t[i][v << 1] + t[j][v << 1 | 1]);
			mx(t[w1 << 1 | l2][v], (w1 | w2) + (l1 | l2) + (l2 | w2) + t[i][v << 1] + t[j][v << 1 | 1]);
			mx(t[w1 << 1 | w2][v], (w1 | w2) + (l1 | l2) + (l1 | l2 | w2) + t[i][v << 1] + t[j][v << 1 | 1]);
			mx(t[w2 << 1 | l1][v], (w1 | w2) + (l1 | l2) + (l1 | w1) + t[i][v << 1] + t[j][v << 1 | 1]);
			mx(t[w2 << 1 | l2][v], (w1 | w2) + (l1 | l2) + (l2 | w1) + t[i][v << 1] + t[j][v << 1 | 1]);
			mx(t[w2 << 1 | w1][v], (w1 | w2) + (l1 | l2) + (l1 | l2 | w1) + t[i][v << 1] + t[j][v << 1 | 1]);
		}
	}	
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; i++){
		int x;
		scanf("%d", &x);
		a[x] = 1;
	}
	solve(1, 1, (1 << n));
	int ans = 0;
	for(int i = 0; i < 4; i++)
		ans = max(ans, t[i][1] + (i > 0));
	printf("%d", ans);
}