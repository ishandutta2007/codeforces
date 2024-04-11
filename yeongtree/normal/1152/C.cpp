#include <iostream>
#include <vector>

using namespace std;

long long ans = 8e18;
long long a, b, t, rans;

long long gcd(long long x, long long y){return (y == 0 ? x : gcd(y, x % y));}
long long lcm(long long x, long long y){return x * y / gcd(x, y);}

void ss(vector<pair<long long, long long> > &pl, vector<long long> &st)
{
    for(long long i = 0; i < st.size() - 1; ++i)
    {
        if(pl[i].second < st[i])
        {
            st[i] = 0;
            ++st[i + 1];
            ss(pl, st);
            return;
        }
    }
    if(pl.back().second < st.back()) return;

    long long div = 1;
    for(long long i = 0; i < st.size(); ++i)
    {
        for(long long j = 0; j < st[i]; ++j)
            div *= pl[i].first;
    }

    long long _a = ((a - 1) / div + 1) * div;
    long long k = _a - a;
    long long _b = b + k;
    long long _lcm = lcm(_a, _b);

    if(_lcm < ans)
    {
        ans = _lcm;
        rans = k;
    }

    ++st[0];
    ss(pl, st);

    return;
}

int main()
{
    cin >> a >> b;
    t = (a > b ? a - b : b - a);
    long long s = t;

    vector<pair<long long, long long> > pl;
    for(long long i = 2; i * i <= s; ++i)
    {
        if(!(s % i))
        {
            long long k = 0;
            while(!(s % i)){s /= i; ++k;}
            pl.emplace_back(i, k);
        }
    }
    if(s != 1) pl.emplace_back(s, 1);

if(t == 0 || t == 1)
    {
        cout << "0";
        return 0;
    }

    else
    {
        vector<long long> st(pl.size());
        ss(pl, st);
        cout << rans;
        return 0;
    }
}