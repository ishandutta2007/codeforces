#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
#define F first
#define S second
const int MAX_N = 1e5 + 6;

int t[MAX_N],a[MAX_N];
LL pre[MAX_N];
LL add[MAX_N];
LL sub[MAX_N];

LL ans[MAX_N];
int cnt[3*MAX_N];

piii p[MAX_N];

int B;

bool cmp(const piii &p1,const piii &p2) {
    if (p1.F.F/B != p2.F.F/B) return p1.F.F/B < p2.F.F/B;
    else return p1.F.S < p2.F.S;
}

LL cur_ans=0;

void addL(int x) {
    cur_ans += cnt[add[x]];
    cnt[pre[x]]++;
}

void addR(int x) {
    cur_ans += cnt[sub[x]];
    cnt[pre[x]]++;
}

void subL(int x) {
    cnt[pre[x]]--;
    cur_ans -= cnt[add[x]];
}

void subR(int x) {
    cnt[pre[x]]--;
    cur_ans -= cnt[sub[x]];
}

int main () {
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=1;n>=i;i++) {
        scanf("%d",&t[i]);
        if (t[i] == 2) t[i] = -1;
    }
    for (int i=1;n>=i;i++) {
        scanf("%d",&a[i]);
    }
    vector<LL> v;
    for (int i=1;n>=i;i++) {
        pre[i] = pre[i-1] + t[i]*1LL*a[i];
    }
    for (int i=0;n>=i;i++) {
        v.push_back(pre[i]);
        add[i] = pre[i] + k;
        v.push_back(pre[i]+k);
        sub[i] = pre[i] - k;
        v.push_back(pre[i]-k);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    for (int i=0;n>=i;i++) {
        pre[i] = lower_bound(v.begin(),v.end(),pre[i]) - v.begin() ;
        sub[i] = lower_bound(v.begin(),v.end(),sub[i]) - v.begin() ;
        add[i] = lower_bound(v.begin(),v.end(),add[i]) - v.begin() ;
    }
    int q;
    scanf("%d",&q);
    B=(sqrt(((n+q)>>1)));
    B = max(B,1);
    for (int i=1;q>=i;i++) {
        int L,R;
        scanf("%d %d",&L,&R);
        --L;
        p[i] = { {L,R} ,i};
    }
    sort(p+1,p+q+1,cmp);
    int L=1,R=0;
    for (int i=1;q>=i;i++) {
        piii q=p[i];
        while (R < q.F.S) addR(++R);
        while (L > q.F.F) addL(--L);
        while (R > q.F.S) subR(R--);
        while (L < q.F.F) subL(L++);
        ans[q.S] = cur_ans;
    }
    for (int i=1;q>=i;i++) {
        printf("%lld\n",ans[i]);
    }
}