#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main () {
    int k;
    int a[12];
    while (scanf("%d",&k) != EOF) {
        int sum=0;
        for (int x=0;12>x;x++) {
            scanf("%d",&a[x]);
            sum+=a[x];
        }
        if (sum<k) printf("-1\n");
        else {
            sort(a,a+12);
            int tmp=0;
            int ans=0;
            for (int x=11;x>=0;x--) {
                if (tmp>=k) break;
                tmp+=a[x];
                ans++;
            }
            printf("%d\n",ans);
        }
    }
}