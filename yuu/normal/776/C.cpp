#include <stdio.h>
#include <locale>
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
template <typename T> inline void read(T &x){
scanf("%I64d", &x);
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
#include <algorithm>
#include <map>
using namespace std;
long long a[100001];
map <long long, int> M;
long long n, k;
long long ans=0;
int main(){
    #ifdef JohnTitor
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // JohnTitor
    read(n);
    read(k);
    M[a[0]]=1;
    FOR(i, 1, n){
        read(a[i]);
        a[i]+=a[i-1];
        if(k==1||k==-1){
            if(M.find(a[i]-1)!=M.end())
                ans+=M[a[i]-1];
        }
        else{
            for(long long kk=1; kk<=10000000000000000; kk*=k){
                if(M.find(a[i]-kk)!=M.end())
                    ans+=M[a[i]-kk];
            }
        }
        if(k==-1){
            if(M.find(a[i]+1)!=M.end())
                ans+=M[a[i]+1];
        }
        if(M[a[i]]==0)
            M[a[i]]=1;
        else M[a[i]]++;
    }
    write(ans);
}