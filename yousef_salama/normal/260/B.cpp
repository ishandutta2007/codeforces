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
#define sz(v) ((int)(v.size()))
using namespace std;
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string s;
int C[3][50][50];
bool have[3][50][50];
int main(){
    cin >> s;
    
    for(int st = 0; st + 10 <= sz(s); st++){
        string a = s.substr(st, 10);
        int cnt = count(a.begin(), a.end(), '-');
        if(cnt != 2)continue;
        if(a[2] != '-' || a[5] != '-')continue;
        
        int day = atoi(a.substr(0, 2).c_str());
        int month = atoi(a.substr(3, 2).c_str());
        int year = atoi(a.substr(6, 4).c_str());
        
        if(2013 <= year && year <= 2015){
            if(1 <= month && month <= 12){
                if(1 <= day && day <= days[month]){
                   C[year - 2013][month][day]++; 
                   have[year - 2013][month][day] = true; 
                
                }
            }
        }
    }
    int Max = -1, day, month, year;
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 50; j++)
    for(int k = 0; k < 50; k++){
        if(have[i][j][k]){
            if(Max == -1 || C[i][j][k] > Max){
                Max = C[i][j][k];
                
                year = i + 2013;
                month = j;
                day = k;
            }
        }
    }
    printf("%02d-%02d-%d\n", day, month, year);
    return 0;
}