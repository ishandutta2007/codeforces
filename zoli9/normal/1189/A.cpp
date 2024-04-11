#include<bits/stdc++.h>
using namespace std;
int db[2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        db[s[i]-'0']++;
    }
    if(db[0]==db[1])
    {
        cout<<2<<endl;
        cout<<s[0]<<" "<<s.substr(1);
    }
    else
    {
        cout<<1<<endl;
        cout<<s<<endl;
    }
    return 0;
}