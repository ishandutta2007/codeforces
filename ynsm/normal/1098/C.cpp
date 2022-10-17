#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n;
ll s;
bool check(int k, bool flag = 0){
	vector< int > h(n), p(n), good(n);
	good[0] = 1;
	for(int i = 0, j = 1; i < n; i++)
		for(int q = 0; j < n && q < k; q++, j++)
			p[j] = i, good[j] = (good[i] && q == 0);
	
	h[0] = 1;
	for(int i = 1; i < n; i++)
		h[i] = h[p[i]] + 1;
	
	ll cur = s;
	for(int i = 0; i < n; i++)
		cur -= h[i];
	if(cur < 0)
		return 0;
	
	vector< int > v;
	for(int i = 0; i < n; i++)
		if(good[i])
        	v.pb(i);                      
    for(int i = n - 1; i > 0; i--){
		if(good[i])
			continue;	
		int h1 = h[i];
		int h2 = v.size() + 1;
		if(cur - h2 + h1 > 0){
			p[i] = v.back();
			h[i] = h[p[i]] + 1;
			v.pb(i);
		}else if(cur > 0){
			int hn = (cur + h1);
			p[i] = v[hn - 2];
			h[i] = h[p[i]] + 1;
		}
		cur = cur - h[i] + h1;
	}
	if(flag)
		for(int i = 1; i < n; i++)
			printf("%d ", p[i] + 1);
	return cur == 0;    
}
int main(){
	scanf("%d%lld", &n, &s);
	if(!check(n)){
		puts("NO");
		return 0;
	}
	puts("YES");
	int l = 1, r = n;
	while(l <= r){
		int m = (l + r) / 2;
		if(!check(m))
			l = m + 1;
		else
			r = m - 1;
	}
	check(l, 1);
	return 0;
}