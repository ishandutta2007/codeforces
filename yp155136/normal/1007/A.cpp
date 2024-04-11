#include <bits/stdc++.h>
using namespace std;

int cnt[123456];
int a[123456];

int main ()
{
    int n;
    scanf("%d",&n);
    vector<int> v;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    for (int i=1;n>=i;i++)
    {
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin()+1;
        cnt[ a[i] ]++;
    }
    int pre=0;
    int ans=0;
    for (int i=1;n>=i;i++)
    {
        ans += min(pre,cnt[i]);
        pre -= min(pre,cnt[i]);
        pre += cnt[i];
    }
    printf("%d\n",ans);
}