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
const int M=1e5+10;
map<int,int> ma,mb; 
int a[M],b[M],t[M],n,m;
int main(){
	n=read(); m=read();
	F(i,1,n){
		a[i]=read(); //ma[a[i]]++;
	}
	F(i,1,n){
		b[i]=read(); //mb[b[i]]++;
	}
	sort(b+1,b+n+1);
	int bst=m;
	F(i,1,n){
		int x=(b[i]-a[1]+m)%m;
		F(j,1,n){
			t[j]=(a[j]+x)%m;
		}
		sort(t+1,t+n+1);
		bool dif=0;
		F(j,1,n) {
			if (t[j]!=b[j]) dif=1;
		}
		if (!dif){
			bst=min(bst,x);
		}
	}
	cout<<bst<<"\n";
	
    return 0;
}