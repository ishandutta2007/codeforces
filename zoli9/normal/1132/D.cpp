#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[200009];
long long b[200009];
long long db[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    k--;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
    }
    long long elso=0;
    long long utolso=3000000000000;
    while(elso<=utolso)
    {
        long long koz=(elso+utolso)/2;
        for(int i=0; i<k; i++)
        {
            db[i]=0;
        }
        long long toltesek=0;
        bool jo=true;
        for(int i=1; i<=n; i++)
        {
            long long energy=a[i];
            while(true)
            {
                long long hany=energy/b[i];
                if(hany<k)
                {
                    db[hany]++;
                    toltesek++;
                    if(toltesek>k)
                    {
                        jo=false;
                        break;
                    }
                    energy+=koz;
                }
                else break;
            }
        }
        if(jo)
        {
            int sum=0;
            for(int i=0; i<k; i++)
            {
                sum+=db[i];
                if(sum>i+1)
                {
                    jo=false;
                    break;
                }
            }
        }
        if(jo)
        {
            utolso=koz-1;
        }
        else
        {
            elso=koz+1;
        }
    }
    if(elso>3000000000000) cout<<-1<<endl;
    else cout<<elso<<endl;


    return 0;
}