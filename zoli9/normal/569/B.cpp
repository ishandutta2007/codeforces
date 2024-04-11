#include <bits/stdc++.h>
using namespace std;
int n;
int t[100009];
int sorrend[100009];
bool v[100009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        if(v[t[i]] || t[i]>n || t[i]<1)
        {
            sorrend[i]=0;
        }
        else
        {
            sorrend[i]=t[i];
        }
        v[t[i]]=true;
    }
    int cnt=1;
    while(v[cnt]) cnt++;
    for(int i=1; i<=n; i++)
    {
        if(sorrend[i]>0)
        {
            cout<<sorrend[i]<<" ";
        }
        else
        {
            cout<<cnt<<" ";
            cnt++;
            while(v[cnt]) cnt++;
        }
    }
    return 0;
}