#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
const int maxn = 2e5 + 5;
char a[maxn];

int main(){
    cin >> n >> k;
    scanf("%s", a);
    int start = -1;
    int end = -1;
    for(int i = 0;i < n;i++){
        if(a[i] == a[(i + 1) % n]){
            start = (i + 1) % n;
            end = i % n;
        }
    }
    if(start == -1){
        if(k % 2 == 0){
            printf("%s", a);
        }else{
            for(int i = 0;i < n;i++){
                if(a[i] == 'W'){
                    a[i] = 'B';
                }else{
                    a[i] = 'W';
                }
            }
            printf("%s", a);
        }
        return 0;
    }
    int i = start, j = start;
    do{    
        //cout << i << " " << j << endl;
        int nxt = (j + 1) % n;
        while(a[j] != a[nxt]){
            j = nxt;
            nxt = (j + 1) % n;
        }
        if(i == j){
            i = (j + 1) % n, j = i;
            continue;
        }
        //cout << j << endl;
        for(int l = (i + 1) % n;l != j % n; l = (l + 1) % n){
            //cout << l << endl;
            int len1 = l - i;
            if(len1 <= 0)
                len1 += n;
            int len2 = j - l;
            if(len2 <= 0)
                len2 += n;
            int len = min(len1, len2);
            int change = min(len, k);
            if(change & 1){
                if(a[l] == 'B')
                    a[l] = 'W';
                else
                    a[l] = 'B';
            }
        }
        i = (j + 1) % n, j = i;
    }while(i != start);
    printf("%s", a);
    return 0;
}