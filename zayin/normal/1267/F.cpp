#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
 
const int maxn=3e5+5;
 
int n,m,ka,kb,pa[maxn],pb[maxn],cnt[2*maxn],e0,inq[2];
pair<int,int> e[2*maxn];
priority_queue<int> Q;
 
int main()
{
	scanf("%d %d %d %d",&n,&m,&ka,&kb);
	fo(i,1,ka) scanf("%d",&pa[i]), cnt[pa[i]]++;
	fo(i,1,kb) scanf("%d",&pb[i]), cnt[pb[i]]++;
	int okb=kb;
	while (ka+kb<n+m-2)
	{
		kb++;
		pb[kb]=pb[kb-1];
		cnt[pb[kb]]++;
	}
	
	fo(i,1,n+m) if (!cnt[i]) Q.push(-i), inq[i>n]++;
	
	int hda=1, hdb=1;
	fo(i,1,n+m-2)
	{
		int tp=-Q.top(); Q.pop();
		inq[tp>n]--;
		if (tp<=n)
		{
			if (hdb>kb) {puts("No"); return 0;}
			e[++e0]=make_pair(tp,pb[hdb]);
			if (--cnt[pb[hdb]]==0) Q.push(-pb[hdb]), inq[pb[hdb]>n]++;
			++hdb;
		} else
		{
			if (hda>ka) {puts("No"); return 0;}
			e[++e0]=make_pair(tp,pa[hda]);
			if (--cnt[pa[hda]]==0)
			{
				if (hda==ka && inq[1]>0 && i<n+m-2)
				{
					if (kb==max(hdb-1,okb)) {puts("No"); return 0;}
					ka++;
					pa[ka]=pa[ka-1];
					cnt[pb[kb--]]--;
					cnt[pa[ka]]++;
					if (hdb>kb) Q.push(-pb[hdb]);
				} else
				{
					Q.push(-pa[hda]), inq[pa[hda]>n]++;
				}
			}
			++hda;
		}
	}

	int x=-Q.top(); Q.pop();
	int y=-Q.top(); Q.pop();
	if ((x>n)==(y>n)) {puts("No"); return 0;}
	e[++e0]=make_pair(x,y);
	
	puts("Yes");
	fo(i,1,e0) printf("%d %d\n",e[i].first,e[i].second);
}