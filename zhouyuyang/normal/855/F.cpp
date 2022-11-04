#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
#define MN 100000
int a[MN+5],b[MN+5],c[MN+5];
int main(){
	int n,t,l,r,k,i;long long ans=0;
	for(scanf("%d",&n);n--;){
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){
			scanf("%d",&k);
			if(k>0)
			    for(i=l;i<r;++i)
			        a[i]=a[i]?a[i]<k?a[i]:k:k,
			        b[i]?c[i]=a[i]+b[i]:0;
			else
			    for(k=-k,i=l;i<r;++i)
			        b[i]=b[i]?b[i]<k?b[i]:k:k,
			        a[i]?c[i]=a[i]+b[i]:0;
		}
		else{
		    for(ans=0,i=l;i<r;++i)
		        ans+=c[i];
		    printf("%I64d\n",ans);
		} 
	}
}