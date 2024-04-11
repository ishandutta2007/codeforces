#include <cstdio>
#include <set>
const int N=1e5+10;
int T,n;
std::set<int> q[N];
char s[N],t[N];
int main(){
	scanf("%d",&T);
	while(T--){
		bool tag=true;
		scanf("%d %s %s",&n,s+1,t+1);
		for(int i=1;i<=n;++i)q[s[i]].insert(i);
		for(int i=1;i<=n;++i){
			if(!q[t[i]].size()){tag=false;break;}
			int u=*q[t[i]].begin();q[t[i]].erase(u);
			if(u==i)continue;
			else if(t[i]=='a'){tag=false;break;}
			else if(t[i]=='b'){
				if(q['c'].size()&&*q['c'].begin()<u){tag=false;break;}
				else q['a'].erase(i),q['a'].insert(u);
			}
			else{
				if(q['a'].size()&&*q['a'].begin()<u){tag=false;break;}
				else q['b'].erase(i),q['b'].insert(u);
			}
		}
		for(int i='a';i<='c';++i)q[i].clear();
		puts(tag?"YES":"NO");
	}
	return 0;
}