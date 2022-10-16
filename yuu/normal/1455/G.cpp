#include <bits/stdc++.h>
using namespace std;

int n, s;
class MinCostTable {
public:
    map<int, int64_t> cost;
    multiset<int64_t> min_values;
    int64_t offset;

    MinCostTable(int initial_value, int64_t initial_cost) {
        if (initial_value == s) initial_cost = 1e18;
        cost[initial_value] = initial_cost;
        min_values.insert(initial_cost);
        offset = 0;
    }

    int64_t GetMinCost() { return *min_values.begin() + offset; }

    void Pop(int value) {
        if (cost.count(value) == 0) return;
        min_values.erase(min_values.find(cost[value]));
        cost.erase(value);
    }

    void RaiseCost(int64_t d) { offset += d; }

    void Assign(int value, int64_t value_cost) {  // overwrite
        if (value == s) value_cost = 1e18;
        Pop(value);
        value_cost -= offset;
        min_values.insert(value_cost);
        cost[value] = value_cost;
    }

    void Merge(MinCostTable& other) {
        for (auto&& [a, b] : other.cost) {
            b += other.offset - offset;
            if (cost.count(a)) {
                min_values.erase(min_values.find(cost[a]));
                cost[a] = min(cost[a], b);
                min_values.insert(cost[a]);
            } else {
                cost[a] = b;
                min_values.insert(b);
            }
        }
    }
    static MinCostTable* Merge(MinCostTable* a, MinCostTable* b) {
        if (a->cost.size() >= b->cost.size()) {
            a->Merge(*b);
            delete b;
            return a;
        } else {
            b->Merge(*a);
            delete a;
            return b;
        }
    }
};
class Node {
public:
    Node* parent;
    Node* next;
    Node* first_child;
    Node* last_child;
    int condition, cost;
    MinCostTable* min_cost;

    Node(int condition, int cost, Node* parent)
            : condition(condition),
              cost(cost),
              parent(parent),
              next(nullptr),
              first_child(nullptr),
              last_child(nullptr),
              min_cost(nullptr) {}

    Node* AppendCommand(const string& cmd) {
        if (cmd == "end") return parent;
        if (cmd == "set") {
            int condition, cost;
            cin >> condition >> cost;
            if (last_child == nullptr) {
                first_child = last_child = new Node(condition, cost, this);
            } else {
                last_child->next = new Node(condition, cost, this);
                last_child = last_child->next;
            }
            return this;
        }
        int condition;
        cin >> condition;
        if (last_child == nullptr) {
            first_child = last_child = new Node(condition, 0, this);
        } else {
            last_child->next = new Node(condition, 0, this);
            last_child = last_child->next;
        }
        return last_child;
    }

    void GetMinCost(int64_t initial_cost) {
        min_cost = new MinCostTable(condition, initial_cost);
        while (first_child != nullptr) {
            if (first_child->cost) {  // assign
                if (first_child->condition != s) {
                    auto min_insert = min_cost->GetMinCost();
                    min_cost->RaiseCost(first_child->cost);
                    min_cost->Assign(first_child->condition, min_insert);
                } else {
                    min_cost->RaiseCost(first_child->cost);
                }
            } else {
                if (min_cost->cost.count(first_child->condition)) {
                    assert(first_child->condition != s);
                    first_child->GetMinCost(min_cost->cost[first_child->condition] + min_cost->offset);
                    min_cost->Pop(first_child->condition);
                    min_cost = MinCostTable::Merge(min_cost, first_child->min_cost);
                }
            }
            first_child = first_child->next;
        }
    }
};
void solve() {
    cin >> n >> s;
    Node* root = new Node(0, 0, nullptr);
    string cmd;
    for (int i = 1; i <= n; i++) {
        cin >> cmd;
        root = root->AppendCommand(cmd);
    }
    root->GetMinCost(0);
    cout << root->min_cost->GetMinCost() << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}