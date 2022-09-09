#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,n,m,i,j,x,y,p[N],q[N],cnt[N],bel[N],dad[N];
vector<int>adj[N],ve[N];
set<int>S;
inline void bfs(int start){
	queue<int>q;q.push(start);
	for(;!q.empty();){
		x=q.front();q.pop();
		int fa=dad[x];
		if(fa){
			bel[x]=fa;
			if(!bel[fa])++cnt[fa];else{
				y=bel[fa];
				--cnt[y],bel[fa]=0,cnt[fa]=1;
				if(!cnt[y])bel[y]=fa,++cnt[fa];
			}
		}
		sort(adj[x].begin(),adj[x].end());
		for(auto it=S.begin();it!=S.end();)
			if(binary_search(adj[x].begin(),adj[x].end(),*it))++it;
				else q.push(*it),dad[*it]=x,S.erase(*it++);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	for(cin>>T;T--;){
		cin>>n>>m;
		S.clear();
		memset(cnt+1,0,n<<2);
		memset(bel+1,0,n<<2);
		memset(dad+1,0,n<<2);
		for(i=1;i<=n;++i)adj[i].clear(),ve[i].clear(),S.insert(i);
		for(i=1;i<=m;++i){
			cin>>x>>y;
			adj[x].push_back(y);adj[y].push_back(x);
		}
		for(;!S.empty();)x=*S.begin(),S.erase(x),bfs(x);
		for(i=1;i<=n;++i)if(bel[i])ve[bel[i]].push_back(i);
		int val=0;
		for(i=1;i<=n;++i)if(!bel[i]){
			vector<int>tmp(ve[i].size()+1);
			for(int&x:tmp)x=++val;
			auto work=[&](int*p){
				for(j=0;j<ve[i].size();++j)p[ve[i][j]]=tmp[j];p[i]=tmp.back();
			};
			work(p);rotate(tmp.begin(),tmp.begin()+1,tmp.end());work(q);
		}
		for(i=1;i<=n;++i)cout<<p[i]<<(i==n?'\n':' ');
		for(i=1;i<=n;++i)cout<<q[i]<<(i==n?'\n':' ');
		for(i=1;i<=n;++i)for(int j:adj[i])assert((p[i]<p[j])==(q[i]<q[j]));
	}
}