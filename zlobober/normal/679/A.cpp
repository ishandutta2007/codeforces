#include <cstdio>
using namespace std;

int ask(int x) {
    printf("%d\n", x);
    fflush(stdout);
    char res[5];
    scanf("%s", res);
    return res[0] == 'y';
}

bool isprime(int x) {
    for (int i = 2; i < x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    int A[] = {2, 3, 5, 7};

    int cnt = 0;
    int num = -1;
    for (int i = 0; i < 4; i++) {
        bool res = ask(A[i]);
        cnt += res;
        if (res)
            num = i;
    }
    if (cnt == 0) {
        puts("prime");
    } else if (cnt >= 2) {
        puts("composite");
    } else {
        for (int i = 2; i * A[num] <= 100; i++) {
            if (isprime(i)) {
                if (ask(i * A[num])) {
                    puts("composite");
                    return 0;
                }
            }
        }
        puts("prime");
    }
}