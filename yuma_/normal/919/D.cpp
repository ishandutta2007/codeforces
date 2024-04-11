#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long double ld;

int solve(const vector<vector<int>>&edges,const string& names,int type){

	vector<int>comes(edges.size());
	vector<int>anss(edges.size());
	for(int i=0;i<edges.size();++i){
		for(int j=0;j<edges[i].size();++j){
			comes[edges[i][j]]++;
		}
	}
	queue<int>que;
	for(int i=0;i<comes.size();++i){
		if(comes[i]==0){
			que.push(i);
		}

	}


	while(!que.empty()){
		int now(que.front());
		if(names[now]=='a'+type)anss[now]++;
		que.pop();
		for(int i=0;i<edges[now].size();++i){
			const int next(edges[now][i]);
			anss[next]=max(anss[next],anss[now]);
			comes[next]--;
			if(comes[next]==0){
				que.push(next);
			}
		}
	}
	if(type==-1&&!all_of(comes.begin(),comes.end(),[](const int a){return a==0;})){
		return -1;
	}else if(type==-1){
		return 1;
	}else{
		return *max_element(anss.begin(),anss.end());
	}
	
}

int main() { 
	
	int N,M;cin>>N>>M;
	string names(N,'.');
	char chs[400002];
	scanf("%s",chs);
	for(int i=0;i<N;++i){
		names[i]=chs[i];
	}
	vector<vector<int>>edges(N);
	for(int i=0;i<M;++i){
		int a,b;scanf("%d %d",&a,&b);
		a--;
		b--;
		edges[a].push_back(b);
	}

	int ok=solve(edges,names,-1);
	if(ok==-1){
		cout<<-1<<endl;
	}else{
		int ans=0;
		for(int i=0;i<26;++i){
			ans=max(ans,solve(edges,names,i));
		}
		cout<<ans<<endl;
	}
	return 0;

}