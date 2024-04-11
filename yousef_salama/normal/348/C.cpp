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

int n, m, q, sz, si;
long long a[100005];
int szB[325], szS[100005], pS[100005][2];
vector <int> B[325], S[100005];
bool Bb[325][100005];
int intersectionSB[100005][325], intersectionBB[325][325];
long long sumB[325], addB[325];

int ki, xi;
char qi;

int main(){
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", &si);
        a[i] = si;
    }
    
    int nB = 0, nS = 0;
    for(int i = 0; i < m; i++){
        scanf("%d", &sz);
        if(sz >= 320){
            pS[i][0] = 1;
            pS[i][1] = nB++;
            szB[nB - 1] = sz;
            
            for(int j = 0; j < sz; j++){
                scanf("%d", &si);
                si--;
                
                Bb[nB - 1][si] = true;
                sumB[nB - 1] += a[si];
                B[nB - 1].push_back(si);
            }
        }else{
            pS[i][0] = 0;
            pS[i][1] = nS++;
            szS[nS - 1] = sz;
            
            for(int j = 0; j < sz; j++){
                scanf("%d", &si);
                si--;
                
                S[nS - 1].push_back(si);
            }
        }
    }
    
    for(int i = 0; i < nS; i++)
    for(int j = 0; j < nB; j++){
        for(int k = 0; k < szS[i]; k++)
            if(Bb[j][S[i][k]])intersectionSB[i][j]++;
    }
    for(int i = 0; i < nB; i++)
    for(int j = 0; j < nB; j++){
        for(int k = 0; k < szB[i]; k++)
            if(Bb[j][B[i][k]])intersectionBB[i][j]++;
    }
 
    while(q--){
        scanf("%s", &qi);
        if(qi == '+'){
            scanf("%d %d", &ki, &xi);
            ki--;
            
            int j = pS[ki][1];
            if(pS[ki][0] == 0){
                for(int i = 0; i < szS[j]; i++)
                    a[S[j][i]] += xi;
                for(int i = 0; i < nB; i++)
                    sumB[i] += (long long)intersectionSB[j][i] * xi;
            }else{
                addB[j] += xi;
                for(int i = 0; i < nB; i++)
                    if(i != j)sumB[i] += (long long)intersectionBB[j][i] * xi;
            }

            
        }else{
            scanf("%d", &ki);
            ki--;
            
            int j = pS[ki][1];
            if(pS[ki][0] == 0){
                long long res = 0;
                for(int i = 0; i < szS[j]; i++)
                    res += a[S[j][i]];
                for(int i = 0; i < nB; i++)
                    res += addB[i] * intersectionSB[j][i];
                printf("%I64d\n", res);
            }else{
                printf("%I64d\n", sumB[j] + addB[j] * szB[j]);
            }
        }
    }
    return 0;
}