#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,a[N],i,rb[N];
int st[N],w,l,r,m;
int main(){
	for(int&x:rb)x=N;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),a[i+n]=a[i+n*2]=a[i];
	for(i=1;i<=n*3;++i){
		for(;w && a[i]>a[st[w]];--w);st[++w]=i;
		if(a[i]*2>=a[st[1]])continue;
		l=1;r=w;for(;l<r;){m=l+r+1>>1;if(a[i]*2<a[st[m]])l=m;else r=m-1;}
		rb[st[l]]=min(rb[st[l]],i);
	}
	for(i=n*3;i;--i)rb[i]=min(rb[i],rb[i+1]);
	for(i=1;i<=n;++i)printf("%d%c",rb[i]==N?-1:rb[i]-i,i==n?'\n':' ');
	return 0;
}