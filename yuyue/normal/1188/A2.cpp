#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+4;
int n,de[M];
set<pair<int,int> > v[M];
bool del[M];
int leaf[M];
int dfn[M],tot,sz[M];
void dfs(int x,int fa){
	dfn[x]=++tot; sz[x]=1;
	if (de[x]==1) leaf[x]=x;
	for (auto O:v[x]){
		int y=O.first;
		if (y==fa) continue;
		dfs(y,x);
		sz[x]+=sz[y];
		leaf[x]=leaf[y];
	}
}
int rt;
bool insub(int x,int y){
	return dfn[y]<=dfn[x]+sz[x]-1 && dfn[y]>=dfn[x];
}
struct info{
	int x,y,z;
};
vector<info> ans;
LL s[M];
void ddfs(int x,int fa){
	LL o=s[x];
	vector<int> vec;
	for (auto O:v[x]){
		int y=O.first;
		if (y==fa) continue;
		s[y]=O.second;
		o-=s[y];
		vec.pb(leaf[y]);
		ddfs(y,x);
	}
	int A=0,B=0;
	for (auto O:v[rt]){
			int y=O.first;
			if (!insub(y,x)){
				if (!A) A=leaf[y];
				else {
					B=leaf[y];
					break;
				}
			}
		}
	if (x==rt) return ;
	if (de[x]==1){
		ans.pb((info){x,A,o/2});
		ans.pb((info){x,B,o/2});
		ans.pb((info){A,B,-o/2});
	}
	else{
		int AA=vec[0],BB=vec[1];
		ans.pb((info){vec[0],A,o/2});
		ans.pb((info){vec[1],B,o/2});
		ans.pb((info){A,B,-o/2});
		ans.pb((info){vec[1],vec[0],-o/2});
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	F(i,1,n-1){
		int x=read(),y=read(),z=read();
		v[x].insert({y,z});
		v[y].insert({x,z});
		de[x]++; de[y]++;
	}
	F(i,1,n){ 
		if (de[i]==2){
			del[i]=1;
			int la=-1;
			for (auto O:v[i]){
				if (la==-1){
					la=O.second;
				}
				else{
					if (la!=O.second){
						puts("NO");
						return 0;
					}
				}
			}
			int l=v[i].begin()->first,r=v[i].rbegin()->first;
			v[l].erase({i,la});
			v[r].erase({i,la});
			v[l].insert({r,la});
			v[r].insert({l,la});
		}
	}
	puts("YES");
	rt=-1;
	F(i,1,n) if (!del[i] && de[i]>=3){
		rt=i;
	}
//	cerr<<rt<<"  root\n";
	if (rt==-1){
		cout<<1<<"\n";
		F(i,1,n){
			if (!del[i]){
				cout<<i<<" "<<(v[i].begin()->first)<<" "<<(v[i].begin()->second)<<"\n";
				break;
			}
		}
		return 0;
	}
	dfs(rt,0);
	ddfs(rt,0);
	cout<<ans.size()<<'\n';
	for(auto O:ans){
		cout<<O.x<<" "<<O.y<<" "<<O.z<<"\n";
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
5
1 2 2
2 3 2
3 4 2
4 5 2
*/