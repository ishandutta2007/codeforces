#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int s[2], temp, C[2][1005];
long long ans;
int calc(int k){
   int x = -1;
   long long ret = 0;
   for(int i = 0; i <= s[k]; i++){
       long long cur = 0;
       for(int j = 0; j < s[k]; j++)
           cur += (long long)4 * (1 +  2 * j - 2 * i) * (1 + 2 * j - 2 * i) * C[k][j];
       if(x == -1 || cur < ret){
           x = i;
           ret = cur;
       }
   }
   ans += ret;
   return x;
}
int main(){
   cin >> s[0] >> s[1];
   for(int i = 0; i < s[0]; i++)
   for(int j = 0; j < s[1]; j++){
       cin >> temp;
       C[0][i] += temp;
       C[1][j] += temp;
   }
   ans = 0;
   int x = calc(0), y = calc(1);
   cout << ans << endl;
   cout << x << ' ' << y << endl;
   return 0;
}