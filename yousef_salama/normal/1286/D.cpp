#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 100005;

struct fraction{
	long long p, q;
	fraction(long long p, long long q): p(p), q(q){}
};

struct event{
	fraction f;
	int ind;
	
	event(fraction f, int ind): f(f), ind(ind){}
};

bool operator <(fraction a, fraction b){
	return a.p * b.q < b.p * a.q;
}
bool operator <(event a, event b){
	return a.f < b.f;
}

int n, pos[MAXN], v[MAXN], p[MAXN];
vector <event> evs;

long long modpow(long long a, long long p){
	if(p == 0)return 1;
	if(p % 2 != 0)return a * modpow(a, p - 1) % MOD;
	
	long long r = modpow(a, p / 2);
	return r * r % MOD;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
long long inv100;

long long tree[4 * MAXN][2][2];
void build(int i, int L, int R){
	if(L == R){
		tree[i][0][1] = 0;
		tree[i][1][0] = 0;
		
		tree[i][0][0] = (100 - p[L]) * inv100 % MOD;
		tree[i][1][1] = p[L] * inv100 % MOD;
	}else{
		int mid = (L + R) / 2;
		
		build(2 * i, L, mid);
		build(2 * i + 1, mid + 1, R);
		
		for(int x = 0; x <= 1; x++)
		for(int y = 0; y <= 1; y++){
			tree[i][x][y] = 0;
			for(int z1 = 0; z1 <= 1; z1++)
			for(int z2 = 0; z2 <= 1; z2++){
				if(z1 == 1 && z2 == 0)continue;
				if(z1 == 1 && z2 == 1 && v[mid] > v[mid + 1])continue;
				if(z1 == 0 && z2 == 0 && v[mid] < v[mid + 1])continue;
				
				tree[i][x][y] = (tree[i][x][y] + tree[2 * i][x][z1] * tree[2 * i + 1][z2][y]) % MOD;
			}
		}
	}
}
void update(int i, int L, int R, int u, fraction t){
	if(u < L || u > R)return;
	if(L == R){
		return;
	}
	
	int mid = (L + R) / 2;
	
	update(2 * i, L, mid, u, t);
	update(2 * i + 1, mid + 1, R, u, t);
	
	for(int x = 0; x <= 1; x++)
	for(int y = 0; y <= 1; y++){
		tree[i][x][y] = 0;
		for(int z1 = 0; z1 <= 1; z1++)
		for(int z2 = 0; z2 <= 1; z2++){
			if(z1 == 1 && z2 == 0 && fraction(pos[mid + 1] - pos[mid], v[mid] + v[mid + 1]) < t)continue;
			if(z1 == 1 && z2 == 1 && v[mid] > v[mid + 1] && fraction(pos[mid + 1] - pos[mid], abs(v[mid] - v[mid + 1])) < t)continue;
			if(z1 == 0 && z2 == 0 && v[mid] < v[mid + 1] && fraction(pos[mid + 1] - pos[mid], abs(v[mid] - v[mid + 1])) < t)continue;
			
			tree[i][x][y] = (tree[i][x][y] + tree[2 * i][x][z1] * tree[2 * i + 1][z2][y]) % MOD;
		}
	}
}
long long totalprob(){
	return (tree[1][0][0] + tree[1][1][1] + tree[1][0][1] + tree[1][1][0]) % MOD;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d %d", &pos[i], &v[i], &p[i]);
	
	for(int i = 0; i < n - 1; i++){
		evs.push_back(event(fraction(pos[i + 1] - pos[i], v[i] + v[i + 1]), i));
		if(v[i] != v[i + 1])evs.push_back(event(fraction(pos[i + 1] - pos[i], abs(v[i] - v[i + 1])), i));
	}
	sort(evs.rbegin(), evs.rend());
		
	inv100 = modinv(100);
		
	build(1, 0, n - 1);
	
	long long res = 0, prob = totalprob();
	for(int i = 0; i < (int)evs.size(); i++){
		update(1, 0, n - 1, evs[i].ind, evs[i].f);
		
		long long curprob = totalprob();
		//cout << evs[i].f.p << ',' << evs[i].f.q << ' ' << curprob << endl;
		
		long long E = evs[i].f.p * modinv(evs[i].f.q) % MOD;
		res = (res + E * (curprob - prob + MOD)) % MOD;
		
		prob = curprob;
	}
	printf("%lld\n", res);
	
	return 0;
}