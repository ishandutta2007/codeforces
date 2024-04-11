#include <cstdio>
#include <cstring>
using namespace std;

const int N = 200500;

char buf[N];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", buf);
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (buf[i] == '>')
            break;
        a++;
    }
    int b = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (buf[i] == '<')
            break;
        b++;
    }
    printf("%d\n", a + b);
}