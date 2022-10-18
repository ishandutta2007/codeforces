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

int n, m, a[30], b[30], c[30];

int id;
map < pair <int, int>, pair <int, int> > MP;
vector < pair <int, int> > v;
vector < vector <int> > sols;
vector <int> sol;
void gen(int i, int ai, int bi, int ci){
    if(i == m){
        if(MP.count(make_pair(bi - ai, ci - bi))){
            if(MP[make_pair(bi - ai, ci - bi)].second > ai)return;
            else MP[make_pair(bi - ai, ci - bi)] = make_pair(id, ai);
        }else{        
            MP[make_pair(bi - ai, ci - bi)] = make_pair(id, ai);
            v.push_back(make_pair(bi - ai, ci - bi));
        }
        id++;
        sols.push_back(sol);
    }else{
        sol.push_back(0);
        gen(i + 1, ai, bi + b[i], ci + c[i]);
        sol.pop_back();
        
        sol.push_back(1);
        gen(i + 1, ai + a[i], bi, ci + c[i]);
        sol.pop_back();
        
        sol.push_back(2);
        gen(i + 1, ai + a[i], bi + b[i], ci);
        sol.pop_back();
    
    }
}
vector <int> res;
int cur_res;

void solve(int i, int ai, int bi, int ci){
    //cout << i << endl;
    if(i == n){
        //cout << (bi - ai) << ',' << (ci - bi) << endl;
        int x = lower_bound(v.begin(), v.end(), make_pair(ai - bi, bi - ci)) - v.begin();
        if(x == v.size())return;
        
        if((v[x].first == (ai - bi)) && (v[x].second == (bi - ci))){
            if(!res.empty()){
                if(cur_res > ai + MP[v[x]].second)return;
                else res.clear();
            }
            cur_res = ai + MP[v[x]].second;
            
            int cur_id = MP[v[x]].first;
            for(int j = 0; j < sols[cur_id].size(); j++)
                res.push_back(sols[cur_id][j]);
            for(int j = 0; j < sol.size(); j++)
                res.push_back(sol[j]);
            return;
        }
    }else{
        sol.push_back(0);
        solve(i + 1, ai, bi + b[i], ci + c[i]);
        sol.pop_back();
        
        sol.push_back(1);
        solve(i + 1, ai + a[i], bi, ci + c[i]);
        sol.pop_back();
        
        sol.push_back(2);
        solve(i + 1, ai + a[i], bi + b[i], ci);
        sol.pop_back();
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        
    m = n / 2;
    
    gen(0, 0, 0, 0);
    sort(v.begin(), v.end());
    
    /*
    for(int i = 0; i < v.size(); i++)
        cout << v[i].first << ' ' << v[i].second << endl;
    cout << endl;
    */
    solve(m, 0, 0, 0);
    
    if(res.empty())printf("Impossible\n");
    else{
        for(int i = 0; i < res.size(); i++){
            if(res[i] == 0)printf("MW\n");
            if(res[i] == 1)printf("LW\n");
            if(res[i] == 2)printf("LM\n");
        }
    }
    
    return 0;
}