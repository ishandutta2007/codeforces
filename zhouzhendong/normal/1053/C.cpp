#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005,mod=1e9+7;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x*f;
}
int n,Q;
int a[N],w[N];
LL c1[N];
int c2[N];
void add(int &x,int y){if ((x+=y)>=mod)x-=mod;}
void add1(int x,LL d){for (;x<=n;x+=x&-x)c1[x]+=d;}
void add2(int x,int d){for (;x<=n;x+=x&-x)add(c2[x],d);}
LL ask1(int x){LL ans=0;for (;x;x-=x&-x)ans+=c1[x];return ans;}
int ask2(int x){int ans=0;for (;x;x-=x&-x)add(ans,c2[x]);return ans;}
void opt1(int i,int nw){
	add1(i,-w[i]);
	add2(i,(-1LL*w[i]*a[i]%mod+mod)%mod);
	w[i]=nw;
	add1(i,w[i]);
	add2(i,1LL*w[i]*a[i]%mod);
}
void opt2(int L,int R){
	LL t=ask1(L-1);
	LL sum=ask1(R)-t;
	int le=L,ri=R,mid,ans=R;
	while (le<=ri){
		mid=(le+ri)>>1;
		LL v=ask1(mid)-t;
		if (v*2>=sum)
			ri=mid-1,ans=mid;
		else
			le=mid+1;
	}
	LL v11=ask2(ans)-ask2(L-1),v12=-1LL*a[ans]*((ask1(ans)-t)%mod)%mod;
	LL v21=ask2(R)-ask2(ans),v22=-1LL*a[ans]*((ask1(R)-ask1(ans))%mod)%mod;
	LL Ans=(v21+v22-v11-v12)%mod;
	Ans=(Ans+mod)%mod;
	printf("%I64d\n",Ans);
}
int main(){
	n=read(),Q=read();
	for (int i=1;i<=n;i++)
		a[i]=read()-i+n;
	memset(c1,0,sizeof c1);
	memset(c2,0,sizeof c2);
	for (int i=1;i<=n;i++){
		w[i]=read();
		add1(i,w[i]);
		add2(i,1LL*w[i]*a[i]%mod);
	}
	while (Q--){
		int x=read(),y=read();
		if (x<0)
			opt1(-x,y);
		else
			opt2(x,y);
	}
	return 0;
}