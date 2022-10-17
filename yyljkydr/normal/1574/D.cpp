#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

struct Data{
   vector<int>c;
   long long s;
};

bool operator <(const Data &a,const Data &b)
{
   return a.s<b.s;
}

map<vector<int>,bool>vis,nok;

priority_queue<Data>q;

int n,c[N],m;

vector<int>a[N];

int main()
{
   vector<int>st;
   long long sm=0;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&c[i]);
      st.push_back(c[i]);
      a[i].resize(c[i]+1);
      for(int j=1;j<=c[i];j++)
         scanf("%d",&a[i][j]);
      sm+=a[i].back();
   }
   q.push({st,sm});
   vis[st]=1;
   scanf("%d",&m);
   vector<int>ban;
   while(m--)
   {
      ban.clear();
      for(int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         ban.push_back(x);
      }
      nok[ban]=1;
   }
   long long ans=0;
   vector<int>va;
   while(!q.empty())
   {
      auto [v,s]=q.top();
      q.pop();
      if(!nok[v])
      {
         ans=s,va=v;
         break;
      }
      else
      {
         for(int i=0;i<v.size();i++)
         {
            int &x=v[i];
            if(x>1)
            {
               x--;
               if(!vis[v])
                  q.push({v,s-a[i+1][x+1]+a[i+1][x]}),vis[v]=1;
               x++;
            }
         }
      }
   }
   // printf("%lld\n",ans);
   for(auto x:va)
      printf("%d ",x);
   puts("");
}