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
const int M=111;
int n;
char s[M];
bitset<M> a[M][M],b[M][M],d[M];
int ct[M];
void del(int x){
	F(i,1,n){
		if (i^x){
			F(j,1,n){
				if (a[i][x][j]) ct[j]--;
			}
			a[i][x].reset();
			a[x][i].reset();
		}
	}
	F(i,1,n){
		F(j,1,n){
			a[i][j][x]=0;
		}
	}
}
vector<int> v[M];
int dis[M][M];
void dfs(int x,int fa,int *dep){
	for (int y:v[x]){
		if (y^fa) {
			dep[y]=dep[x]+1;
			dfs(y,x,dep);
		} 
	}
}
bool check(auto edge){
	F(i,1,n) v[i].clear();
	F(i,0,n-2){
		int x=edge[i].first,y=edge[i].second;
//		cerr<<x<<" "<<y<<" edge \n";
		v[x].pb(y); v[y].pb(x);
	}
	F(i,1,n)
	{
		dis[i][i]=0;
		dfs(i,0,dis[i]);
	}
	F(i,1,n){
		F(j,i+1,n){
			F(k,1,n)
			if (b[i][j][k]!=(dis[i][k]==dis[j][k])) return 0;
		}
	}
	return 1;
}
void work(){
	n=read();
	vector<pair<int,int> > edge;
	F(i,1,n) ct[i]=0;
	F(i,1,n){
		F(j,i+1,n){
			a[i][j].reset();
			scanf("%s",s+1);
			F(k,1,n){
				if (s[k]=='1') a[i][j][k]=1,ct[k]++;
				else a[i][j][k]=0;
			}
			a[j][i]=a[i][j];
			b[i][j]=a[i][j];
		} 
	}
	int T=n-1;
	bitset<M> in; 
	F(i,1,n) in[i]=1;
	while (T--){
		bitset<M> tmp;
		if (in.count()==2){
			int x=0,y=0;
			F(i,1,n){
				if (in[i]){
					if (!x) x=i;
					else y=i;
				}
			}
//			cerr<<x<<" "<<y<<" !!!\n";
			if (a[x][y].any()){
				puts("No");
				return ;
			}
			edge.pb({x,y});
			break;
		}
		bool flag=0;
		
		DF(i,n,1){
//			tmp=in;
			if (!in[i]) continue;
			tmp.reset();
			F(j,1,n){
				if (in[j] && i!=j) tmp|=a[i][j];
			}
			if (in[i]){
				F(j,1,n){
					if (in[j] && j!=i){
						F(k,j+1,n){
							if (in[k] && k!=i && a[j][k][i]){
								tmp&=a[j][k];
							}
						} 
					}
				}
			}
			if (tmp.count()==1){
				int X=0;
				F(j,1,n){
					if (tmp[j]){
						X=j;
						break;
					}
				}
				assert(1<=X && X<=n);
				edge.pb({X,i});
				del(i); in[i]=0;
				flag=1;
				break;
			}
			d[i]=tmp;
		}
		if (!flag){
			F(i,1,n){
//				tmp=in;
				if (in[i]){
					int X=0;
					F(j,1,n){
						if (in[j] && j!=i){
							if (a[i][j].count()==1){
								int ps=a[i][j]._Find_first();
								if (ct[ps]==ct[i]+1 && d[i][ps] && d[i][j]){
									X=ps;
									break;
								}
							}
						}
					}
					if (X){
						edge.pb({X,i});
						del(i); in[i]=0;
						flag=1;
						break;
					} 
				}
				if (flag) break;
			}
		}
		
		F(i,0,SZ(edge)){
			int x=edge[i].first,y=edge[i].second;
//			cerr<<x<<" "<<y<<" edge \n";
//			v[x].pb(y); v[y].pb(x);
		}
//		cerr<<flag<<" !!!!!\n";
		if (!flag){
			puts("No");
			return ;
		}
	}
	if (check(edge)){
		puts("Yes");
		F(i,0,n-2){
			int x=edge[i].first,y=edge[i].second;
			cout<<x<<" "<<y<<"\n";
		}
	}
	else 	puts("No");
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
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
1
1 2
8
1
4
*/