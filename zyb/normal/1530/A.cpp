#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,a[N];
#define pb push_back
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d",&n);
        int s = 0;
        while (n) {
            s = max(s, n % 10);
            n /= 10;
        }
        printf("%d\n",s);
    }
}