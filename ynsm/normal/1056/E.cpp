#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    
                     
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9;
const ll INF = 1e18;

char s[N], t[N];
int n, m, a, b, ans;
pair< ull, ull > h[N], p[N], bs = {227, 229}, mod = {1e9 + 7, 1e9 + 9};
pair< ull, ull > geth(int l, int r){
	if(l == 0)
		return h[r];
	return {(h[r].f - h[l - 1].f * p[r - l + 1].f % mod.f + mod.f) % mod.f, (h[r].s - h[l - 1].s * p[r - l + 1].s % mod.s + mod.s) % mod.s};
}
bool good(pii a, pii b){
	if(a.s - a.f != b.s - b.f)
		return 0;
	return geth(a.f, a.s) == geth(b.f, b.s);
}
bool check(int x, int y){
	pii a, b;
	a = b = mp(-1, -1);
	for(int i = 0, j = 0; i < n; i++){
		if(s[i] == '0'){
			if(a == mp(-1, -1))
				a = {j, j + x - 1};
			if(!good(a, {j, j + x - 1}))
				return 0;
			j += x;
		}else{
			if(b == mp(-1, -1))
				b = {j, j + y - 1};
			if(!good(b, {j, j + y - 1}))
				return 0;
			j += y;
		}
		if(i == n - 1 && j != m)
			assert(0);
	}	             
	return !good(a, b);
}
bool g(char c){  
	if('0' <= c && c <= '9')
		return 1;
	if('a' <= c && c <= 'z')
		return 1;
	return  0;
}

int main(){
	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	m = strlen(t);
	
	for(int i = 0; i < n; i++)
		if(s[i] == '0')
			a++;
		else
			b++;
	h[0] = {t[0], t[0]};
	p[0] = {1, 1};
	for(int i = 1; i < m; i++){             
		h[i].f = (h[i - 1].f * bs.f + t[i]) % mod.f;
		p[i].f = p[i - 1].f * bs.f % mod.f;

		h[i].s = (h[i - 1].s * bs.s + t[i]) % mod.s;
		p[i].s = p[i - 1].s * bs.s % mod.s;
	}
	for(int i = 1; i * a < m; i++){
		if((m - i * a) % b != 0)
			continue;
		int j = (m - i * a) / b;
		if(check(i, j))
			ans++;
	}
	printf("%d", ans);
	return 0;
}