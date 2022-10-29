#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int N = 400006;

LL L[N],R[N];

int e[N];

LL cnt[N];

int main ()
{
    int n;
    scanf("%d",&n);
    vector<LL> v;
    for (int i=1;n>=i;i++)
    {
        scanf("%lld %lld",&L[i],&R[i]);
        v.push_back(L[i]);
        v.push_back(R[i]+1);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    for (int i=1;n>=i;i++)
    {
        int l = lower_bound(v.begin(),v.end(),L[i]) - v.begin();
        int r = lower_bound(v.begin(),v.end(),R[i]+1) - v.begin();
        e[l]++;
        e[r]--;
        //cout << "l = " << l << " , r = " << r << endl;
    }
    int now=0;
    for (int i=0;v.size()>i;i++)
    {
        //cout << "i = " << i << " , now = " << now << " , v = " <<v[i] << " e = " << e[i] <<endl;
        if (i)
        {
            cnt[now] += (v[i] - v[i-1]);
        }
        now += e[i];
    }
    for (int i=1;n>=i;i++)
    {
        printf("%lld%c",cnt[i]," \n"[i==n]);
    }
}