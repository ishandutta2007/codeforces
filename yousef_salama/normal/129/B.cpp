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
#define oo 1 << 25
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    int g[N][N];
    memset(g, 0, sizeof g);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        g[a - 1][b - 1] = 1;
        g[b - 1][a - 1] = 1;
    }
    for(int itr = 0; itr < N; itr++){
        int ans = 0;
        vector <int> kick_out;
        for(int i = 0; i < N; i++){
            int cnt = 0;
            for(int j = 0; j < N; j++)
                if(g[i][j])cnt++;
            if(cnt == 1){
                kick_out.push_back(i);
                ans++;
            }
        }
        for(int i = 0; i < kick_out.size(); i++)
            for(int j = 0; j < N; j++){
                g[kick_out[i]][j] = 0;
                g[j][kick_out[i]] = 0;
            }
        if(ans == 0){
            cout << itr << endl;
            return 0;
        }
    }
    return 0;
}