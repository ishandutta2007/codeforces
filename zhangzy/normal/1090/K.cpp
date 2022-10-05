#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int mo1=998244353;
const int mo2=1e9+7;
const int Base=2333;
int n,vis[100];
char s[1000006],t[1000006];
struct data {
    int loc,x;
    long long h1,h2;
}a[1000001];
bool cmp(data p,data q) {
    if (p.x!=q.x) return p.x<q.x;
    if (p.h1!=q.h1) return p.h1<q.h1;
    return p.h2<q.h2;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        a[i].loc=i;
        scanf("%s%s",s,t);
        int len1=strlen(s),len2=strlen(t);
        for (int j=0;j<26;j++) vis[j]=0;
        for (int j=0;j<len2;j++) vis[t[j]-97]=1;
        a[i].x=0;
        for (int j=0;j<26;j++)
            a[i].x=a[i].x*2+vis[j];
        int j=len1-1;
        for (;j>=0;j--) if (!vis[s[j]-97]) break;
        j++;
        a[i].h1=0;
        a[i].h2=0;
        for (int k=0;k<j;k++) {
            a[i].h1=(a[i].h1*Base+s[k]-96)%mo1;
            a[i].h2=(a[i].h2*Base+s[k]-96)%mo2;
        }
    }
    sort(a+1,a+n+1,cmp);
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (i==1||a[i].h1!=a[i-1].h1||a[i].h2!=a[i-1].h2||a[i].x!=a[i-1].x)
            cnt++;
    printf("%d\n",cnt);
    for (int i=1;i<=n;) {
        int j=i;
        while (j<=n) {
            if (a[j].h1!=a[i].h1||a[j].h2!=a[i].h2||a[j].x!=a[i].x) break;
            j++;
        }
        printf("%d ",j-i);
        for (int k=i;k<j;k++) printf("%d ",a[k].loc);
        printf("\n");
        i=j;
    }
    return 0;
}