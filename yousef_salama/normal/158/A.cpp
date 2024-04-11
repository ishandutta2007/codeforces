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
int n, k, a[55];
int main(){
   cin >> n >> k;
   for(int i = 0; i < n; i++)
       cin >> a[i];
   int i, j;
   for(i = k; i < n; i++)
       if(a[i] < a[i - 1])break;
   for(j = 0; j < n; j++)
      if(a[j] == 0)break;
   cout << min(i, j) << endl;
}