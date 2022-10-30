#include<bits/stdc++.h>
#define maxn 200050
using namespace std;

int n,m,a[maxn];

int cnt[maxn];

int T[maxn];

int pos[maxn];

int lowbit(int i)   {
    return i&-i;
}
void change(int i) {
    for (++i;i<=m;i+=lowbit(i))
        ++T[i];
}

int query(int i)    {
    if (!i) return 0;
    int ans=0;
    for (;i;i-=lowbit(i))
        ans+=T[i];
    return ans;
}

int main()  {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),++cnt[a[i]%m],pos[i]=i;
    
    sort(pos+1,pos+n+1,[&](int i,int j) {
        return a[i]<a[j];
    });

    int sgn=0;
    for (int k=n;k;--k) {
        int i=pos[k];
        sgn^=query(a[i]%m)&1;
        // cout<<i<<":"<<a[i]%m<<" "<<query(a[i]%m)<<endl;
        change(a[i]%m);
    }

    int ans=1;
    for (int i=0;i<m;++i)   {
        if (!cnt[i]) continue;

        // cout<<i<<":"<<cnt[i]<<endl;
        if (cnt[i]>1) ans=0;
        for (int j=0;j<i;++j)
            if (cnt[i]&&cnt[j])
                ans=ans*(i-j)%m;
    }
    if (sgn)
        ans=m-ans;
    printf("%d\n",ans%m);
    return 0;
}