#include <bits/stdc++.h>
using namespace std;

vector<int> v[3];

#define SZ(x) ((int)(x).size())

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
    }
    sort(v[1].begin(),v[1].end()); reverse(v[1].begin(),v[1].end());
    sort(v[2].begin(),v[2].end()); reverse(v[2].begin(),v[2].end());
    int ans = 123456789;
    for (int i=0;SZ(v[1])>=i;i++)
    {
        //take i's v[1]
        for (int j=0;SZ(v[2])>=j;j++)
        {
            int tot_thick = i*1 + j*2;
            int tot_wid = 0;
            for (int k=i;SZ(v[1])>k;k++)
            {
                tot_wid += v[1][k];
            }
            for (int k=j;SZ(v[2])>k;k++)
            {
                tot_wid += v[2][k];
            }
            if (tot_wid <= tot_thick)
            {
                ans = min(ans,tot_thick);
            }
        }
    }
    printf("%d\n",ans);
}