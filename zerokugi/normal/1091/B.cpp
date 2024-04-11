#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define __builtin_popcount __builtin_popcountll

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
    os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
    os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const map<S, T> &t) {
    os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

namespace int_geom{
#define at(i) ((*this)[i])
#define SELF (*this)
    enum {TRUE = -1, FALSE = 0, BORDER = 1};
    typedef ll R;
    struct P{
        R X, Y;
        P(R X=0, R Y=0):X(X), Y(Y){}
        bool operator< (const P &q) const {
            return X != q.X ? X < q.X : Y < q.Y;
        }
        bool operator== (const P &q) const {return X == q.X && Y == q.Y;}
        P operator+ (const P &q) const {return P(X+q.X, Y+q.Y);}
        P operator- (const P &q) const {return P(X-q.X, Y-q.Y);}
        P operator* (const R &q) const {return P(X*q, Y*q);}
        P operator/ (const R &q) const {return P(X/q, Y/q);}
        P operator- () const {return P(-X, -Y);}
    };
    void swap(P &a, P &b){P t=a;a=b;b=t;}
    inline R norm(const P &p){return p.X*p.X+p.Y*p.Y;}
    inline R inp(const P& p, const P& q){return p.X*q.X+p.Y*q.Y;}
    inline R outp(const P& p, const P& q){return p.X*q.Y-p.Y*q.X;}
    inline int ccw(const P &s, const P &t, const P &p, int adv=0){
        int res = outp(t-s, p-s);
        if(res || !adv) return res ? (res < 0 ? -1 : 1) : 0;
        if(inp(t-s, p-s) < 0) return -2;	// p-s-t
        if(inp(s-t, p-t) < 0) return 2;		// s-t-p
        return 0;							// s-p-t
    }

    int orthant(const P &p){
        return p.X < 0 || (p.X == 0 && p.Y > 0);
    }

    bool comparg(const P &i, const P &j){
        if(orthant(i) != orthant(j)) return orthant(i) < orthant(j);
        if((i.Y)*(j.X) == (j.Y)*(i.X)) return norm(i) > norm(j);
        return ((i.Y)*(j.X) < (j.Y)*(i.X));
    }

    void argsort(vector<P> &v){
        sort(ALL(v), comparg);
    }

    void normalize(P &p){
        ll g = __gcd(abs(p.X), abs(p.Y));
        p.X /= g;
        p.Y /= g;
    }


    struct G : public vector<P>{
        G(size_type size=0):vector(size){}
        G(vector<P>::iterator begin, vector<P>::iterator end):vector(begin, end){}
//		S edge(int i)const {return S(at(i), at(i+1 == size() ? 0 : i+1));}
        bool contains(const P &p)const {
            bool in = false;
            for (int i = 0; i < size(); ++i) {
                P a = at(i) - p, b = at(i+1 == size() ? 0 : i+1) - p;
                if (a.Y > b.Y) int_geom::swap(a, b);
                if (a.Y <= 0 && 0 < b.Y && outp(a, b) < 0) in = !in;
                if (outp(a, b) == 0 && inp(a, b) <= 0) return BORDER;
            }
            return in ? TRUE : FALSE;
        }
        G convex_hull(bool online = false) {
            if(size() < 2) return *this;
            sort(ALL(*this));
            G r;
            r.resize((int)size()*2);
            int k=0;
            for(int i=0;i<size();r[k++]=at(i++))
                while(k>1 && ccw(r[k-2], r[k-1], at(i)) < 1-online) k--;
            int t = k;
            for(int i=(int)size()-1;i>=0;r[k++]=at(i--))
                while(k>t && ccw(r[k-2], r[k-1], at(i)) < 1-online) k--;
            r.resize(k-1);
            return r;
        }
        R area()const {	// return 2 * area of a polygon
            R sum = 0;
            REP(i, size()) sum += outp(at(i), at((i+1)%size()));
            return abs(sum);
        }
    };

};
using namespace int_geom;
namespace std{
    istream& operator>>(istream &is, P &p){R x,y;is>>x>>y;p=P(x, y);return is;}
    ostream& operator<<(ostream &os, const int_geom::P &p){return os << "(" << p.X <<", "<<p.Y <<")";}
}

int T, n, m, y, b, r;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    while(cin >> n){
        vector<P> p(n), q(n);
        REP(i, n) {
            cin >> p[i];
        }
        vector<P> p2;
        REP(i, n) {
            cin >> q[i];
            REP(j, n) p2.push_back(p[j] + q[i]);
        }
        sort(ALL(p2));
        int c = 1;
        if (n == 1) {
            cout << p2[0].X << " " << p2[0].Y << endl;
        } else {
            REPS(i, (int) p2.size() - 1) {
                if (p2[i] == p2[i - 1]) c++;
                else c = 1;
                if (c == n) {
                    cout << p2[i].X << " " << p2[i].Y << endl;
                    break;
                }
            }
        }
    }
    return 0;
}