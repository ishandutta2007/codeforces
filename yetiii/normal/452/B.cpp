#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
using namespace std;

typedef pair<int, int> Pt;
void add(vector<Pt> &v, int x, int y, int n, int m, int K)
{
    for (int dx=-K;dx<=K;++dx) for (int dy=-K;dy<=K;++dy)
    {
        int nx=x+dx, ny=y+dy;
        if (nx<0||ny<0||nx>n||ny>m) continue;
        v.push_back(make_pair(nx, ny));
    }
}
inline double no(int a, int b)
{
    return sqrt(a*a+b*b);
}
inline double len(const vector<Pt> &v)
{
    double rs=0;
    for (int i=0;i<v.size();++i) for (int j=0;j<i;++j) if (v[i]==v[j]) return -1;
    for (int i=1;i<v.size();++i)
    {
        rs+=no(v[i].first-v[i-1].first, v[i].second-v[i-1].second);
    }
    return rs;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<Pt> rs(4), co, t(4);
    int K=3;
    add(co, 0, 0, n, m, K);
    add(co, n, 0, n, m, K);
    add(co, 0, m, n, m, K);
    add(co, n, m, n, m, K);
    //printf("%d\n", co.size());
    double md=-1;
    for (int i=0;i<co.size();++i) for (int j=0;j<co.size();++j)
        for (int i1=0;i1<co.size();++i1) for (int j1=0;j1<co.size();++j1)
            {
                t[0]=co[i];
                t[1]=co[j];
                t[2]=co[i1];
                t[3]=co[j1];
                if (len(t)>md)
                {
                    md=len(t);
                    rs=t;
                }
            }
    for (int i=0;i<4;++i) printf("%d %d\n", rs[i].first, rs[i].second);
    return 0;
}