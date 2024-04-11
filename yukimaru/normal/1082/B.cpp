/*********************************************************************
    > File Name: 1082_B.cpp
    > Author: yuki
 *********************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
#include<cmath>
using namespace std;

struct Seg
{
	int st, ed;
};

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		char s[100005]={0};
		scanf("%s", s);
		int len=n;
		Seg seg[100005];
		int cnt=0, ts=-1, td=-1;
		for(int i=0; i<len; i++)
		{
			if(s[i] == 'G')
			{
				if(ts == -1)
				{
					cnt++;
					ts=i;
					td=i;
				}
				else td++;
			}
			else if(s[i]=='S' && ts!=-1 && td!=-1)
			{
				seg[cnt].st=ts;
				seg[cnt].ed=td;
				ts=-1;
				td=-1;
			}
		}
		if(ts!=-1 && td!=-1)
		{
			seg[cnt].st=ts;
			seg[cnt].ed=td;
		}
//		for(int i=1; i<=cnt; i++)
//			printf("! %d %d\n", seg[i].st, seg[i].ed);
		int ans=0, tmp;
		for(int i=1; i<=cnt; i++)
		{
			tmp=0;
			tmp=max(tmp, seg[i].ed-seg[i].st+1);
			if(cnt != 1)
				tmp=max(tmp, seg[i].ed-seg[i].st+1+1);
			if(i!=cnt && seg[i].ed+2 == seg[i+1].st && cnt>=3)
				tmp=max(tmp, seg[i+1].ed-seg[i].st+1);
			if(i!=cnt && seg[i].ed+2 == seg[i+1].st && cnt==2)
				tmp=max(tmp, seg[i+1].ed-seg[i].st);
			ans=max(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}