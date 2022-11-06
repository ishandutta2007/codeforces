#include <bits/stdc++.h>

using namespace std;

int ge(){
    int t;scanf("%d",&t);
    int x=0;
    for(int j=0;j<t;++j){
        int a;scanf("%d",&a);
        a--;
        x|=(1<<a);
    }
    return x;
}
int main(){

    int N,M;cin>>N>>M;
    vector<int>nums(1<<9);
    for(int i=0;i<N;++i){
        nums[ge()]++;
    }
    for(int i=(1<<9)-1;i>=0;--i){
        for(int j=i+1;j<(1<<9);++j){
            if((i&j)==i){
                nums[j]+=nums[i];
            }
        }
    }

   
    vector<vector<pair<long long,int> >>costs(int(1<<9),vector<pair<long long,int> >(2,make_pair((long long )(1e18),-1)));
    for(int i=0;i<M;++i){
        int c;scanf("%d",&c);
        costs[ge()].push_back(make_pair(c,i+1));
    }
    for(int i=0;i<(1<<9);++i){
        sort(costs[i].begin(),costs[i].end());
        costs[i].resize(2);
    }
// return 0;
    pair<int,pair<long long int,pair<int,int>>>answer(-1,make_pair(-1,make_pair(-1,-1)));
    for(int i=0;i<(1<<9);++i){
        for(int j=i;j<(1<<9);++j){
            auto a=costs[i][0];
            auto b=costs[j][i==j];
            long long int total_cost=a.first;
            total_cost+=b.first;
            if(total_cost<1e10){
                auto ans=make_pair(nums[i|j],make_pair(-total_cost,make_pair(a.second,b.second)));
                answer=max(answer,ans);
            }
            
        }
    }
    cout<<answer.second.second.first<<' '<<answer.second.second.second<<endl;
    return 0;
}