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

void operator += (pair <int, int> &a, pair <int, int> b){
    a.first += b.first;
    a.second += b.second;
}
void operator -= (pair <int, int> &a, pair <int, int> b){
    a.first -= b.first;
    a.second -= b.second;
}

int n, f[100005], s[100005];
vector <int> gt[100005], g[100005];
vector < pair <int, int> > ans;
bool visited[100005], d[100005];

pair <int, int> optimal_ans;

vector <int> comp;
void find_comp(int i){
    visited[i] = true;
    comp.push_back(i);
    
    for(int j = 0; j < g[i].size(); j++)if(!visited[g[i][j]])
        find_comp(g[i][j]);
}

vector <int> cycle;
bool iscycle[100005];
void find_cycle(int i){
    for(int j = 0; j < comp.size(); j++)
        d[comp[j]] = false, iscycle[comp[j]] = false;
    
    stack <int> s;
    while(!d[i]){
        s.push(i);
        
        d[i] = true;
        i = f[i];
    }
    int j = i;
    
    while(s.top() != j){
        cycle.push_back(s.top());
        s.pop();
    }
    cycle.push_back(j);
    
    reverse(cycle.begin(), cycle.end());
    
    for(int j = 0; j < cycle.size(); j++)
        iscycle[cycle[j]] = true;
}

pair <int, int> dp_tree[100005][2];
int par_tree[100005][2];
pair <int, int> solve_tree(int i, int matched){
    if(dp_tree[i][matched].first != -1)return dp_tree[i][matched];
    
    par_tree[i][matched] = -1;

    pair <int, int> res, total;
    for(int j = 0; j < gt[i].size(); j++){
        int u = gt[i][j];
        if(iscycle[u])continue;
        
        res += solve_tree(u, 0);
    }
    total = res;
    if(matched == 0){
        for(int j = 0; j < gt[i].size(); j++){
            int u = gt[i][j];
            if(iscycle[u])continue;
            
            pair <int, int> cur = total;
            cur -= solve_tree(u, 0);
            cur += solve_tree(u, 1);
            
            cur.first++;
            if(s[i] != s[u])cur.second++;
            
            if(cur > res){
                par_tree[i][matched] = j;
                res = cur;
            }
        }
    }
    return dp_tree[i][matched] = res;
}
void find_pairs(int i, int matched){
    for(int j = 0; j < gt[i].size(); j++){
        int u = gt[i][j];
        if(iscycle[u])continue;
        
        if(par_tree[i][matched] == j){
            ans.push_back(make_pair(i, u));
            find_pairs(u, 1);
        }else{
            find_pairs(u, 0);
        }
    }
}

pair <int, int> dp_cycle[100005][2];
int end;
bool ismatched[100005][2];
pair <int, int> solve_cycle(int i, int matched){
    if(dp_cycle[i][matched].first != -1)return dp_cycle[i][matched];
    
    pair <int, int> res;
    res = solve_tree(i, matched);
    if(i != end)res += solve_cycle(f[i], 0);
    
    ismatched[i][matched] = false;
    if(matched == 0 && i != end){
        pair <int, int> cur;
        cur = solve_tree(i, 1);
        cur += solve_cycle(f[i], 1);
        
        cur.first++;
        if(s[i] != s[f[i]])cur.second++;
        
        if(cur > res){
            ismatched[i][matched] = true;
            res = cur;
        }
    }
    return dp_cycle[i][matched] = res;
}
void clear_dp(){
    for(int i = 0; i < comp.size(); i++)
    for(int j = 0; j < 2; j++)
        dp_cycle[comp[i]][j].first = -1;
}
void solve_comp(int source){
    comp.clear();
    cycle.clear();
    
    find_comp(source);
    find_cycle(comp[0]);
    
    //cycle[cycle.size() - 1] -> cycle[0]
    clear_dp();
    end = cycle[cycle.size() - 2];
    pair <int, int> a1;
    if(cycle.size() > 2)
        a1 = solve_cycle(cycle[1], 0);
    a1 += solve_tree(cycle[0], 1);
    a1 += solve_tree(cycle[cycle.size() - 1], 1);
    
    a1.first++;
    if(s[cycle[0]] != s[cycle[cycle.size() - 1]])a1.second++;

    
    //clear[cycle.size() - 1] -X> cycle[0]
    clear_dp();
    end = cycle[cycle.size() - 1];
    pair <int, int> a2 = solve_cycle(cycle[0], 0);


    int matched;
    if(a1 > a2){
        optimal_ans += a1;
        find_pairs(cycle[0], 1);
        find_pairs(cycle[cycle.size() - 1], 1);
        
        ans.push_back(make_pair(cycle[0], cycle[cycle.size() - 1]));
        
        clear_dp();
        end = cycle[cycle.size() - 2];
        if(cycle.size() > 2)
            solve_cycle(cycle[1], 0);

        int cur_i = cycle[1], matched = 0;
        while(cur_i != cycle[cycle.size() - 1]){
            if(ismatched[cur_i][matched] == 0){
                find_pairs(cur_i, matched);
                matched = 0;
            }else{
                find_pairs(cur_i, 1);
                matched = 1;
                
                ans.push_back(make_pair(cur_i, f[cur_i]));
            }
            cur_i = f[cur_i];
        }
    }else{
        optimal_ans += a2;
        
        clear_dp();
        end = cycle[cycle.size() - 1];
        solve_cycle(cycle[0], 0);
        
        int cur_i = cycle[0], matched = 0;
        do{
            if(ismatched[cur_i][matched] == 0){
                find_pairs(cur_i, matched);
                matched = 0;
            }else{
                find_pairs(cur_i, 1);
                matched = 1;
                
                ans.push_back(make_pair(cur_i, f[cur_i]));
            }
            cur_i = f[cur_i];
        }while(cur_i != cycle[0]);
    }
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &f[i], &s[i]);
        f[i]--;
        
        gt[f[i]].push_back(i);
        
        g[f[i]].push_back(i);
        g[i].push_back(f[i]);
    }
    for(int i = 0; i < n; i++)
    for(int matched = 0; matched < 2; matched++)
        dp_tree[i][matched].first = -1;
    
    for(int i = 0; i < n; i++)if(!visited[i])
        solve_comp(i);
    
    printf("%d %d\n", optimal_ans.first, optimal_ans.second);
    for(int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    return 0;
}