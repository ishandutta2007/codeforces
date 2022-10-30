#include <bits/stdc++.h>
using namespace std;
int db[10];
int main()
{
    ios::sync_with_stdio(false);
    string s;
    int cnt=0;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]-'a'==cnt)
        {
            db[s[i]-'a']++;
        }
        else if(s[i]-'a'==cnt+1)
        {
            db[s[i]-'a']++;
            cnt++;
        }
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(db[0]==0 || db[1]==0 || db[2]==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(db[0]==db[2] || db[1]==db[2])
    {
        cout<<"YES"<<endl;
            return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}