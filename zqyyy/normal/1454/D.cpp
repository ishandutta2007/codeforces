#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,m,mx,num;
inline void work(){
	n=m=num=read();mx=1;
	for(int i=2;i*i<=m;i++)
		if(m%i==0){
			int cnt=0;
			while(m%i==0)m/=i,cnt++;
			if(cnt>mx)mx=cnt,num=i;
		}
	printf("%lld\n",mx);
	for(int i=1;i<mx;i++)printf("%lld ",num),n/=num;
	printf("%lld\n",n);
}
signed main(){
	int T=read();
	while(T--)work();
	return 0;
}