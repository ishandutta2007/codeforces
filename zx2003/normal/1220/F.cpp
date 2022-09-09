#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int N=4e5+5;
int n,a[N],i,d1[N],d2[N],st[N],w,d[N],mxid,mnid=n,b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),a[n+i]=a[i];
	for(i=1;i<=n*2;++i){
		for(;w && a[st[w]]>=a[i];d1[i]=max(d1[i],d1[st[w--]]+1));
		st[++w]=i;d1[i]=max(d1[i],w);
	}
	mxid=st[1]-n;
	w=0;
	for(i=n*2;i;--i){
		for(;w && a[st[w]]>=a[i];d2[i]=max(d2[i],d2[st[w--]]+1));
		st[++w]=i;d2[i]=max(d2[i],w);
	}
	b[mxid]=b[mxid+n]=1;
	for(i=mxid+1;i<mxid+n;++i)b[i]=max(b[i-1],d1[i]);
	for(i=mxid+n+1;i<n*2;++i)b[i]=max(b[i-1],d1[i]);
	for(i=n;i<n*2;++i)d[i]=max(d[i],b[i]);
	b[mxid]=b[mxid+n]=1;
	for(i=mxid+n-1;i>mxid;--i)b[i]=max(b[i+1],d2[i]);
	for(i=mxid-1;i;--i)b[i]=max(b[i+1],d2[i]);
	mnid=n;
	for(i=n;i<n*2;++i){
		d[i]=max(d[i],b[i-n+1]);
		if(d[i]<d[mnid])mnid=i;
	}
	printf("%d %d\n",d[mnid],mnid-n);
	return 0;
}