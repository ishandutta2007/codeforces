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
const int maxm = (int) 1.5e7 + 20;

const LL mx = (1LL << 32) - 1;

int cnt[105];

LL calc()
{
    LL res = 1;
    for(int i = 2; i <= 100; i++)
    {
        for(int j = 0; j < cnt[i]; j++)
        {
            res *= i;
            if(res > mx) return -1;
        }
    }
    return res;
}

void work()
{
    int n; cin >>n;
    stack<int> S;
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        string s; cin >>s;
        if(s == "add")
        {
            if(calc() == -1)
            {
                puts("OVERFLOW!!!");
                return ;
            }
            ans += calc();

            if(ans > mx)
            {
                puts("OVERFLOW!!!");
                return ;
            }
        }
        else if(s == "for")
        {
            int x; cin >>x;
            S.push(x);
            cnt[x]++;
        }
        else
        {
            int x = S.top();
            S.pop();
            cnt[x]--;
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