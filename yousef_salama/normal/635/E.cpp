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
#include <complex>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

long long d, n, m;
pair <long long, long long> v[200005];
int main(){
    scanf("%I64d %I64d %I64d", &d, &n, &m);
    
    for(int i = 0; i < m; i++)
        scanf("%I64d %I64d", &v[i].first, &v[i].second);
    sort(v, v + m);
    
    priority_queue < pair <long long, long long> > inside_range, outside_range;
    for(int i = 0; i < m; i++)
        outside_range.push(make_pair(-v[i].first, v[i].second));
    
    long long position = 0, fuel = n, total = 0;
    while(true){
        if(position + fuel >= d){
            printf("%I64d\n", total);
            return 0;
        }
        
        while(!outside_range.empty()){
            pair <long long, long long> t = outside_range.top();
            
            if(-t.first <= position + fuel){
                inside_range.push(make_pair(-t.second, -t.first));
                outside_range.pop();
            }else break;
        }
        
        if(inside_range.empty())break;
        while(!inside_range.empty()){
            pair <long long, long long> t = inside_range.top();
            if(t.second < position){
                inside_range.pop();
                continue;
            }
            
            if(t.second > position){
                fuel -= t.second - position;
                position = t.second;
                continue;
            }
            
            if(t.second == position){
                if(fuel == n){
                    inside_range.pop();
                    continue;
                }else{
                    if(outside_range.empty()){
                        total += min(n - fuel, d - (position + fuel)) * (-t.first);
                        fuel += min(n - fuel, d - (position + fuel));
                        break;
                    }else{
                        pair <long long, long long> t2 = outside_range.top();
                        
                        long long c = min(n - fuel, (-t2.first) - (position + fuel));
                        total += c * (-t.first);
                        fuel += c;
                        break;
                    }
                }
            }
            
        }
    }
    printf("-1\n");
    
    return 0;
}