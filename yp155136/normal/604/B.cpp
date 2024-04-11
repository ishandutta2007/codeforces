#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main () {
    int n,k;
    while (scanf("%d %d",&n,&k) != EOF) {
        int s[n];
        for (int x=0;n>x;x++) scanf("%d",&s[x]);
        int ans=s[n-1];
        if (k>=n) printf("%d\n",ans);
        else {        //b1 + b2 = k      while      b1 + 2*b2 = n 
            int b2 = n-k;
            int b1 = k-b2;
            for (int x=0;b2>x;x++) {
                //cout << "s[" << x << "] + s[" << 2*b2-x << "] = " << s[x] + s[2*b2-x] << endl;
                if (s[x] + s[2*b2-1-x] > ans) ans=s[x] + s[2*b2-1-x];
            }
            printf("%d\n",ans);
        }
    }
}