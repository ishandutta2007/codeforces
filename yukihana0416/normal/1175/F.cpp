#include <bits/stdc++.h>
using namespace std;
#define LL long long

template< typename T > inline void read(T &x)
{
    static char _c;
    static bool _f;

    x = 0;
    _f = 0;
    _c = getchar();

    while(_c < '0' || '9' < _c) {if(_c == '-') _f = true; _c = getchar();}
    while('0' <= _c && _c <= '9') {x = x * 10 + _c - '0'; _c = getchar();}
    if(_f) x = -x;
}

template < typename T > inline void Min(T &x, T y) {if(y < x) x = y;}
template < typename T > inline void Max(T &x, T y) {if(x < y) x = y;}


#define lowbit(x) ((x) & -(x))
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(l,r) ((l)+(((r)-(l))>>1))

const int MOD = (int) 1e9 + 7;
const int inf = (int) 1e9;
const int maxn = (int) 3e5 + 20;
const int maxm = (int) 5e5 + 20;

int n;
int a[maxn];
int vis[maxn], clk;
int mx[maxn];

void work()
{
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 1)
        {

            mx[i] = 1;
            int L, R;
            for(int j = i - 1; j >= 1; j--)
            {
                if(a[j] == 1) break;
                mx[j] = max(mx[j + 1], a[j]);
            }
            for(int j = i + 1; j <= n; j++)
            {
                if(a[j] == 1) break;
                mx[j] = max(mx[j - 1], a[j]);
            }


            clk++;
            for(int j = i; j >= 1; j--)
            {
                if(vis[a[j]] == clk) break;
                vis[a[j]] = clk;
                L = j;
            }

            R = i;
            for(int j = L; j <= i; j++)
            {
                while(R > i && mx[R] >= mx[j])
                {
                    vis[a[R]] = clk - 1;
                    R--;
                }
                while(R + 1 <= n && mx[R + 1] < mx[j] && vis[a[R + 1]] != clk)
                {
                    R++;
                    vis[a[R]] = clk;
                }

                if(R - j + 1 == mx[j])
                {
//                    cout <<"L : " <<i <<" " <<j <<" " <<R <<endl;
                    ans++;
                }

                vis[a[j]] = clk - 1;
            }

            clk++;
            for(int j = i; j <= n; j++)
            {
                if(vis[a[j]] == clk) break;
                vis[a[j]] = clk;
                R = j;
            }

            L = i;
            for(int j = R; j >= i; j--)
            {
                while(L < i && mx[L] >= mx[j])
                {
                    vis[a[L]] = clk - 1;
                    L++;
                }

//                cout <<"q : " <<j <<" " <<L <<endl;

                while(L - 1 >= 1 && mx[L - 1] < mx[j] && vis[a[L - 1]] != clk)
                {
                    L--;
                    vis[a[L]] = clk;
                }

//                cout <<"q2 : " <<j <<" " <<L <<endl;

                if(j - L + 1 == mx[j])
                {
//                    cout <<"R : "<<i <<" " <<L <<" " <<j <<endl;
                    ans++;
                }

                vis[a[j]] = clk - 1;
            }

            ans--;

//            cout <<i <<" " <<ans <<endl;
        }
    }

    cout <<ans <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    int tc = 1;
//    cin >>tc;
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}