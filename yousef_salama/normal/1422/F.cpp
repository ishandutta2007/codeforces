#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100005;
const int MAX = 200005;

long long modpow(long long x, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return x * modpow(x, p - 1) % MOD;
	
	long long r = modpow(x, p / 2);
	return r * r % MOD;
}
long long modinv(long long x){
	return modpow(x, MOD - 2);
}

vector < pair <int, int> > tree[4 * MAXN];
void update(int i, int L, int R, int u, int v, long long val, int ind){
	if(v < L || R < u)return;
	if(u <= L && R <= v){
		if(tree[i].empty()){
			tree[i].push_back({ind, val});
		}else{
			tree[i].push_back({ind, val * tree[i].back().second % MOD});
		}
		return;
	}
	
	int mid = (L + R) / 2;
	
	update(2 * i, L, mid, u, v, val, ind);
	update(2 * i + 1, mid + 1, R, u, v, val, ind);
}
long long query(int i, int L, int R, int u, int v){
	if(u < L || R < u)return 1;
	
	long long ret = 1;
	
	auto d = upper_bound(tree[i].begin(), tree[i].end(), make_pair(v, 1 << 30));
	if(d != tree[i].begin())ret = prev(d)->second;
	
	if(L == R)return ret;

	int mid = (L + R) / 2;
	ret = ret * query(2 * i, L, mid, u, v) % MOD * query(2 * i + 1, mid + 1, R, u, v) % MOD;
	return ret;
}
void print(int i, int L, int R){
	cout << i << " ====> ";
	for(pair <int, int> p : tree[i])
		cout << p.first << ',' << p.second << ' ';
	cout << endl;
	
	if(L == R)return;
	
	int mid = (L + R) / 2;
	print(2 * i, L, mid);
	print(2 * i + 1, mid + 1, R);
}


int main(){
	int n;
	scanf("%d", &n);
	
	vector < vector < pair <int, int> > > w(MAX);
	
	auto add = [&](int ind, int prime, int power){
					vector < pair <int, int> >& v = w[prime];
					
					while(!v.empty() && v.back().first <= power){
						if(v.size() > 1){
							update(1, 0, n - 1, v[(int)v.size() - 2].second + 1, v.back().second, modpow(prime, MOD - 1 - v.back().first), ind);
						}else{
							update(1, 0, n - 1, 0, v.back().second, modpow(prime, MOD - 1 - v.back().first), ind);
						}
						v.pop_back();
					}
					
					if(v.empty()){
						update(1, 0, n - 1, 0, ind, modpow(prime, power), ind);	
					}else{
						update(1, 0, n - 1, v.back().second + 1, ind, modpow(prime, power), ind);
					}
					v.push_back({power, ind});
				};
	
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		
		for(int j = 2; j * j <= a; j++)if(a % j == 0){
			int cnt = 0;
			while(a % j == 0){
				a /= j;
				cnt++;
			}
			add(i, j, cnt);
		}
		if(a > 1)add(i, a, 1);
	
		//cout << ">>>> " << i << endl;
		//print(1, 0, n - 1); 
	}
	/*
	for(int i = 1; i <= 10; i++){
		cout << i << " ::: ";
		for(auto p : w[i])
			cout << p.first << ',' << p.second << ' ';
		cout << endl;
	}*/
	
	int q, last = 0;
	scanf("%d", &q);
	
	while(q--){
		int x, y;
		scanf("%d %d", &x, &y);
		x = (x + last) % n;
		y = (y + last) % n;
		if(x > y)swap(x, y);
		
		//cout << x << ',' << y << ' ';
		
		last = query(1, 0, n - 1, x, y);
		printf("%d\n", last);
	}
	return 0;
}