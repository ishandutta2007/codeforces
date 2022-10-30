#include <bits/stdc++.h>
using namespace std;
bool osszetett[1000009];
long long oszto[1000009];
long long meddig=1000001;
long long legoszto[1000009];
long long n;
int main()
{
    ios::sync_with_stdio(false);
    long long cnt=2;
    while(cnt<=meddig)
    {
        if(osszetett[cnt])
        {
            cnt++;
            continue;
        }
        for(long long i=2*cnt; i<=meddig; i+=cnt)
        {
            if(!osszetett[i])
            {
                osszetett[i]=true;
                oszto[i]=cnt;
            }
        }
        cnt++;
    }
    for(long long i=2; i<=meddig; i++)
    {
        if(!osszetett[i]) legoszto[i]=i;
        else
        {
            legoszto[i]=legoszto[i/oszto[i]];
        }
    }
    cin>>n;
    if(!osszetett[n])
    {
        cout<<n<<endl;
        return 0;
    }
    long long kicsi=n-legoszto[n]+1;
    long long best=n;
    for(long long u=kicsi; u<=n; u++)
    {
        if(!osszetett[u])
        {
            best=min(best, u);
            continue;
        }
        long long cur=u-legoszto[u]+1;
        //cout<<cur<<" "<<u<<endl;
        best=min(best, cur);
    }
    cout<<best<<endl;
    return 0;
}