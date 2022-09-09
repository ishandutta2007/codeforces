#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,s1,s2,a[N],i,l,r,m,u,v,y,z;
int main(){
	scanf("%d%d%d",&n,&s1,&s2);if(s1>s2)swap(s1,s2);l=s2-s1;
	for(i=1;i<=n;++i)scanf("%d",a+i),r=max(r,max(abs(s1-a[i]),abs(s2-a[i])));
	for(;l<r;){
		m=(l+r)>>1;u=a[n]-m,v=a[n]+m;
		for(i=n-1;i && u<=v;--i)
			if(u<=a[i] && a[i]<=v)u=a[i]-m,v=a[i]+m;
				else u=max(u,a[i]-m),v=min(v,a[i]+m);
		if((u<=s1 && s1<=v) || (u<=s2 && s2<=v))r=m;
			else l=m+1;
	}
	return printf("%d\n",l),0;
}