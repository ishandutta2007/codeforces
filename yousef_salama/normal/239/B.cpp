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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;
int n, q, li, ri, x[10];
int di[] = {1, -1};
string a;
int main(){
    cin >> n >> q >> a;
    while(q--){
        cin >> li >> ri;
        li--, ri--;
        
        string s = a.substr(li, ri - li + 1);
        memset(x, 0, sizeof x);
        
        int CP = 0, DP = 0;
        while(CP >= 0 && CP < s.size()){
            if(s[CP] == '>'){
                DP = 0;
                CP += di[DP];
                if(CP < s.size() && (s[CP] == '>' || s[CP] == '<'))s.erase(--CP, 1);
            }else if(s[CP] == '<'){
                DP = 1;
                CP += di[DP];
                if(CP >= 0 && (s[CP] == '>' || s[CP] == '<'))s.erase(CP + 1, 1);
            }else{
                x[s[CP] - '0']++;
                
                if(s[CP] == '0'){
                    s.erase(CP, 1);
                    if(DP == 0)continue;
                }else s[CP]--;
                
                CP += di[DP];
            }
        }
        for(int i = 0; i < 10; i++){
            if(i > 0)cout << ' ';
            cout << x[i];
        }
        cout << endl;
    }
    return 0;
}