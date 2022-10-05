#include<bits/stdc++.h>
using namespace std;
int up(int x,int y){
  return (x+y-1)/y;
}

int n, v, b, a[101000], tmp[101000];

bool chk(int now){
  int st=now+1, en=n-now, p=1, aim, de;
  memcpy(tmp,a,sizeof a);
  //printf("%d %d %d::\n",now,st,en);
  for (int i=st;i<=en;++i){
    aim=b;
    for (;aim;){
      for (;!tmp[p]&&p<=n;) ++p;
      //printf(" %d %d\n",i,p);
      if (p>n) return 0;
      if (up(abs(p-i),v)>min(i,n-i+1)){
        ++p; continue;
      }
      de=min(tmp[p],aim);
      tmp[p]-=de; aim-=de;
    }
  }
  return 1;
}

int main(){
  cin>>n>>v>>b;
  for (int i=1;i<=n;++i) scanf("%d",&a[i]);
  int l=0, r=n/2, mid, ans=r;
  for (;l<=r;){
    mid=l+r>>1;
    if (chk(mid)){
      ans=mid; r=mid-1;
    }else{
      l=mid+1;
    }
  }
  cout<<ans<<endl;
}