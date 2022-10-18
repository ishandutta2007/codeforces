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
int n, m, k, x[5];
string s[5], a[25], cur[5];
int main(){
   cin >> n;
   for(int i = 0; i < n; i++)
       cin >> s[i];
   cin >> m;
   int ind = -1, Max = 0;
   for(int itr = 0; itr < m; itr++){
       cin >> k;
       for(int i = 0; i < k; i++)
           cin >> a[i];
       for(int i = 0; i < n; i++)
           x[i] = i;
       int ans = -1;
       do{
           int inv = 0;
           for(int i = 0; i < n; i++)
           for(int j = i + 1; j < n; j++)
               inv += x[i] > x[j];
           for(int i = 0; i < n; i++)
               cur[i] = s[x[i]];

           int j = 0;
           for(int i = 0; i < k; i++)
               if(a[i] == cur[j])j++;
	   if(j == n)ans = max(ans, (n * (n - 1)) / 2 - inv + 1);           
       }while(next_permutation(x, x + n));
       
       if(ans != -1 && (ind == -1 || ans > Max)){
           Max = ans;
           ind = itr + 1;
       }
   }
   if(ind == -1)cout << "Brand new problem!" << endl;
   else{
       cout << ind << endl;
       cout << "[:";
       for(int i = 0; i < Max; i++)
           cout << "|";
       cout << ":]" << endl;
   }
   return 0;
}