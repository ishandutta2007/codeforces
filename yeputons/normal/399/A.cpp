# include <algorithm>
# include <iostream>
# include <cstring>
# include <cstdio>
# include <queue>
# define turbo ios_base::sync_with_stdio(0)
# define test cout << " wtf? "
# define newline << '\n'
# define sp << ' ' <<
# define fp << ' '

int d[2001] , use[2001] , was[2001];

main(){
    using namespace std;
    turbo; cin.tie(0);
    ///freopen("input.txt", "r", stdin);
    int n , p , k; cin >> n >> p >> k;
    if((p - k) > 1)cout <<"<< ";
    if((p - k) > 0) for(int i = p - k; i < p; i++) cout << i fp;
    else for(int i = 1; i < p; i++) cout << i fp;
    cout << '(' << p << ')' fp;
    if(p + k <= n) for(int i = p + 1; i <= p + k; i++) cout << i fp;
    else for(int i = p + 1; i <= n; i++) cout << i fp;
    if((p +k)< n) cout << ">>";
    return 0;
}