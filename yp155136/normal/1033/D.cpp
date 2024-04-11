#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll G = (1ll<<31)-1;
ll mull(ll a,ll b,ll mod) {
    if (a<G && b<G) return (a*b)%mod;
    ll ret=0,now=a;
    while (b) {
        if (b&1) {
            ret += now;
            if (ret >= mod) ret-=mod;
        }
        now += now;
        if (now >= mod) now-=mod;
        b>>=1;
    }
    return ret%mod;
}

ll addd(ll a,ll b,ll m) {
    return (a+b)%m;
    if (a+b >= m) return a+b-m;
    else return a+b;
}

ll ppow(ll a,ll n,ll mod) {
    ll ret=1,now=a;
    a%=mod;
    while (n) {
        if (n&1) ret = mull(ret,now,mod);
        now = mull(now,now,mod);
        n>>=1;
    }
    return ret;
}

const bool PRIME = 1,COMPOSITE = 0;
bool miller_rabin(ll n,ll a) {
    if (__gcd(n,a) == n) return PRIME;
    else if (__gcd(n,a) != 1) return COMPOSITE;
    ll d=n-1,r=0;
    while ( d%2==0) {
        d>>=1;
        ++r;
    }
    ll ret = ppow(a,d,n);
    if (ret == 1 || ret == n-1) return PRIME;
    while (r--){
        ret = mull(ret,ret,n);
        if (ret == n-1) return PRIME;
    }
    return COMPOSITE;
}
bool isPrime(ll n) {
    if (n==2) return PRIME;
    if (n%2==0) return COMPOSITE;
    ll as[7]={2,325,9375,28178,450775,9780504,1795265022};
    for (int i=0;i<7;++i) {
        if (miller_rabin(n,as[i]) == COMPOSITE) return COMPOSITE;
    }
    return PRIME;
}

ll myRnd() {
    return ((rand()*(1ll<<14))^rand());
}

ll a,c;
ll doo(ll x,ll n) {
    return addd( mull(a,mull(x,x,n),n),c,n );
}

map<ll,int> mp;

void solve(ll n,int times=1) {
    if (n==1)return;
    //cout << "n="<<n<<",times="<<times<<endl;
    if (isPrime(n)==PRIME){
        mp[n]+=times;
        return;
    }
    else if (n <= (1ll<<32)) {
        for (ll i=2;i*i<=n;++i) {
            while (n%i==0) {
                n/=i;
                mp[i]+=times;
            }
        }
        if (n!=1) mp[n]+=times;
        return;
    }
    /*else {
        for (auto &i:mp) {
            while (n%i.first==0) {
                i.second+=times;
                n/=i.first;
            }
        }
        if (n==1) return;
    }*/
    
    if (isPrime(n)==PRIME){
        mp[n]+=times;
        return;
    }
    else if (n <= (1ll<<32)) {
        for (ll i=2;i*i<=n;++i) {
            while (n%i==0) {
                n/=i;
                mp[i]+=times;
            }
        }
        if (n!=1) mp[n]+=times;
        return;
    }
    a=myRnd()%n;
    if (!a) a=1;
    c=myRnd()%n;
    while (c==0||c==2) c=myRnd()%n;
    ll start=myRnd()%n;
    ll s1 = doo(start,n);
    ll s2 = doo(s1,n);
    while (true) {
        //cout << "S1="<<s1<<",s2="<<s2<<endl;
        if (s1 == s2) {
            start = myRnd()%n;
            a=myRnd()%n;
            if (!a) a=1;
            c=myRnd()%n;
            while (c==0||c==2)c=myRnd()%n;
            s1=doo(start,n);
            s2=doo(s1,n);
            continue;
        }
        ll _ = __gcd(abs(s1-s2),n);
        if (_ != 1) {
            solve(_,times);
            solve(n/_,times);
            return;
        }
        s1 = doo(s1,n);
        s2 = doo(s2,n);
        s2 = doo(s2,n);
    }
}

ll pp(ll a,ll n) {
    if(n*log10(a) > 18+0.4771) return (1ll<<62);
    ll ret=1;
    while (n--) ret*=a;
    return ret;
}

void solve2(ll x) {
    if (x==1)return;
    for (auto &i:mp) {
        if (i.first<0)continue;
        while (x%i.first==0) {
            i.second++;
            x/=i.first;
        }
    }
    if (x==1) return;
    if (isPrime(x) == PRIME) {
        mp[x]++;
        return;
    }
    double p[3]={0.25,0.3333333333333333333333333,0.5};
    //cout<<"x="<<x<<endl;
    for (int i=0;i<3;++i) {
        ll y = pow(x,p[i])-9;
        y=max(y,0ll);
        while (pp(y,4-i)<x)++y;
        if (pp(y,4-i)==x && isPrime(y) == PRIME){
            mp[y]+=(4-i);
            return;
        }
    }
    mp[x]+=1;
    mp[-x]+=1;
}

int main () {
    int n;
    cin >> n;
    vector<ll> v;
    for (int i=0;i<n;++i) {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            if (i==j) continue;
            ll g = __gcd(v[i],v[j]);
            if (g!=1) {
                int cnt=0;
                for (int k=0;k<n;++k) {
                    while (v[k]%g==0) {
                        v[k]/=g;
                        ++cnt;
                    }
                }
                solve(g,cnt);
            }
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            if (i==j) continue;
            ll g = __gcd(v[i],v[j]);
            if (g!=1) {
                int cnt=0;
                for (int k=0;k<n;++k) {
                    while (v[k]%g==0) {
                        v[k]/=g;
                        ++cnt;
                    }
                }
                solve(g,cnt);
            }
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            if (i==j) continue;
            ll g = __gcd(v[i],v[j]);
            if (g!=1) {
                int cnt=0;
                for (int k=0;k<n;++k) {
                    while (v[k]%g==0) {
                        v[k]/=g;
                        ++cnt;
                    }
                }
                solve(g,cnt);
            }
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            if (i==j) continue;
            ll g = __gcd(v[i],v[j]);
            if (g!=1) {
                int cnt=0;
                for (int k=0;k<n;++k) {
                    while (v[k]%g==0) {
                        v[k]/=g;
                        ++cnt;
                    }
                }
                solve(g,cnt);
            }
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            if (i==j) continue;
            ll g = __gcd(v[i],v[j]);
            if (g!=1) {
                int cnt=0;
                for (int k=0;k<n;++k) {
                    while (v[k]%g==0) {
                        v[k]/=g;
                        ++cnt;
                    }
                }
                solve(g,cnt);
            }
        }
    }
    for (ll i:v) {
        //solve(i,1);
        solve2(i);
    }
    ll ret=1;
    for (auto i:mp) {
        ret *= (i.second+1);
        ret %= 998244353;
    }
    cout << ret << endl;
}