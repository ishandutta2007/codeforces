#include <vector>
#include <iostream>
 
//using namespace std;
 
std::vector<int> read239;
 
int main(){
    std::cin.tie(0);
    std::cout.sync_with_stdio(0);
    int r;
    std::cin >> r;
    std::cout << (r>2 && r%2==0 ? "Yes" : "No");   
    std::cout << '\n';
}