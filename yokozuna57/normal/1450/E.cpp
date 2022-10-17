#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define fr first
#define sc second

const int INF=1000000000;

void ng(){
	puts("NO");
	exit(0);
}

int n,m;
vector<pair<pair<int,int>,int>> edges;

int ret_cost=-1;
int ret_dist[202];
int cost;
int dist[202];
void f(int s){
	//cout<<s<<endl;
	for(int i=0;i<n;i++)dist[i]=INF;
	dist[s]=1000;
	for(int i=0;i<n;i++){
		bool upd=false;
		for(auto ed: edges){
			if(dist[ed.fr.sc]>dist[ed.fr.fr]+ed.sc){
				dist[ed.fr.sc]=dist[ed.fr.fr]+ed.sc;
				upd=true;
			}
		}
		if(!upd)break;
		if(i==n-1)ng();
	}
	int m=INF,M=0;
	for(int i=0;i<n;i++){
		m=min(m,dist[i]);
		M=max(M,dist[i]);
	}
	cost=M-m;
	for(auto ed: edges){
		if(dist[ed.fr.fr]==dist[ed.fr.sc])ng();
	}
	if(cost>ret_cost){
		ret_cost=cost;
		for(int i=0;i<n;i++){
			ret_dist[i]=dist[i];
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v,b;
		scanf("%d%d%d",&u,&v,&b);
		u--; v--;
		edges.push_back(mp(mp(u,v),1));
		if(b==0){
			edges.push_back(mp(mp(v,u),1));
		}
		else {
			edges.push_back(mp(mp(v,u),-1));
		}
	}
	for(int i=0;i<n;i++)f(i);
	if(ret_cost==-1){
		puts("NO");
	}
	else {
		puts("YES");
		printf("%d\n",ret_cost);
		for(int i=0;i<n;i++){
			printf("%d%c",ret_dist[i],(i+1==n)?'\n':' ');
		}
	}
}