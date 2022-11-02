#include <bits/stdc++.h>
using namespace std;
string s;
string z[5];
bool ans=false;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(int i=0; i<5; i++)
    {
        cin>>z[i];
        if(z[i][0]==s[0] || z[i][1]==s[1]) ans=true;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}