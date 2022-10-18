#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vector < vector <int> > a(n, vector <int> (m));
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);

    bool first = true;
    while(k--){
        if(first)first = false;
        else printf(" ");

        int i = 0, j;
        scanf("%d", &j);
        j--;

        while(i < n){
            if(a[i][j] == 1){
                a[i][j] = 2;
                j++;
            }else if(a[i][j] == 2){
                i++;
            }else{
                a[i][j] = 2;
                j--;
            }
        }
        printf("%d", j + 1);
    }
    printf("\n");
    return 0;
}