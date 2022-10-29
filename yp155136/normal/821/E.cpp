#include <iostream>
#include <stdio.h>
#include <cassert>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 17;
const LL mod = 1e9 + 7;

struct Rec {
    int n,m;
    LL a[MAX_N][MAX_N];
    void init(int _n,int _m ){
        n=_n;
        m=_m;
        memset(a,0,sizeof(a));
    }
};

Rec operator*(const Rec &r1,const Rec &r2) {
    assert(r1.m == r2.n);
    Rec ret;
    ret.init(r1.n,r2.m);
    for (int i=1;r1.n>=i;i++) {
        for (int j=1;r1.m>=j;j++) {
            for (int k=1;r1.m>=k;k++) {
                ret.a[i][j] += r1.a[i][k]*r2.a[k][j];
                ret.a[i][j] %= mod;
            }
        }
    }
    return ret;
}

Rec pow(Rec a,LL n) {
    if (n==1) return a;
    bool used=false;
    Rec ret;
    Rec b=a;
    while (n>0) {
        if (n%2==1) {
            if (!used) ret=b;
            else ret = ret * b;
            used=true;
        }
        n/=2;
        b = b*b;
    }
    return ret;
}

LL a[106],b[106],c[106];

int main () {
    int n;
    LL k;
    scanf("%d %lld",&n,&k);
    k++;
    Rec ans;
    ans.init(16,1);
    ans.a[1][1] = 1;
    for (int i=1;n>=i;i++) {
        scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
        a[i]++;
        b[i]++;
        c[i]++;
        if (b[i] > k) b[i]=k;
        Rec tran;
        tran.init(16,16);
        for (int j=1;c[i]>=j;j++) {
            for (int k=-1;1>=k;k++) {
                if (1<=j+k && j+k<=c[i]) {
                    tran.a[j][j+k]=1;
                }
            }
        }
        for (int j=c[i]+1;16>=j;j++) ans.a[j][1]=0;
        if (b[i] - a[i] >=1)tran = pow(tran,b[i]-a[i]);
        else continue;
        //cout<<"i = "<<i<<endl;
        ans = tran * ans;
    }
    printf("%lld\n",ans.a[1][1]);
}