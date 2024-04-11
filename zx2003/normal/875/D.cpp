#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
const int N=200005;
int n,a[N],i,b[40],j,pre[N],nxt[N];
ll ans;
map<int,int> lst;
inline int min(int a,int b){
	return a>b?b:a;
}
inline int max(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d",&n);ans=1ll*n*(n+1)/2;
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		if(!lst.count(a[i]))lst[a[i]]=0;
		for(j=0,pre[i]=lst[a[i]];j<30;++j)
			if(a[i]>>j&1)b[j]=i;
				else pre[i]=max(b[j],pre[i]);
		lst[a[i]]=i;
	}
	for(i=0;i<30;++i)b[i]=n+1;
	for(i=n;i;--i)
		for(j=0,nxt[i]=n+1;j<30;++j)
			if(a[i]>>j&1)b[j]=i;
				else nxt[i]=min(b[j],nxt[i]);
	for(i=1;i<=n;++i)ans-=1ll*(i-pre[i])*(nxt[i]-i);cout<<ans<<endl;
	return 0;
}