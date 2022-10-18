//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

int n, hi;
int main(){
   scanf("%d", &n);
   
   int s = 0, m = 0, phi = 0;
   for(int i = 0; i < n; i++){
      scanf("%d", &hi);

      s += phi - hi;
      m = max(m, -s);
      
      phi = hi;
   }
   printf("%d\n", m);

   return 0;
}