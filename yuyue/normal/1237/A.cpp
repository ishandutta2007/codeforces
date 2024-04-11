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
vector<int> ji,ou;
int n,a[100000];
int main(){
	n=read(); 
	int tt=0;
	F(i,1,n) {
		a[i]=read();
		tt+=a[i];
		if (a[i]&1) ji.pb(i);
	}
	int num=SZ(ji)+1;
	int x=(num+tt)/2,y=(num-tt)/2;
	F(i,0,x-1) a[ji[i]]++;
	F(i,x,SZ(ji)) a[ji[i]]--;
	F(i,1,n) cout<<a[i]/2<<"\n"; 
    return 0;
}