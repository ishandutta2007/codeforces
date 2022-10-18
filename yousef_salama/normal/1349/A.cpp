#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	const int MAX = 200005;
	vector < vector <int> > v(MAX);
	
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		
		for(int d = 2; d * d <= a; d++)if(a % d == 0){
			int cnt = 0;
			while(a % d == 0){
				a /= d;
				cnt++;
			}
			v[d].push_back(cnt);
		}
		if(a > 1)v[a].push_back(1);
	}
	
	long long g = 1;
	for(int i = 0; i < MAX; i++){
		if((int)v[i].size() <= n - 2)continue;
		
		sort(v[i].begin(), v[i].end());
		
		if((int)v[i].size() == n){
			for(int j = 0; j < v[i][1]; j++)
				g *= i;
		}else{
			for(int j = 0; j < v[i][0]; j++)
				g *= i;
		}
	}
	printf("%lld\n", g);
	
	return 0;
}