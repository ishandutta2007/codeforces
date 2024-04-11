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
int main(){
	int x=4,y=5;
	int n=read();
	if (n==1 || n==2) {
	cout<<"1\n";	
	return 0;
	}
	while (y<n) {
		if (x&1) x=2*y,y=x+1;
		else x=x*2+1,y=x+1; 	
	}
	cout<<(x==n || y==n)<<"\n";
    return 0;
}