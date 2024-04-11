#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int Mod=998244353;
int pw[MAXN];
int cnt_row[MAXN][2][2],cnt_col[MAXN][2][2],cnt_all[2][2];
int main()
{
    for(int i=(pw[0]=1);i<MAXN;i++)
        pw[i]=2*pw[i-1]%Mod;
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    map<pair<int,int>,int> mp;
    int fre_row=n,fre_col=m;
    set<int> inv_row,inv_col;
    while(k--)
    {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        if(mp.find({x,y})!=mp.end())
        {
            int t=mp[{x,y}];
            // printf("del %d %d %d\n",x,y,t);
            cnt_row[x][t][y&1]--;
            cnt_col[y][t][x&1]--;
            cnt_all[t][(x+y)&1]--;
            int fr=1,fc=1,ir=0,ic=0;
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                {
                    fr&=(cnt_row[x][i][j]==0);
                    fc&=(cnt_col[y][i][j]==0);
                }
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                {
                    if(cnt_row[x][i][j]>0 && cnt_row[x][i^1][j]>0)ir=1;
                    if(cnt_row[x][i][j]>0 && cnt_row[x][i][j^1]>0)ir=1;
                }
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                {
                    if(cnt_col[y][i][j]>0 && cnt_col[y][i^1][j]>0)ic=1;
                    if(cnt_col[y][i][j]>0 && cnt_col[y][i][j^1]>0)ic=1;
                }
            fre_row+=fr;
            fre_col+=fc;
            if(!ir)inv_row.erase(x);
            if(!ic)inv_col.erase(y);
            mp.erase({x,y});
        }
        if(t>=0)
        {
            // printf("add %d %d %d\n",x,y,t);
            int fr=1,fc=1,ir=0,ic=0;
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                {
                    fr&=(cnt_row[x][i][j]==0);
                    fc&=(cnt_col[y][i][j]==0);
                }
            cnt_row[x][t][y&1]++;
            cnt_col[y][t][x&1]++;
            cnt_all[t][(x+y)&1]++;
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                {
                    if(cnt_row[x][i][j]>0 && cnt_row[x][i^1][j]>0)ir=1;
                    if(cnt_row[x][i][j]>0 && cnt_row[x][i][j^1]>0)ir=1;
                }
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                {
                    if(cnt_col[y][i][j]>0 && cnt_col[y][i^1][j]>0)ic=1;
                    if(cnt_col[y][i][j]>0 && cnt_col[y][i][j^1]>0)ic=1;
                }
            fre_row-=fr;
            fre_col-=fc;
            if(ir)inv_row.insert(x);
            if(ic)inv_col.insert(y);
            mp[{x,y}]=t;
        }
        int res_row=(inv_row.empty() ? pw[fre_row] : 0);
        int res_col=(inv_col.empty() ? pw[fre_col] : 0);
        int res_all=2;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(cnt_all[i][j]>0)res_all=1;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            {
                if(cnt_all[i][j]>0 && cnt_all[i^1][j]>0)res_all=0;
                if(cnt_all[i][j]>0 && cnt_all[i][j^1]>0)res_all=0;
            }
        // printf("-- %d %d %d\n",res_row,res_col,res_all);
        printf("%d\n",((res_row+res_col-res_all)%Mod+Mod)%Mod);
    }
    return 0;
}