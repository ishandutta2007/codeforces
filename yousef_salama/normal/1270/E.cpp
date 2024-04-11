#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, x[MAXN], y[MAXN];
long long d[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
		
	vector <int> A;
	
	for(int i = 0; i < n; i++)
		d[i] = 1LL * (x[i] - x[0]) * (x[i] - x[0]) + 1LL * (y[i] - y[0]) * (y[i] - y[0]);
	
	for(int s = 0; ; s++){
		bool found = false;
		for(int i = 0; i < n; i++){
			if(d[i] % 2 != 0){
				found = true;
				break;
			}
		}
		
		if(found){
			for(int i = 0; i < n; i++)
				if(d[i] % 2 == 0)A.push_back(i);
				
			printf("%d\n", (int)A.size());
			for(int i = 0; i < (int)A.size(); i++){
				if(i > 0)printf(" ");
				printf("%d", A[i] + 1);
			}
			printf("\n");
			
			break;
		}else{
			for(int i = 0; i < n; i++)
				d[i] /= 2;
		}
	}
	
	return 0;
}