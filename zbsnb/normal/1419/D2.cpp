#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n;cin>>n;
    multiset<int,greater<int> > s;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        s.insert(tmp);
    }
    for(int i=1;i<=n-n/2;i++){
        a[i*2-1]=*s.begin();s.erase(s.begin());
    }
    for(int i=1;i<=n/2-1;i++){
        auto tmp=s.lower_bound(min(a[2*i-1],a[2*i+1])-1);
        if(tmp==s.end()) tmp=s.begin();
        a[i*2]=*tmp;
        s.erase(tmp);
    }
    a[n/2*2]=*s.begin();
    int ans=0;
    for(int i=2;i<=n-1;i++){
        if(a[i]<a[i-1]&&a[i]<a[i+1]) ans++;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}