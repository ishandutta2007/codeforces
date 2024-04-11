#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long gcd(long long x, long long y) {return (y ? gcd(y, x % y) : x);}

struct Frac
{
    long long up, dn;

    Frac(long long x, long long y) : up(x), dn(y)
    {
        if(!x && !y) return;

        int g = gcd(up, dn);
        up /= g; dn /= g;

        if(dn < 0){up = -up; dn = -dn;}
    }

    bool operator< (const Frac &other)
    {
        return up * other.dn < dn * other.up;
    }

    bool operator== (const Frac &other)
    {
        return (up == other.up) && (dn == other.dn);
    }
};

struct lin
{
    Frac inc, yInc;

    lin(long long x1, long long y1, long long x2, long long y2)
    : inc(y1 - y2, x1 - x2), yInc(y1 * x2 - y2 * x1, x1 - x2)
    {
        if(x1 == x2) yInc = {x1, 1};
    }

    bool operator< (const lin &other)
    {
        if(inc == other.inc) return yInc < other.yInc;
        return inc < other.inc;
    }

    bool operator== (const lin &other)
    {
        return (inc == other.inc) && (yInc == other.yInc);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int x[n], y[n]; for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    vector<lin> lines;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            lines.emplace_back(x[i], y[i], x[j], y[j]);

    sort(lines.begin(), lines.end());
    auto beginIt = lines.begin();
    auto endIt = unique(lines.begin(), lines.end());

    long long ans = (long long)(endIt - beginIt) * (endIt - beginIt - 1) / 2;
    long long cnt = 1;
    for(auto it = beginIt + 1; it != endIt; ++it)
    {
        if(it -> inc == (it - 1) -> inc) ++cnt;
        else{ans -= cnt * (cnt - 1) / 2; cnt = 1;}
    }
    ans -= cnt * (cnt - 1) / 2;

    cout << ans;
    return 0;
}