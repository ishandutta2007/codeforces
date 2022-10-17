#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct edge{
	int to;
	int cost;
	int num;
};

edge mke(int t,int c,int n){
	edge ed;
	ed.to=t;
	ed.cost=c;
	ed.num=n;
	return ed;
}

int main(){
	int n,m;
	static int a[200010],b[200010],c[200010],d[200010];

	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}

	static vector<edge> G[200010]; 
	static int total[200010]={0},sum[200010]={0};
	static bool used[200010];
	queue<int> que;

	for(int i=0;i<m;i++){
		G[a[i]].push_back(mke(b[i],c[i],i));
		G[b[i]].push_back(mke(a[i],c[i],i));
		total[a[i]]+=c[i];
		total[b[i]]+=c[i];
	}

	for(int i=1;i<=n;i++){
		used[i]=false;
	}

	que.push(1);

	while(!que.empty()){
		int p=que.front(); que.pop();
		if(p!=n){
			for(int i=0;i<G[p].size();i++){
				edge ed=G[p][i];
				if(!used[ed.to]){
					sum[ed.to]+=ed.cost;
					if(sum[ed.to]==total[ed.to]/2)que.push(ed.to);		

					if(a[ed.num]==p)d[ed.num]=0;
					else d[ed.num]=1;
				}
			}
			used[p]=true;
		}
	}
	
	for(int i=0;i<m;i++){
		printf("%d\n",d[i]);
	}
}