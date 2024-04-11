#include<bits/stdc++.h>
using namespace std;
int T,lst,a[110],n,bs[1001000],cas;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),++cas;
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int tp=0;
		puts("YES");
		for(int i=1;i<=1000000&&tp<n;++i){
			if(bs[i]!=cas){
				printf("%d ",i),tp++;
				for(int j=1;j<=n;++j)for(int k=j+1;k<=n;++k)
					bs[min(abs(a[j]-a[k])+i,1000001)]=cas;
			}
		}
		puts("");
	}
}