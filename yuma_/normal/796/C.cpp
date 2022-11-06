#include <bits/stdc++.h>
using namespace std;

bool check(const int p,vector<vector<int>>&edges,vector<int>&as){
    vector<int>flags(as.size());
    int t=0;
    for(int i=0;i<as.size();++i){
        if(p>=as[i]+2){
            continue;
        }else if(p==as[i]+1){
            t++;
            for(auto e:edges[i]){
                flags[e]++;

            }
            flags[i]++;
        }else if(p==as[i]){
            t++;
            flags[i]++;
        }else{
            t++;
        }
    }
    return any_of(flags.begin(),flags.end(),[=](const int& a){return a==t;});
}
int main(){
   
    int N;cin>>N;
    vector<int>as;
    for(int i=0;i<N;++i){
        int a;scanf("%d",&a);
        as.emplace_back(a);
    }
    vector<vector<int>>edges(N);
    for(int i=0;i<N-1;++i){
        int a,b;cin>>a>>b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int amin=-1e9-10;
    int amax=1e9+10;
    while(amin+1!=amax){
        int amid=(amin+amax)/2;
        bool ok=check(amid,edges,as);
        if(ok)amax=amid;
        else amin=amid;
    }
    cout<<amax<<endl;
	return 0;
}