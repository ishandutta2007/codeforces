#include <bits/stdc++.h>
using namespace std;
int n;
int t[1000009];
int hol[1000009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        hol[t[i]]=i;
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(t[i]!=i)
        {
            cnt++;
            t[hol[i]]=t[i];
            hol[t[i]]=hol[i];
            t[i]=i;
            hol[i]=i;
        }
    }
    if(n%2==0)
    {
        if(cnt%2==0) cout<<"Petr"<<endl;
        else cout<<"Um_nik"<<endl;
    }
    else
    {
        if(cnt%2==1) cout<<"Petr"<<endl;
        else cout<<"Um_nik"<<endl;
    }

    return 0;
}