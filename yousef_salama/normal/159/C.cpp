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
int k, n, len, p, occ[26], cnt[2005][26];
bool rem[200005];
char c;
string s;
int main(){
    cin >> k >> s >> n;
    len = s.size();
    for(int i = 0; i < len; i++)
        occ[s[i] - 'a']++;
    for(int i = 0; i < k; i++)
    for(int j = 0; j < 26; j++)
        cnt[i][j] = occ[j];
    while(n--){
        cin >> p >> c;
        p--;
        for(int i = 0; i < k; i++){
            if(p - cnt[i][c - 'a'] >= 0){
                p -= cnt[i][c - 'a'];
            }else{
                cnt[i][c - 'a']--;
                for(int j = 0; j < len; j++)
                    if(s[j] == c && !rem[i * len + j]){
                        if(p == 0){
                            rem[i * len + j] = 1;
                            break;
                        }else p--;
                    }
                break;
            }
        }
    }
    for(int i = 0; i < k * len; i++)
        if(!rem[i])cout << s[i % len];
    cout << endl;
    return 0;
}