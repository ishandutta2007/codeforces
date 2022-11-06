#include <bits/stdc++.h>

using namespace std;

int dfs(int now,const vector<vector<int>>&edges){
    vector<int>nums(4);
    for(auto e:edges[now]){
        nums[dfs(e,edges)]++;
    }
    if(nums[3]){
        return 2;
    }else{
        if(nums[0]){
            if(nums[1]){
                return 2;
            }else{
                return 1;
            }
        }else{
            if(nums[1]){
                return 0;
            }else{
                if(nums[2]){
                    return 3;
                }else{
                    return 0;
                }
            }
        }
    }
}

int main() {
    int Q;cin>>Q;
    while(Q--){
        int N;
        scanf("%d",&N);
        vector<pair<int,int>>vs(N);
        for(int i=0;i<N;++i){
            int a,b;
            scanf("%d %d",&a,&b);
            a--;
            if(b==1)vs[a].first++;
            else vs[a].second++;
        }
        sort(vs.begin(),vs.end(),greater<pair<int,int>>());
        set<int>aset;
        for(int i=1;i<=N;++i){
            aset.emplace(i);
        }
        int answer1=0;
        int answer2=0;
        for(auto p:vs){
            auto it=aset.upper_bound(p.first+p.second);
            if(it==aset.begin()){

            }else{
                answer1+=*prev(it);
                answer2+=min(*prev(it),p.first);
                aset.erase(prev(it));
            }
        }
        printf("%d %d\n",answer1,answer2);
    }
    return 0;
}