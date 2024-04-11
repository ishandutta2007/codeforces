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

int n, k;
string s;

vector <int> ac[10]; 

int main(){
    cin >> n >> k >> s;
    
    vector < pair <int, string> > sols;
    for(int d = 0; d <= 9; d++){
        string cs = s;
        for(int i = 0; i < 10; i++)ac[i].clear();

        for(int i = 0; i < n; i++)
            ac[abs((int)(s[i] - '0') - d)].push_back(i);

        int cost = 0;
        int rk = k;
        for(int i = 0; i < 10; i++){
            if(ac[i].size() <= rk){
                for(int j = 0; j < ac[i].size(); j++)
                    cs[ac[i][j]] = (char)(d + '0');

                cost += i * ac[i].size();
                rk -= ac[i].size();
                
                if(rk == 0)break;
            }else{
                if(i == 0)break;
                
                cost += i * rk;
                
                for(int j = 0, sz = ac[i].size(); j < ac[i].size(); j++, sz--){
                    if(rk == 0)break;
                    
                    if(sz == rk){
                        for(int z = j; z < ac[i].size(); z++)
                            cs[ac[i][z]] = (char)(d + '0');

                        break;
                    }
                    
                    if((int)(cs[ac[i][j]] - '0') > d){
                        cs[ac[i][j]] = (char)(d + '0');
                        rk--;
                    }
                }

                break;
            }
        }
        
        sols.push_back(make_pair(cost, cs));
    }
    
    sort(sols.begin(), sols.end());
    cout << sols[0].first << endl << sols[0].second << endl;
    
    return 0;
}