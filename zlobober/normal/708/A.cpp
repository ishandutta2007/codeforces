#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100500;

char buf[N];

int main() {
    gets(buf);
    int n = strlen(buf);
    int beg = 0;
    while (beg != n && buf[beg] == 'a')
        beg++;
    if (beg == n) {
        buf[n - 1] = 'z';
    } else {
        int end = beg;
        while (end != n && buf[end] != 'a')
            end++;
        for (int i = beg; i < end; i++)
            buf[i] = ('a' + ((buf[i] - 'a' + 25) % 26));
    }
    puts(buf);
}