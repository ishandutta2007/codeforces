#include<stdio.h>
#include<cstring>
using namespace std;
char s[1005];
int i,j,k,l;
int main()
{
    char c=getchar();
    scanf("%s",s);
    l=strlen(s);
    for (int i=0;i<l;i++)
    {
        if (c=='L')
        {
            if (s[i]=='q')
            putchar('w');
            else
            if (s[i]=='w')
            putchar('e');
            else
            if (s[i]=='e')
            putchar('r');
            else
            if (s[i]=='r')
            putchar('t');
            else
            if (s[i]=='t')
            putchar('y');
            else
            if (s[i]=='y')
            putchar('u');
            else
            if (s[i]=='u')
            putchar('i');
            else
            if (s[i]=='i')
            putchar('o');
            else
            if (s[i]=='o')
            putchar('p');
            else
            if (s[i]=='a')
            putchar('s');
            else
            if (s[i]=='s')
            putchar('d');
            else
            if (s[i]=='d')
            putchar('f');
            else
            if (s[i]=='f')
            putchar('g');
            else
            if (s[i]=='g')
            putchar('h');
            else
            if (s[i]=='h')
            putchar('j');
            else
            if (s[i]=='j')
            putchar('k');
            else
            if (s[i]=='k')
            putchar('l');
            else
            if (s[i]=='l')
            putchar(';');
            else
            if (s[i]=='z')
            putchar('x');
            else
            if (s[i]=='x')
            putchar('c');
            else
            if (s[i]=='c')
            putchar('v');
            else
            if (s[i]=='v')
            putchar('b');
            else
            if (s[i]=='b')
            putchar('n');
            else
            if (s[i]=='n')
            putchar('m');
            else
            if (s[i]=='m')
            putchar(',');
            else
            if (s[i]==',')
            putchar('.');
            else
            if (s[i]=='.')
            putchar('/');
        }
        else
        {
            if (s[i]=='w')
            putchar('q');
            else
            if (s[i]=='e')
            putchar('w');
            else
            if (s[i]=='r')
            putchar('e');
            else
            if (s[i]=='t')
            putchar('r');
            else
            if (s[i]=='y')
            putchar('t');
            else
            if (s[i]=='u')
            putchar('y');
            else
            if (s[i]=='i')
            putchar('u');
            else
            if (s[i]=='o')
            putchar('i');
            else
            if (s[i]=='p')
            putchar('o');
            else
            if (s[i]=='s')
            putchar('a');
            else
            if (s[i]=='d')
            putchar('s');
            else
            if (s[i]=='f')
            putchar('d');
            else
            if (s[i]=='g')
            putchar('f');
            else
            if (s[i]=='h')
            putchar('g');
            else
            if (s[i]=='j')
            putchar('h');
            else
            if (s[i]=='k')
            putchar('j');
            else
            if (s[i]=='l')
            putchar('k');
            else
            if (s[i]==';')
            putchar('l');
            else
            if (s[i]=='x')
            putchar('z');
            else
            if (s[i]=='c')
            putchar('x');
            else
            if (s[i]=='v')
            putchar('c');
            else
            if (s[i]=='b')
            putchar('v');
            else
            if (s[i]=='n')
            putchar('b');
            else
            if (s[i]=='m')
            putchar('n');
            else
            if (s[i]==',')
            putchar('m');
            else
            if (s[i]=='.')
            putchar(',');
            else
            if (s[i]=='/')
            putchar('.');
        }
    }
}