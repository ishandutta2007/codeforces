#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#define taskname "FINDNUM"
vector <int> v;
int n;
ll f[1001][25];
bool done[1001][26];
bool isprime(int x){
    int i=2;
    while(i*i<=x){
        if(x%i==0) return 0;
        i++;
    }
    return 1;
}
int nextprime(int x){
    int res=x+1;
    while(!isprime(res))
        res++;
    return res;
}
ll power(int a, int x){
    if(x==0) return 1;
    ll temp=power(a, x/2);
    temp*=temp;
    if(x%2)
        temp*=a;
    return temp;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    ll res=1;
    int prime=2;
    while(v.size()<25){
        v.pb(prime);
        prime=nextprime(prime);
    }
    FOR(i, 1, n){
        DFOR(j, 24, 1){
            if(!done[i][j]){
                if(log10(double(v[j]))*(double)(i-1)>18) continue;
                f[i][j]=power(v[j], i-1);
                done[i][j]=1;
            }
            if(done[i][j+1])
                f[i][j]=min(f[i][j], f[i][j+1]);
            for(int k=i+i; k<=n; k+=i){
                if(log10(double(f[i][j]))+log10(double(v[j-1]))*(k/i-1)>18) break;
                ll temp=power(v[j-1], k/i-1);
                if(done[k][j-1]){
                    f[k][j-1]=min(f[k][j-1], f[i][j]*temp);
                    done[k][j-1]=1;
                }
                else{
                    f[k][j-1]=f[i][j]*temp;
                    done[k][j-1]=1;
                }
            }
        }
        if(done[i][0]){
            if(done[i][1])
                f[i][0]=min(f[i][0], f[i][1]);
        }
        else if(i<63){
            if(!done[i][0]){
                f[i][0]=power(2, i-1);
                done[i][0]=1;
            }
            else
                f[i][0]=min(f[i][0], power(2, i-1));
        }
    }
    writeln(f[n][0]);
}