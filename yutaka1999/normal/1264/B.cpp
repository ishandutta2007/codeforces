#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[4];
int B[4];
int main()
{
	for(int i=0;i<=3;i++) scanf("%d",&A[i]);
	int sum=0;
	for(int i=0;i<4;i++) sum+=A[i];
	for(int f=0;f<=3;f++)
	{
		for(int s=0;s<=3;s++)
		{
			for(int i=0;i<4;i++) B[i]=A[i]*2;
			B[f]--,B[s]--;
			if(B[f]<0||B[s]<0) continue;
			if(B[1]-B[0]!=B[2]-B[3]||B[1]-B[0]<0) continue;
			B[1]-=B[0];
			B[2]=B[3];
			if(B[0]>0&&B[2]>0&&B[1]==0) continue;
			int now=f;
			vector <int> ans;
			while(1)
			{
				ans.push_back(now);
				if(now==0)
				{
					if(B[0]==0) break;
					now++;
					B[0]--;
				}
				else if(now==1)
				{
					if(B[0]==0&&B[1]==0) break;
					if(B[1]==0||(B[0]>0&&s!=0))
					{
						now--;
						B[0]--;
					}
					else
					{
						if(B[1]==0) break;
						now++;
						B[1]--;
					}
				}
				else if(now==2)
				{
					if(B[2]==0&&B[1]==0) break;
					if(B[1]==0||(B[2]>0&&s!=3))
					{
						now++;
						B[2]--;
					}
					else
					{
						if(B[1]==0) break;
						now--;
						B[1]--;
					}
				}
				else if(now==3)
				{
					if(B[2]==0) break;
					B[2]--;
					now--;
				}
			}
			if(ans.size()<sum) continue;
			puts("YES");
			for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);puts("");
			return 0;
		}
	}
	puts("NO");
	return 0;
}