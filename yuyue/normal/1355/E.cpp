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
const int M=1e5+10;
LL a[M],s;
LL n,A,D,C;
LL check(int mid){
	LL ca=0,cd=0;
	F(i,1,n){
		if (a[i]<mid) ca+=mid-a[i];
		else cd+=a[i]-mid;
	}
	if (C<A+D) return min(ca,cd)*C+(ca>cd ? A*(ca-cd) : D*(cd-ca));
	return ca*A+cd*D;
}
int main(){
	n=read(); A=read(); D=read(); C=read();
	F(i,1,n) a[i]=read(),s+=a[i];
	if (!A || !D){
		cout<<0<<"\n";
		return 0;
	} 
	if (!C){
		int o=s%n;
		cout<<min(1ll*o*D,1ll*(n-o)*A)<<"\n";
		return 0;
	}
	sort(a+1,a+n+1);
	LL p=a[n/2+1];
	LL l=0,r=1e9,ans=1e18;
	while (l<=r){
		int mid=(l+r>>1);
		LL m1=check(mid-1),m2=check(mid),m3=check(mid+1);
		LL o=min(m1,min(m2,m3));
		ans=min(ans,o);
		if (o==m1) r=mid-1;
		else l=mid+1;
				
	}
	cout<<ans<<"\n";
    return 0;
}