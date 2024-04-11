#include <bits/stdc++.h>
using namespace std;
int n;
int a[1502];
vector <pair <int, int>> upd[1501];
map <int, int> best;
int f[1501];
int g[1501];
void get_sum(int sum){
    for(int r=1; r<=n; r++){
        for(int l=r, now=0; l>=1; l--){
            now+=a[l];
            if(now==sum) f[r]=max(f[r], g[l-1]+1);
        }
        g[r]=max(f[r], g[r-1]);
    }
    int r=n;
    while(g[r]){
        if(f[r]==g[r]){
            for(int l=r, now=0; l>=1; l--){
                now+=a[l];
                if(now==sum) if(g[l-1]+1==f[r]){
                    cout<<l<<' '<<r<<'\n';
                    r=l-1;
                    break;
                }
            }
        }
        else r--;
    }
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int l=1; l<=n; l++){
        for(int r=l, sum=0; r<=n; r++){
            sum+=a[r];
            auto it=best.find(sum);
            if(it==best.end()) upd[r].push_back(make_pair(sum, 1));
            else upd[r].push_back(make_pair(sum, it->second+1));
        }
        for(auto v: upd[l]) best[v.first]=max(best[v.first], v.second);
    }
    int best_sum=0, best_length=0;
    for(auto v: best) if(v.second>best_length){
        best_length=v.second;
        best_sum=v.first;
    }
    cout<<best_length<<'\n';
    get_sum(best_sum);
}