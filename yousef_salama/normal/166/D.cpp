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
#define MOD 1000000007
using namespace std;
int n, m, p[100005][2][2], ind_shoe[100005], ind_cust[100005];
long long dp[100005][2][2];
pair < pair <int, int> , int> org_shoe[100005], org_cust[100005]; 
pair <int, int> shoe[100005], cust[100005];
vector < pair <int, int> > v;
bool found(int li){
    int f = lower_bound(shoe, shoe + n, make_pair(li, 0)) - shoe;
    
    if(f == n || shoe[f].first != li)return false;
    return true;
}
int cost(int li){
    int f = lower_bound(shoe, shoe + n, make_pair(li, 0)) - shoe;
    return shoe[f].second;
}
int ind(int li){
    return lower_bound(shoe, shoe + n, make_pair(li, 0)) - shoe;
}
long long solve(int cust_ind, int have_small, int have_large){
    long long &ret = dp[cust_ind][have_small][have_large];

    if(ret == -1){
        ret = 0;
        
        int &cur = p[cust_ind][have_small][have_large];
        cur = 0;
        
        long long temp;
        if(cust_ind == m - 1){
            //eshtery small
            if(have_small){ 
                long long cur_cost = cost(cust[cust_ind].first);
                if(cur_cost <= cust[cust_ind].second){
                    temp = cur_cost;
                    if(temp >= ret)ret = temp, cur = 1;
                }
            }
            //eshtery large
            if(have_large){
                
                long long cur_cost = cost(cust[cust_ind].first + 1);
                if(cur_cost <= cust[cust_ind].second){
                    temp = cur_cost;
                    if(temp >= ret)ret = temp, cur = 2;
                }
            }
        }else{
            //matshetresh 7aga
            if(cust[cust_ind].first == cust[cust_ind + 1].first){
                temp = solve(cust_ind + 1, have_small, have_large);
            }else if(cust[cust_ind].first + 1 == cust[cust_ind + 1].first){
                temp = solve(cust_ind + 1, have_large, found(cust[cust_ind + 1].first + 1));
            }else{
                temp = solve(cust_ind + 1, found(cust[cust_ind + 1].first), 
                        found(cust[cust_ind + 1].first + 1));
            }
            if(temp >= ret)ret = temp, cur = 0;
            //eshtery small
            if(have_small){
                long long cur_cost = cost(cust[cust_ind].first);
                
                if(cust[cust_ind].second >= cur_cost){
                    if(cust[cust_ind].first == cust[cust_ind + 1].first){
                        temp = solve(cust_ind + 1, false, have_large) + cur_cost;
                    }else if(cust[cust_ind].first + 1 == cust[cust_ind + 1].first){
                        temp = solve(cust_ind + 1, have_large, found(cust[cust_ind + 1].first + 1)) + cur_cost;
                    }else{
                        temp = solve(cust_ind + 1, found(cust[cust_ind + 1].first), 
                                found(cust[cust_ind + 1].first + 1)) + cur_cost;
                    }
                    if(temp >= ret)ret = temp, cur = 1;
                }
            }
            //eshtery large
            if(have_large){
                
                long long cur_cost = cost(cust[cust_ind].first + 1);
                
                if(cust[cust_ind].second >= cur_cost){
                    if(cust[cust_ind].first == cust[cust_ind + 1].first){
                        temp = solve(cust_ind + 1, have_small, false) + cur_cost;
                    }else if(cust[cust_ind].first + 1 == cust[cust_ind + 1].first){
                        temp = solve(cust_ind + 1, false, found(cust[cust_ind + 1].first + 1)) + cur_cost;
                    }else{
                        temp = solve(cust_ind + 1, found(cust[cust_ind + 1].first), 
                                found(cust[cust_ind + 1].first + 1)) + cur_cost;
                    }
                    if(temp >= ret)ret = temp, cur = 2;
                }
            }
        }
    }
    return ret;
}
void find_path(int cust_ind, int have_small, int have_large){
    int &cur = p[cust_ind][have_small][have_large];
    if(cust_ind == m - 1){
        if(cur == 0){
            return;
        }else if(cur == 1){
            v.push_back(make_pair(cust_ind, ind(cust[cust_ind].first)));
        }else{
            v.push_back(make_pair(cust_ind, ind(cust[cust_ind].first + 1)));
        }
    }else{
        if(cur == 0){
            if(cust[cust_ind].first == cust[cust_ind + 1].first){
                find_path(cust_ind + 1, have_small, have_large);
            }else if(cust[cust_ind].first + 1 == cust[cust_ind + 1].first){
                find_path(cust_ind + 1, have_large, found(cust[cust_ind + 1].first + 1));
            }else{
                find_path(cust_ind + 1, found(cust[cust_ind + 1].first), 
                        found(cust[cust_ind + 1].first + 1));
            }
        }else if(cur == 1){
            v.push_back(make_pair(cust_ind, ind(cust[cust_ind].first)));
            
            if(cust[cust_ind].first == cust[cust_ind + 1].first){
                find_path(cust_ind + 1, false, have_large);
            }else if(cust[cust_ind].first + 1 == cust[cust_ind + 1].first){
                find_path(cust_ind + 1, have_large, found(cust[cust_ind + 1].first + 1));
            }else{
                find_path(cust_ind + 1, found(cust[cust_ind + 1].first), 
                        found(cust[cust_ind + 1].first + 1));
            }
        }else{
            v.push_back(make_pair(cust_ind, ind(cust[cust_ind].first + 1)));
            
            if(cust[cust_ind].first == cust[cust_ind + 1].first){
                find_path(cust_ind + 1, have_small, false);
            }else if(cust[cust_ind].first + 1 == cust[cust_ind + 1].first){
                find_path(cust_ind + 1, false, found(cust[cust_ind + 1].first + 1));
            }else{
                find_path(cust_ind + 1, found(cust[cust_ind + 1].first), 
                        found(cust[cust_ind + 1].first + 1));
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &org_shoe[i].first.second, &org_shoe[i].first.first);
        org_shoe[i].second = i;
    }
    sort(org_shoe, org_shoe + n);
    for(int i = 0; i < n; i++){
        ind_shoe[i] = org_shoe[i].second;
        shoe[i] = org_shoe[i].first;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &org_cust[i].first.second, &org_cust[i].first.first);
        org_cust[i].second = i;
    }
    sort(org_cust, org_cust + m);
    for(int i = 0; i < m; i++){
        ind_cust[i] = org_cust[i].second;
        cust[i] = org_cust[i].first;
    }
    memset(dp, -1, sizeof dp);
    printf("%I64d\n", solve(0, found(cust[0].first), found(cust[0].first + 1)));
    
    find_path(0, found(cust[0].first), found(cust[0].first + 1));
    
    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i++)
        printf("%d %d\n", ind_cust[v[i].first] + 1, ind_shoe[v[i].second] + 1);
    return 0;
}