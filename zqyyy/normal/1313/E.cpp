#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=5e5+5;
int z[N<<1];
inline void Z(char *s,int n){
	for(int i=1;i<=n;i++)z[i]=0;
	z[1]=n;
	for(int i=2,l=0,r=0;i<=n;i++){
		if(i<=r)z[i]=min(z[i-l+1],r-i+1);
		while(i+z[i]<=n && s[z[i]+1]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1; 
	}
}
inline void exkmp(char *s,int n,char *t,int m,int *p){
	for(int i=1,l=0,r=0;i<=n;i++){
		if(i<=r)p[i]=min(z[i-l+1],r-i+1);
		while(i+p[i]<=n && p[i]<m && s[i+p[i]]==t[p[i]+1])p[i]++;
		if(i+p[i]-1>r)l=i,r=i+p[i]-1;
	}
}
char a[N],b[N],s[N<<1];
int n,m,p1[N],p2[N];
struct BIT{
	ll c[N<<1];
	#define lowbit(x) ((x)&-(x))
	inline void add(int p,int x){
		if(!p)return;
		for(;p<=m;p+=lowbit(p))c[p]+=x;
	}
	inline ll ask(int p){
		ll res=0;
		for(;p;p-=lowbit(p))res+=c[p];
		return res;	
	}
}t1,t2;
int main(){
	n=read(),m=read();
	scanf("%s%s%s",a+1,b+1,s+1);
	Z(s,m),exkmp(a,n,s,m,p1);
	reverse(s+1,s+m+1),reverse(b+1,b+n+1);
	Z(s,m),exkmp(b,n,s,m,p2);
	reverse(p2+1,p2+n+1);
	ll ans=0;
	for(int i=1,j=0;i<=n;i++){
		if(p1[i]==m)p1[i]--;
		while(j<n && j+1<i+m-1){
			if(p2[++j]==m)p2[j]--;
			t1.add(p2[j],p2[j]),t2.add(p2[j],1);
		}
		ans+=t1.ask(m)-t1.ask(m-p1[i]-1)-1ll*(t2.ask(m)-t2.ask(m-p1[i]-1))*(m-p1[i]-1);
		t1.add(p2[i],-p2[i]),t2.add(p2[i],-1);	
	}
	return cout<<ans,0;
}