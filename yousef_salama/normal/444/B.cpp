#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, d, a[MAXN], b[MAXN], c[MAXN];
long long x;

int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main(){
    scanf("%d %d %I64d", &n, &d, &x);
    initAB();
    
    if(d <= 600){
        for(int i = 0; i < n; i++)if(b[i] == 1)
        for(int j = 0; j + i < n; j++)
            c[j + i] = max(c[j + i], a[j]);
    }else{
        set < pair <int, int> > S;
        for(int i = 0; i < n; i++)S.insert({a[i], i});
        
        for(int i = n - 1; i >= 0; i--){
            auto d = --S.end();
            while(true){
                if(b[i - d->second] == 1){
                    c[i] = d->first;
                    break;
                }
                
                if(d == S.begin())break;
                d--;
            }
            S.erase({a[i], i});
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d\n", c[i]);
        
    return 0;
}