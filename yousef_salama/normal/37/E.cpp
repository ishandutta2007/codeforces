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

int N, M;
char s[55][55];

int num[55][55], color[2505];
vector <int> g[2505];

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

void flood_fill(int i, int j, int cur_num){
    num[i][j] = cur_num;
    
    for(int d = 0; d < 4; d++){
        int ni = i + di[d], nj = j + dj[d];
        if(ni < 0 || ni >= N || nj < 0 || nj >= M)continue;
        
        if((num[ni][nj] == -1) && (s[i][j] == s[ni][nj])){
            flood_fill(ni, nj, cur_num);
            continue;
        }
        if((num[ni][nj] != -1) && (num[ni][nj] != cur_num)){
            g[cur_num].push_back(num[ni][nj]);
            g[num[ni][nj]].push_back(cur_num);
        }
    }
}

int dist[2505];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", s[i]);

    memset(num, -1, sizeof num);
    
    int cur_num = 0;
    bool exist = false;

    for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++){
        if(num[i][j] == -1){
            color[cur_num] = s[i][j] == 'B' ? 1 : 0;
            if(color[cur_num] == 1)exist = true;

            flood_fill(i, j, cur_num);
            cur_num++;
        }
    }
    
    if(!exist){
        printf("0\n");
        return 0;
    }
    
    int D = 1 << 30;
    for(int i = 0; i < cur_num; i++){
        queue <int> q;
        memset(dist, -1, sizeof dist);

        dist[i] = 0;
        q.push(i);

        int cur_D = 0;

        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(int j = 0; j < g[v].size(); j++){
                int u = g[v][j];
                if(dist[u] == -1){
                    dist[u] = dist[v] + 1;
                    q.push(u);

                    if(color[u] == 1)cur_D = max(cur_D, dist[u]);
                }
            }
        }
        D = min(D, cur_D);
    }
    printf("%d\n", D + 1);
    
}