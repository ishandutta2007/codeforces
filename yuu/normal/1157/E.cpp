#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int b[200001];
multiset <int> s;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    for(int i=1; i<=n; i++) s.insert(b[i]);
    for(int i=1; i<=n; i++){
        int best=(*s.begin());
        int low=n-a[i];
        if((*s.rbegin())>=low){
            auto it=s.lower_bound(n-a[i]);
            if((a[i]+best)%n>(a[i]+*it)%n) best=*it;
        }
        cout<<(a[i]+best)%n<<" \n"[i==n];
        s.erase(s.find(best));
    }
}