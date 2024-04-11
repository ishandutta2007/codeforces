#include<bits/stdc++.h>
using namespace std;
const int N=105;
int t,n;
bool judge(int x){int y=sqrt(x);return x==y*y;}
int main(){
  for(scanf("%d",&t);t;--t){
    scanf("%d",&n);
    if(n%2==0&&(judge(n/2)||judge(n)))puts("YES");
    else puts("NO");
  }
  return 0;
}