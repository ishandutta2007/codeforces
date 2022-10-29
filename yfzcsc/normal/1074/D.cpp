#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
const int maxn=1e5+10;
tr1::unordered_map<int,int>f,val;
int Q;
int find(int x){
	if(!f.count(x))return val[x]=0,f[x]=x;
	if(x==f[x])return x;
	int z=f[x];
	f[x]=find(f[x]);
	val[x]^=val[z];
	return f[x];
}
int main(){
	scanf("%d",&Q);
	int lst=0;
	for(int i=1,t,l,r,x;i<=Q;++i){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d%d",&l,&r,&x);
			l^=lst,r^=lst,x^=lst;
			if(l>r)swap(l,r);
			int L=l-1,R=r;
			l=find(l-1),r=find(r);
//			printf("[%d->%d]",L,R);
			if(l!=r)f[l]=r,val[l]=val[L]^val[R]^x;
		} else {
			scanf("%d%d",&l,&r);
			l^=lst,r^=lst;
			if(l>r)swap(l,r);
//			printf("{%d,%d}",l-1,r);
			int L=l-1,R=r;
			l=find(l-1),r=find(r);
			if(l!=r)lst=1,puts("-1");
			else printf("%d\n",lst=val[L]^val[R]);
		}
	}
}