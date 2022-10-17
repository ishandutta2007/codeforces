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
LL n,S;
int main(){
	n=read(); S=read();
	LL T=S-n+1;
	if (n==1) {
		if (S==1) cout<<"NO\n";
		else {
			cout<<"YES\n"<<S<<"\n"<<S-1<<"\n";
		}
		return 0;
	}
	if (T>S/2 && S-T<S/2){
		cout<<"YES\n";
		F(i,1,n-1) cout<<1<<" ";
		cout<<T<<'\n';
		cout<<S/2<<"\n";
	}
	else {
		cout<<"NO\n";
	}
    return 0;
}