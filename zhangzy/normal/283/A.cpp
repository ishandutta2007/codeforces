#include<bits/stdc++.h>
#define db double
using namespace std;

int T,n=1,sz=201000,c[202000];
db tot=0;

void add(int x,int v){
  for (;x<=sz;x+=x&-x) c[x]+=v;
}
int que(int x){
  int t=0;
  for (;x;x-=x&-x) t+=c[x];
  return t;
}


int main(){
  int t,x,y;
  for (cin>>T;T--;){
    scanf("%d",&t);
    if (t==1){
      scanf("%d%d",&x,&y); swap(x,y);
      add(1,x); add(y+1,-x);
      tot+=x*y;
    }else if (t==2){
      scanf("%d",&x);
      tot+=x;
      add(++n,x);add(n+1,-x);
    }else{
      tot-=x=que(n);
      add(n,-x); add(n+1,x);
      n--;
    }
    printf("%.10lf\n",tot/n);
  }
}