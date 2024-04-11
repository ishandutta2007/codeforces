#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int T,n,a[N],i,j,ans[N];
vector<int>ve[N];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(i=1;i<=n;++i)ve[i].clear();
		for(i=1;i<=n;++i)scanf("%d",a+i),ve[a[i]].push_back(i);
		memset(ans+1,-1,n<<2);
		for(i=1;i<=n;++i)if(!ve[i].empty()){
			int lst=0,mx=0;
			for(int x:ve[i])mx=max(mx,x-lst-1),lst=x;mx=max(mx,n-lst);
			for(j=mx+1;j<=n && ans[j]==-1;++j)ans[j]=i;
		}
		for(i=1;i<=n;++i)printf("%d%c",ans[i],i==n?'\n':' ');
	}
}