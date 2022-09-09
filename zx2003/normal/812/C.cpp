#include<cstdio>
#include<cctype>
#include<algorithm>
#include<iostream>
typedef long long ll;
inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x;
}
const int N=100010;
ll t,s,a[N],c[N],ans;
int l,r,m,n,i;
int main(){
	r=n=getint();
	s=getint();
	for(i=1;i<=n;++i)a[i]=getint();
	l=0;
	while(l<r){
		m=(l+r+1)>>1;
		for(i=1;i<=n;++i)c[i]=a[i]+1ll*i*m;
		std::sort(c+1,c+n+1);
		t=0;
		for(i=1;i<=m;++i)t+=c[i];
		if(t>s)r=m-1;
			else l=m,ans=t;
	}
	std::cout<<l<<" "<<ans;
	return 0;
}