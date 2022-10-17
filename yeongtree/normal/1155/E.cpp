#include <iostream>

using namespace std;

constexpr int Q = (int)1e6 + 3;

struct modInt
{
    int n;
    static modInt rev[Q];

    modInt(void){}
    modInt(int _n) : n(_n) {}

    static void inRev(void)
    {
        rev[0] = 0;
        rev[1] = 1;
        for(int i = 2; i < Q; ++i)
            rev[i] = -(rev[Q % i] * (Q / i));
    }

    operator int&() {return n;}

    modInt& operator+= (int x) {n += x; if(n >= Q) n -= Q; return *this;}
    modInt& operator-= (int x) {n -= x; if(n < 0) n += Q; return *this;}
    modInt& operator*= (int x) {n = (long long)n * x % Q; return *this;}
    modInt& operator/= (int x) {n = (long long)n * rev[x] % Q; return *this;}
    modInt operator- (void) {modInt ret = Q - n; return ret;}
    modInt operator+ (int x) {modInt ret = n; return ret += x;}
    modInt operator- (int x) {modInt ret = n; return ret -= x;}
    modInt operator* (int x) {modInt ret = n; return ret *= x;}
    modInt operator/ (int x) {modInt ret = n; return ret /= x;}
};

modInt modInt::rev[Q];

int main()
{
    modInt::inRev();

    modInt res[11];
    for(int i = 0; i < 11; ++i)
    {
        cout << "? " << i << '\n'; fflush(stdout);
        int tmp; cin >> tmp; if(tmp == -1) return 0; res[i] = tmp;
    }

    modInt pow[11][11];
    for(int i = 0; i < 11; ++i)
    {
        pow[i][0] = 1;
        for(int j = 1; j < 11; ++j)
            pow[i][j] = pow[i][j - 1] * i;
    }

    modInt _res[11], eff[11];
    for(int i = 10; i >= 0; --i)
    {
        for(int j = 0; j <= i; ++j) _res[j] = res[j];

        for(int j = i - 1; j >= 0; --j)
        {
            for(int k = 0; k <= j; ++k)
                _res[k] = (_res[k + 1] - _res[k]) / (i - j);
        }

        eff[i] = _res[0];
        for(int j = 0; j < i; ++j)
            res[j] -= eff[i] * pow[j][i];
    }

    for(int i = 0; i < Q; ++i)
    {
        modInt ans = 0, tmp = 1;
        for(int j = 0; j < 11; ++j)
        {
            ans += eff[j] * tmp;
            tmp *= i;
        }

        if(ans == 0){cout << "! " << i << '\n'; fflush(stdout); return 0;}
    }

    cout << "! -1" << '\n'; fflush(stdout);
    return 0;
}