#include<bits/stdc++.h>
const int N=150005;
int p[N],t[N],n,i,j,k,a[N],b[N];
long long T,st,mn[N],mx[N];
double l,r=1,m,v;
inline bool cmp(const int&x,const int&y){return 1ll*p[x]*t[y]>1ll*p[y]*t[x];}
inline bool cmp2(const int&x,const int&y){return p[x]<p[y];}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",p+i),a[i]=b[i]=i;
	for(i=1;i<=n;++i)scanf("%d",t+i),T+=t[i];
	std::sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i=j){
		for(j=i;j<=n && !cmp(a[i],a[j]);++j);
		for(k=i;k<j;++k)mx[a[k]]=st+t[a[k]];
		for(k=i;k<j;++k)st+=t[a[k]];
		for(k=i;k<j;++k)mn[a[k]]=st;
	}
	std::sort(b+1,b+n+1,cmp2);
	for(;r-l>1e-8;){
		m=(l+r)/2;
		v=0;
		for(i=j=1;i<=n;++i){
			for(;p[b[j]]<p[b[i]];++j)v=std::max(v,(1-m*mx[b[j]]/T)*p[b[j]]);
			if(v>(1-m*mn[b[i]]/T)*p[b[i]])break;
		}
		if(i<=n)r=m;else l=m;
	}
	printf("%.8f\n",l);
	return 0;
}