#include<bits/stdc++.h>
using namespace std;
#define ll long long
int lim[4];
vector<pair<int,int> > t[4];
int get(){
    vector<pair<int,int> > tmp;
    for(int i=0;i<=2;i++){
        if(lim[i]!=t[i].size()){
            tmp.push_back({t[i][lim[i]].first,i});
        }
    }
    if(tmp.empty()) return 0;
    sort(tmp.begin(),tmp.end());
    lim[tmp[0].second]++;
    return tmp[0].first;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int tmp,a,b;cin>>tmp>>a>>b;
        t[(a<<1)|b].push_back({tmp,i});
    }

    for(int i=0;i<=3;i++) sort(t[i].begin(),t[i].end());
    for(int i=int(t[3].size())-1;i>=k;i--){
        t[0].push_back(t[3][i]);
        t[3].pop_back();
    }
    sort(t[0].begin(),t[0].end());
    lim[3]=t[3].size();
    lim[2]=lim[1]=k-lim[3];
    lim[0]=0;
    int cnt=m-(lim[1]+lim[2]+lim[3]);
    if(cnt<0){
        cout<<-1<<endl;
        return 0;
    }

    int ans=0;
    for(auto val:t[3])ans+=val.first;
    for(int i=0;i<lim[1];i++){
        if(i==t[1].size()||i==t[2].size()){
            cout<<-1<<endl;
            return 0;
        }
        ans+=t[1][i].first+t[2][i].first;
    }
    for(int i=0;i<cnt;i++){
        int tmp=get();
        if(tmp)ans+=tmp;
        else{
            cout<<-1<<endl;
            return 0;
        }
    }

    // cout<<lim[0]<<" "<<lim[1]<<" "<<lim[2]<<" "<<lim[3]<<endl;

    int minn=ans,pos[4];for(int i=0;i<=3;i++)pos[i]=lim[i];
    for(lim[3]--;lim[3]>=0;lim[3]--){
        ans-=t[3][lim[3]].first;
        int now=k-lim[3];
        // cout<<lim[3]<<" "<<now<<endl;
        if(now==t[1].size()+1||now==t[2].size()+1)break;
        if(now<=lim[1]&&now<=lim[2]){
            int tmp=get();
            if(tmp)ans+=tmp;
            else break;
        }
        else{
            if(now>lim[1]){
                ans+=t[1][now-1].first;
            }
            if(now>lim[2]){
                ans+=t[2][now-1].first;
            }
            if(now>lim[1]&&now>lim[2]){
                if(lim[0]==0)break;
                ans-=(t[0][--lim[0]].first);
            }
            lim[1]=max(lim[1],now);
            lim[2]=max(lim[2],now);
        }
        if(minn>ans){
            minn=ans;
            for(int i=0;i<=3;i++)pos[i]=lim[i];
        }
        // cout<<lim[0]<<" "<<lim[1]<<" "<<lim[2]<<" "<<lim[3]<<" "<<minn<<endl;
    }
    lim[3]++;

    cout<<minn<<endl;
    for(int i=0;i<=3;i++){
        for(int j=0;j<pos[i];j++){
            cout<<t[i][j].second<<" ";
        }
    }
    cout<<endl;

}