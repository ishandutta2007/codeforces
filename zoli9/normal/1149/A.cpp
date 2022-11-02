#include <bits/stdc++.h>
using namespace std;
bool osszetett[500009];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*osszetett[2]=false;
    for(int i=2; i<=500000; i++)
    {
        if(!osszetett[i])
        {
            for(int c=2*i; c<=500000; c+=i)
            {
                osszetett[c]=true;
            }
        }
    }
    osszetett[1]=true;*/
    cin>>n;
    int e1=0;
    int e2=0;
    for(int i=1; i<=n; i++)
    {
        int tt;
        cin>>tt;
        if(tt==1) e1++;
        else e2++;
    }
    if(e2>0)
    {
        cout<<2<<" ";
        e2--;
    }
    if(e1>0)
    {
        cout<<1<<" ";
        e1--;
    }
    while(e2>0)
    {
        cout<<2<<" ";
        e2--;
    }
    while(e1>0)
    {
        cout<<1<<" ";
        e1--;
    }
    cout<<endl;
    return 0;
}