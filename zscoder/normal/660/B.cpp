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