#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

char s[MAXN];
int N, a[MAXN];

int main(){
    scanf("%s", s);
    N = strlen(s);
    
    int b = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == '(')a[i] = 1;
        else if(s[i] == ')')a[i] = -1;
        else a[i] = -1;
    
        b += a[i];
    }
    
    for(int i = N - 1; i >= 0; i--)if(s[i] == '#'){
        if(b > 0)a[i] -= b;
        break;
    }
    
    vector <int> v;
    
    b = 0;
    for(int i = 0; i < N; i++){
        b += a[i];
        if(b < 0){
            printf("-1\n");
            return 0;
        }
        
        if(s[i] == '#')v.push_back(-a[i]);
    }
    
    if(b != 0){
        printf("-1\n");
        return 0;
    }
    
    for(int i = 0; i < v.size(); i++)
        printf("%d\n", v[i]);
    return 0;
}