#include <bits/stdc++.h>
using namespace std;
struct coor{
    long long int x;
    long long int y;
};
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
vector<coor>ans;
void dfs(coor nowco,const long long int d,const int way,const int now,const vector<vector<int>>&edges,const int from){
    int num=edges[now].size();
    
    if(num>=5){
        throw(false);
    }
    int nextway=-1;
    for(auto e:edges[now]){
        if(e==from)continue;
        else{
            nextway++;
            if(from!=-1&&nextway==(way+2)%4){
                nextway++;
            }
            coor nextco(nowco);
            nextco.x+=dx[nextway]*d;
            nextco.y+=dy[nextway]*d;
            ans[e]=(nextco);
            dfs(nextco,d/2,nextway,e,edges,now);
        }
    }
    return;
}
int main(){
    int N;cin>>N;
    ans.resize(N);
    vector<vector<int>>edges(N);
    for(int i=0;i<N-1;++i){
        int a,b;cin>>a>>b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bool flag=true;
    ans[0]=coor{0,0};
    try{
        dfs(coor{0,0},(1ll<<40),-1,0,edges,-1);
    }catch(...){
        flag=false;
    }
    if(flag){
        cout<<"YES"<<endl;
        for(int i=0;i<ans.size();++i){
            cout<<ans[i].x<<" "<<ans[i].y<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
    
    
    return 0;

}