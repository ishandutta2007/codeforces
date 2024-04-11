#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    int vmove=(n-10)/2;
    int pmove=(n-11-vmove);
    int vv=0;
    int pp=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='8')
        {
            if(pp<pmove)
            {
                pp++;
            }
            else
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
        else
        {
            if(vv<vmove)
            {
                vv++;
            }
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    return 0;
}