#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i, x) for(int i=0;i<(int)(x);i++)
#define REPS(i, x) for(int i=1;i<=(int)(x);i++)
#define RREP(i, x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i, x) for(int i=((int)(x));i>0;i--)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i, c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define __builtin_popcount __builtin_popcountll

typedef long long RInteger;
struct Rational{
    RInteger p,q;
    Rational(RInteger pp=1,RInteger qq=1):p(pp),q(qq){
        if(q==0)p=1;else if(p==0)q=1;
        else{
            if(q<0)q=-q,p=-p;
            RInteger g=__gcd(abs(p),q);
            p/=g;q/=g;
        }
    };
};
Rational operator+(const Rational &a,const Rational &b){
    return Rational(a.p*b.q+b.p*a.q,a.q*b.q);
}
Rational operator-(const Rational &a){
    return Rational(-a.p,a.q);
}
Rational operator-(const Rational &a,const Rational &b){
    return Rational(a.p*b.q-b.p*a.q,a.q*b.q);
}
Rational operator*(const Rational &a,const Rational &b){
    return Rational(a.p*b.p,a.q*b.q);
}
Rational operator/(const Rational &a,const Rational &b){
    return Rational(a.p*b.q,a.q*b.p);
}
bool operator==(const Rational &a,const Rational &b){
    return (a.p==b.p)&&(a.q==b.q);
}
bool operator<(const Rational &a,const Rational &b){
    return a.p*b.q<b.p*a.q;
}
bool operator>(const Rational &a,const Rational &b){return b<a;}
bool operator<=(const Rational &a,const Rational &b){return (a<b)||(a==b);}
bool operator>=(const Rational &a,const Rational &b){return (a>b)||(a==b);}
bool operator!=(const Rational &a,const Rational &b){return !(b==a);}

template <typename T=int>
struct Zipper{
    vector<T> dec;
    map<T, int> enc;
    Zipper(){}
    void add(T t){dec.pb(t);}
    size_t size(){return dec.size();}
    void compile(){
        sort(ALL(dec)); UNIQUE(dec);
        REP(i, dec.size()) enc[dec[i]] = i;
    }
    T operator[](int i){return dec[i];}
    int operator()(T t){return enc[t];}
    int lb(T t){return lower_bound(ALL(dec), t) - dec.begin();}
    int ub(T t){return upper_bound(ALL(dec), t) - dec.begin();}
};

ll mergecount(vector<int> &a) {
    ll count = 0;
    int n = a.size();
    if (n > 1) {
        vector<int> b(a.begin(), a.begin() + n/2);
        vector<int> c(a.begin() + n/2, a.end());
        count += mergecount(b);
        count += mergecount(c);
        for (int i = 0, j = 0, k = 0; i < n; ++i)
            if (k == c.size())       a[i] = b[j++];
            else if (j == b.size())  a[i] = c[k++];
            else if (b[j] < c[k])   a[i] = b[j++];
            else                   { a[i] = c[k++]; count += n/2 - j; }
    }
    return count;
}

const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, w;
int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> w;
    vector<pair<Rational, Rational>> v;
    Zipper<Rational> zip1, zip2;
    REP(i, n) {
        ll a, b;
        cin >> b >> a;
        const Rational x = Rational(b, w - a);
        const Rational y = Rational(-b, w + a);
        v.emplace_back(y, x);
        zip1.add(y);
        zip2.add(x);
    }
    zip1.compile();
    zip2.compile();
    vector<pii> v2;
    for (auto it : v) v2.emplace_back(zip1(it.first), -zip2(it.second));
    sort(ALL(v2));
    vi v3;
    for(auto it : v2) v3.emplace_back(-it.second);
    cout << mergecount(v3) << endl;
    return 0;
}