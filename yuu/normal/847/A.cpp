/* longhoang08 */
#include <bits/stdc++.h>
#define maxn 100010
#define cmax 1000000007
#define llmax (1LL << 61)
#define el '\n'
#define pb push_back
#define mp make_pair
#define getbit(s,i) ((s>>(i-1))&1)
#define bug(X) { cerr << #X << " = " << (X) << endl; }
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define For(i,a,b) for(int i = a; i <= b; i++)
#define Ford(i,a,b) for(int i = a; i >= b; i--)
#define Forv(i,v) for(int i = 0, _v = v.size(); i < _v; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> ptq;

int n, l[maxn], r[maxn];

int main()
{
    if (fopen("a.txt","r"))
    {
        freopen("a.txt","r",stdin);
        //freopen("b.txt","w",stdout);
    } else IOS;
    cin >> n;
    For(i,1,n) cin >> l[i] >> r[i];
    vector <int> v;
    For(i,1,n)
        if (l[i] == 0)
        {
            v.pb(i);
        }
    int now = v.back(), d = 0;
    while (true)
    {
        now = v.back();
        v.pop_back();
        d++;
        while (r[now] != 0)
        {
            now = r[now];
            d++;
        }
        if (d == n) break;
        int nex = v.back();
        l[nex] = now;
        r[now] = nex;
    }
    For(i,1,n) cout << l[i] << ' ' << r[i] << el;

}