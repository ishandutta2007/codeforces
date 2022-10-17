#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define oo(x) fixed<<setprecision(x)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
char ch[1111];
int n,m;
int gcd(int x,int y){
	return !y ? x : gcd(y,x%y); 
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int main(){
	n=read(); m=read();
	if (m==1 && n==1){
		cout<<0<<"\n";
		return 0;
	}
	F(i,1,n){
		F(j,1,m){
			int x=i,y=j;
			if (n<m) y+=n;
			else x+=m;
			cout<<lcm(x,y)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}