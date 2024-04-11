#include <bits/stdc++.h>
using namespace std;

const int N = 100006;
int a[N];
int pos[N];
bool dp[N];

int main () {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        int x;
        scanf("%d",&a[i]);
        pos[ a[i] ] = i;
    }
    for (int i=n;i>=1;--i) {
        int p = pos[i];
        bool flag = false; //first lose
        for (int j=p;j<=n;j+=i) {
            if (a[j]>i && !dp[ j ]) flag = true;
        }
        for (int j=p;j>=1;j-=i) {
            if (a[j]>i && !dp[ j ]) flag = true;
        }
        dp[p] = flag;
    }
    for (int i=1;i<=n;++i) {
        if (dp[i]) putchar('A');
        else putchar('B');
    }
    puts("");
}