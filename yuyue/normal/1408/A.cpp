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
int a[M],b[M],c[M],d[M];
int main(){
	int T=read();
	while(T--){
		int n=read(); 
		F(i,1,n){
			a[i]=read();
		}
		F(i,1,n){
			b[i]=read();
		}
		F(i,1,n){
			c[i]=read();
		}
		d[1]=a[1];
		F(i,2,n-1){
			if (a[i]!=d[i-1]){
				d[i]=a[i];
			}
			else if (b[i]!=d[i-1]){
				d[i]=b[i];
			}else {
				d[i]=c[i];
			}
		}
		if (a[n]!=d[n-1] && a[n]!=d[1]){
			d[n]=a[n];
		}
		else if (b[n]!=d[n-1] && b[n]!=d[1]){
			d[n]=b[n];
		}else {
			d[n]=c[n];
		}
		F(i,1,n) cout<<d[i]<<" ";
		cout<<"\n";
	}
	return 0;
}