#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100006;
const LL INF = (1LL<<60);

#define SZ(x) ((int)(x).size())

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

string fa = "What are you doing while sending \"";
string fb = "\"? Are you busy? Will you send \"";
string fc = "\"?";

LL dp[N];

void kirino(LL n,LL k)
{
    if (k > dp[n])
    {
        cout << '.';
        return;
    }
    if (n == 0)
    {
        cout << f0[k-1];
        return;
    }
    if (k <= SZ(fa))
    {
        cout << fa[k-1];
        return;
    }
    k -= SZ(fa);
    if (k <= dp[n-1])
    {
        kirino(n-1,k);
        return;
    }
    k -= dp[n-1];
    if (k <= SZ(fb))
    {
        cout << fb[k-1];
        return;
    }
    k -= SZ(fb);
    if (k <= dp[n-1])
    {
        kirino(n-1,k);
        return;
    }
    k -= dp[n-1];
    if (k <= SZ(fc))
    {
        cout << fc[k-1];
        return;
    }
    assert(0);
    //cout << "geeeeeeeeeeee" << endl;
}

int main ()
{
    dp[0] = SZ(f0);
    for (int i=1;N>i;i++)
    {
        dp[i] = SZ(fa) + dp[i-1] + SZ(fb) + dp[i-1] + SZ(fc);
        if (dp[i] > INF) dp[i] = INF;
    }
    int q;
    cin >> q;
    while (q--)
    {
        LL n,k;
        cin >> n >> k;
        kirino(n,k);
    }
    cout << endl;
}