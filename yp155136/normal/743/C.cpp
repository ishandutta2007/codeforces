#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;

struct P {
    LL a,b;
    P() {}
    P(LL _a,LL _b) : a(_a),b(_b) {}
    void pp() {
        cout<<"val = "<<a<<"/"<<b<<endl;
    }
};

P operator+(const P &p1,const P &p2) {
    LL a=p1.a*p2.b+p1.b*p2.a;
    LL b=p1.b*p2.b;
    return P(a/__gcd(a,b),b/__gcd(a,b));
}

P operator-(const P &p1,const P &p2) {
    return p1+(P(-p2.a,p2.b));
}

bool operator<(const P &p1,const P &p2) {
    return p1.a*p2.b<p2.b*p1.a;
}

const LL INF = 1e9;

int main () {
    int n;
    while (scanf("%d",&n) != EOF) {
        if (n==1) {
            puts("-1");
            continue;
        }
        int i=n;
        P need = P(1,n);
        for (int j=n+1;INF>=j;j++) {
            P ret = need-P(1,j);
            if (ret.a == 1 && ret.b != j && ret.b!=i && ret.b<=1e9) {
                cout<<i<<" "<<j<<" "<<ret.b<<endl;
                break;
            }
        }
    }
}