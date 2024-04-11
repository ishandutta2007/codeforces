#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int mod=19260817,M=4e5+10;
LL s[M];
int n,N;
#define lowbit(x) (x&-x)
void add(int x,LL d){
	for (;x<=N;x+=lowbit(x)) s[x]=(s[x]+d)%mod;
}
LL qry(int x){
	LL ans=0;
	for (;x;x-=lowbit(x)) ans=(ans+s[x])%mod;
	return ans;
}
LL sm(int l,int r){
	return (qry(r)-qry(l-1)+mod)%mod;
}
int c[M],ct;
struct node{
	int x,y,id;
}a[M],b[M],t[M];
bool cmpx(node x,node y){
	return x.x<y.x;
}
bool cmpy(node x,node y){
	return x.y<y.y;
}
int gt(int x){
	return lower_bound(c+1,c+N+1,x)-c;
}
LL coa[M],cob[M];
int main(){
	n=read();
	F(i,1,n){
		a[i]=(node){read(),read(),i};
		b[i]=(node){read(),read(),i};
		c[++ct]=a[i].x; 	c[++ct]=a[i].y; 
		c[++ct]=b[i].x; 	c[++ct]=b[i].y; 
	}
	sort(c+1,c+ct+1);
	N=unique(c+1,c+ct+1)-c-1;
	F(i,1,n){
		a[i].x=gt(a[i].x);	
		a[i].y=gt(a[i].y);	
		b[i].x=gt(b[i].x);	
		b[i].y=gt(b[i].y);	
	}
	F(i,1,n) t[i]=a[i];
	sort(t+1,t+n+1,cmpx);
	sort(a+1,a+n+1,cmpy);
	int j=0;
	F(i,1,n){
		while (j<n && t[j+1].x<=a[i].y) j++,add(t[j].y,1ll*t[j].id*t[j].id%mod*t[j].id%mod);
		coa[a[i].id]=sm(a[i].x,N);
	}
	ms(s,0);
	F(i,1,n) t[i]=b[i];
	sort(t+1,t+n+1,cmpx);
	sort(b+1,b+n+1,cmpy);
	j=0;
	F(i,1,n){
		while (j<n && t[j+1].x<=b[i].y) j++,add(t[j].y,1ll*t[j].id*t[j].id%mod*t[j].id%mod);
		cob[b[i].id]=sm(b[i].x,N);
	}
	F(i,1,n){
		if (coa[i]!=cob[i]){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
    return 0;
}