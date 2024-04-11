#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline int
typedef long long ll;
I read(int &res){
    re g=1;register char ch=getchar();res=0;
    while(!isdigit(ch)){
        if(ch=='-')g=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar();
    }
    res*=g;
}
const int E=1e9+7;
struct P{
	int out,in;
	friend bool operator < (P x,P y){
		return x.out==y.out?x.in<y.in:x.out<y.out;
	}
}p[202000];
int n,m,f[202000],g[202000],s[202000],w[202000],a[202000],maxi=-1,mini=E,sum,ans=0;
int main(){
	read(n);sum=E;
	F(i,1,n){
		read(p[i].out);read(p[i].in);
		maxi=max(maxi,p[i].in);
		mini=min(mini,p[i].out);
	}
	sort(p+1,p+1+n);
	F(i,1,n){
		a[i]=p[i].out;
		if(p[i].in<mini)g[i]=1;
	}
	F(i,1,n){
		m=(int)(upper_bound(a+1,a+1+n,p[i].in)-a-1);
		f[i]=s[m]+p[i].in;
		if(!g[i])g[i]=w[m];
		re t=f[i]-p[i].out;
		if(t==s[i-1]&&i!=1){
			w[i]=g[i]+w[i-1];
			w[i]%=E;
		}
		else if(t<s[i-1]||i==1){
			w[i]=g[i];
		}
		else w[i]=w[i-1];
		s[i]=min(s[i-1],t);
		if(p[i].out>maxi)sum=min(sum,f[i]);
	}
	F(i,1,n){
		if(p[i].out>maxi&&f[i]==sum)ans=(ans+g[i])%E;
	}
	cout<<ans;
    return 0;
}