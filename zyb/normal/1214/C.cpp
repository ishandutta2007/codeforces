#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define lowbit(x) x&-x
int n,m,a,b,ans;
char c[N];
int main() {
    //freopen("0.in","r",stdin);
    scanf("%d",&n);
    scanf("%s",c);
    int s=0;
    for (int i=0;i<n;i++) {
        if (c[i]=='(') s++;
        else s--;
        if (s<-1) return puts("No"),0;
    }
    if (s) puts("No");
    else puts("Yes");
}