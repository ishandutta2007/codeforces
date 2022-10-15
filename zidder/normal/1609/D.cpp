#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 1005;
int par[N];
int sz[N];
int stsz;
int bsum = 0;
multiset<int> small, big;

void binsert(int v){
	big.insert(v);
	bsum+=v;
}

void berase(int v){
	big.erase(big.find(v));
	bsum-=v;
}

int dsu(int a){
	if (par[a] == a) return a;
	return par[a] = dsu(par[a]);
}

bool merge(int a, int b){
	a = dsu(a);
	b = dsu(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a, b);
	if (small.find(sz[a]) != small.end()) small.erase(small.find(sz[a]));
	else berase(sz[a]);
	if (small.find(sz[b]) != small.end()) small.erase(small.find(sz[b]));
	else berase(sz[b]);
	par[b] = a;
	sz[a] += sz[b];
	if (big.size() < stsz) binsert(sz[a]);
	else if (sz[a] > *big.begin()){
		small.insert(*big.begin());
		berase(*big.begin());
		binsert(sz[a]);
	}
	else small.insert(sz[a]);
	if (big.size() < stsz) {
		binsert(*small.rbegin());
		small.erase(--small.end());
	}
	return true;
}

void inc(){
	stsz++;
	binsert(*small.rbegin());
	small.erase(--small.end());
}

void solve(int test_ind){
	int n, d;
	cin >> n >> d;

	for (int i=0;i<n;++i){
		par[i] = i;
		sz[i] = 1;
		small.insert(1);
	}

	small.erase(small.find(1));
	binsert(1);
	stsz = 1;

	int ans = 0;
	for (int i=0;i<d;++i){
		int a, b;
		scanf("%d%d", &a, &b);
		a--;b--;
		if (!merge(a, b)){
			inc();
		}
		cout << bsum - 1 << endl;
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}