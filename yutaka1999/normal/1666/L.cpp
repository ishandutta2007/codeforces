#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;
typedef pair <int,int> P;

int back[SIZE];
int from[SIZE];
vector <int> vec[SIZE];
int n,m,s;
const P NG = P(-1,-1);
P dfs(int v,int p,int c){
	back[v]=p;
	from[v]=c;
	for(int i=0;i<vec[v].size();i++){
		int to=vec[v][i];
		if(to==s) continue;
		if(back[to]==-1){
			P p=dfs(to,v,c);
			if(p!=NG) return p;
		} else{
			if(from[to]!=c){
				return P(v,to);
			}
		}
	}
	return NG;
}
int main(){
	scanf("%d%d%d",&n,&m,&s);s--;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		vec[a].push_back(b);
	}
	for(int i=0;i<n;i++) back[i]=-1;
	for(int i=0;i<vec[s].size();i++){
		int to=vec[s][i];
		P p;
		if(back[to]!=-1) p=P(s,to);
		else p=dfs(to,s,i);
		if(p!=NG){
			int t=p.second;
			vector <int> v1;
			while(t!=s){
				v1.push_back(t);
				t=back[t];
			}
			v1.push_back(s);
			vector <int> v2;
			v2.push_back(p.second);
			t=p.first;
			while(t!=s){
				v2.push_back(t);
				t=back[t];
			}
			v2.push_back(s);
			puts("Possible");
			printf("%d\n",v1.size());
			for(int j=0;j<v1.size();j++) printf("%d ",v1[v1.size()-j-1]+1);puts("");
			printf("%d\n",v2.size());
			for(int j=0;j<v2.size();j++) printf("%d ",v2[v2.size()-j-1]+1);puts("");
			return 0;
		}
	}
	puts("Impossible");
}