# include <cstdio>
const int MS=43;
const int ML=20;

bool poss[MS];
int four[MS], seven[MS]; //fours, sevens
int res[ML];
bool solve(long long n, int respos)
{
	if (n<0)
		return false;
    if (n==0)
		{
        for (int i=respos; i<ML; ++i)
            res[i]=0;
			return true;
		}
    for (int i=n%10; i<MS; i+=10)
        if (poss[i] && solve((n-i)/10, respos+1))
 
        {
            res[respos]=i;
            
            return true;
        }
        
            
    return false;
    
}
int main()
{
  for (int a=0; a<=6; ++a)
    for (int b=0; a+b<=6; ++b)
    {
      poss[4*a+7*b]=true;
      four[4*a+7*b]=a;
      seven[4*a+7*b]=b;
    }
//     for (int i=0; i<MS; ++i)
// 			if (poss[i])
// 				printf("%d=4*%d+7*%d\n", i, four[i], seven[i]);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%I64d", &n);
        if (solve(n, 0))
        {
            for (int i=0; i<6; ++i)
						{
							bool in=false;
							for (int k=ML-1; k>=0; --k)
							{
								char dig;
								if (i<four[res[k]])
									dig='4';
								else if (i<four[res[k]]+seven[res[k]])
									dig='7';
								else
									dig='0';
								if (dig!='0')
									in=true;
								if (in)
									putchar(dig);
							}
							if (!in)
								putchar('0');
							if (i==5)
								printf("\n");
							else
								printf(" ");
						}
        }
        else
            printf("-1\n");
    }
}