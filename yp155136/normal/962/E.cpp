#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200006;
const int INF = 1000000007;

int a[N];
char c[N];

vector<int> rv[N],bv[N];

LL l1[N],l2[N];
LL l11[N],l22[N];

int main ()
{
    int n;
    scanf("%d",&n);
    vector<LL> v;
    v.push_back(-INF);
    v.push_back(INF);
    LL P_max = -INF, P_min = INF;
    for (int i=1;n>=i;i++)
    {
        scanf("%d %c",&a[i],&c[i]);
        if (c[i] == 'P')
        {
            v.push_back(a[i]);
            P_max = max(P_max,a[i]*1LL);
            P_min = min(P_min,a[i]*1LL);
        }
        else if (c[i] == 'R')
        {
            ;
        }
        else if (c[i] == 'B')
        {
            ;
        }
    }
    sort(v.begin(),v.end());
    //LL ans = max(0LL,P_max - P_min);
    LL ans=0;
    for (int i=1;n>=i;i++)
    {
        if (c[i] == 'P') continue;
        else if (c[i] == 'R')
        {
            int _ = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
            --_;
            rv[_].push_back(a[i]);
        }
        else if (c[i] == 'B')
        {
            int _ = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
            --_;
            bv[_].push_back(a[i]);
        }
    }
    for (int i=0;n+1>=i;i++)
    {
        if ((int)rv[i].size() == 0) continue;
        if (v[i] == -INF && v[i+1] == INF)
        {
            ans += rv[i].back() - rv[i].front();
            continue;
        }
        else if (v[i] == -INF)
        {
            ans += v[i+1] - rv[i].front();
            continue;
        }
        else if (v[i+1] == INF)
        {
            ans += rv[i].back() - v[i];
            continue;
        }
        else
        {
            LL tmp = min(v[i+1] - rv[i].front() , rv[i].back() - v[i]);
            for (int j=0;rv[i].size()-1>j;j++)
            {
                tmp = min(tmp,rv[i][j] - v[i] + v[i+1] - rv[i][j+1]);
            }
            LL len1 = tmp;
            l1[i] = len1;
            l2[i] = v[i+1] - v[i];
            //ans += tmp;
        }
    }
    for (int i=0;n+1>=i;i++)
    {
        //rv[i] = bv[i];
        swap(rv[i],bv[i]);
        if ((int)rv[i].size() == 0) continue;
        if (v[i] == -INF && v[i+1] == INF)
        {
            ans += rv[i].back() - rv[i].front();
            continue;
        }
        else if (v[i] == -INF)
        {
            ans += v[i+1] - rv[i].front();
            continue;
        }
        else if (v[i+1] == INF)
        {
            ans += rv[i].back() - v[i];
            continue;
        }
        else
        {
            LL tmp = min(v[i+1] - rv[i].front() , rv[i].back() - v[i]);
            for (int j=0;rv[i].size()-1>j;j++)
            {
                tmp = min(tmp,rv[i][j] - v[i] + v[i+1] - rv[i][j+1]);
            }
            LL len1 = tmp;
            l11[i] = len1;
            l22[i] = v[i+1] - v[i];
        }
    }
    //cout << "pre ans = " << ans << endl;
    for (int i=0;v.size()-1>i;i++)
    {
        if (!l11[i] && !l1[i])
        {
            if (v[i] != -INF&& v[i+1] != INF) /*cout << "i = " << i << endl,*/ans += v[i+1] - v[i];
            continue;
        }
        if (!l2[i]) l2[i] = (v[i+1] - v[i]);
        if (!l22[i]) l22[i] = (v[i+1] - v[i]);
        LL tmp =  min( l1[i] + l11[i] + (v[i+1]-v[i]) , l2[i] + l22[i] );
        tmp = min(tmp,l1[i] + (v[i+1] - v[i]) + l22[i]);
        tmp = min(tmp,l11[i] + (l2[i]) + (v[i+1] - v[i]));
        //cout << "i = " <<i << " , tmp = " << tmp << " , v_i = " << v[i] << " , v_ii = " << v[i+1] <<endl;
        ans += tmp;
    }
    printf("%lld\n",ans);
}