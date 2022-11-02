#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int h=s.size();
    int ac=-1;
    string s2="";
    for(int i=0; i<h; i++)
    {
        if(s[i]=='a') ac=i;
        else s2+=s[i];
    }
    int h2=s2.size();
    if(h2%2==1)
    {
        cout<<":("<<endl;
        return 0;
    }
    for(int i=0; i<h2/2; i++)
    {
        if(s2[i]!=s2[i+h2/2])
        {
            cout<<":("<<endl;
            return 0;
        }
    }
    if(ac>=h-h2/2)
    {
        cout<<":("<<endl;
            return 0;
    }
    for(int i=0; i<h-h2/2; i++)
    {
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}