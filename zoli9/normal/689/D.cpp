#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200009];
long long b[200009];
long long mi[200009][20];
long long ma[200009][20];
long long loga[200009];
long long ans=0;
long long qmax(long long k, long long v)
{
    long long hossz=v-k+1;
    return max(ma[k][loga[hossz]], ma[v-(1<<loga[hossz])+1][loga[hossz]]);
}
long long qmin(long long k, long long v)
{
    long long hossz=v-k+1;
    return min(mi[k][loga[hossz]], mi[v-(1<<loga[hossz])+1][loga[hossz]]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    for(int i=1; i<=n; i++)
    {
        ma[i][0]=a[i];
        mi[i][0]=b[i];
    }
    loga[1]=0;
    for(int i=2; i<=n+2; i++)
    {
        loga[i]=loga[i/2]+1;
    }
    for(int ki=1; ki<=19; ki++)
    {
        for(int i=1; i<=n; i++)
        {
            if(i+(1<<ki)-1>n) break;
            mi[i][ki]=min(mi[i][ki-1], mi[i+(1<<(ki-1))][ki-1]);
            ma[i][ki]=max(ma[i][ki-1], ma[i+(1<<(ki-1))][ki-1]);
        }
    }
    for(int st=0; st<n; st++)
    {
        int elso=st;
        int utolso=n-1;
        int kozep;
        while(elso<=utolso)
        {
            kozep=(elso+utolso)/2;
            if(qmax(st+1, kozep+1)<qmin(st+1, kozep+1))
            {
                elso=kozep+1;
            }
            else utolso=kozep-1;
        }
        long long ez, az;
        ez=elso;
        elso=st;
        utolso=n-1;
        while(elso<=utolso)
        {
            kozep=(elso+utolso)/2;
            if(qmax(st+1, kozep+1)<=qmin(st+1, kozep+1))
            {
                elso=kozep+1;
                //cout<<"* "<<elso<<" "<<utolso<<endl;
            }
            else
            {
                utolso=kozep-1;
            }
        }
        az=elso;
        ans+=(az-ez);
    }
    cout<<ans<<endl;
    return 0;
}