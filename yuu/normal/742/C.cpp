#include <stdio.h>
#include <vector>
using namespace std;
bool d[101];
int adj[101];
int a;
int n;
long long b[101];
int cccnt;
long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b, a%b);
}
long long lcm(long long a, long long b){
    return a/gcd(a, b)*b;
}
int main(){
//    freopen("C.INP", "r", stdin);
    scanf("%i", &n);
    for(int i=1; i<=n; i++){
        scanf("%i", &a);
        adj[i]=a;
    }
    for(int i=1; i<=n; i++){
        if(!d[i]){
            int u=i;
            d[i]=1;
            if(adj[u]==u) continue;
            else{
                long long cnt=0;
                do{
                    u=adj[u];
                    if(u!=i&&d[u]){
                        printf("-1");
                        return 0;
                    }
                    d[u]=1;
                    cnt++;

                }
                while(u!=i);
                if(cnt%2)
                    b[++cccnt]=cnt;
                else{
                    if(cnt>2)
                        b[++cccnt]=cnt/2;
                }
            }
        }
    }
    long long res=1;
    for(int i=1; i<=cccnt; i++)
        res=lcm(res, b[i]);
    if(res==1)
        printf("1");
    else printf("%I64d", res);
}