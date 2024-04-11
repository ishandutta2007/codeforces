#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    vector <int> a(n);

    array <int, 3> O, A;
    for(int i = 0; i < 3; i++){
        printf("or %d %d\n", i + 1, (i + 1) % 3 + 1);
        fflush(stdout);
        scanf("%d", &O[i]);
    }
    for(int i = 0; i < 3; i++){
        printf("and %d %d\n", i + 1, (i + 1) % 3 + 1);
        fflush(stdout);
        scanf("%d", &A[i]);
    }

    auto bit = [&](int mask, int ind){
        if(mask & (1 << ind))return 1;
        else return 0;
    };

    for(int i = 0; i < 30; i++){
        if(bit(O[0], i) == bit(A[0], i)){
            a[0] |= bit(O[0], i) << i;
            a[1] |= bit(O[0], i) << i;

            if(bit(O[1], i) == bit(A[1], i)){
                a[2] |= bit(O[0], i) << i;
            }else{
                a[2] |= (1 - bit(O[0], i)) << i;
            }
        }else{
            if(bit(O[1], i) == bit(A[1], i)){
                a[0] |= (1 - bit(O[1], i)) << i;
                a[1] |= bit(O[1], i) << i;
                a[2] |= bit(O[1], i) << i;
            }else{
                a[0] |= bit(O[2], i) << i;
                a[1] |= (1 - bit(O[2], i)) << i;
                a[2] |= bit(O[2], i) << i;
            }
        }
    }

    for(int i = 3; i < n; i++){
        int x, y;
        printf("or 1 %d\n", i + 1);
        fflush(stdout);
        scanf("%d", &x);

        printf("and 1 %d\n", i + 1);
        fflush(stdout);
        scanf("%d", &y);

        a[i] = a[0] ^ (x - y);
    }

    /*
    for(int c : a)
        cout << c << ' ';
    cout << endl;
    */

    sort(a.begin(), a.end());
    printf("finish %d\n", a[k - 1]);
    fflush(stdout);

    return 0;
}