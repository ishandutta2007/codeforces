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

const int K = 317;

int N, M, power[100005], x[100005], y[100005];
int type, a, b;
int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &power[i]);
    
    for(int st = 0; st < N; st += K){
        int en = min(N - 1, st + K - 1);
        
        for(int i = en; i >= st; i--){
            if(i + power[i] > en){
                x[i] = i + power[i];
                y[i] = 1;
            }else{
                x[i] = x[i + power[i]];
                y[i] = y[i + power[i]] + 1;
            }
        }
    }
    
    while(M--){
        scanf("%d", &type);
        if(type == 0){
            scanf("%d %d", &a, &b);
            a--, b;
            
            power[a] = b;
            
            int st = a / K * K;
            int en = min(N - 1, st + K - 1);
            
            for(int i = en; i >= st; i--){
                if(i + power[i] > en){
                    x[i] = i + power[i];
                    y[i] = 1;
                }else{
                    x[i] = x[i + power[i]];
                    y[i] = y[i + power[i]] + 1;
                }
            }
        }else{
            scanf("%d", &a);
            a--;

            int c = 0;
            while(x[a] < N){
                c += y[a];
                a = x[a];
            }
            
            while(a + power[a] < N){
                a += power[a];
                c++;
            }
            
            printf("%d %d\n", a + 1, c + 1);
        }
    }
    return 0;
}