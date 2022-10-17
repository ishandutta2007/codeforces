#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 100500;
            
int n, a[N];
ll s;
map<int, int> cnt;
set< pii > st;
void no(){
	printf("cslnb");
	exit(0);
}
void yes(){
	printf("sjfnb");
	exit(0);
}            
void add(int x){
	st.erase({-cnt[x], x});
	cnt[x]++;
	st.insert({-cnt[x], x});
}
void del(int x){
	st.erase({-cnt[x], x});
	cnt[x]--;
	st.insert({-cnt[x], x});
}
bool check(int x){
	if(x == 0)
		return 0;
	del(x);
	add(x - 1);
	bool ans = 0;
	if(-(st.begin() -> f) <= 1)
		ans = 1;
	add(x);
	del(x - 1);
	return ans;
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		cnt[a[i]]++;
	for(int i = 0; i < n; i++)	
		st.insert({-cnt[a[i]], a[i]});
	bool sd = 0;
	for(int i = 0; i < n; i++)
		sd |= check(a[i]);
	if(!sd)
		no();	
	for(int i = 0; i < n; i++)
		s += a[i] - i;
	if(s & 1)        
		yes();
	else
		no();
	return 0;
}