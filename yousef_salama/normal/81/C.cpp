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

const int MAXN = 100005;

int n, a, b, ti, ans[MAXN];
pair <int, int> marks[MAXN];
int main(){
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++){
        scanf("%d", &ti);
        marks[i] = make_pair(ti, i);
    }
    
    sort(marks, marks + n);
    
    if(a == b){
        for(int i = 0; i < a; i++)
            printf("1 ");
        for(int i = 0; i < b - 1; i++)
            printf("2 ");
        printf("2\n");
        
        return 0;
    }else if(b < a){
        int i = 0;
        while(i < n){
            int j = i;
            while(j < n && marks[j].first == marks[i].first)j++;
            
            if(a >= j - i){
                a -= j - i;
                while(i < j){
                    ans[marks[i].second] = 1;
                    i++;
                }
            }else{
                vector <int> v;
                while(i < j){
                    v.push_back(marks[i].second);
                    i++;
                }
                
                sort(v.begin(), v.end());
                for(int k = 0; k < a; k++)
                    ans[v[k]] = 1;
                for(int k = a; k < v.size(); k++)
                    ans[v[k]] = 2;
            
                break;
            }
        }
        while(i < n){
            ans[marks[i].second] = 2;
            i++;
        }
    }else{
        int i = 0;
        while(i < n){
            int j = i;
            while(j < n && marks[j].first == marks[i].first)j++;
            
            if(b >= j - i){
                b -= j - i;
                while(i < j){
                    ans[marks[i].second] = 2;
                    i++;
                }
            }else{
                vector <int> v;
                while(i < j){
                    v.push_back(marks[i].second);
                    i++;
                }
                
                sort(v.rbegin(), v.rend());
                for(int k = 0; k < b; k++)
                    ans[v[k]] = 2;
                for(int k = b; k < v.size(); k++)
                    ans[v[k]] = 1;
                    
                break;
            }
        }
        while(i < n){
            ans[marks[i].second] = 1;
            i++;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    
    return 0;
}