#include <bits/stdc++.h>
using namespace std;
long long m, a, b;
long long C=500000;
long long elso[500009];
bool proba[500009];
long long maxi;
long long ans;
/*void f(long long x)
{
    //cout<<x<<endl;
    elso[x]=maxi;
    if(x-b>0 && elso[x-b]==0)
    {
        f(x-b);
    }
    if(x+a>C || x+a>m) return;
    maxi=max(maxi, x+a);
    f(x+a);
}*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>a>>b;
    priority_queue<long long> Q;
    Q.push(0);
    while(Q.size()>0)
    {
        long long legjobb=-Q.top();
        Q.pop();
        maxi=max(maxi, legjobb);
        elso[legjobb]=maxi;
        if(legjobb>b && elso[legjobb-b]==0)
        {
            Q.push(-(legjobb-b));
        }
        if(legjobb+a<=m && legjobb+a<=C && elso[legjobb+a]==0)
        {
            Q.push(-(legjobb+a));
        }
    }
    /*while(x<=C && x<=m)
    {
        elso[x]=maxi;
        if(!proba[x] && x-b>0 && elso[x-b]==0)
        {
            proba[x]=true;
            x-=b;
            continue;
        }
        maxi=max(maxi, x+a);
        x+=a;
    }*/
    for(long long i=1; i<=(min(m, C)); i++)
    {
        if(elso[i]==0) continue;
        ans+=(m-elso[i]+1);
        //cout<<i<<" "<<elso[i]<<endl;
    }
    ans+=(m+1);
    //cout<<ans<<endl;
    long long g=__gcd(a, b);
    C++;
    while(C%g!=0)
    {
        C++;
    }
    if(C>m)
    {
        cout<<ans<<endl;
        return 0;
    }
    long long Cmax=m;
    while(Cmax%g!=0)
    {
        Cmax--;
    }
    long long dbjo=(Cmax-C)/g+1;
    ans+=((m+1)*dbjo);
    long long sum=(Cmax+C)*(dbjo);
    sum/=2;
    ans-=sum;
    cout<<ans<<endl;

    return 0;
}