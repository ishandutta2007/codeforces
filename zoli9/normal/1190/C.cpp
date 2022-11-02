#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    int e0=-1;
    int u0=-1;
    int e1=-1;
    int u1=-1;
    for(int i=0; i<n; i++)
    {
        char ccc;
        cin>>ccc;
        if(ccc=='0')
        {
            if(e0==-1) e0=i;
            u0=i;
        }
        else
        {
            if(e1==-1) e1=i;
            u1=i;
        }
    }
    if(e0==-1 || e1==-1)
    {
        cout<<"tokitsukaze"<<endl;
        return 0;
    }
    int tav0=u0-e0+1;
    int tav1=u1-e1+1;
    if(tav0<=k || tav1<=k)
    {
        cout<<"tokitsukaze"<<endl;
        return 0;
    }
    if(u0<e1 || u1<e0)
    {
        if(k<tav0 || k<tav1)
        {
            cout<<"once again"<<endl;
        return 0;
        }
    }
    if(tav0==k+1 && tav1==k+1)
    {
        cout<<"quailty"<<endl;
        return 0;
    }
    cout<<"once again"<<endl;
    return 0;
}