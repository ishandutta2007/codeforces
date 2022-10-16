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
#define taskname "C"
int n;
int pri[1000001];
vector <int> v;
ll a, b;
bool solve(){
    pair <int, int> old=mp(a, b);
    ll s=a*b;
    if(s==1) return 1;
    ll k=exp(log(s)/3);
    while(k*k*k>s) k--;
    while(k*k*k<s) k++;
    if(k*k*k==s){
        while(k>1){
            int i=pri[k];
            int sum=0;
            while(k%i==0){
                k/=i;
                sum++;
            }
            int m=0, n=0;
            while(a%i==0){
                a/=i;
                m++;
            }
            while(b%i==0){
                b/=i;
                n++;
            }
            if(m<sum||n<sum) return 0;
        }
        return 1;
    }
    else return 0;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 2, 1000000) if(!pri[i]){
        for(int j=i; j<=1000000; j+=i) pri[j]=i;
    }
    while(n--){
        read(a);
        read(b);
        puts(solve()?"Yes":"No");
    }
}