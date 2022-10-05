#include<bits/stdc++.h>
using namespace std;

int n, cnt[111], x;

int main(){
  for (cin>>n;n--;){
    cin>>x;
    ++cnt[x];
  }
  cout<<*max_element(cnt+1,cnt+100+1);
}