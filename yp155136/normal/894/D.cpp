#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long LL;
const int N = 1000006;

vector<int> v[N];
vector<LL> pre[N];

#define SZ(x) ((int)(x).size())

int l[N];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=2;n>=i;i++)
    {
        scanf("%d",&l[i]);
    }
    for (int i=n;i>=1;i--)
    {
        v[i].push_back(0);
        int L=(i<<1),R=((i<<1)|1);
        if (L>n) ;
        else if (R>n)
        {
            for (int x:v[L])
            {
                v[i].push_back(x+l[L]);
            }
        }
        else
        {
            int Lid=0,Rid=0;
            while (Lid != SZ(v[L]) || Rid != SZ(v[R]))
            {
                if (Lid == SZ(v[L])) v[i].push_back(v[R][Rid++]+l[R]);
                else if (Rid == SZ(v[R])) v[i].push_back(v[L][Lid++]+l[L]);
                else
                {
                    int lnum = v[L][Lid] + l[L];
                    int rnum = v[R][Rid] + l[R];
                    if (lnum >= rnum)
                    {
                        v[i].push_back(rnum);
                        Rid++;
                    }
                    else
                    {
                        v[i].push_back(lnum);
                        Lid++;
                    }
                }
            }
        }
        pre[i].resize(SZ(v[i]));
        for (int j=0;SZ(v[i])>j;j++)
        {
            if (j) pre[i][j] = pre[i][j-1] + v[i][j];
            else pre[i][j] = v[i][j];
        }
        //partial_sum(v[i].begin(),v[i].begin()+SZ(v[i]),pre[i]);
    }
    while (m--)
    {
        int a,h;
        scanf("%d %d",&a,&h);
        LL ans=0;
        int lasta=a;
        int oria = a;
        while (a > 0 && h>0)
        {
            if (oria == a)
            {
                //cout << "gee"<<endl;
                //cout << "h = "<<h<<endl;
                auto iter = upper_bound(v[a].begin(),v[a].end(),h);
                --iter;
                int pos = iter-v[a].begin();
                //cout << "pos = "<<pos<<endl;
                ans += (h*1LL*(pos+1) - pre[a][pos]);
                //cout << "kirino"<<endl;
                lasta = a;
                a >>= 1;
                h -= l[lasta];
                //cout << "finish gee" <<endl;
            }
            else
            {
                int targeta;
                if (lasta == (a<<1)) targeta = ((a<<1)|1);
                else targeta = ((a<<1));
                ans += h;
                if (targeta <= n)
                {
                    //cout << "hello targeta = "<<targeta<<endl;
                    int tmph = h-l[targeta];
                    if (tmph > 0)
                    {
                        auto iter = upper_bound(v[targeta].begin(),v[targeta].end(),tmph);
                        --iter;
                        int pos = iter - v[targeta].begin();
                        ans += (tmph*1LL*(pos+1) - pre[targeta][pos]);
                    }
                }
                lasta = a;
                a>>=1;
                h -= l[lasta];
            }
        }
        printf("%lld\n",ans);
    }
}