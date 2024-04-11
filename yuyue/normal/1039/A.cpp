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
const int M=2e5+10;
int n,p[M];
LL T;
LL a[M],b[M];
int s[M],nt[M];
int main(){
	n=read(); T=read();
	F(i,1,n){
		a[i]=read();
	}
	bool fl=0;
	F(i,1,n){
		p[i]=read();
		if (p[i]<p[i-1] || p[i]<i) fl=1;
		s[i]++; s[p[i]]--;
		nt[p[i]]=1;
	}
	F(i,1,n) s[i]+=s[i-1];
	if (fl){
		puts("No");
		return 0;
	}
	b[n]=3e18;
	F(i,1,n-1){
		if (s[i] && nt[i]){
			puts("No");
			return 0;	
		}
		if (s[i]) b[i]=a[i+1]+T;
		else b[i]=a[i+1]+T-1;
	}
	F(i,2,n){
		if (b[i]==b[i-1]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	F(i,1,n){
		cout<<b[i]<<" ";
	}
	cout<<"\n";
    return 0;
}