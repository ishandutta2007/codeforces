#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

typedef long long LL;

LL _[13] = {0,9,99,999,9999,99999,999999,9999999,99999999,999999999LL,9999999999LL,99999999999LL,999999999999LL};
LL n;
LL ans;
set<LL> st;

void solve(LL T)
{
    //cout << "T = "<<T<<endl;
    if (n + (n-1) < T) return;
    if (st.find(T) != st.end()) return;
    //cout << "T = "<<T<<endl;
    LL minx = ((T)/2+1);
    LL maxx;
    if (T==n) maxx = T-1;
    //else if (T-1 == n) maxx = T-2;
    else maxx = min(T-1,n);
    //cout << "T = "<<T<<" , minx = "<<minx<<", maxx = "<<maxx<<endl;
    ans += (maxx-minx+1);
    //if (T%2==0) --ans;
    st.insert(T);
}

int main ()
{
    cin >> n;
    int i=0;
    if (n<=4)
    {
        printf("%lld\n",n*(n-1)/2);
        return 0;
    }
    while (n+(n-1) >= _[i]) i++;
    --i;
    //we must contain i nines
    solve(_[i]); //all 9's
    for (int extra=0;8>=extra;extra++)
    {
        LL _10 = 10,_1 = 1;
        LL tmp = _[i];
        for (int cnt=0;i>=cnt;cnt++)
        {
            LL part1 = tmp/_1;
            LL part2 = tmp%_1;
            if (cnt==i)solve(part1 * _10 + extra * _1 + part2);
            _10 *= 10;
            _1 *= 10;
        }
    }
    printf("%lld\n",ans);
}