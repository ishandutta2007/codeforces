#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "H"
int n;
string s;
int c[256];
vector <int> v;
string t;
string g;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    cin>>n>>s;
    FFOR(i, 0, n) c[s[i]]++;
    FOR(i, 1, n) if(n%i==0){
        int l=n/i;
        int d=0;
        int cnt=i*(l%2);
        FFOR(j, 0, 256) d+=c[j]/2;
        if(d<(l/2)*i) continue;
        FFOR(j, 0, 256) if(c[j]%2){
            v.pb(j);
            c[j]--;
            cnt--;
        }
        FFOR(j, 0, 256){
            while(cnt&&c[j]){
                cnt--;
                c[j]--;
                v.pb(j);
            }
        }
        cout<<i<<'\n';
        int f=0;
        FOR(j, 1, i){
            t="";
            DFOR(x, l/2, 1){
                while(c[f]==0) f++;
                t+=char(f);
                c[f]-=2;
            }
            g=t;
            reverse(g.begin(), g.end());
            if(j>1) cout<<' ';
            if(l%2){
                cout<<t<<char(v.back())<<g;
                v.pop_back();
            }
            else cout<<t<<g;
        }
        return 0;
    }
}