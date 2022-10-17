#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() {
 
    int n;
    cin>>n;
    vector<int> a(n+1);
    int u, v;
    for (int i = 0; i<n-1; i++)
    {
        cin>>u>>v;
        a[u]++;
        a[v]++;
    }
    bool check = false;
    for (int i = 1; i<=n; i++) if (a[i]==2) check = true;
    if (check) cout<<"NO";
    else cout<<"YES";
}