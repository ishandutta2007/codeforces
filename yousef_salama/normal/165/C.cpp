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
#include <string.h>
using namespace std;
int k, n, j, sum, d[1000005];
long long ans = 0;
string s;
int main(){
    cin >> k >> s;
    n = s.size();
    d[0] = s[0] == '0';
    for(int i = 1; i < n; i++)
        d[i] = (s[i] == '1'?0:d[i - 1] + 1);
    j = 0; sum = 0;
    for(int i = 0; i < n; i++){
        sum += s[i] - '0';
        while(j < i){
            if(sum - (s[j] - '0') < k)break;
            else{
                sum -= (s[j] - '0');
                j++;
            }
        }
        if(sum == k)ans += 1 + (j - 1 >= 0?d[j - 1]:0);
    }
    cout << ans << endl;
    return 0;
}