#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;

int cnt[N];
int pre[N];

int main ()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    for (int i=1;N>i;i++)
    {
        pre[i] = pre[i-1] + cnt[i];
    }
    int ans=1;
    for (int gcd=2;N>gcd;gcd++)
    {
        bool can=true;
        //cout << "gcd = "<<gcd<<" , pre = "<<pre[gcd-1]<<" , pre = "<<pre[k]<<endl;
        if (pre[gcd-1] > 0) continue;
        if (k >= gcd+1)
        {
            ans = gcd;
            continue;
        }
        for (int i=gcd+1;N>i;i+=gcd)
        {
            int l=i+k;
            int r = min(i+gcd-2,N-1);
            //cout <<"l = "<<l<<" , r = "<<r<<endl;
            if (r < l) continue;
            if (pre[r] - pre[l-1] > 0)
            {
                can = false;
                break;
            }
        }
        //cout << "can = "<<can<<endl;
        if (can) ans = gcd;
    }
    printf("%d\n",ans);
}