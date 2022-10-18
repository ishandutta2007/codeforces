#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        for(int i = 0; i < n; i++)scanf("%d", &a[i]);

        int j = min_element(a.begin(), a.end()) - a.begin();
        
        printf("%d\n", n - 1);
        for(int i = j + 1; i < n; i++){
            printf("%d %d %d %d\n", j + 1, i + 1, a[j], a[j] + (i - j));
        }
        for(int i = j - 1; i >= 0; i--){
            printf("%d %d %d %d\n", j + 1, i + 1, a[j], a[j] + (j - i));
        }
    }
    return 0;
}