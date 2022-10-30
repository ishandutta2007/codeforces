#include <bits/stdc++.h>
using namespace std;
char c[1000000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
    }
    int cnt=1;
    int db=1;
    while(cnt<=n)
    {
        cout<<c[cnt];
        cnt+=db;
        db++;
    }
    cout<<endl;
    return 0;
}