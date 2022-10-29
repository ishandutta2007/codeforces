#include <bits/stdc++.h>
using namespace std;

typedef double ld;
typedef pair<ld,int> P; //value,time
const int N = 200006;

ld pre[N],pre2[N],pre3[N];

ld t[N];

ld dp[N];
int cnt[N];

//dp[i] = dp[j] + (pre2[i] - pre2[j]) - pre[j] * (pre3[i] - pre3[j]) + cost!

ld f(int i)
{
    return pre2[i];
}

ld g(int j)
{
    return dp[j] - pre2[j] + pre[j]*pre3[j];
}

ld h(int i)
{
    return -pre3[i];
}

ld q(int j)
{
    return pre[j];
}

struct Line
{
    ld m,b;
    int id;
    Line(ld _m,ld _b,int _id) : m(_m),b(_b),id(_id){}
    P get_val(ld x)
    {
        return make_pair(m*x+b,cnt[id]);
    }
};

bool check(Line a,Line b,Line c)
{
    return (a.m - b.m) * (a.b - c.b) <= (a.m - c.m) * (a.b - b.b);
}

P cal(int n,ld cost)
{
    deque<Line> dq;
    dq.push_back(Line(0,0,0));
    for (int i=1;n>=i;i++)
    {
        while (dq.size() > 1 && dq[0].get_val(h(i)) > dq[1].get_val(h(i)))
        {
            dq.pop_front();
        }
        dp[i] = dq[0].get_val(h(i)).first + f(i) + cost;
        cnt[i] = cnt[ dq[0].id ] +1;
        Line newLine = Line(q(i),g(i),i);
        while (dq.size() > 1 && check( dq[ dq.size()-2 ] , dq[ dq.size()-1 ],newLine)) dq.pop_back();
        dq.push_back(newLine);
    }
    return make_pair(dp[n],cnt[n]);
}

int main ()
{
    //freopen("input2001.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >>n >>k;
    for (int i=1;n>=i;i++)
    {
        cin >> t[i];
        pre[i] = pre[i-1] + t[i];
        pre2[i] = pre2[i-1] + pre[i]/t[i];
        pre3[i] = pre3[i-1] + 1/t[i];
    }
    ld L=0,R=1e15+9;
    int cnt = 150;
    while (cnt--)
    {
        ld mid=(L+R)/2.0;
        P tmp = cal(n,mid);
        if (tmp.second <= k) R = mid;
        else L = mid;
    }
    P tmp = cal(n,R);
    cout <<fixed <<setprecision(12) << tmp.first - tmp.second*R <<endl;
}