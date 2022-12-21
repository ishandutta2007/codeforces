#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,a[N];
char c[N],b[N];
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d",&n);
        scanf("%s",c);
        strcpy(b,c);
        sort(b,b+n);
        int s=0;
        for (int i=0;i<n;i++) if (b[i]!=c[i])  s++;
        printf("%d\n",s);
    }
}