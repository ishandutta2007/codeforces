#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2020;
int n,m,f[M*M];
int id(int x,int y){
	return (x-1)*m+y;
}
char a[M][M];
int vis[M*5];
int Fd(int x){
	return f[x]==x ? x : f[x]=Fd(f[x]);
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); m=read();
	bool fl=0;
	F(i,1,n*m) f[i]=i;
	F(i,1,n){
		scanf("%s",a[i]+1);
		F(j,1,m){
			if (a[i][j]=='#'){
				vis[i]=1;
				vis[j+n]=1;
				if (a[i-1][j]=='#'){
					f[Fd(id(i,j))]=Fd(id(i-1,j));
				}	
				if (a[i][j-1]=='#'){
					f[Fd(id(i,j))]=Fd(id(i,j-1));
				}	
			}
		}
	}
	int tx=0,ty=0;
	F(i,1,n) tx+=!vis[i];		
	F(i,1,m) ty+=!vis[i+n];
	if ((!tx)+(!ty)==1){
		puts("-1");
		return 0;
	}
	int ans=0; set<int> s;
	F(i,1,n){
		F(j,1,m){
			if (a[i][j]=='#') s.insert(Fd(id(i,j)));
		}
	}
	ans=s.size();
	F(i,1,n){
		s.clear();
		F(j,1,m){
			if (a[i][j]=='#'){
				if (a[i][j-1]!='#' && s.count(Fd(id(i,j)))) fl=1;
				s.insert(Fd(id(i,j))); 
			}
		}
		fl|=(s.size()>1);
	}
	F(i,1,m){
		s.clear();
		F(j,1,n){
			if (a[j][i]=='#'){
				if (a[j-1][i]!='#' && s.count(Fd(id(j,i)))) fl=1;
				s.insert(Fd(id(j,i))); 
			}
		}
		fl|=(s.size()>1);
	}
	if (fl) puts("-1");
	else cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/