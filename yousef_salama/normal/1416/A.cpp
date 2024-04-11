#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		vector < vector <int> > v(n);
		for(int i = 0; i < n; i++){
			int a;
			scanf("%d", &a);
			
			v[a - 1].push_back(i);
		}
		
		vector <int> evs(n, n);
		for(int i = 0; i < n; i++)if(!v[i].empty()){
			int d = max(v[i][0], n - v[i].back() - 1);
			for(int j = 0; j + 1 < (int)v[i].size(); j++)
				d = max(d, v[i][j + 1] - v[i][j] - 1);
			
			evs[d] = min(evs[d], i);
		}
		
		int mn = n;
		for(int i = 0; i < n; i++){
			if(i > 0)printf(" ");
			
			mn = min(mn, evs[i]);
			printf("%d", mn == n ? -1 : mn + 1);
		}
		printf("\n");
	}
	return 0;
}