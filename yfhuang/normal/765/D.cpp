#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

int f[maxn];
int n;int g[maxn],h[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",f + i);
	}
	int m = 0;
	memset(g,0,sizeof(g));
	bool flag = true;
	for(int i = 1;i <= n;i++){
		if(g[i] != 0) continue;
		if(f[i] != i){
			int ff = f[f[i]];
			if(ff != f[i]) flag = false;
			else{
				if(g[f[i]] != 0){
					g[i] = g[f[i]];
				}else{
					g[i] = g[f[i]] = ++m;
					h[m] = f[i];
					//cout << m << " " << i << endl;
				}
			}
		}else{
			g[i] = ++m;
			h[m] = i;
			//cout << m << " " << i << endl;
		}
	}
	if(!flag){
		puts("-1");
		return 0;
	}
	printf("%d\n",m);
	//cout << m << endl;
	for(int i = 1;i <= n;i++){
		printf("%d%c",g[i],i == n ? '\n' : ' ');
	}for(int i = 1;i <= m;i++){
		printf("%d%c",h[i],i == m ? '\n' : ' ');
	}
	return 0;
}