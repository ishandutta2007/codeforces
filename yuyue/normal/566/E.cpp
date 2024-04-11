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
const int M=1024;
bitset<M> a[M],tmp;
bitset<M> e[M],nl,vis;
#define pii pair<int,int>
#define mp make_pair
vector<pii> ans;
int n;
int main(){
	n=read();
	if (n==2){
		cout<<"1 2\n";
		return 0;
	}
	F(i,1,n) e[i][i]=1;
	F(i,1,n){
		int x=read();
		F(j,1,x){
			int y=read();
			a[i][y]=1;
		}
		F(j,1,i-1){
			tmp=a[i]&a[j];
			if (tmp.count()==2){
				int x=tmp._Find_first(),y=tmp._Find_next(x);
				if (!e[x][y]){
					e[x][y]=e[y][x]=1;
					ans.pb(mp(x,y));
					nl[x]=nl[y]=1;
				}
			}
		}
	}
	if (SZ(ans)+1==0){
		F(i,2,n){
			cout<<1<<" "<<i<<"\n";
		}
		return 0;
	}
	if (SZ(ans)==0){
		int x=ans[0].first,y=ans[0].second;
		F(i,1,n){
			if (a[i].count()!=n){
				F(j,1,n){
					if (!nl[j]){
						if (a[i][j]){
							ans.pb(mp(x,j));
						}
						else{
							ans.pb(mp(y,j));
						}
					}
				}
				break;
			}
		}
		F(i,0,SZ(ans)) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		return 0;
	}
	F(i,1,n){
		if (nl[i]) continue;
		int mi=n+1;
		F(j,1,n){
			if (a[j][i] && (a[j]&nl).count()<mi){
				tmp=a[j]&nl;
				mi=tmp.count();
			}
		}
		F(j,1,n){
			if (tmp[j] && e[j]==tmp){
				ans.pb(mp(i,j));
			}
		}
	}
	F(i,0,SZ(ans)) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
5
5 1 2 3 4 5
4 1 2 3 4
4 2 3 4 5
3 1 2 3
3 3 4 5

8
4 1 2 3 6
6 1 2 3 4 6 7
8 1 2 3 4 5 6 7 8 
5 2 3 4 5 7
3 3 4 5
4 1 2 3 6
5 2 3 4 7 8
3 3 7 8
*/