#include <bits/stdc++.h>
using namespace std;
string s;
int ans[100009];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='0')
        {
            if(v.size()>0)
            {
                ans[v.back()]=1;
                v.pop_back();
            }
            ans[i]=0;
        }
        else
        {
            v.push_back(i);
        }
    }
    for(int i=0; i<s.size(); i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}