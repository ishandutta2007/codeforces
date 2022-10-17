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
const int M=5e5+10;
LL calc(int n){
	return 1ll*n*n*(n+1)/2-1ll*n*(n+1)*(2*n+1)/6+1ll*n*(n+1)/2;
}
int n,a[M],L[M],R[M],b[M],m,len[M],lb[M],rb[M];
char ch[M];
int main(){
//	cout<<calc(3)<<"\n";
	n=read();
	scanf("%s",ch+1);
	int lst=1;
	F(i,1,n) a[i]=ch[i]-'0';
	LL ans=0; 
	F(i,1,n){
		if (a[i]^a[i+1] || i==n){
			b[++m]=a[i];
			L[m]=lst;
			R[m]=i; 
			len[m]=i-lst+1; 
			lst=i+1;
			if (b[m]){
				ans+=calc(len[m]);
			}
		} 
	}
	static int s[M],tp; 
	tp=0;
	F(i,1,m){
		if (b[i]){
			int pos=tp;
			F(x,1,len[i]){
				int l=0;
				while (pos && len[s[pos]]<=x) pos--;
				if (!pos) l=1;
				else l=R[s[pos]]-x+1;
				ans+=1ll*x*(L[i]-l);
				if (x==len[i]) lb[i]=l;
			}
			while (tp && len[i]>=len[s[tp]]) tp--;
			s[++tp]=i;
		}
	}
	tp=0;
	DF(i,m,1){
		if (b[i]){
			int pos=tp;
			F(x,1,len[i]){
				int r=n;
				while (pos && len[s[pos]]<x) pos--;
				if (!pos) r=n;
				else r=L[s[pos]]+x-2;
				ans+=1ll*x*(r-R[i]);
				if (x==len[i]) rb[i]=r;
			}
			ans+=1ll*len[i]*(L[i]-lb[i])*(rb[i]-R[i]);
			while (tp && len[i]>=len[s[tp]]) tp--;
			s[++tp]=i;
		}
	}
	cout<<ans<<"\n";
	return 0;
}