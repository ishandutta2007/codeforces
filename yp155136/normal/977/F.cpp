#include <bits/stdc++.h>
using namespace std;

const int N = 600006;

int a[N];

int pre[N];
int dp[N];
int dp_num[N];

int main ()
{
    int n;
    scanf("%d",&n);
    vector<int> v;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
        v.push_back(a[i]-1);
        v.push_back(a[i]+1);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    for (int i=1;n>=i;i++)
    {
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
    }
    for (int i=1;n>=i;i++)
    {
        int val = a[i];
        //cout << "i = " << i << " , val = " << val
        if (dp[val-1] + 1 > dp[val])
        {
            dp[val] = dp[val-1] + 1;
            dp_num[val] = i;
            if (dp[val-1] != 0)
            {
                pre[i] = dp_num[val-1];
            }
        }
    }
    int mx=0;
    int mx_id = 0;
    for (int i=0;N>i;i++)
    {
        if (dp[i] > mx)
        {
            mx = dp[i];
            mx_id = i;
        }
    }
    v.clear();
    //vector<int> v;
    printf("%d\n",mx);
    int now = dp_num[mx_id];
    while (now != 0)
    {
        v.push_back(now);
        now = pre[now];
    }
    reverse(v.begin(),v.end());
    for (int i=0;v.size()>i;i++)
    {
        if (i) printf(" ");
        printf("%d",v[i]);
    }
    puts("");
}