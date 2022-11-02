#include<bits/stdc++.h>
#define maxn 234000

using namespace std;
char s[maxn];
int a,b,c,n,m,cnt[256],t;

int main()
{
    cin>>n;
    scanf("%s",s);
    m=strlen(s);
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<m;i++) cnt[s[i]]++;
    t=0; for (int i=0;i<256;i++) t=max(t,cnt[i]);
    a=min(m,t+n);
    if (n==1&&t==m) a=m-1;
    scanf("%s",s);
    m=strlen(s);
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<m;i++) cnt[s[i]]++;
    t=0; for (int i=0;i<256;i++) t=max(t,cnt[i]);
    b=min(m,t+n);
    if (n==1&&t==m) b=m-1;
    scanf("%s",s);
    m=strlen(s);
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<m;i++) cnt[s[i]]++;
    t=0; for (int i=0;i<256;i++) t=max(t,cnt[i]);
    c=min(m,t+n);
    if (n==1&&t==m) c=m-1;
    if (a>b&&a>c) printf("Kuro\n");
    else if (b>a&&b>c) printf("Shiro\n");
    else if (c>a&&c>b) printf("Katie\n");
    else printf("Draw\n");
    return 0;
}