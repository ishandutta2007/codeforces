#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define pb push_back
#define fi first
#define se second
vii sbx;
vii sby;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        sbx.pb(ii(x,y));
        sby.pb(ii(y, x));
    }
    sort(sbx.begin(), sbx.end());
    sort(sby.begin(), sby.end());
    ll ansx = 0;
    ll ansy = 0;
    ll cntx = 1;
    ll cnty = 1;
    ll ansxy = 0;
    ll cntans = 1;
    for(int i = 1; i < n; i++)
    {
        if(sbx[i].fi == sbx[i - 1].fi)
        {
            cntx++;
        }
        if(sbx[i].fi != sbx[i - 1].fi || i == n - 1)
        {
            ansx += (cntx*(cntx-1))/2;
            cntx = 1;
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(sby[i].fi == sby[i - 1].fi)
        {
            cnty++;
        }
        if(sby[i].fi != sby[i - 1].fi || i == n - 1)
        {
            ansy += (cnty*(cnty-1))/2;
            cnty = 1;
        }
    }
    for(int i = 1; i < n; i++)
    {
        if((sbx[i].fi == sbx[i - 1].fi)&&(sbx[i].se == sbx[i - 1].se))
        {
            cntans++;
        }
        if(sbx[i] != sbx[i - 1] || i == n - 1)
        {
            ansxy += (cntans*(cntans-1))/2;
            cntans = 1;
        }
    }
    ll ans = ansx + ansy - ansxy;
    cout << ans;
    return 0;
}