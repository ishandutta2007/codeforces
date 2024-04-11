#include<bits/stdc++.h>
using namespace std;
int a[100100],n,b[100100],id[100100];
int comp(int x,int y){
	return a[x]<a[y];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=i;
	sort(b+1,b+n+1,comp),sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)id[b[i]]=i;
	if(unique(a+1,a+n+1)-a-1!=n)return puts("-1"),0;
	for(int i=1;i<=n;++i)printf("%d ",a[(id[i])%n+1]);
}