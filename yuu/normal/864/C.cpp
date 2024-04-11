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
int a, b, k, f;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(a);
    read(b);
    read(f);
    read(k);
    if(b<f){
        write(-1);
        return 0;
    }
    if(b<a-f){
        write(-1);
        return 0;
    }
    if(k>=2){
        if(b<2*(a-f)){
            write(-1);
            return 0;
        }
    }
    if(k>=3){
        if(b<2*f){
            write(-1);
            return 0;
        }
    }
    int ans=0;
    int c=b;
    FOR(i, 1, k){
        if(i%2){
            b-=f;
            if((i<k&&b>=2*(a-f))||(i==k&&b>=a-f)){
                b-=a-f;
                continue;
            }
            else{
                b=c-(a-f);
                ans++;
                continue;
            }
        }
        else{
            if(b<a-f){
                write(-1);
                return 0;
            }
            b-=a-f;
            if((i<k&&b>=2*f)||(i==k&&b>=f)){
                b-=f;
                continue;
            }
            else{
                b=c-f;
                ans++;
                continue;
            }
        }
    }
    writeln(ans);
}