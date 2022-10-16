#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool good[2100][2100];int lp[2100][2100],rp[2100][2100];
vector<pair<int,int> > E;

void Solve(int l,int r)
{
    if(l==r)return;
    int x=rp[l+1][r],y=lp[l][r-1];
    
    if(y<x)
    {
        vector<pair<int,int> > I;
        I.push_back(make_pair(l,y));
        while(y<r)
        {
            I.push_back(make_pair(y+1,lp[y+1][r]));y=lp[y+1][r];
        }
        for(int i=0;i<I.size();i++)Solve(I[i].first,I[i].second);
        E.push_back(make_pair(I[0].first,I.back().second));
        if(I.size()>3)
        {
            E.push_back(make_pair(I[1].first,I.back().second));
            for(int i=2;i<I.size()-1;i++)E.push_back(make_pair(I[0].first,I[i].second));
        }
    }
    else
    {
        Solve(x,y);
        vector<pair<int,int> > I;
        int p=y;while(p<r){I.push_back(make_pair(p+1,lp[p+1][r]));p=lp[p+1][r];}
        for(int i=0;i<I.size();i++)Solve(I[i].first,I[i].second);
        int pos=y;while(!good[pos][r])pos--;
        E.push_back(make_pair(r,pos));//if(r==pos)puts("A");
        if(I.size()>=3)
        {
            E.push_back(make_pair(I[0].first,r));//if(I[0].first==r)puts("B");
            for(int i=1;i<I.size()-1;i++)
            {
                E.push_back(make_pair(I[i].second,pos));//if(I[i].second==pos)puts("C");
            }
        }

        I.clear();p=x;while(p>l){I.push_back(make_pair(rp[l][p-1],p-1));p=rp[l][p-1];}
        reverse(I.begin(),I.end());
        for(int i=0;i<I.size();i++)Solve(I[i].first,I[i].second);
        pos=x;while(!good[l][pos])pos++;
        E.push_back(make_pair(l,pos));//if(l==pos)puts("D");
        if(I.size()>=3)
        {
            E.push_back(make_pair(I.back().second,l));//if(I.back())
            for(int i=1;i<I.size()-1;i++)E.push_back(make_pair(I[i].first,pos));
        }
    }
}

int main()
{
    int TT=0;scanf("%d",&TT);
    while(TT--)
    {
        int n=0;scanf("%d",&n);
        E.clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                char ch='\0';scanf(" %c",&ch);
                good[i][j]=ch=='1';
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)lp[i][j]=good[i][j]?j:lp[i][j-1];
            for(int j=i;j>=1;j--)rp[j][i]=good[j][i]?j:rp[j+1][i];
        }
        Solve(1,n);
        for(int i=0;i<E.size();i++)printf("%d %d\n",E[i].first,E[i].second);
    }
}