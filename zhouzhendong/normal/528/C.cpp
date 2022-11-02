#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=100005*4;
int n,m;
multiset <int> S[N];
void AddE(){
	vector <int> id;
	For(i,1,n)
		if (S[i].size()%2)
			id.pb(i);
	while (!id.empty()){
		int a=id.back();
		id.pop_back();
		int b=id.back();
		id.pop_back();
		S[a].insert(b),S[b].insert(a);
	}
}
vector <int> id;
void dfs(int x){
	while (!S[x].empty()){
		int y=*S[x].begin();
		S[x].erase(S[x].find(y));
		S[y].erase(S[y].find(x));
		dfs(y);
	}
	id.pb(x);
}
vector <pair <int,int> > ans;
int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		S[x].insert(y),S[y].insert(x);
	}
	AddE();
	dfs(1);
	For(i,0,(int)id.size()-2){
		if (~i&1)
			ans.pb(mp(id[i],id[i+1]));
		else
			ans.pb(mp(id[i+1],id[i]));
	}
	if (id.size()%2==0)
		ans.pb(mp(id[0],id[0]));
	printf("%d\n",(int)ans.size());
	for (auto E : ans)
		printf("%d %d\n",E.fi,E.se);
	return 0;
}