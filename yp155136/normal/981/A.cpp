#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())

bool check(string s)
{
    string t=s;
    reverse(t.begin(),t.end());
    return !(t==s);
}

int main()
{
    string s;
    cin >> s;
    int ans=0;
    for(int i=0;SZ(s)>i;i++)
    {
        for(int j=1;SZ(s)>i+j-1;j++)
        {
            if (check(s.substr(i,j))) ans = max(ans,j);
        }
    }
    cout<<ans<<endl;
}