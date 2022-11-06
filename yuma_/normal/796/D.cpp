#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int from;
    int to;
    int id;
};
int main(){
   
    int N,K,D;cin>>N>>K>>D;
    queue<pair<int,int>>que;
    vector<int>memo(N,-1);
    for(int i=0;i<K;++i){
        int p;cin>>p;p--;
        que.emplace(p,0);
        memo[p]=true;
    }
    vector<vector<Edge>>edges(N);
    for(int i=0;i<N-1;++i){
        int a,b;cin>>a>>b;a--;b--;
        edges[a].push_back(Edge{a,b,i});
        edges[b].push_back(Edge{b,a,i});
    }
    vector<int>useedgeids(N-1);
    while(!que.empty()){
        auto atop(que.front());
        que.pop();
        const int now=atop.first;
        const int nowcost=atop.second;
        if(nowcost==D)break;
        for(auto e:edges[now]){
            if(memo[e.to]==-1){
                memo[e.to]=nowcost+1;
                useedgeids[e.id]=true;
                que.push(make_pair(e.to,nowcost+1));
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<N-1;++i){
        if(useedgeids[i]==false)ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]+1;
        if(i==ans.size()-1)cout<<endl;
        else cout<<" ";
    }

	return 0;
}