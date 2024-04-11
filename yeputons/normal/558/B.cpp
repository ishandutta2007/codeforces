#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<iomanip>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vin;
typedef vector<string> vs;
typedef vector<vector<ll> > vvin;
typedef vector<bool> vb;

#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define BREP(i,a,b) for(ll i=a-1;i>=b;i--)
#define brep(i,n) BREP(i,n,0)
#define pb push_back
#define inf 1e18
#define mp make_pair
#define sz size()
#define DEBUG 0
#define all(vec) (vec).begin(),(vec).end()
#define fi first
#define se second
#define POPCOUNT __builtin_popcountll
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define mset(a,b) memset(a,b,sizeof a)
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
const int MOD = (int)1e9 + 7;

long long pow(long long base, long long exp, long long mod){
    long long result = 1;
    while(exp>0){
        if(exp&1) result*=base;
        base*=base;
        if(base>mod) base%=mod;
        if(result>mod) result%=mod;
        exp/=2;
    }
    return result;
}

long long mult(long long A, long long B) {
    if ( B == 0 ) return 0;
    long long u = mult(A, B/2);
    long long res;
    if ( B%2 == 0 )
        res = u + u;
    else
        res = u + u + A;
    while ( res >= MOD ) res -= MOD;
    return res;
}

ll n,num;
vin nums;
void inp() {
    rep(i,n) {
        cin>>num;
        nums.pb(num);
    }
}
ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<int>


// first part

void sieve(ll upperbound) {          // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1;                   // add 1 to include upperbound
    bs.set();                                                 // set all bits to 1
    bs[0] = bs[1] = 0;                                     // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);  // also add this vector containing list of primes
        } 
}

bool isprime(int a) {
    for (int i=2;i*i<=a;i++)
        if(a%i==0)
            return false;
    return true;
}

int lcs(string a, string b) {
    int arr[150][150];
    rep(i,a.sz+1)
        arr[i][0]=0;
    rep(j,b.sz+1)
        arr[0][j]=0;
    REP(i,1,a.sz+1)
        REP(j,1,b.sz+1) {
            if(a[i-1]==b[j-1])
                arr[i][j]=1+arr[i-1][j-1];
            else
                arr[i][j]=MAX(arr[i-1][j], arr[i][j-1]);
        }
    return arr[a.sz][b.sz];
}

bool sorted(int s, int e) {
    REP(i,s,e)
        if(nums[i]>nums[i+1])
            return false;
    return true;
}

bool comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
    if(a.first!=b.first)
        return a.first>b.first;
    return (a.second.first-a.second.second+1) < (b.second.first - b.second.second+1);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // blah
    cin>>n;
    inp();
    map<int,int> c,s,e;
    rep(i,n) {
        c[nums[i]]++;
        e[nums[i]]=i;
        s[nums[i]]=-1;
    }
    rep(i,n)
        if(s[nums[i]]==-1)
            s[nums[i]]=i;
    vector<pair<int, pair<int, int> > > ps;
    map<int,int>::iterator it;
    for(it=c.begin();it!=c.end();++it) 
        ps.pb(mp(it->second,mp(e[it->first],s[it->first])));
    sort(all(ps),comp);
    cout<<ps[0].second.second+1<<" "<<ps[0].second.first+1;
    return 0;
}