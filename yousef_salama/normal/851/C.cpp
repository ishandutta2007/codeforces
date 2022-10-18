#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, a[MAXN][5];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	for(int j = 0; j < 5; j++)
		scanf("%d", &a[i][j]);
		
	if(n > 100)printf("0\n");
	else{
		vector <int> v;
		for(int i = 0; i < n; i++){
			bool ok = true;
			for(int x = 0; x < n; x++)
			for(int y = x + 1; y < n; y++){
				if(x == i)continue;
				if(y == i)continue;
				
				long long d = 0;
				for(int k = 0; k < 5; k++)
					d += (a[x][k] - a[i][k]) * (a[y][k] - a[i][k]);
				if(d > 0)ok = false;
			}
			if(ok)v.push_back(i);
		}
		printf("%d\n", (int)v.size());
		for(int x : v)
			printf("%d\n", x + 1);
	}
	return 0;
}