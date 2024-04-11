// NOT written by YLWang
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define inf 0x7f7f7f7f
#define maxn 1000010
#define ri register int
#define il inline
using namespace std;
int a[maxn];
int b[maxn];
int v[maxn] = {0};
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		memset(v,0,sizeof(v));//
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			v[a[i]] = 1;//
		}
		int p=1,flag = 1;//
		for(int i=1;i<=n;i++)
		{
			b[p++] = a[i];//bi
			while(1)//bi
			{
				a[i]++;
				if(!v[a[i]]&&a[i]<=2*n)
				{//
					v[a[i]] = 1;//
					b[p++] = a[i];
					break;
				}
				else if(a[i] > 2*n)
				{//
					flag = 0;
					break;
				}
			}
		}
		if(!flag)
			cout << -1;
		else
			for(int i=1;i<p;i++)
				cout << b[i] << " ";
 		cout << endl;
	}
	return 0;
}