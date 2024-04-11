#include <bits/stdc++.h>
using namespace std;
int a[200001];
map <int, int> m[11];
int n, k;
int main(){
    cin>>n>>k;
    long long ans=0;
    for(int i=1; i<=n; i++) cin>>a[i];
    auto inside=[&ans](int i){
        for(long long len=1, w=10; len<=10; len++, w=(w*10)%k){
            int md=(w*a[i])%k;
            md=(k-md)%k;
            auto it=m[len].find(md);
            if(it!=m[len].end()) ans+=it->second;
        }
        int len=0;
        int t=a[i];
        while(t>0){
            len++;
            t/=10;
        }
        m[len][a[i]%k]++;
    };
    for(int i=1; i<=n; i++) inside(i);
    for(int len=1; len<=10; len++) m[len].clear();
    for(int i=n; i>=1; i--) inside(i);
    cout<<ans<<'\n';
}