#include<bits/stdc++.h>
#define maxn 305
using namespace std;

int n,m;

int cnt[maxn][maxn];

struct qry	{
	int x1,y1,x2,y2;
};

int C0,C1;

vector<qry> query(string s[maxn][maxn])	{
	
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			cnt[i][j]=0;
	
	vector<qry> ans;
	auto mov=[&](int x1,int y1,int x2,int y2)	{
		ans.push_back(qry{x1,y1,x2,y2});
//		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
//		s[x2][y2].push_front(s[x1][y1].back());
//		s[x1][y1].pop_back();
	};
	auto clear=[&](int x,int y)	{
		int sz=s[x][y].size();
		while (sz--)	
			if (s[x][y][sz]=='1')
				mov(x,y,x,2),++cnt[x][2];
			else
				mov(x,y,x,1),++cnt[x][1];
		s[x][y].clear();
	};
	
	for (int i=1;i<=n;++i)	
		for (int j=3;j<=m;++j)
			clear(i,j);
//	cout<<"mid1 s:"<<endl;
//	for (int i=1;i<=n;++i)	{
//		for (int j=1;j<=m;++j)	{
//				cout<<cnt[i][j];
//			cout<<" ";
//		}
//		cout<<endl;
//	}
	auto solve=[&](int lim)	{
		for (int i=lim;i<=n;++i)	{
			auto deal=[&](int j,char c)	{
				int x=(i==1?2:1);
				int sz=s[i][j].size();
				while (sz--)
					if (s[i][j][sz]==c)
						mov(i,j,x,j),++cnt[x][j];
					else
						mov(i,j,i,j^3),++cnt[i][j^3];
				s[i][j].clear();
				if (i!=1)
					while (cnt[i][j])
						mov(i,j,x,j),--cnt[i][j],++cnt[x][j];
			};
			deal(1,'0');
			deal(2,'1');
		}
	};
	solve(1);
//	cout<<"mid1.5 s:"<<endl;
//	for (int i=1;i<=n;++i)	{
//		for (int j=1;j<=m;++j)	{
//				cout<<cnt[i][j];
//			cout<<" ";
//		}
//		cout<<endl;
//	}
	solve(2);
	
//	cout<<"mid2 s:"<<endl;
//	for (int i=1;i<=n;++i)	{
//		for (int j=1;j<=m;++j)	{
////			for (char c:s[i][j])
//				cout<<cnt[i][j];
//			cout<<" ";
//		}
//		cout<<endl;
//	}
	for (int i=1;i<=n;++i)	
		for (int j=1;j<=m;++j)	{
//			if (s==::s) continue;
			if (i==1&&j==1) {
//				assert(cnt[1][1]==C0);
			}
			else
			if (i==1&&j==2)	{
				assert(cnt[1][2]==C1);
			}
			else
				assert(!cnt[i][j]);
		}
	for (int i=1;i<=n;++i)	
		for (int j=1;j<=m;++j)	{
			assert(!s[i][j].size());
		}
	return ans;
}

string s[maxn][maxn],t[maxn][maxn];

int main()	{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)	{
			cin>>s[i][j];
			for (char c:s[i][j])
				if (c=='0')
					++C0;
				else
					++C1;
		}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)	{
			cin>>t[i][j];
			reverse(t[i][j].begin(),t[i][j].end());
		}

	auto pre=query(s),suf=query(t);
	cout<<pre.size()+suf.size()<<endl;
	for (qry q:pre)
		cout<<q.x1<<" "<<q.y1<<" "<<q.x2<<" "<<q.y2<<'\n';	
	reverse(suf.begin(),suf.end());
	cout<<endl;
	for (qry q:suf)
		cout<<q.x2<<" "<<q.y2<<" "<<q.x1<<" "<<q.y1<<'\n';	
	return 0;
}