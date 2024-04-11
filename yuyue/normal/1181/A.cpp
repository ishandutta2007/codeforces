#include<bits/stdc++.h>
#define LL long long
#define rep(i,n) for (int i=0;i<(n);i++)
#define Rep(i,n) for (int i=1;i<=(n);i++)
using namespace std;
LL read(){
    char ch=getchar(); LL w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}

int main(){
	LL x=read(),y=read(),z=read();
	cout<<(x+y)/z<<" ";
	LL num=(x+y)/z;
	LL a=x/z,b=y/z;
	if (num==a+b) cout<<0<<"\n";
	else cout<<min(z-x%z,z-y%z)<<"\n";
    return 0;
}