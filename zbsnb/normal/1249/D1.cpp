#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;
#define ll long long
vector<pair<int,int> > l[200010];
vector<pair<int,int> > r[200010];
int a[200010],p;
int main(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        l[a].push_back({b,i});
        r[b].push_back({b,i});
    }

    //cout<<"?"<<endl;
    int ans=0;
    multiset<pair<int,int>,greater<pair<int,int> > > s;
    for(int i=1;i<=2e5;i++){
        //cout<<i<<" "<<s.size()<<endl;
        for(int j=0;j<l[i].size();j++){
            s.insert(l[i][j]);
        }
        //cout<<i<<" "<<s.size()<<endl;
        while(s.size()>k){
            auto it=s.begin();
            ans++;a[++p]=it->second;
            s.erase(it);
        }
        //cout<<"?"<<endl;
        multiset<pair<int,int> >::iterator it;
        for(int j=0;j<r[i].size();j++){
            if((it=s.find(r[i][j]))!=s.end())s.erase(it);
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=p;i++)cout<<a[i]<<" ";cout<<endl;
}