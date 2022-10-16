#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[501][501];
int b[501][501];
multiset <int> s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>a[i][j];
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>b[i][j];
    for(int d=2; d<=n+m; d++){
        for(int i=1; i<=n; i++){
            int j=d-i;
            if(j<1||j>m) continue;
            s.insert(a[i][j]);
        }
        for(int i=1; i<=n; i++){
            int j=d-i;
            if(j<1||j>m) continue;
            auto it=s.find(b[i][j]);
            if(it==s.end()){
                puts("NO");
                return 0;
            }
            s.erase(it);
        }
    }
    puts("YES");
}