#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#define maxn 200100
using namespace std;
typedef pair<int,int> par;
set<par> st[4];
int vis[maxn],p[maxn],a[maxn],b[maxn],n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	scanf("%d",&m);
	for(int i=1;i<=n;++i)
		st[a[i]].insert(par(p[i],i)),
		st[b[i]].insert(par(p[i],i));
	for(int i=1;i<=m;++i){
		int c;
		scanf("%d",&c);
		while(st[c].size()&&vis[st[c].begin()->second])
			st[c].erase(*st[c].begin());
		if(!st[c].size()){
			printf("-1 ");
			continue;
		} else {
			printf("%d ",st[c].begin()->first);
			vis[st[c].begin()->second]=true;
			st[c].erase(*st[c].begin());
		}
	}
}