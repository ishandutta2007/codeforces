#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long ll;

int main () {
    
    ll n2[64];
    n2[0]=1;
    for (int x=1;64>x;x++) n2[x] = 2*n2[x-1];
    
    ll a,b;
    while (scanf("%I64d %I64d",&a,&b) != EOF) {
        ll ans=0;
        for (int i=2;60>=i;i++) {   //total
            for (int j=1;i>j;j++) {  //which = 0
                ll tmp = n2[i] - 1 -n2[j-1];
                if (tmp>=a && tmp<=b) ans++;
                //cout << tmp << endl;
            }
        }
        printf("%I64d\n",ans);
    }
}