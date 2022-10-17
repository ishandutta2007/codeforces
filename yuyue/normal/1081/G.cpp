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
int n,k,mod,len,c[210101];
void solve(int l,int r,int dep){
	if (dep==k || l==r){
		len=max(len,r-l+1);
		c[r-l+1]++;
		return ;
	}
	int mid=(l+r>>1);
	solve(l,mid,dep+1);
	solve(mid+1,r,dep+1);
}
LL inv[210110];
LL calc(int x,int y){
	LL res=0;
	F(i,1,x+y){
		int l=max(1,i-x),r=min(y,i-1);
		res=(res+inv[i]*(r-l+1))%mod;
	}
	return (inv[2]*x%mod*y%mod+mod-res)%mod;
}
int main(){
	n=read(); k=read(); mod=read();
	inv[1]=1;
	F(i,2,2*n+10) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	solve(1,n,1);
//	cout<<len<<" "<<c[len-1]<<" "<<c[len]<<"   gg\n";
	LL a1=calc(len-1,len-1),a2=calc(len,len),a3=calc(len-1,len);
	LL ss=1ll*len*(len-1)%mod*c[len]%mod
	+1ll*(len-2)*(len-1)%mod*c[len-1]%mod;
	
	ss=ss*inv[4]%mod;
	LL st=a1*c[len-1]%mod*(c[len-1]-1)%mod*inv[2]+
		  a2*c[len]%mod*(c[len]-1)%mod*inv[2]+
		  a3*c[len-1]%mod*c[len]%mod;
	cout<<(ss+st)%mod;
    return 0;
}