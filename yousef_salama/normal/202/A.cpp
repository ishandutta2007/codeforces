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
string s;
int main(){
   cin >> s;
   char c = *max_element(s.begin(), s.end());

   for(int i = 0; i < s.size(); i++)
       if(s[i] == c)cout << c;
   cout << endl;
   return 0;
}