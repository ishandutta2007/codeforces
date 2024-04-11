#include<bits/stdc++.h>
using namespace std;
int a[100100],ans=-1<<20,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		for(int j=0;j*j<=a[i];++j)if(j*j==a[i])goto nxt;
		ans=max(ans,a[i]);
		nxt:;
		
	}
	printf("%d",ans);
}