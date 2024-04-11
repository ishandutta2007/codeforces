#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    if(min(m, k)>=n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}