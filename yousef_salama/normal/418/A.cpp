#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, k, cnt[MAXN];

vector < pair <int, int> > v;
void build(int n){
    if(n == 1)return;
    else if(n % 2 == 0){
    	build(n - 1);

    	for(int i = 1; i <= n - 1; i++)
    		v.push_back({n, i});
    }else{
        build(n - 2);

        for(int i = 1; i <= n - 2; i++){
            if(i % 2 == 1){
                v.push_back({n, i});
                v.push_back({i, n - 1});
            }else{
                v.push_back({i, n});
                v.push_back({n - 1, i});
            }
        }
        v.push_back({n - 1, n});
    }
}
int main(){
    scanf("%d %d", &n, &k);

    if(n % 2 == 0){
    	if((n - 1) / 2 < k)printf("-1\n");
    	else{
    		build(n);

    		vector < pair <int, int> > w;
			for(pair <int, int> e : v){
				if(cnt[e.first] >= k)continue;

				cnt[e.first]++;
				w.push_back(e);
			}

			printf("%d\n", w.size());
			for(pair <int, int> e : w)
				printf("%d %d\n", e.first, e.second);
    	}
    }else{
        if((n - 1) / 2 < k)printf("-1\n");
        else{
            build(n);

            vector < pair <int, int> > w;
            for(pair <int, int> e : v){
            	if(cnt[e.first] >= k)continue;

            	cnt[e.first]++;
            	w.push_back(e);
            }

            printf("%d\n", w.size());
            for(pair <int, int> e : w)
                printf("%d %d\n", e.first, e.second);
        }
    }
    return 0;
}