#include<bits/stdc++.h>
using namespace std;
const int N=1005; 
int t,n,m,a[N];
char s[N];
bool work(){
  static int b[N];
  memcpy(b+1,a+1,n<<2);
  bool flag=0;
  for(int i=1;i<=n;++i){
    if(a[i])continue;
    int cnt=(i>1&&a[i-1])+(i<n&&a[i+1]);
    if(cnt==1)flag=1,b[i]=1;
  }
  memcpy(a+1,b+1,n<<2);
  return flag;
}
void solve(){
  scanf("%d%d%s",&n,&m,s+1);
  for(int i=1;i<=n;++i)a[i]=s[i]-'0';
  for(int tt=1;tt<=m;++tt)if(!work())break;
  for(int i=1;i<=n;++i)printf("%d",a[i]);puts("");
}
int main(){
  for(scanf("%d",&t);t;--t)solve();
  return 0;
}