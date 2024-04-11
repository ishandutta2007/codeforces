#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,Q,fa[N];
double v[N],vson[N],ans;
vector <int> e[N];
void solve(int x,int pre){
	ans-=1.0-v[x];
	fa[x]=pre,vson[x]=0;
	for (auto y : e[x])
		if (y!=pre){
			ans-=v[x]*v[y];
			vson[x]+=v[y];
			solve(y,x);
		}	
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		e[i].clear();
	v[0]=0;
	for (int i=1;i<=n;i++)
		scanf("%lf",&v[i]),v[i]=1.0-v[i];
	for (int i=1,a,b;i<n;i++){
		scanf("%d%d",&a,&b),a++,b++;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	ans=n;
	solve(1,0);
	scanf("%d",&Q);
	while (Q--){
		int x;
		double y;
		scanf("%d%lf",&x,&y),x++;
		ans+=v[fa[x]]*vson[fa[x]]+v[x]*vson[x]+1.0-v[x];
		vson[fa[x]]-=v[x];
		v[x]=1.0-y;
		vson[fa[x]]+=v[x];
		ans-=v[fa[x]]*vson[fa[x]]+v[x]*vson[x]+1.0-v[x];
		printf("%.6lf\n",ans);
	}
	return 0;
}