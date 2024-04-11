#include <bits/stdc++.h>
using namespace std;

const long long N = 100;
const long long MOD = 1e9 + 7;
long long step[N][N][2];
long long num [N][N][2];

struct node{
private:
    long long a,b,c;
public:
    void set(long long x,long long y,long long z){
        a = x;
        b = y;
        c = z;
    }
    long long getA() const {
        return a;
    }
    long long getB() const {
        return b;
    }
    long long getC() const {
        return c;
    }
};

long long modC(long long below,long long over){
    if (below == 0 || over == 0){
        return 1;
    }
    long long ans = 1;
    long long i = 1,j = below;
    for (;i<=over;i++,j--){
        ans *= j;
        ans /= i;
    }
    return ans % (long long)MOD;
} 

node que[N * N * 10];

void bfs(long long n50,long long n100,long long k){
    memset(step,-1,sizeof(step));
    memset(num,0,sizeof(num));
    step[n50][n100][0] = 0;
    num[n50][n100][0] = 1;
    long long l = 0 ;
    long long r = 0 ;
    que[r++].set(n50,n100,0);
    while (l < r){
        long long foo = que[l].getC();
        long long nx = que[l].getA();
        long long ny = que[l].getB();
        long long mx = nx;
        long long my = ny;
        if (foo){
            mx = n50 - mx;
            my = n100 - my;
        }
        //cout<<nx<<' '<<ny<<' '<<foo<<endl;
        for (long long i=0;i <= mx;i++){
            for (long long j=0;j <= my;j++){
                if (i == 0 && j == 0){
                    continue;
                }
                long long remove = i * 50 + j * 100;
                if (remove > k){
                    continue;
                }
                if (foo){
                    long long tx = nx + i;
                    long long ty = ny + j;
                    long long cost = step[nx][ny][foo] + 1;
                    if (tx > n50 || ty > n100){
                        continue;
                    }
                    if (step[tx][ty][!foo] < cost && step[tx][ty][!foo] != -1){
                        continue;
                    }
                    if (step[tx][ty][!foo] == -1){
                    	que[r++].set(tx,ty,!foo);
					}
                    step[tx][ty][!foo] = cost;
                    num[tx][ty][!foo] += num[nx][ny][foo] * modC(mx,i) % MOD * modC(my,j);
                    //cout<<nx<<' '<<i<<' '<<tx<<' '<<ny<<' '<<j<<' '<<ty<<' '<<modC(mx,i) % MOD * modC(my,j)<<endl;
                    num[tx][ty][!foo] %= MOD;
                }else{
                    long long tx = nx - i;
                    long long ty = ny - j;
                    long long cost = step[nx][ny][foo] + 1;
                    if (tx < 0 || ty < 0){
                        continue;
                    }
                    if (step[tx][ty][!foo] < cost && step[tx][ty][!foo] != -1){
                        continue;
                    }
                    if (step[tx][ty][!foo] == -1){
                    	que[r++].set(tx,ty,!foo);
					}
                    step[tx][ty][!foo] = cost;
                    num[tx][ty][!foo] += num[nx][ny][foo] * modC(mx,i) % MOD * modC(my,j);
                    //cout<<nx<<' '<<i<<' '<<tx<<' '<<ny<<' '<<j<<' '<<ty<<' '<<modC(mx,i) % MOD * modC(my,j)<<endl;
                    num[tx][ty][!foo] %= MOD;
                }
            }
        }
        l++;
    }
}

int main(){
    long long n,k;
    scanf("%lld%lld",&n,&k);
    k = k / 50 * 50;
    long long n50 = 0;
    long long n100 = 0;
    for (long long i=1;i<=n;i++){
        long long read;
        scanf("%lld",&read);
        if (read == 50){
            n50 ++;
        }else{
            n100 ++;
        }
    }
    bfs(n50,n100,k);
    printf("%lld\n%lld\n",step[0][0][1],num[0][0][1]);
    return 0;
}