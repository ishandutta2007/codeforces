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
int a[M],n;
int s[M];
LL L[M],R[M];
int f[M];
int tp;
void out1(int pos){
	int lst=1;
	F(i,1,tp){
		F(j,lst,s[i]) f[j]=a[s[i]];
		lst=s[i]+1;
	}
}
void out2(int pos){
	int lst=n;
	F(i,1,tp){
		F(j,s[i],lst) f[j]=a[s[i]];
		lst=s[i]-1;
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	n=read();
	F(i,1,n){
		a[i]=read();
	}
	tp=1;
	LL ans=a[1]; s[1]=1; L[1]=a[1];
	F(i,2,n){
		while (tp && a[s[tp]]>a[i]) ans-=1ll*(i-s[tp-1]-1)*(a[s[tp]]-a[s[tp-1]]),tp--;
		s[++tp]=i;
		ans+=a[i]+1ll*(s[tp]-s[tp-1]-1)*(a[s[tp]]-a[s[tp-1]]);
		L[i]=ans;
//		cout<<ans<<"\n";
	}
	ms(s,0);
	tp=1;
	R[n]=ans=a[n]; s[1]=n; s[0]=n+1;
	DF(i,n-1,1){	
		while (tp && a[s[tp]]>a[i]) ans-=1ll*(s[tp-1]-i-1)*(a[s[tp]]-a[s[tp-1]]),tp--;
		s[++tp]=i;
		ans+=a[i]+1ll*(s[tp-1]-s[tp]-1)*(a[s[tp]]-a[s[tp-1]]);
		R[i]=ans;
//		cout<<ans<<"\n";
	}
	LL ret=0,p=0;
	F(i,1,n){
		if (L[i]+R[i]-a[i]>ret) ret=L[i]+R[i]-a[i],p=i;
	}
//	cout<<ret<<'\n';
	
	tp=1; ms(s,0);s[1]=1;
	if (p==1) f[1]=a[1];
	F(i,2,n){
		while (tp && a[s[tp]]>a[i]) tp--;
		s[++tp]=i;
		if (i==p) out1(p);
	}
	ms(s,0); tp=1; s[1]=n; s[0]=n+1;
	if (p==n) f[n]=a[n];
	DF(i,n-1,1){
		while (tp && a[s[tp]]>a[i]) tp--;
		s[++tp]=i;
		if (i==p) out2(p);
	}
	F(i,1,n) cout<<f[i]<<" ";
	return 0;
}