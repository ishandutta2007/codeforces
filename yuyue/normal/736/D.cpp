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
const int M=5e5+10;
int a[M],b[M];
int n,m;
bitset<4002> d[2002];
void inv(){
	F(i,1,n){
		F(j,i,n){
			if (d[j][i]){
				swap(d[i],d[j]);
				break;
			}
		}
		F(j,1,n){
			if (j^i && d[j][i]){
				d[j]^=d[i];
			}
		}
	}
}
int main(){
	n=read(); m=read();
	F(i,1,m){
		a[i]=read();
		b[i]=read();
		d[a[i]][b[i]]=1;
	}
	F(i,1,n){
		d[i][i+n]=1;
	}
	inv();
	F(i,1,m){
		if (!d[b[i]][a[i]+n]) puts("YES");
		else puts("NO");
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/