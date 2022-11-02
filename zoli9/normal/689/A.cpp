#include <bits/stdc++.h>
using namespace std;
int n;
char s[19];
bool van[10];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>s[i];
    for(int i=1; i<=n; i++)
    {
        van[s[i]-'0']=true;
    }
    if(((van[1] || van[2] || van[3]) && (van[1] || van[4] || van[7]) && (van[3] || van[6] || van[9]) && (van[7] || van[0] || van[9])) || (van[0] && (van[1] || van[2] || van[3]))) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}