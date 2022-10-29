#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 2006;

#define F first
#define S second

int a[N];
bool yee[N];

int main ()
{
    int n,k;
    scanf("%d %d",&n,&k);
    vector<pii> v;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        v.push_back(make_pair(a[i],i));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int tot=0;
    for (int i=0;k>i;i++)
    {
        yee[ v[i].second ] = true;
        tot += v[i].first;
    }
    printf("%d\n",tot);
    vector<int> ans;
    int pre=0;
    for (int i=1;n>=i;i++)
    {
        ++pre;
        if (yee[i])
        {
            ans.push_back(pre);
            pre=0;
        }
    }
    if (!yee[n])
    {
        ans[k-1] += pre;
    }
    for (int i=0;k>i;i++)
    {
        printf("%d%c",ans[i]," \n"[i == k-1]);
    }
}