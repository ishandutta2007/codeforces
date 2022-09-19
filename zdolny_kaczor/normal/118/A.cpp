# include <bits/stdc++.h>
using namespace std;
bool in (char c, char * a) {
    while (*a) {
        if (c == *a)
            return true;
        a++;
    }
    return false;
}
int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (isalnum(c) && !in(c, "aoeuiyAOEUIY")) {
            printf(".%c", tolower(c));
        }
    }
}