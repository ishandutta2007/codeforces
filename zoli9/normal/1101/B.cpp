#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int leghossz=-1;
    int elso=-1;
    int utolso=-1;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='[')
        {
            elso=i;
            break;
        }
    }
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i]==']')
        {
            utolso=i;
            break;
        }
    }
    if(elso==-1 || utolso==-1 || elso>utolso)
    {
        cout<<-1<<endl;
        return 0;
    }
    int elso2=-1;
    int utolso2=-1;
    for(int i=elso; i<=utolso; i++)
    {
        if(s[i]==':')
        {
            elso2=i;
            break;
        }
    }
    for(int i=utolso; i>=elso; i--)
    {
        if(s[i]==':')
        {
            utolso2=i;
            break;
        }
    }
    if(elso2==-1 || utolso2==-1 || elso2>=utolso2)
    {
        cout<<-1<<endl;
        return 0;
    }
    int ans=4;
    for(int i=elso2; i<=utolso2; i++)
    {
        if(s[i]=='|') ans++;
    }
    cout<<ans<<endl;
    return 0;
}