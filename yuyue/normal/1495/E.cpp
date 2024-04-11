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
const int mod=1e9+7;

const int M=5e6+10;
int n,m,seed,base,t[M],a[M],b[M];
int rnd(){
	LL ret=seed;
	seed=(1ll*seed*base+233)%mod;
	return ret;
}
int main(){
	n=read(); m=read();
	LL sm0=0,sm1=0,lst=0;
	F(i,1,m){
		int p=read(),k=read(),bb=read(),w=read();
		seed=bb; base=w;
		F(j,lst+1,p){
			t[j-1]=(rnd()%2)+1;
			a[j-1]=(rnd()%k)+1;
			b[j-1]=a[j-1];
			if (t[j-1]==2) sm1+=a[j-1];
			else sm0+=a[j-1];
		}
		lst=p;
	}
	int opt=2,pos=n;
	if (sm1>sm0) opt=1;
//	F(i,0,n-1){
//		cout<<a[i]<<" "<<t[i]<<"   gg\n";
//	}
	F(i,0,n-1){
		if (t[i]==opt){
			pos=i;
			break;
		}
	}
	
//	cout<<pos<<"\n";
	if (pos) a[0]--;
	LL tmp=0;
	F(T,1,3*n){
		if (a[pos]){
			if (t[pos]==opt) tmp+=a[pos],a[pos]=0;
			else {
				LL o=min(tmp,1ll*a[pos]);
				a[pos]-=o;
//				cout<<pos<<" - "<<o<<"  hry \n";
				tmp-=o;
			}
		}
		pos++;
		pos%=n;
	}
	LL ret=1;
	F(i,0,n-1){
		LL tt=(((1ll*(i+1)*(i+1))^((t[i]==opt ? b[i] : b[i]-a[i])))+1)%mod;
		ret=ret*tt%mod;
	}
	cout<<ret<<"\n";
	return 0; 
}
/*
100 1 100 2 0 1
*/