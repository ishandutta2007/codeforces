#include <bits/stdc++.h>
using namespace std;

int main(){
   
    int N,M,K;cin>>N>>M>>K;
    set<int>holes;
    for(int i=0;i<M;++i){
        int a;scanf("%d",&a);
        a--;
        holes.emplace(a);
    }
    int now=0;
    int ans=-1;
    if(holes.find(0)!=holes.end())ans=0;
    for(int i=0;i<K;++i){
        int a,b;cin>>a>>b;a--;b--;
        if(now==a)now=b;
        else if(now==b)now=a;
        if(ans==-1&&holes.find(now)!=holes.end())ans=now;

    }
    if(ans==-1)ans=now;
    cout<<ans+1<<endl;
	return 0;
}