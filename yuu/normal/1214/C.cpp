#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string t;
int main(){
  cin>>n>>s;
  int sum=0;
  for(char c: s) if(c=='(') sum++; else sum--;
  if(sum){
    puts("No");
    return 0;
  }
  bool bad=0;
  for(char c: s) if(!bad){
    if(c=='(') sum++;
    else sum--;
    if(sum<0){
      bad=1;
    }
    else t+=c;
  }
  else t+=c;
  if(!bad){
    puts("Yes");
    return 0;
  }
  t+=')';
  sum=0;
  for(char c: t){
    if(c=='(') sum++;
    else sum--;
    if(sum<0){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
}