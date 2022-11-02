#include <bits/stdc++.h>
using namespace std;
char tab[13][13];
char spec='-';
int first=-1;
int second=-1;
int kul;
string s;
bool volt[26];
int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(!volt[s[i]-'A']) volt[s[i]-'A']=true;
        else
        {
            spec=s[i];
            break;
        }
    }
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==spec)
        {
            if(first==-1) first=i;
            else second=i;
        }
    }
    if(second-first==1)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    kul=second-first;
    tab[1][(kul-1)/2]=spec;
    int ind=first+1;
    for(int i=(kul-1)/2-1; i>=0; i--)
    {
        tab[1][i]=s[ind%27];
        ind++;
        if(s[ind%27]==spec) ind++;
    }
    for(int i=0; i<13; i++)
    {
        tab[0][i]=s[ind%27];
        ind++;
        if(s[ind%27]==spec) ind++;
    }
    for(int i=12; i>(kul-1)/2; i--)
    {
        tab[1][i]=s[ind%27];
        ind++;
        if(s[ind%27]==spec) ind++;
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<13; j++)
        {
            cout<<tab[i][j];
        }
        cout<<endl;
    }
    return 0;
}