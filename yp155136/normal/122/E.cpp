#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 20;
const int K = 16;

LL f[N];

vector<LL> get_per(LL n,LL k)
{
    f[0]=1;
    for (int i=1;N>i;i++)
    {
        f[i] = f[i-1] * i;
    }
    vector<LL> ret;
    ret.resize(n);
    set<int> st;
    for (int i=1;n>=i;i++)
    {
        st.insert(i);
    }
    for (int i=0;n>i;i++)
    {
        int times=0;
        auto now = st.begin();
        while (f[n-i-1] < k)
        {
            k -= f[n-i-1];
            now++;
        }
        ret[i] = (*now);
        st.erase(now);
    }
    return ret;
}

int main ()
{
    vector<LL> v;
    for (int sz=1;9>=sz;sz++)
    {
        for (int i=0;(1<<sz)>i;i++)
        {
            LL now=0;
            for (int j=0;sz>j;j++)
            {
                if (((1<<j)&i) != 0)
                {
                    now *= 10;
                    now += 4;
                }
                else
                {
                    now *= 10;
                    now += 7;
                }
            }
            v.push_back(now);
        }
    }
    v.push_back(4444444444LL);
    sort(v.begin(),v.end());
    int n,k;
    cin >> n >> k;
    f[0]=1;
    for (int i=1;N>i;i++) f[i] = f[i-1] * i;
    if (n <= K && f[n] < k)
    {
        puts("-1");
        return 0;
    }
    if (n <= K)
    {
        vector<LL> ret = get_per(n,k);
        LL ans=0;
        for (int i=0;n>i;i++)
        {
            if (i+1 == 4 || i+1 == 7)
            {
                if (ret[i] == 4 || ret[i] == 7)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    LL tmp = n-K;
    LL now = n-K;
    auto iter = lower_bound(v.begin(),v.end(),tmp);
    if ((*iter) != now) --iter;
    LL ans = iter-v.begin()+1;
    set<LL> lucky;
    for (LL i:v) lucky.insert(i);
    vector<LL> ret = get_per(K,k);
    for (int i=0;K>i;i++)
    {
        int pos = i+now+1;
        if (lucky.find(pos) != lucky.end())
        {
            LL val=ret[i] + now;
            if (lucky.find(val) != lucky.end()) ans++;
        }
    }
    cout << ans<<endl;
}