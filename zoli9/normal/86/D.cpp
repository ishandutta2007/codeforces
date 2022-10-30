#include <bits/stdc++.h>
using namespace std;
int n, t;
int szamok[200009];
int darab[1000009];
int kor[1000009];
int korszam;
long long answer[200009];
vector<pair<pair<int, int>, int> > query[10000];
bool rendez(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
  if(a.first.second<b.first.second) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>t;
  int sqrtn=sqrt(n);
  for(int i=1; i<=n; i++)
  {
    cin>>szamok[i];
  }
  for(int i=1; i<=t; i++)
  {
    int kezd, veg;
    cin>>kezd>>veg;
    int hanyados=kezd/sqrtn;
    query[hanyados].push_back({{kezd, veg}, i});
  }
  for(int i=0; i<=sqrtn+2; i++)
  {
    sort(query[i].begin(), query[i].end(), rendez);
  }
  //int kezd=1;
  //int veg=0;
  //long long eredmeny=0;
  for(int i=0; i<=sqrtn+2; i++)
  {  
    //memset(darab, 0, 1000005*sizeof(int));
    //unordered_map<int, int> darab;
    
    int kezd=i*sqrtn;
    int veg=kezd-1;
    long long eredmeny=0;
    korszam++;
    for(int j=0; j<query[i].size(); j++)
    {
      while(veg<query[i][j].first.second)
      {
        veg++;
        if(kor[szamok[veg]]<korszam)
        {
          darab[szamok[veg]]=0;
          kor[szamok[veg]]=korszam;
        }
        eredmeny-=((long long)darab[szamok[veg]]*darab[szamok[veg]]*szamok[veg]);
        darab[szamok[veg]]++;
        eredmeny+=((long long)darab[szamok[veg]]*darab[szamok[veg]]*szamok[veg]);
      }
      /*while(veg>query[i][j].first.second)
      {
        eredmeny-=((long long)darab[szamok[veg]]*darab[szamok[veg]]*szamok[veg]);
        darab[szamok[veg]]--;
        eredmeny+=((long long)darab[szamok[veg]]*darab[szamok[veg]]*szamok[veg]);
        veg--;
      }*/
      
      if(kezd<query[i][j].first.first)
      {
        while(kezd<query[i][j].first.first)
        {
          if(kor[szamok[kezd]]<korszam)
          {
            darab[szamok[kezd]]=0;
            kor[szamok[kezd]]=korszam;
          }
          eredmeny-=((long long)darab[szamok[kezd]]*darab[szamok[kezd]]*szamok[kezd]);
          darab[szamok[kezd]]--;
          eredmeny+=((long long)darab[szamok[kezd]]*darab[szamok[kezd]]*szamok[kezd]);
          kezd++;
        }
      }
      else
      {
        while(kezd>query[i][j].first.first)
        {
          kezd--;
          if(kor[szamok[kezd]]<korszam)
          {
            darab[szamok[kezd]]=0;
            kor[szamok[kezd]]=korszam;
          }
          eredmeny-=((long long)darab[szamok[kezd]]*darab[szamok[kezd]]*szamok[kezd]);
          darab[szamok[kezd]]++;
          eredmeny+=((long long)darab[szamok[kezd]]*darab[szamok[kezd]]*szamok[kezd]);
        }
      }
      answer[query[i][j].second]=eredmeny;
    }
  }
  for(int i=1; i<=t; i++)
  {
    cout<<answer[i]<<'\n';
  }
  return 0;
}