#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <map>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,pii> piiii;
const int MAX_N = 2506;

struct BIT_2D {
    static const int MAX_N = 2506;
    int bit[MAX_N][MAX_N];
    int n,m;
    void init(int n,int m) {
        this->n = n;
        this->m = m;
        memset(bit,0,sizeof(bit));
    }
    void add(int x,int y,int w) {
        for (int i=x;n>=i;i+=i&(-i)) {
            for (int j=y;m>=j;j+=(j&(-j))) {
                bit[i][j] ^= w;
            }
        }
    }
    int qry(int x,int y) {
        int ret=0;
        for (int i=x;i>=1;i-=i&(-i)) {
            for (int j=y;j>=1;j-=j&(-j)) {
                ret ^= bit[i][j];
            }
        }
        return ret;
    }
} bit;

int myRnd() {
    return (rand()<<15) + rand();
}

int main () {
    srand(time(NULL));
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    bit.init(n+1,m+1);
    map<piiii,int> mp;
    while (q--) {
        int a,b,c,d,e;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        if (a==3) {
            int ret1=bit.qry(b,c);
            int ret2=bit.qry(d,e);
            if (ret1 == ret2) puts("Yes");
            else puts("No");
        }
        else {
            int now=myRnd();
            if (a==1) {
                mp[ {{b,c} , {d,e}} ] = now;
            }
            if (a==2) now=mp[{{b,c},{d,e}}];
            bit.add(d+1,e+1,now);
            bit.add(b,e+1,now);
            bit.add(d+1,c,now);
            bit.add(b,c,now);
        }
    }
}