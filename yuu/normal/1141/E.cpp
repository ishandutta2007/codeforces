#include <bits/stdc++.h>
using namespace std;
long long h;
int n;
int d[200001];
int main(){
    cin>>h>>n;
    for(int i=1; i<=n; i++) cin>>d[i];
    long long per_round=0;
    long long high=0;
    for(int i=1; i<=n; i++){
        per_round-=d[i];
        if(per_round>=h){
            cout<<i<<'\n';
            return 0;
        }
        high=max(high, per_round);
    }
    if(per_round<=0){
        cout<<-1;
        return 0;
    }
    long long ans=((h-high)/per_round)*n;
    h-=((h-high)/per_round)*per_round;
    while(true) for(int i=1; i<=n; i++){
        h+=d[i];
        ans++;
        if(h<=0){
            cout<<ans<<'\n';
            return 0;
        }
    }
}