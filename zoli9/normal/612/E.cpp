#include <bits/stdc++.h>
using namespace std;
int n;
int t[1000009];
bool bejar[1000009];
vector<vector<int> > korok[1000009];
int megoldas[1000009];
int main() {
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>t[i];
  }
  vector<int> aktkor;
  for(int i=1; i<=n; i++)
  {
    if(!bejar[i])
    {
      aktkor.clear();
      bejar[i]=true;
      aktkor.push_back(i);
      int w=t[i];
      while(w!=i)
      {
        bejar[w]=true;
        aktkor.push_back(w);
        w=t[w];
      }
      korok[aktkor.size()].push_back(aktkor);
    }
  }
  for(int i=1; i<=n; i++)
  {
    if(i%2)
    {
      for(auto kor: korok[i])
      {
        for(int k=0; k<kor.size(); k++)
        {
          int kovindex=k+(i+1)/2;
          kovindex%=i;
          megoldas[kor[k]]=kor[kovindex];
        }
      }
    }
    else
    {
      if(korok[i].size()%2)
      {
        cout<<-1<<endl;
        return 0;
      }
      for(int j=0; j<korok[i].size(); j+=2)
      {
        auto& k1=korok[i][j];
        auto& k2=korok[i][j+1];
        for(int k=0; k<i; k++)
        {
          megoldas[k1[k]]=k2[k];
          megoldas[k2[k]]=k1[(k+1)%i];
        }
      }
    }
    
  }
  for(int i=1; i<=n; i++)
  {
    cout<<megoldas[i]<<" ";
  }
  cout<<endl;
  return 0;
}