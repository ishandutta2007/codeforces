#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
mt19937 rd(time(0));
int a[500010];
int cnt[500010];
ull has[500010];
ull val[500010];
list<int> vec[500010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    auto t=clock();
    auto now_time=[&]{
        return (clock()-t)/(double)CLOCKS_PER_SEC;
    };
    int n;cin>>n;
    ull anss=1e18;
    for(int i=1;i<=n;i++) cin>>a[i];

    {
        for(int i=1;i<=n;i++) val[i]=(ull)(rd())*(ull)(rd()),vec[i].clear();
        ull ans=0;
        map<ull,int> mp;
        mp[0]++; int pre=0;
        for(int i=1;i<=n;i++) {
            int tmp=a[i];
            has[i]=has[i-1]+val[tmp], cnt[tmp]++, vec[tmp].push_back(i);
            if(cnt[tmp]%3==0) {
                has[i]-=3*val[tmp];}
            mp[has[i]]++;
            if(vec[tmp].size()>3){
                int now=vec[tmp].front();vec[tmp].pop_front();
                for(;pre<now;pre++){
                    mp[has[pre]]--;
                }
            }
            ans+=mp[has[i]]-1;
            // cout<<pre<<" "<<i<<" "<<mp[has[i]]<<" "<<has[i]<<endl;
        }
        anss=min(ans,anss);
    }
    cout<<anss<<endl;
}