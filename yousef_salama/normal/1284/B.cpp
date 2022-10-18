#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, li, si;
bool ok[MAXN];
vector <int> v[MAXN], w;

int main(){
	scanf("%d", &n);
	
	long long res = 1LL * n * n;
	for(int i = 0; i < n; i++){
		scanf("%d", &li);
		
		int prv = 1LL << 30;
		for(int j = 0; j < li; j++){
			scanf("%d", &si);
			v[i].push_back(si);
			
			if(si <= prv)prv = si;
			else prv = -1;
		}
		
		if(prv != -1){
			ok[i] = true;
			w.push_back(v[i][0]);
		}
	}
	
	sort(w.begin(), w.end());
	for(int i = 0; i < n; i++)if(ok[i])
		res -= upper_bound(w.begin(), w.end(), v[i].back()) - w.begin();
	
	printf("%lld\n", res);
	
	return 0;
}