#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10;
int n,a[M],x,y;
int main(){
	n=read(); x=read(); y=read();
	F(i,1,n) a[i]=read();
	F(i,1,n){
		bool fl=0;
//		cout<<i-x<<" "<<i+y<<"\n";
		F(j,i-x,i+y){
			if (j==i || j<=0 || j>n) continue;
//			if (i==5)	cout<<j<<" ";

			if (a[j]<=a[i]){
				fl=1;
				break;
			}
		}
		if (!fl) {
			cout<<i<<"\n";
			break;
		}
	}
	return 0;
}