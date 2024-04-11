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
const int M=1e5+10;
LL n,a[M];
int main(){
	n=read();
	F(i,1,n) a[i]=read();
	cout<<"1 1\n"<<-a[1]<<"\n";
	if (n==1) {
		F(i,1,2)	cout<<"1 1\n"<<0<<"\n";
		return 0;
	}
	cout<<2<<" "<<n<<"\n";
	a[1]=0;
	F(i,2,n){
		LL tmp=1ll*a[i]*(n-1);
		cout<<tmp<<" ";
		a[i]+=tmp;
	}
	cout<<"\n"<<1<<" "<<n<<"\n";
	F(i,1,n){
		cout<<-a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}