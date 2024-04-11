#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int maxn = 2e5 + 5;

int n, f;
bool is_prime[maxn];
int prime[maxn];
int tot;

void init(){
	memset(is_prime, 0, sizeof(is_prime));
	is_prime[0] = true;
	is_prime[1] = true;
	tot = 0;
	for(int i = 2;i < maxn;i++){
		if(!is_prime[i]){
			prime[++tot] = i;
			for(int j = 2 * i;j < maxn;j += i){
				is_prime[j] = true;
			}
		}
	}
	for(int i = 1;i <= tot;i++){
		for(int j = i;j <= tot;j++){
			if(1LL * prime[i] * prime[j] >= maxn)
				break;
			is_prime[prime[i] * prime[j]] = false;
		}
	}
}


int main(){
	bitset<maxn> p;
	init();
	for(int i = 0;i < maxn;i++){
		if(!is_prime[i])
			p[i] = true;
	}
	while(cin >> n >> f){
		p[f] = false;
		vector<bitset<maxn> > W(100);
		vector<int> G(maxn, 0);
		W[0] = p;
		for(int i = 1;i < maxn;i++){
			while(W[G[i]][i]) G[i]++;
			W[G[i]] |= p << i;
		}
		int g = 0;
		for(int i = 1;i <= n;i++){
			int r, w, b;
			scanf("%d%d%d",&r, &w, &b);
			g ^= G[w - r - 1];
			g ^= G[b - w - 1];
		}
		if(g == 0){
			cout << "Bob\nAlice\n" << endl;
		}else{
			cout << "Alice\nBob\n" << endl;
		}
	}
	return 0;
}