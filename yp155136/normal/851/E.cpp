#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 106;

int a[N];

map<LL,LL> mp;

int get_mex(vector<int> v)
{
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    for (int i=0;v.size()>i;i++)
    {
        if (v[i] != i) return i;
    }
    return v.size();
}

LL solve(LL x)
{
    if (mp.find(x) != mp.end()) return mp[x];
    vector<int> v;
    for (int i=1;;i++)
    {
        //select k=i
        if ( x < (1LL<<(i-1)) ) break;
        v.push_back(solve( (x&((1LL<<(i-1))-1) | (x>>i)) ));
    }
    return mp[x] = get_mex(v);
}

int main ()
{
    int n;
    scanf("%d",&n);
    vector<int> v;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        int tmp=a[i];
        for (int j=2;j*j <= tmp;j++)
        {
            if (tmp%j==0)
            {
                v.push_back(j);
                while (tmp%j==0) tmp/=j;
            }
        }
        if (tmp != 1)
        {
            v.push_back(tmp);
        }
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    mp[0] = 0;
    LL sg = 0;
    for (int p:v)
    {
        LL mask=0;
        for (int i=1;n>=i;i++)
        {
            int cnt=0;
            while (a[i]%p==0)
            {
                ++cnt;
                a[i] /= p;
            }
            if (cnt)
            {
                mask |= (1<<(cnt-1));
            }
        }
        sg ^= solve(mask);
    }
    if (sg) puts("Mojtaba");
    else puts("Arpa");
}