#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

bool check(long long x){
          for(int i = 2;(long long) i * i <= x;i++){
                    if(x % i == 0) return false;
          }
          return true;
}

int main(){
          int n;
          cin >> n;
          if(check(n)) return 0 * puts("1");
          if(n % 2 == 0 || check(n - 2)) puts("2");
          else puts("3");
          return 0;
}