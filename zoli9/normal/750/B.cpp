#include <bits/stdc++.h>
using namespace std;
int n;
int kor=0;
string ans="YES";
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        string s;
        cin>>a>>s;
        if(kor==20000)
        {
            if(s!="North") ans="NO";
        }
        if(kor==0)
        {
            if(s!="South") ans="NO";
        }
        if(s=="South")
        {
            kor+=a;
            if(kor>20000)
            {
                ans="NO";
            }
        }
        else if(s=="North")
        {
            kor-=a;
            if(kor<0)
            {
                ans="NO";
            }
        }
    }
    if(kor!=0) ans="NO";
    cout<<ans<<endl;
    return 0;
}