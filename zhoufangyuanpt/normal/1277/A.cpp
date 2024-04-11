//luogu
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        int ss=0;
		bool bk=false;
		int bi=0,bj=0;
        for(int i=0,j=1;i<=9;i++,j*=10)
        {
            if(n/j<10)
			{
				ss+=n/j-1;
				bk=true;bi=n/j;bj=j;
				break;
			}
            else ss+=9;
        }
		if(bk==true)
		{
			for(int j=bj;j>0;j/=10)
			{
				if((n/j)%10>bi){bk=true;break;}
				else if((n/j)%10<bi){bk=false;break;}
			}
			if(bk==true)ss++;
		}
		printf("%d\n",ss);
    }
	return 0;
}