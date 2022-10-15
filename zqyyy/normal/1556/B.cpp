#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,a[N],b[2];
inline void work(){
	n=read(),b[0]=b[1]=0;
	for(int i=1;i<=n;i++)b[a[i]=read()&1]++;
	if(n&1){
		int p=b[1]>b[0];
		if(b[p]-b[p^1]!=1){puts("-1");return;}
		ll ans=0,num=0;
		for(int i=1;i<=n;i++)
			if(a[i]==p)ans+=abs(2*num+1-i),num++;
		printf("%lld\n",ans);
		return;	
	}
	if(b[0]!=b[1]){puts("-1");return;}
	ll sum=0,ans=0,num=0,p=1;
	for(int i=1;i<=n;i++)
		if(a[i]==p)ans+=abs(2*num+1-i),num++;
	sum=ans,p=ans=num=0;
	for(int i=1;i<=n;i++)
		if(a[i]==p)ans+=abs(2*num+1-i),num++;
	sum=min(sum,ans);
	printf("%lld\n",sum);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}