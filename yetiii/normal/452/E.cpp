#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;

const int M=1<<20;
const int maxlen=M;
const int alphabet=256;
int rmt[M+M];
void rmq_build(int *a, int n)
{
    for (int i=0;i<n;++i)
    {
        rmt[i]=1e9;
        rmt[M+i]=a[i];
    }
    for (int i=M-1;i>=0;--i) rmt[i]=min(rmt[i+i], rmt[i+i+1]);
}
int rmq(int l, int r)
{
    int rs=1e9;
    l+=M; r+=M;
    for (;l<=r;l=(l+1)>>1, r=(r-1)>>1)
    {
        if (l&1) rs=min(rs, rmt[l]);
        if ((r&1)==0) rs=min(rs, rmt[r]);
    }
    return rs;
}
char s[maxlen]; int n;
int lcp[maxlen], lcpn[maxlen], lpos[maxlen], rpos[maxlen];
int pn[maxlen], cn[maxlen];
int p[maxlen], cnt[maxlen], c[maxlen];
void sarr()
{
    for (int i=0; i<n; ++i)
        ++cnt[s[i]];
    for (int i=1; i<alphabet; ++i)
        cnt[i]+=cnt[i-1];
    for (int i=0; i<n; ++i)
        p[--cnt[s[i]]]=i;
    c[p[0]]=0;
    int classes=1;
    for (int i=1; i<n; ++i) {
        if (s[p[i]]!=s[p[i-1]])  ++classes;
        c[p[i]]=classes-1;
    }
    memset(lcp, 0, sizeof lcp);
    for (int h=0; (1<<h)<n; ++h) {
        for (int i=0; i<n; ++i)
            rpos[c[p[i]]]=i;
        for (int i=n-1; i>=0; --i)
            lpos[c[p[i]]]=i;

        for (int i=0; i<n; ++i) {
            pn[i]=p[i]-(1<<h);
            if (pn[i] < 0)  pn[i]+=n;
        }
        memset(cnt, 0, classes * sizeof(int));
        for (int i=0; i<n; ++i)
            ++cnt[c[pn[i]]];
        for (int i=1; i<classes; ++i)
            cnt[i]+=cnt[i-1];
        for (int i=n-1; i>=0; --i)
            p[--cnt[c[pn[i]]]]=pn[i];
        cn[p[0]]=0;
        classes=1;
        for (int i=1; i<n; ++i) {
            int mid1=(p[i]+(1<<h))%n, mid2=(p[i-1]+(1<<h))%n;
            if (c[p[i]]!=c[p[i-1]]||c[mid1]!=c[mid2])
                ++classes;
            cn[p[i]]=classes-1;
        }
        rmq_build(lcp, n-1);
        for (int i=0; i<n-1; ++i) {
            int a=p[i], b=p[i+1];
            if (c[a]!=c[b])
                lcpn[i]=lcp[rpos[c[a]]];
            else {
                int aa=(a+(1<<h))%n, bb=(b+(1<<h))%n;
                lcpn[i]=(1<<h)+rmq(lpos[c[aa]], rpos[c[bb]]-1);
                lcpn[i]=min(n, lcpn[i]);
            }
        }
        memcpy(lcp, lcpn, (n-1) * sizeof(int));
        memcpy(c, cn, n * sizeof(int));
    }
}
char s1[M], s2[M], s3[M];
const int mod=1000000007;
int add(int a, int b)
{
    a+=b; if (a>=mod) a-=mod; return a;
}
int sub(int a, int b)
{
    a-=b; if (a<0) a+=mod; return a;
}
int mul(int a, long long b)
{
    return (a*b)%mod;
}
int n1, n2, n3, d[M], dl[M], dr[M];
struct Es
{
    int a, b, c;
    int ab()
    {
        return mul(a, mul(b, c));
    }
};
Es operator +(const Es &a, const Es &b)
{
    return{a.a+b.a, a.b+b.b, a.c+b.c};
}
Es sdl[M], sdr[M], ty[M];
Es gt(int i)
{
    i=p[i];
    if (i<n1) return{1, 0, 0};
    i-=n1+1;
    if (i<n2) return{0, 1, 0};
    return{0, 0, 1};
}
int ski[M];
int main()
{
    //freopen("in.txt", "r", stdin);
    gets(s1);n1=strlen(s1);
    gets(s2);n2=strlen(s2);
    gets(s3);n3=strlen(s3);
    for (int i=0;i<n1;++i) s[n++]=s1[i]; s[n++]='z'+1;
    for (int i=0;i<n2;++i) s[n++]=s2[i]; s[n++]='z'+2;
    for (int i=0;i<n3;++i) s[n++]=s3[i]; s[n++]='z'+3;
    sarr();
    for (int i=0;i<n;++i) ty[i]=gt(i);
    for (int i=n-2;i>=0;--i)
    {
        int j=i+1; sdr[i]=ty[i+1];
        while (j+1<n&&lcp[i]<=lcp[j]) sdr[i]=sdr[i]+sdr[j], j=dr[j];
        dr[i]=j;
    }
    for (int i=0;i+1<n;++i)
    {
        int j=i-1; sdl[i]=ty[i];
        while (j>=0&&lcp[i]<=lcp[j]) sdl[i]=sdl[i]+sdl[j], j=dl[j];
        dl[i]=j;
    }
    set<pair<int, pair<int, int>>> cu;
    vector<pair<int, int>> ev;
    for (int i=0;i+1<n;++i) ev.push_back(make_pair(lcp[i], -i));
    sort(ev.begin(), ev.end());
    int z=0, lp=n;
    for (int i=ev.size()-1;i>=0;)
    {
        int l=ev[i].first;
        while (lp>l) d[lp]=z, --lp;
        int j=i;
        while (i>=0&&ev[i].first==l) --i;
        while (j!=i)
        {
            int I=-ev[j--].second;
            int l=lcp[I];
            if (ski[l]>I) continue;
            int cn=(sdl[I]+sdr[I]).ab();
            z=add(z, cn);
            ski[l]=dr[I];
            auto it=cu.lower_bound(make_pair(dl[I], make_pair(0, 0)));
            while (it!=cu.end()&&it->second.first<=dr[I])
            {
                z=sub(z, it->second.second);
                auto itb=it; ++itb;
                cu.erase(it); it=itb;
            }
            cu.insert(make_pair(dl[I], make_pair(dr[I], cn)));
        }
    }
    for (int i=0;i<min(min(n1, n2), n3);++i) printf("%d ", d[i+1]);
    return 0;
}