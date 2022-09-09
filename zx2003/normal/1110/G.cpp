#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,n,u,v,i,d[N],wcnt;
vector<int>e[N],a,aa;
inline void bfs(int u){
	queue<int>q;q.push(u);memset(d+1,0,n<<2);d[u]=1;
	for(;!q.empty();){u=q.front(),q.pop();for(int i:e[u])if(!d[i])d[i]=d[u]+1,q.push(i);}
}
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	for(cin>>T;T--;){
		cin>>n;for(i=1;i<=n;++i)e[i].clear();a.clear();
		for(i=1;i<n;++i)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		cin>>s;wcnt=0;for(i=0;i<n;++i)wcnt+=e[i+1].size()>1 && s[i]=='W';
		if(wcnt && (n>3 || (n==3 && (s[0]=='W')+(s[1]=='W')+(s[2]=='W')>=2))){cout<<"White\n";continue;}
		bfs(1);aa.clear();for(i=1;i<=n;++i)if(e[i].size()==1 && s[i-1]=='W')aa.push_back(i);
		if(aa.size()>2 || (aa.size()==2 && d[aa[0]]%2==d[aa[1]]%2)){cout<<"White\n";continue;}
		if(n<=3){cout<<"Draw\n";continue;}
		for(i=1;i<=n;++i){if(e[i].size()>3)break;if(e[i].size()==3)a.push_back(i);}
		if(i<=n || a.size()>2){cout<<"White\n";continue;}
		if(a.size()==2 && aa.size()==0 && n==6){cout<<"Draw\n";continue;}
		auto ck=[&](int x){
			bfs(x);
			for(i=0;i<3;++i)if(s[e[x][i]-1]=='W')return true;
			for(u=0,i=1;i<=n;++i)u+=d[i]==3;
			return u>1;
		};
		bool fl=0;for(int x:a)fl|=ck(x);
		if(a.size()==2)fl|=d[a[0]]&1;
		if(a.size()==1 && aa.size()==1)fl|=d[aa[0]]%2==0;
		if(fl)cout<<"White\n";else cout<<"Draw\n";
	}
	return 0;
}