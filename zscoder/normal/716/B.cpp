#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int N = 50000;
int cnt[27];
string s; int n;
int counter;

bool valid()
{
    //cout << counter << endl;
	return (counter == 26);
}

void fillall()
{
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '?') s[i] = 'A';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	n = s.length();
	if(n < 26) {cout << -1; return 0;}
	counter = 0;
	for(int i = 0; i < 26; i++)
	{
		if(s[i] == '?')
		{
			counter++; continue;
		}
		cnt[s[i]-'A']++;
		if(cnt[s[i]-'A'] == 1) counter++;
	}
	if(valid())
	{
		int cur = 0;
		while(cnt[cur]>0) cur++;
		for(int i = 0; i < 26; i++)
		{
			if(s[i] == '?')
			{
				s[i] = cur + 'A';
				cur++;
				while(cnt[cur]>0) cur++;
			}
		}
		fillall();
		cout << s;
		return 0;
	}
	for(int i = 26; i < n; i++)
	{
		if(s[i] != '?') {cnt[s[i]-'A']++; if(cnt[s[i]-'A']==1) counter++;}
		if(s[i-26] != '?') {cnt[s[i-26]-'A']--; if(cnt[s[i-26]-'A']==0) counter--;}
		if(s[i-26] == '?') counter--;
		if(s[i] == '?') counter++;
		if(valid())
		{
			int cur = 0;
			while(cnt[cur]>0) cur++;
			for(int j = i - 25; j <= i; j++)
			{
				if(s[j] == '?')
				{
					s[j] = cur + 'A';
					cur++;
					while(cnt[cur]>0) cur++;
				}
			}
			fillall();
			cout << s;
			return 0;
		}
	}
	cout << -1;
	return 0;
}