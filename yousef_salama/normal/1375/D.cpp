#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int t, n, a[MAXN];
bool m[MAXN];

int getmex(){
	memset(m, false, sizeof m);
	for(int i = 0; i < n; i++)m[a[i]] = true;
	
	int j = 0;
	while(m[j])j++;

	return j;
}


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		vector <int> v;	
		while(true){
			int j = getmex();
			
			if(j == n){
				bool found = false;
				for(int i = 0; i < n; i++)if(a[i] != i){
					v.push_back(i + 1);
					a[i] = n;
					
					found = true;
					break;
				}
				
				if(!found)break;
			}else{
				v.push_back(j + 1);
				a[j] = j;
			}
		}
		
		printf("%d\n", (int)v.size());
		for(int i = 0; i < (int)v.size(); i++){
			if(i > 0)printf(" ");
			printf("%d", v[i]);
		}
		printf("\n");
	}
	return 0;
}