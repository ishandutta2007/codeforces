#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
using namespace std;
using ll=long long;

struct status{
  int now;
  int to;
  int id;
};

struct aa{
  int id;
  int need;
};

struct query{
  int i;
  int j;
  int d;
};

int main(void){
  int N;cin>>N;
  //cout<<N<<endl;
  vector<int>tos(N);
  vector<status>stas(N);
  for(int i=0;i<N;++i){
    int a;
    scanf("%d",&a);
    //cout<<a<<endl;
    stas[i].now=a;
    stas[i].id=i+1;
  }
  //cout<<N<<endl;
  for(int i=0;i<N;++i){
    scanf("%d",&tos[i]);
  }
  sort(stas.begin(),stas.end(),[](const status&l,const status&r){
    return l.now<r.now;
  });
  sort(tos.begin(),tos.end());
  for(int i=0;i<N;++i){
    stas[i].to=tos[i];
  }
  vector<aa>aas;
  vector<query>qs;

  bool ok=true;
  for(int i=0;i<N;++i){
    int sa=stas[i].to-stas[i].now;
    //cout<<sa<<endl;
    if(sa>0){
      aas.push_back(aa{stas[i].id,sa});
    }else if(sa<0){
      sa=abs(sa);
      while(!aas.empty()&&sa>0){
        auto aaa=aas.back();
        int use=min(sa,aaa.need);
        sa-=use;
        qs.push_back(query{aaa.id,stas[i].id,use});
        aas.back().need-=use;
        if(aas.back().need==0){
          aas.pop_back();
        }
      }
      if(sa>0){
        ok=false;
        break;
      }
    }
  }
  if(!aas.empty()){
    ok=false;
  }
  if(ok){
    cout<<"YES"<<endl;
    cout<<qs.size()<<endl;
    for(int i=0;i<qs.size();++i){
      printf("%d %d %d\n",qs[i].i,qs[i].j,qs[i].d);
    }
  }else{
    cout<<"NO"<<endl;
  }
  
  return 0;
}