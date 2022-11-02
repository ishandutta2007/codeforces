#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    string s;
    cin>>s;
    int best=-1;
    int bestpl=-1;
    for(int i=0; i<n; i++)
    {
        if((s[i]-'a')<best)
        {
            cout<<"YES"<<endl;
            cout<<bestpl+1<<" "<<i+1<<endl;
            return 0;
        }
        best=s[i]-'a';
        bestpl=i;
    }
    cout<<"NO"<<endl;
    return 0;
}