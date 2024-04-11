#include <bits/stdc++.h>
using ld=long double;
using namespace std;
using ll=long long ;



int main(){
    int N;cin>>N;
    vector<vector<int>>g(N);
    for(int i=0;i<N-1;++i){
        int a,b;scanf("%d %d",&a,&b);
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool have=(find_if(g.begin(),g.end(),[](const vector<int>&v){return v.size()==2;})!=g.end());
    if(!have){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}