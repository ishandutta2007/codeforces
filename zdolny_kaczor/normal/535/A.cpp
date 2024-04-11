# include <cstdio>
char dig[10][10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char tens[10][10]={"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char teens[10][10]={"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
int main()
{
    int s;
    scanf("%d", &s);
    if (s<10)
        printf("%s\n", dig[s]);
    else if (s>=10 && s<20)
        printf("%s\n", teens[s-10]);
    else if (s%10==0)
        printf("%s\n", tens[s/10]);
    else
        printf("%s-%s\n", tens[s/10], dig[s%10]);
}