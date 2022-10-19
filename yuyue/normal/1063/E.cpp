#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1024;
int n,p[M],rp[M];
bool vis[M]; 
int a[M][M],b[M];//1 \ 2 / 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	bool fl=1;
	F(i,1,n) p[i]=read(),fl&=(p[i]==i),rp[p[i]]=i;
	if (fl){
		cout<<n<<"\n";
		F(i,1,n){
			F(j,1,n){
				cout<<'.';
			}
			cout<<"\n";
		}
		return 0;
	}
	int now=n,bg=0;
	F(i,1,n){
		if (!vis[i]){
			if (p[i]==i) continue;
			int ct=0;
			for (int x=i;!vis[x];x=p[x]){
				vis[x]=1;
				b[++ct]=x;
			}
			if (!bg){
				bg=i;
				DF(j,ct,2){
					int fr=b[j],to=rp[fr];
//					int to=b[j],fr=p[to];
					if (fr<to){
						a[now][fr]=1;
						a[now][to]=1;
					}
					else{//to....fr
						a[now][to]=2;
						a[now][fr]=2;
					}
					now--; 
				}
			}
			else{
				int la=now; now--;
				DF(j,ct,2){
					int fr=b[j],to=rp[fr];
					if (fr<to){
						a[now][fr]=1;
						a[now][to]=1;
					}
					else{//to....fr
						a[now][to]=2;
						a[now][fr]=2;
					}
					now--; 
				}
				a[now+1][bg]=2;
				a[la][bg]=1;
				a[la][b[ct]]=1;
			}
		}
	}
	cout<<n-1<<"\n";
	F(i,1,n){
		F(j,1,n){
			cout<<(!a[i][j] ? '.' : (a[i][j]==1 ? '\\' : '/'));
		}
		cout<<"\n"; 
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