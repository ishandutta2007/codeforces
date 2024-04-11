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
int n,m;
string ss[555],st[555];
int main(){
	n=read(); m=read();
	F(i,0,n-1) cin>>st[i];
	F(i,0,m-1) cin>>ss[i];
    int Q=read();
    while (Q--){
    	int x=read()-1;
    	cout<<st[x%n]<<ss[x%m]<<"\n";
	}
	return 0;
}