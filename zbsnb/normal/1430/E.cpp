#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[1000010];
vector<int> vec[26];
int a[1000010];

int h[1000010],n;
#define lowb(x) ((x)&(-x))
void upd(int x,int y){
    for(int i=x;i<=n;i+=lowb(i)) h[i]+=y;
}
int que(int x){
    int ret=0;
    for(int i=x;i>=1;i-=lowb(i)) ret+=h[i];
    return ret;
}

int main(){
    cin>>n;cin>>(s+1);
    for(int i=1;i<=n;i++) a[i]=n+1-i;
    for(int i=1;i<=n;i++){
        vec[s[i]-'a'].push_back(i);
    }
    for(int i=0;i<26;i++){
        vector<int> tmp;
        for(int j=0;j<int(vec[i].size());j++){
            tmp.push_back(a[vec[i][j]]);
        }
        sort(tmp.begin(),tmp.end());
        
        // for(auto &it:tmp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        for(int j=0;j<int(vec[i].size());j++){
            a[vec[i][j]]=tmp[j];
        }
    }
    
    // for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    // cout<<endl;

    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=i-1-que(a[i]);
        upd(a[i],1);
        // cout<<i<<" "<<ans<<endl;

        // for(int i=1;i<=n;i++){
        //     cout<<que(i)-que(i-1)<<" ";
        // }
        // cout<<endl;

    }
    cout<<ans<<endl;
}