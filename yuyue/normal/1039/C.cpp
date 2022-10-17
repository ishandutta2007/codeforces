#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
LL read(){
    char ch=getchar(); LL w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=5e5+10,mod=1e9+7;
int n,m,k;
LL c[M];
struct edge{
	int x,y;
	LL z;
}e[M];
bool cmp(edge A,edge B){
	return A.z<B.z;
}
int f[M];
int Fd(int x){
	if (f[x]==x) return x;
	return f[x]=Fd(f[x]);
}
LL pw[M];
int main(){
	n=read(); m=read(); k=read();
	F(i,1,n) c[i]=read();
	pw[0]=1;
	F(i,1,n) pw[i]=pw[i-1]*2%mod;
	F(i,1,n) f[i]=i;
	F(i,1,m){
		int x=read(),y=read();
		e[i]=(edge){x,y,c[x]^c[y]};
	}
	sort(e+1,e+m+1,cmp);
	LL lst=-1,ans=0;
	F(i,1,m){
		int j=i;
		int con=n;
		vector<int> nd;
		while (j<=m &&  e[j].z==e[i].z){
			int X=Fd(e[j].x),Y=Fd(e[j].y);
//			cout<<X<<" "<<Y<<"    hhhh\n";
			if (X^Y){
				con--;
				f[X]=Y;
				nd.pb(X); nd.pb(Y);
			}
			j++;
		}
		j--;
		LL im=e[j].z-lst-1; im%=mod;
		ans=(ans+im*pw[n])%mod;
//		cout<<im<<" "<<con<<"   wo h\n";
		ans=(ans+pw[con])%mod;
		lst=e[j].z;
		for (int x:nd) f[x]=x;
		i=j; 
	}
	LL im=(1ll<<k)-lst-1; im%=mod;
//	cout<<im<<"   ppp\n";
	ans=(ans+im*pw[n])%mod;
	cout<<ans<<"\n";
    return 0;
}