#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int i;
    for(i=1;i<n;i++)
    {
        bool flag=true;
        for(int j=0;j<(n-i);j++)
        {
            if(s[j]!=s[i+j]) {flag=false; break;}
        }
        if(flag) break;
    }
    cout<<s; string _s=s.substr(n-i,i);
    for(int j=1;j<k;j++) cout<<_s;
    return 0;
}