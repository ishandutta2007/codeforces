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
const int M=1e5+10,N=222;
int n,m;
int id(int x,int y){
	return (x-1)*m+y;
}
int p[M],t[M];
LL a[N][N],b[N][N];
bool us[N][N];
bool cmp(int x,int y){
	return t[x]<t[y];
}
void work(){
	n=read(); m=read();
	F(i,1,n){
		F(j,1,m){
			a[i][j]=read();	
			t[id(i,j)]=a[i][j];
			p[id(i,j)]=id(i,j);
			b[i][j]=us[i][j]=0;
		}
	}
	sort(p+1,p+n*m+1,cmp);
	F(i,1,m){
		int o=(p[i]-1)/m+1,oo=(p[i]-1)%m+1;
		b[o][i]=t[p[i]];
		us[o][oo]=1;
	}
	F(i,1,n){
		int ps=1;
		F(j,1,m){
			if (!us[i][j]){
				while (ps<=m && b[i][ps]) ps++;
				b[i][ps]=a[i][j];
			}
		}
	}
	F(i,1,n){
		F(j,1,m){
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int main(){
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/