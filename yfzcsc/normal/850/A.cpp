#include<bits/stdc++.h>
#define maxn 10010
using namespace std;
int a[maxn][10],good[maxn],tp,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=5;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)if(j!=i)
			for(int k=j+1;k<=n;++k)if(k!=i){
				int ans=0;
				for(int l=1;l<=5;++l)
					ans+=(a[j][l]-a[i][l])*(a[k][l]-a[i][l]);
				if(ans>0)goto nxt;
			}
		good[++tp]=i;
		nxt:;
	}
	printf("%d\n",tp);
	for(int i=1;i<=tp;++i)printf("%d\n",good[i]);
}