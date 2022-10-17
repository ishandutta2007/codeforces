#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, q, a[N], t[N << 2][2], ans[N][2];

void build(int v, int tl, int tr){
	t[v][0] = 0;
	t[v][1] = 1;
	if(tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}
void push(int v){
	if(t[v << 1][0])
		t[v << 1][0] = t[v][1];
	else
		t[v << 1][0] = t[v][0];
	
	if(t[v << 1][1])
		t[v << 1][1] = t[v][1];
	else
		t[v << 1][1] = t[v][0];
	
	if(t[v << 1 | 1][0])
		t[v << 1 | 1][0] = t[v][1];
	else
		t[v << 1 | 1][0] = t[v][0];
	
	if(t[v << 1 | 1][1])
		t[v << 1 | 1][1] = t[v][1];
	else
		t[v << 1 | 1][1] = t[v][0];
	t[v][0] = 0;
	t[v][1] = 1;
}

void upd(int v, int tl, int tr, int l, int r, int x, int y){
	if(tr < l || r < tl || l > r)
		return;
	if(l <= tl && tr <= r){
		if(t[v][0])
			t[v][0] = y;
		else
			t[v][0] = x;
		if(t[v][1])
			t[v][1] = y;
		else     
			t[v][1] = x;
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	upd(v << 1, tl, tm, l, r, x, y);
	upd(v << 1 | 1, tm + 1, tr, l, r, x, y);
}
void solve(int v, int tl, int tr){
	if(tl == tr){
		ans[tl][0] = t[v][0];
		ans[tl][1] = t[v][1];
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	solve(v << 1, tl, tm);
	solve(v << 1 | 1, tm + 1, tr);
}
int main()
{
	int m = 100000;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, m);
	while(q--){
		char ch = getchar();
		while(ch != '<' && ch != '>')
			ch = getchar();
		int x, y;
		scanf("%d", &x);
		y = abs(x);

		if(ch == '<'){
			if(x < 0){
				upd(1, 1, m, y + 1, m, 1, 1);
			}
			if(x > 0){
				upd(1, 1, m, 1, y - 1, 1, 0);
				upd(1, 1, m, y, m, 1, 1);
			}
			if(x == 0){
				upd(1, 1, m, 1, m, 1, 1);
			}
		}else{
			if(x < 0){
				upd(1, 1, m, y, m, 0, 0);
				upd(1, 1, m, 1, y - 1, 1, 0);
			}
			if(x > 0){
				upd(1, 1, m, y + 1, m, 0, 0);
			}
			if(x == 0){
				upd(1, 1, m, 1, m, 0, 0);
			}
		}
	}
	solve(1, 1, m);
	for(int i = 1; i <= n; i++){
		if(a[i] == 0)
			printf("%d ", a[i]);
		if(a[i] < 0){            
			if(ans[-a[i]][0] == 0)  
				printf("%d ", a[i]);
			else
				printf("%d ", -a[i]);
		}
		if(a[i] > 0){            
			if(ans[a[i]][1] == 0)  
				printf("%d ", -a[i]);
			else
				printf("%d ", a[i]);
		}
	}
	return 0;
}