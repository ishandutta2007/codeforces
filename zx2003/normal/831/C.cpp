#include<cstdio>
#include<algorithm>
#include<set>
using std::set;
typedef long long ll;
const int N=2010;
int k,n,a[N],b[N],i,j,s[N],ans,kk,l;
set<int> ss;
set<int>::iterator it;
int main(){
	scanf("%d%d",&k,&n);
	if(k==1)return puts("1"),0;
	for(i=1;i<=k;++i){
		scanf("%d",a+i);
		ss.insert(s[i]=s[i-1]+a[i]);
	}
	for(i=1;i<=n;++i)scanf("%d",b+i);
	if(n>1){
		for(it=ss.begin();it!=ss.end();++it)s[++kk]=*it;
		std::sort(b+1,b+n+1);
		ss.clear();
		for(i=1;i<=kk;++i){
			for(j=2,l=i+1;j<=n && l<=kk;j+=b[j]-b[1]==s[l]-s[i],++l)
				while(l<=kk && b[j]-b[1]!=s[l]-s[i])
					++l;
			if(j>n)ss.insert(s[i]);
		}
	};
	return printf("%u\n",(unsigned int)ss.size()),0;
}