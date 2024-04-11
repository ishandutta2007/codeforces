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
const int MAXM = 200005;

int n, m, A[MAXN], B[MAXN], C[MAXN], D[MAXM], dp[MAXN];

int OA[MAXN], OB[MAXN], id[MAXN], ids;
vector < bitset <MAXM> > s;
bool mark[MAXN];

int main(){
    vector <int> vx;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        
        OA[i] = A[i];
        vx.push_back(A[i]);
        
        if(A[i] == -1)id[i] = ids++;
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &B[i]);
        
        OB[i] = B[i];
        vx.push_back(B[i]);
    }
    
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());

    for(int i = 0; i < n; i++)A[i] = lower_bound(vx.begin(), vx.end(), A[i]) - vx.begin();
    for(int i = 0; i < m; i++)B[i] = lower_bound(vx.begin(), vx.end(), B[i]) - vx.begin();
    
    for(int i = 1; i <= n + 1; i++)
        C[i] = 1 << 30;
    C[0] = 0;
    
    for(int i = 0; i < n; i++){
        if(A[i] != 0){
            int L = 0, R = n;
            while(L < R){
                int mid = (L + R + 1) / 2;
                if(C[mid] < A[i])L = mid;
                else R = mid - 1;
            }
            C[L + 1] = A[i];
            dp[i] = L + 1;
        }else{
            bitset <MAXM> d;
            
            D[0] = 1;
            for(int j = 1, q = 0; j < MAXM; j++){
                while(C[q] < j)q++;
                D[j] = q;
                d.set(j - 1, D[j] - D[j - 1]);
            }
            s.push_back(d);
            for(int j = 0; j < m; j++){
                C[D[B[j]]] = min(C[D[B[j]]], B[j]);
                dp[i] = max(dp[i], D[B[j]]);
            }
        }
    }
    
    int X = 0;
    for(int i = 0; i < n; i++)
        X = max(X, dp[i]);

    sort(OB, OB + m);
    sort(B, B + m);
    int k = m - 1;
/*
    for(int i = 0; i < n; i++)
         cout << dp[i] << ' ';
    cout << endl;
    cout << X << endl;
  */  

    int j = n - 1, prev = 1 << 30;
    while(X > 0){
         if(OA[j] != -1){
            if((dp[j] == X) && (OA[j] < prev)){
                X--;
                prev = OA[j];
            }
            
            j--;
            continue;
        }else{
            D[0] = 1;
            for(int i = 1; i < MAXM; i++)
                D[i] = D[i - 1] + s[id[j]][i - 1];
            while((k >= 0) && (OB[k] >= prev))k--;
            if(k < 0){
                j--;
                continue;
            }
            
            if(D[B[k]] == X){
                X--;
                OA[j] = OB[k];
                prev = OB[k];
                mark[k] = true;
                k--;
            }
            
            j--;
            continue;
        }
    }

    k = 0;
    for(int i = 0; i < n; i++){
        if(OA[i] == -1){
            while(mark[k])k++;
            
            OA[i] = OB[k];
            k++;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", OA[i]);
    }
    printf("\n");

    return 0;
}