#include<bits/stdc++.h>
#define ui unsigned int
using namespace std;

ui n, a, b, c, d, ans;
bitset<100000007>np;
ui id(ui x){
  return x%2&&x%3? x-x/2-x/3+x/6: 0;
}

int main(){
  cin>>n>>a>>b>>c>>d;
  for (ui i=2,sum,las;i<=n;++i){
    if (id(i)&&!np[id(i)]||i<=3){
      if (i>3){
        for (ui j=i+i,t;j<=n;j+=i)
          if (t=id(j)) np[t]=1;
      }
      for (sum=0,las=n;las;) sum+=las/=i;
      ans+= sum*(((a*i+b)*i+c)*i+d);
    }
  }
  cout<<ans<<endl;
}