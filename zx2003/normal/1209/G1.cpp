#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,a[N],i,j,lst,mr,ri[N],aa[N],ct[N],ans;
int main(){
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=n;i;--i){
		if(!aa[a[i]])aa[a[i]]=i;
		ri[i]=aa[a[i]];++ct[a[i]];
	}
	ans=n;
	for(i=1;i<=n;++i){
		mr=max(mr,ri[i]);
		if(i==mr){
			int mx=0;
			for(j=lst+1;j<=mr;++j)mx=max(mx,ct[a[j]]);
			ans-=mx;lst=i;
		}
	}
	printf("%d\n",ans);
}