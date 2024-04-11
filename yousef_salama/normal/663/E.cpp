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
#include <unordered_map>

using namespace std;

void print(vector <long long> v){
    printf("%d:", v.size());
    for(int i = 0; i < v.size(); i++)
        printf(" %d", v[i]);
    printf("\n");
}

vector <long long> operator +(vector <long long> A, vector <long long> B){
    vector <long long> r(A.size());
    for(int i = 0; i < A.size(); i++)
        r[i] = A[i] + B[i];
    return r;
}
vector <long long> operator *(long long C, vector <long long> A){
    vector <long long> r(A.size());
    for(int i = 0; i < A.size(); i++)
        r[i] = C * A[i];
    return r;
}
vector <long long> operator *(vector <long long> A, vector <long long> B){
    vector <long long> r(A.size());
    for(int i = 0; i < A.size(); i++)
        r[i] = A[i] * B[i];
    return r;
}

vector <long long> fft(vector <long long> v){
    if(v.size() == 1)return v;
    
    int n = v.size();
    int m = n / 2;
    
    vector <long long> v0(m, 0);
    for(int i = 0; i < m; i++)v0[i] += v[i];
    for(int i = m; i < n; i++)v0[i - m] += v[i];
    v0 = fft(v0);
    
    vector <long long> v1(m, 0);
    for(int i = 0; i < m; i++)v1[i] += v[i];
    for(int i = m; i < n; i++)v1[i - m] -= v[i];
    v1 = fft(v1);
    
    vector <long long> r;
    r.insert(r.end(), v0.begin(), v0.end());
    r.insert(r.end(), v1.begin(), v1.end());
    return r;
}
vector <long long> ifft(vector <long long> v){
    if(v.size() == 1)return v;
    
    int n = v.size();
    int m = n / 2;
    
    vector <long long> v0_(v.begin(), v.begin() + m);
    vector <long long> v1_(v.begin() + m, v.begin() + n);
    
    v0_ = ifft(v0_);
    v1_ = ifft(v1_);
    
    vector <long long> v0 = v0_ + v1_;
    vector <long long> v1 = v0_ + (-1) * v1_;
    
    vector <long long> r;
    r.insert(r.end(), v0.begin(), v0.end());
    r.insert(r.end(), v1.begin(), v1.end());
    
    for(int i = 0; i < r.size(); i++)r[i] /= 2;
    
    return r;
}

int n, m;
char G[20][100001];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", G[i]);
        
    /*for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        G[i][j] = '0';*/
        
    vector <long long> A(1 << n, 0);
    vector <long long> B(1 << n, 0);
    
    for(int j = 0; j < m; j++){
        int x = 0;
        for(int i = 0; i < n; i++)
            x += (G[i][j] == '1') << i;
        
        A[x]++;
    }
    
    for(int i = 0; i < B.size(); i++){
        B[i] = __builtin_popcount(i);
        B[i] = min(B[i], n - B[i]);
    }
    
    vector <long long> r = ifft(fft(A) * fft(B));
    printf("%d\n", (int) *min_element(r.begin(), r.end()));
    
    return 0;
}