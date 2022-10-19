#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, mxx, mnx, mxy, mny, ans;
vector< pii > v;
vector< int > p;
void tup(){
	vector< int > ans(n + 1);
	for(int mask = 0; mask < (1<<n); mask++){
		int cnt = 0, cur = 0;
		vector< int > pp;
		for(int i = 0; i < n; i++)
			if((1<<i) & mask){
				pp.pb(i);
				cnt++;
			}
	    for(int i = 0; i < cnt; i++)
			cur += abs(v[pp[i]].f - v[pp[(i + 1) % cnt]].f) + abs(v[pp[i]].s - v[pp[(i + 1) % cnt]].s);
		ans[cnt] = max(ans[cnt], cur);
	}
	for(int i = 3; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		v.pb({x, y});
        if(i == 0)
			mxx = x, mnx = x, mxy = y, mny = y;
		mxx = max(mxx, x);
		mnx = min(mnx, x);
		mxy = max(mxy, y);
		mny = min(mny, y);
	}
	//tup();
	//return 0;
	for(int i = 0; i < n; i++)
		if(v[i].f == mxx || v[i].f == mnx || v[i].s == mxy || v[i].s == mny)
			p.pb(i); 
    for(auto i : p)
    	for(auto j : p)
    		for(int q = 0; q < n; q++)
            	ans = max(ans, max(v[i].f, max(v[j].f, v[q].f)) - min(v[i].f, min(v[j].f, v[q].f)) +  max(v[i].s, max(v[j].s, v[q].s)) - min(v[i].s, min(v[j].s, v[q].s)));
    printf("%d ", 2 * ans);
	for(int i = 4; i <= n; i++)
		printf("%d ", 2 * (mxx + mxy - mnx - mny) );
	return 0;
}