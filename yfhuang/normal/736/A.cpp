#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long f[100];

int n;

int main(){
      f[0] = 0,f[1] = 1,f[2] = 2;
      for(int i = 3;i < 100 ;i++){
                f[i] = f[i - 1] + f[i - 2] + 1;
                if(f[i] > 1e18) break;  
      }
      long long n;
      cin >> n;
      n--;
      for(int i = 1;i < 100;i++){
                if(f[i] > n){
                    cout << i - 1 << endl;
                    break;
                }
      }
      return 0;
}