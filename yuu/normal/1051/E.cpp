#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
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
#define taskname "E"
string a;
class z_algorithm{
public:
    string s, a;
    int n;
    int z[1000001];
    int g[1000001];
    void input(){
        cin>>s;
        n=s.size();
    }
    void construct(){
        if(n==1) return;
        int p=0;
        z[1]=-1;
        FFOR(i, 1, n){
            z[i]=-1;
            if(i<=p+z[p]) z[i]=min(z[i-p], p+z[p]-i);
            while(z[i]+i+1<n){
                if(s[z[i]+1]==s[z[i]+i+1]) z[i]++;
                else break;
            }
            if(p+z[p]<i+z[i]) p=i;
        }
    }
    void match(){
        g[0]=-1;
        while((g[0]+1<min(a.size(), s.size()))&&(a[g[0]+1]==s[g[0]+1])) g[0]++;
        int p=0;
        int cnt=0;
        FFOR(i, 1, a.size()){
            g[i]=-1;
            if(i<=p+g[p]) g[i]=min(z[i-p], p+g[p]-i);
            int old=g[i];
            while((g[i]+1<s.size())&&(g[i]+i+1<a.size())){
                if(s[g[i]+1]==a[g[i]+i+1]) g[i]++;
                else break;
                cnt++;
            }
            if(p+g[p]<i+g[i]) p=i;
        }
    }
    inline bool greater(int l, int r){
        if((l>r)||(l<0)) return 0;
        if((r-l+1)<(s.size())) return 1;
        if((r-l+1)>(s.size())) return 0;
        if((g[l]+1)==(s.size())) return 0;
        return s[g[l]+1]>=a[l+g[l]+1];
    }
    inline bool less(int l, int r){
        if((l>r)||(l<0)) return 0;
        if((r-l+1)<(s.size())) return 0;
        if((r-l+1)>(s.size())) return 1;
        if((g[l]+1)==(s.size())) return 0;
        return s[g[l]+1]<=a[l+g[l]+1];
    }
} l, r;
ll f[1000000];
ll s[1000000];
const ll base=998244353;
int n;
int sum(int l, int r){
    if(l==0) return s[r];
    else if(l<0) return s[r]+1;
    else return s[r]-s[l-1];
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a;
    l.input();
    r.input();
    l.construct();
    r.construct();
    l.a=a;
    r.a=a;
    l.match();
    r.match();
    int first_good;
    int last_good;
    FFOR(i, 0, a.size()){
        first_good=i-l.s.size()+1;
        while(l.greater(first_good, i)) first_good--;
        last_good=i-r.s.size()+1;
        if(last_good<0) last_good=0;
        while(r.less(last_good, i)) last_good++;
        if(last_good<=first_good) f[i]=sum(last_good-1, first_good-1)%base;
        if(a[i]=='0'){
            f[i-1]=0;
            s[i-1]=(i==1)?0:s[i-2];
        }
        s[i]=f[i];
        if(i) s[i]=(s[i]+s[i-1])%base;
    }
    writeln((f[a.size()-1]+base)%base);
}