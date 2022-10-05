#include<bits/stdc++.h>
using namespace std;

int n, x[]={0,0,1}, y[]={3,0,0};

int main(){
  cin>>n;
  for (int i=0;i<n;++i)
    printf("%d %d\n",x[i%3]+i/3*2,y[i%3]);
}