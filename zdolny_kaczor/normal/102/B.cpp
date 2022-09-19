# include <cstdio>
# include <cstring>
char num[100002];
int cou(int x)
{
    int res=0;
    while (x>0)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}
int main()
{
    scanf("%s", num);
    int len=strlen(num);
    if (len==1)
        printf("0\n");
    else
    {
        int sum=0;
        for (int i=0; i<len; ++i)
            sum+=num[i]-'0';
        int res=1;
        while (sum>=10)
        {
            sum=cou(sum);
            res++;
        }
        printf("%d\n", res);
    }
}