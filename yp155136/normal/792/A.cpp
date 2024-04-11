#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 6;

int a[MAX_N];

int main () {
    int n;
    while (scanf("%d",&n) != EOF) {
        for (int i=1;n>=i;i++) {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        int mn=2147483647;
        for (int i=1;n>i;i++) {
            mn = min(mn,a[i+1]-a[i]);
        }
        int cnt=0;
        for (int i=1;n>i;i++) {
            if (a[i+1]-a[i]==mn) cnt++;
        }
        printf("%d %d\n",mn,cnt);
    }
}