#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10;
int lst[M],hd[M],a[M],n;
LL t[M],tt;
void upd(int x,int d){
	tt+=d-t[x];
	t[x]=d;
}
int main(){
	n=read(); 
	F(i,1,n) {
		a[i]=read();
		if (!hd[a[i]]) upd(a[i],n-i+1);
		lst[hd[a[i]]]=i;
		hd[a[i]]=i;	
	}
	LL ans=0;
	F(i,1,n){
		ans+=tt;
		if (lst[i]) {
			upd(a[i],n-lst[i]+1);
		}
		else upd(a[i],0);
	}
	ans=ans+(ans-n);
	cout<<fixed<<setprecision(10)<<ans/(1.0*n*n)<<"\n";
	return 0;
}