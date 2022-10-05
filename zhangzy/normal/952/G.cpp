#include<bits/stdc++.h>
std::string s; char c;

int main(){
  std::cin>>s;
  for (auto t:s){
    for (;c!=t;--c) puts("..\nX.");
    puts("X.");
  }
}