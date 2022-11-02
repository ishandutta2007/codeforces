#include <bits/stdc++.h>
using namespace std;
long long modinvers(long long a, long long p)
{
    long long ans=1;
    long long hat=a;
    long long kell=p-2;
    while(kell>0)
    {
        if(kell%2)
        {
            ans*=hat;
            ans%=p;
        }
        kell/=2;
        hat*=hat;
        hat%=p;
    }
    return ans;
}
long long MOD=1000000007;
long long fakt[200009];
long long faktinv[200009];
int n;
long long t[200009];
long long s1[200009];
long long s2[200009];
long long alatt(long long x, long long y)
{
    long long ret=fakt[x];
    ret*=(faktinv[y]);
    ret%=MOD;
    ret*=(faktinv[x-y]);
    ret%=MOD;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    fakt[0]=1;
    faktinv[0]=1;
    fakt[1]=1;
    faktinv[1]=1;
    for(long long i=2; i<=n; i++)
    {
        fakt[i]=fakt[i-1]*i;
        fakt[i]%=MOD;
        faktinv[i]=faktinv[i-1]*modinvers(i, MOD);
        faktinv[i]%=MOD;
    }
    if(n==1)
    {
        cout<<(t[1]%MOD)<<endl;
        return 0;
    }
    if(n%4==2 || n%4==3) //minusz
    {
        int np=n;
        if(n%2==1) np--;
        for(long long i=1; i<=np; i+=2)
        {
            s1[i]=alatt((np/2)-1, i/2);
        }
        for(long long i=2; i<=np; i+=2)
        {
            s1[i]=s1[i-1];
        }
        if(n==np)
        {
            for(int i=1; i<=n; i++)
            {
                s2[i]=s1[i];
            }
        }
        else
        {
            s2[1]=1;
            s2[n]=-1;
            for(int i=2; i<n; i++)
            {
                if(i%2==1)
                {
                    s2[i]=s1[i]-s1[i-1];
                    s2[i]+=MOD;
                    s2[i]%=MOD;
                }
                else
                {
                    s2[i]=s1[i]+s1[i-1];
                    s2[i]%=MOD;
                }
            }
        }
    }
    else //plusz
    {
        int np=n;
        if(n%2==1) np--;
        for(long long i=1; i<=np; i+=2)
        {
            s1[i]=alatt((np/2)-1, i/2);
        }
        for(long long i=2; i<=np; i+=2)
        {
            s1[i]=-s1[i-1];
            s1[i]+=MOD;
            s1[i]%=MOD;
        }
        if(n==np)
        {
            for(int i=1; i<=n; i++)
            {
                s2[i]=s1[i];
            }
        }
        else
        {
            s2[1]=1;
            s2[n]=1;
            for(int i=2; i<n; i++)
            {
                if(i%2==1)
                {
                    s2[i]=s1[i]-s1[i-1];
                    s2[i]+=MOD;
                    s2[i]%=MOD;
                }
                else
                {
                    s2[i]=s1[i]+s1[i-1];
                    s2[i]%=MOD;
                }
            }
        }
    }
    long long answer=0;
    for(int i=1; i<=n; i++)
    {
        long long add=t[i]*s2[i];
        add%=MOD;
        answer+=add;
        answer+=MOD;
        answer%=MOD;
    }
    cout<<answer<<endl;
    return 0;
}