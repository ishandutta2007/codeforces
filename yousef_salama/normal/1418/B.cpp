#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		vector <int> a(n), l(n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		vector <int> val, ind;
		for(int i = 0; i < n; i++){
			scanf("%d", &l[i]);
			if(l[i] == 0){
				val.push_back(a[i]);
				ind.push_back(i);
			}
		}
		sort(val.rbegin(), val.rend());
		
		for(int i = 0; i < (int)val.size(); i++)
			a[ind[i]] = val[i];
		
		for(int i = 0; i < n; i++){
			if(i > 0)printf(" ");
			printf("%d", a[i]);
		}
		printf("\n");
	}
	return 0;
}