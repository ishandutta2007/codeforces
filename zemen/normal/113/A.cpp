/*
 * main.cpp
 *
 *  Created on: 28.08.2011
 *      Author: zemen
 */

#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
    char s[100003];
    int mr = -1;
    bool norm;
    int type = 0;
    int cnt = 0;
    int oneword = -1;
    while (scanf("%s", s) != EOF) {
            norm = 0;
            int n = strlen(s);
            if (type == 0 && n > 3 && mr != 0)
                    if (s[n - 1] == 's' && s[n - 2] == 'o' && s[n - 3] == 'i' && s[n - 4] == 'l') {
                            mr = 1;
                            norm = 1;
                            if (cnt > 0 && oneword == 1) {
                            	printf("NO");
                            	return 0;
                            }
                            oneword = 0;
                    }
            if (type == 0 && n > 4 && mr != 1)
                    if (s[n - 1] == 'a' && s[n - 2] == 'l' && s[n - 3] == 'a' && s[n - 4] == 'i' && s[n - 5] == 'l') {
                            mr = 0;
                            norm = 1;
                            if (cnt > 0 && oneword == 1) {
                            	printf("NO");
                            	return 0;
                            }
                            oneword = 0;
                    }
            if (type == 0 && n > 2 && mr != 0)
                    if (s[n - 1] == 'r' && s[n - 2] == 't' && s[n - 3] == 'e') {
                            mr = 1;
                            norm = 1;
                            type = 1;
                            if (cnt > 0 && oneword == 1) {
                            	printf("NO");
                            	return 0;
                            }
                            oneword = 0;
                    }
            if (type == 0 && n > 3 && mr != 1)
                    if (s[n - 1] == 'a' && s[n - 2] == 'r' && s[n - 3] == 't' && s[n - 4] == 'e') {
                            mr = 0;
                            norm = 1;
                            type = 1;
                            if (cnt > 0 && oneword == 1) {
                            	printf("NO");
                            	return 0;
                            }
                            oneword = 0;
                    }
            if ((oneword == -1 || type == 1) && n > 5 && mr != 0)
                    if (s[n - 1] == 's' && s[n - 2] == 'i' && s[n - 3] == 't' && s[n - 4] == 'i' && s[n - 5] == 'n' && s[n - 6] == 'i') {
                            mr = 1;
                            norm = 1;
                            if (cnt > 0 && oneword == 1) {
                            	printf("NO");
                            	return 0;
                            }
                            oneword = 0;
                            if (cnt == 0)
                            	oneword = 1;
                    }
            if ((oneword == -1 || type == 1) && n > 5 && mr != 1)
                    if (s[n - 1] == 's' && s[n - 2] == 'e' && s[n - 3] == 't' && s[n - 4] == 'i' && s[n - 5] == 'n' && s[n - 6] == 'i') {
                            mr = 0;
                            norm = 1;
                            if (cnt > 0 && oneword == 1) {
                            	printf("NO");
                            	return 0;
                            }
                            oneword = 0;
                            if (cnt == 0)
                            	oneword = 1;
                    }
            if (!norm) {
                    printf("NO");
                    return 0;
            }
            ++cnt;
    }
    if (cnt > 1 && type == 0) {
    	printf("NO");
    	return 0;
    }
    printf("YES");
}