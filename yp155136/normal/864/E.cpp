#include <bits/stdc++.h>
using namespace std;

const int N = 106;
const int M = 2006;

struct _
{
    int t,d,p,id;
    _(){}
    _(int _t,int _d,int _p,int _id):t(_t),d(_d),p(_p),id(_id){}
} __[N];

bool operator<(const _ &_1,const _ &_2)
{
    return _1.d < _2.d;
}

int dp[N][M];
vector<int> dp_track[N][M];

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        int t,p,d;
        scanf("%d %d %d",&t,&d,&p);
        __[i] = _(t,d,p,i);
    }
    sort(__+1,__+n+1);
    int m = 2000;
    int mx_val = -1;
    vector<int> mx_val_track;
    for (int i=1;n>=i;i++)
    {
        for (int j=1;m>=j;j++)
        {
            if (j > __[i].d || j <= __[i].t)
            {
                dp[i][j] = dp[i-1][j];
                dp_track[i][j] = dp_track[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - __[i].t ] + __[i].p);
                if (dp[i][j] == dp[i-1][j])
                {
                    dp_track[i][j] = dp_track[i-1][j];
                }
                else
                {
                    dp_track[i][j] = dp_track[i-1][ j-__[i].t ];
                    dp_track[i][j].push_back(__[i].id);
                }
            }
            if (dp[i][j] > mx_val)
            {
                mx_val = dp[i][j];
                mx_val_track = dp_track[i][j];
            }
        }
    }
    printf("%d\n",mx_val);
    printf("%d\n",(int)mx_val_track.size());
    for (int i=0;mx_val_track.size()>i;i++)
    {
        if (i) printf(" ");
        printf("%d",mx_val_track[i]);
    }
    puts("");
}