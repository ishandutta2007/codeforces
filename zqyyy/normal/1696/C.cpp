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
int n,m,K;
ll a[N],b[N];
#define GG return puts("No"),void()
inline void work(){
	n=read(),K=read();
	int cnt1=0,cnt2=0;
	ll lst=0,num=0;
	for(int i=1;i<=n;i++){
		int x=read();
		ll c=1;
		while(x%K==0)x/=K,c*=K;
		if(lst!=x){
			if(lst)a[++cnt1]=lst,a[++cnt1]=num;
			lst=x,num=0;	
		}
		num+=c;
	}
	a[++cnt1]=lst,a[++cnt1]=num;
	m=read(),lst=num=0;
	for(int i=1;i<=m;i++){
		int x=read();
		ll c=1;
		while(x%K==0)x/=K,c*=K;
		if(lst!=x){
			if(lst)b[++cnt2]=lst,b[++cnt2]=num;
			lst=x,num=0;	
		}
		num+=c;
	}
	b[++cnt2]=lst,b[++cnt2]=num;
	if(cnt1^cnt2)GG;
	for(int i=1;i<=cnt1;i++)
		if(a[i]^b[i])GG;
	puts("Yes");
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}