#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7, LOG = 20;
const ll INF = 1e18;
 
int n, m, k;
pii ans[N];
vector< int > v[LOG];
void f(int i, int j){
	ans[m++] = {i + 1, j + 1};
}
int main()
{
	scanf("%d", &n);
	for(int j = 0; j < LOG; j++){
		int m = n / (2 << j) * (2 << j);		
		for(int i = 0; i < m; i++){
			int q = (i ^ (1 << j));
			if(q < i)
				f(q, i);
		}
	}
	int ptr = 0;
	while(ptr < n){
		int x = 1;
		while(ptr + x * 2 <= n)
			x *= 2;		
		for(int i = ptr; i < ptr + x; i++)
			v[k].pb(i);
		k++;
		ptr += x;			
	}
	vector< int > a = v[k - 1];
	for(int i = k - 2; i > 0; i--){
		while(a.size() < v[i].size()){
			vector< int > b;
			while(!a.empty()){
				f(a.back(), v[0].back());
				b.pb(a.back());
				b.pb(v[0].back());
				a.pop_back();
				v[0].pop_back();
			}
			a = b;
		}
        if(a.size() == v[i].size()){
			vector< int > b;
			while(!a.empty()){
				f(a.back(), v[i].back());
				b.pb(a.back());
				b.pb(v[i].back());
				a.pop_back();
				v[i].pop_back();
			}
			a = b;
		}
	}
	printf("%d\n", m);
	for(int i = 0; i < m; i++)
		printf("%d %d\n", ans[i].f, ans[i].s);
	return 0;
}