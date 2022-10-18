#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

char s[MAXN], t[MAXN];
int N;

void msort(char *w, int L){
    if(L % 2 != 0)return;
    
    msort(w, L / 2);
    msort(w + (L / 2), L / 2);
    
    if(strncmp(w, w + (L / 2), L / 2) > 0){
        for(int i = 0; i < (L / 2); i++)
            swap(w[i], w[i + (L / 2)]);
    }
}

int main(){
    scanf("%s %s", s, t);
    N = strlen(s);
    
    msort(s, N);
    msort(t, N);
    
    //printf("%s\n", s);
    //printf("%s\n", t);
    
    if(strncmp(s, t, N) == 0)printf("YES\n");
    else printf("NO\n");
    
    return 0;
}