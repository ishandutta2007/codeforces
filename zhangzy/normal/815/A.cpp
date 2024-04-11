#include<bits/stdc++.h>
using namespace std;

int n, m, a[111][111];
struct nd{
  int ty, id;
};
vector<nd>vec;

bool chk1(int ti){
  for (int j=1;j<=m;++j)
    if (a[ti][j]<=0) return 0;
  return 1;
}
bool chk2(int tj){
  for (int i=1;i<=n;++i)
    if (a[i][tj]<=0) return 0;
  return 1;
}

int main(){
  cin>>n>>m;
  for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j)
      cin>>a[i][j];
  for (;;){
    int ti=0, tj=0;
    for (int i=1;i<=n&&!ti;++i)
      for (int j=1;j<=m&&!ti;++j){
        if (a[i][j]) ti=i, tj=j;
      }
    if (!ti){
      cout<<vec.size()<<endl;
      for (auto o:vec){
        cout<<(o.ty==1? "row": "col")<<' '<<o.id<<endl;
      }
      return 0;
    }
    if (m>n){
      if (chk1(ti)){
        for (int j=1;j<=m;++j)
          a[ti][j]--;
        vec.push_back((nd){1,ti});
        continue;
      }
      if (chk2(tj)){
        for (int i=1;i<=n;++i)
          a[i][tj]--;
        vec.push_back((nd){2,tj});
        continue;
      }
    }else{
      if (chk2(tj)){
        for (int i=1;i<=n;++i)
          a[i][tj]--;
        vec.push_back((nd){2,tj});
        continue;
      }
      if (chk1(ti)){
        for (int j=1;j<=m;++j)
          a[ti][j]--;
        vec.push_back((nd){1,ti});
        continue;
      }
    }
    cout<<-1<<endl;
    return 0;
  }
}