#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;

#define gcd __gcd

/*
int ivan[1001];
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++) cin >> ivan[i];
    for(int i = 0; i < n - 1; i++)
    {
        if(gcd(ivan[i], ivan[i+1]) != 1) cnt++;
    }
     cout << cnt << "\n";
    for(int i = 0; i < n - 1; i++)
    {
        if(gcd(ivan[i], ivan[i+1]) != 1)
        {
            cout << ivan[i] << " " << 1 << " ";
        }
        else
        {

            cout << ivan[i] << " ";
        }
    }
   cout << ivan[n-1];
    return 0;
}
*/

/*
int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= 2*n; i++)
    {
        if(2*n + i <= m)
        {
            cout << 2*n + i << " ";
        }
        if(i <= m)
        {
            cout << i << " ";
        }
    }
}
*/
int a[300001];
int dp[300001];

int q(int l, int r)
{
    return r-l+1;
}

int main()
{
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i+1] = dp[i];
        if(a[i]) dp[i]++;
    }
    int lo = 0; int hi = 0; int cnt = 0;
    int maxlo = 0; int maxhi = 0; int curmax = 0;
    if(k == 0)
    {
        int ans = 0; int cur = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i]) cur++;
            else
            {
                ans = max(ans, cur);
                cur = 0;
            }
        }
        ans = max(ans, cur);
        cout << ans << "\n";
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        return 0;
    }
    if(!a[0]) cnt++;
    while(lo < n && hi < n)
    {
        if(hi == n - 1)
        {
            if(q(lo, hi) > curmax)
                {
                    curmax = q(lo, hi);
                    maxlo = lo;
                    maxhi = hi;
                }
            hi++; continue;
        }
        if(lo == n - 1)
        {
            if(q(lo, hi) > curmax)
                {
                    curmax = q(lo, hi);
                    maxlo = lo;
                    maxhi = hi;
                }
           lo++; continue;
        }
        if(cnt < k)
        {
            hi++;
            if(!a[hi]) cnt++;
        }
        else if(cnt == k)
        {
            if(hi < n - 1 && a[hi+1])
            {
                hi++;
            }
            else
            {
                if(q(lo, hi) > curmax)
                {
                    curmax = q(lo, hi);
                    maxlo = lo;
                    maxhi = hi;
                }
                lo++;
                if(lo > hi)
                {
                    hi++;
                    if(!a[hi]) cnt++;
                }
                if(!a[lo-1]) cnt--;
            }
        }
        //cout << lo << " " << hi << " " << cnt << endl;
    }
    cout << curmax << "\n";
    for(int i = 0; i < n; i++)
    {
        if(i >= maxlo && i <= maxhi) cout << 1 << " ";
        else cout << a[i] << " ";
    }
}