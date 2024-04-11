#include <bits/stdc++.h>
using namespace std;
int n;
long long s1, s2;
long long t[100009];
int l2[100009];
long long minimum[100009][21];
long long maximum[100009][21];
int logn;
long long qmin(int a, int b)
{
    int hl=l2[b-a+1];
    return min(minimum[a][hl], minimum[b-(1<<hl)+1][hl]);
}
long long qmax(int a, int b)
{
    int hl=l2[b-a+1];
    return max(maximum[a][hl], maximum[b-(1<<hl)+1][hl]);
}
int meddig_jo(int indulas, long long tav)
{
    if(indulas==n) return n;
    int minie=indulas;
    int miniu=n;
    while(minie<=miniu)
    {
        int minik=(minie+miniu)/2;
        if(t[indulas]-tav<=qmin(indulas, minik) && t[indulas]+tav>=qmax(indulas, minik)) minie=minik+1;
        else miniu=minik-1;
    }
    return miniu;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>s1>>s2;
    t[1]=s1;
    t[2]=s2;
    n+=2;
    for(int i=3; i<=n; i++) cin>>t[i];
    l2[1]=0;
    for(int i=2; i<=n; i++)
    {
        l2[i]=1+l2[i/2];
    }
    for(int i=1; i<=n; i++)
    {
        minimum[i][0]=t[i];
        maximum[i][0]=t[i];
    }
    for(int k=1; k<=l2[n]+1; k++)
    {
        for(int i=1; n-i+1>=(1<<k); i++)
        {
            minimum[i][k]=min(minimum[i][k-1], minimum[i+(1<<(k-1))][k-1]);
            maximum[i][k]=max(maximum[i][k-1], maximum[i+(1<<(k-1))][k-1]);
        }
    }
    long long elso=0;
    long long utolso=1000000001;
    while(elso<=utolso)
    {
        long long kozep=(elso+utolso)/2;
        bool jo=true;
        int legtavolabbi=1;
        for(int i=1; i<=n; i++)
        {
            if(i>legtavolabbi)
            {
                jo=false;
                break;
            }
            legtavolabbi=max(legtavolabbi, meddig_jo(i, kozep));
        }
        if(jo) utolso=kozep-1;
        else elso=kozep+1;
    }
    cout<<elso<<endl;
    return 0;
}