#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;


char s1[1000005], s2[1000005];
int tag1, tag2, i, l1, l2;
string str[50] = {"Washington", "Adams", "Jefferson", "Madison", "Monroe", "Adams", "Jackson", "Van Buren", "Harrison", "Tyler", "Polk", "Taylor", "Fillmore", "Pierce", "Buchanan", "Lincoln", "Johnson", "Grant", "Hayes", "Garfield", "Arthur", "Cleveland", "Harrison", "Cleveland", "McKinley", "Roosevelt", "Taft", "Wilson", "Harding", "Coolidge", "Hoover", "Roosevelt", "Truman", "Eisenhower", "Kennedy", "Johnson", "Nixon", "Ford", "Carter", "Reagan"};
int main()
{
scanf("%d", &tag1);
cout << str[tag1 - 1] << endl;
return 0;
}