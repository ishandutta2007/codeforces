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
/*
**12**  
*|*1|2*|*

*|2|*1|*
*|2|*1
2*|1|*
2*|1

2|1



*/ 
vector< vector< int > > ans;
int get(int l, int r){
	return r - l + 1;
}
void f(vector< pair<pii, int> > &a){
	for(int i = 0; i + 1 < a.size(); i++){
		if(a[i].f.s + 1 == a[i + 1].f.f){
			a[i].f.s = a[i + 1].f.s;
			a[i].s += a[i + 1].s;
			for(int j = i + 2; j < a.size(); j++)
				a[j - 1] = a[j];	
			a.pop_back();
			i--;
		}
	}
	return;
}                                                                      
void solve(vector< pair<pii, int> > a){
	f(a);
	int l, r;
	l = r = -1;
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < i; j++)
			if(a[j].f.f == a[i].f.s + 1)
				l = j, r = i;	
	if(l == -1)
		return;
	int A = l;
	int B = r - l - 1;
	int C = a.size() - r - 1;
	vector< int > op;
	if(A > 0){
		op.pb(get(0, l - 1));
		op.pb(get(l, l));
		op.pb(get(l + 1, r));
		if(C > 0)
			op.pb(get(r + 1, a.size() - 1));
	}else{
		op.pb(get(0, r - 1));
		op.pb(get(r, r));
		if(C > 0)
			op.pb(get(r + 1, a.size() - 1));		
	}
	
	vector< int > opp;
	vector< vector< pair<pii, int> > > b;
	for(int i = 0, j = 0; i < op.size(); i++){
		int x = op[i];
		int y = 0;
		vector< pair<pii, int> > v;
		while(x--){
			y += a[j].s;
			v.pb(a[j]);
			j++;
		}
		b.pb(v);
		opp.pb(y);
	}
	reverse(b.begin(), b.end());
	a.clear();
	for(auto y : b)
		for(auto x : y)
			a.pb(x);
	ans.pb(opp);
	solve(a);
}
int main(){
	int n;
	scanf("%d", &n);
	vector< pair<pii, int> > a(n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a[i].f.f = a[i].f.s = --x;
		a[i].s = 1;
	}
	solve(a);
	printf("%d\n", ans.size());
	for(auto v : ans){
		printf("%d ", v.size());
		for(auto x : v)
			printf("%d ", x);
		printf("\n");
	}
}