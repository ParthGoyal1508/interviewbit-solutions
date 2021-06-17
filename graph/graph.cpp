#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];

int visit_dfs[100000];
void dfs(int node) {
    if (visit_dfs[node] == 1) return;
    cout << node << " ";
    visit_dfs[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) dfs(adj[node][i]);
    return;
}

int visit_bfs[100000];
void bfs(int node) {
    queue<int> q;
    visit_bfs[node] = 1;
    q.push(node);
    while (!q.empty()) {
        int n = q.front();
        cout << n << " ";
        q.pop();
        for (int i = 0; i < adj[n].size(); i++) {
            if (!visit_bfs[adj[n][i]]) {
                visit_bfs[adj[n][i]] = 1;
                q.push(adj[n][i]);
            }
        }
    }
}

vector<pair<int, int>> starting_time;
vector<pair<int, int>> ending_time;
int visit[100000];
int timer = 0;
void toposort(int node) {
    if (visit[node]) return;
    starting_time.push_back({timer++, node});
    visit[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) toposort(adj[node][i]);
    ending_time.push_back({timer++, node});
}

int visit_first_scc[100000];
stack<int> finish;
void scc(int node) {
    if (visit_first_scc[node]) return;
    visit_first_scc[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) scc(adj[node][i]);
    finish.push(node);
    return;
}

vector<int> reverse_adj[100000];
void reverse(int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < adj[i].size(); j++)
            reverse_adj[adj[i][j]].push_back(i);
    }
    return;
}

int visit_second_scc[100000];
void dfs_scc(int node) {
    if (visit_second_scc[node]) return;
    visit_second_scc[node] = 1;
    cout << node << " ";
    for (int i = 0; i < reverse_adj[node].size(); i++)
        if (!visit_second_scc[reverse_adj[node][i]])
            dfs_scc(reverse_adj[node][i]);
    return;
}

void scc_reverse() {
    while (!finish.empty()) {
        int top_elem = finish.top();
        finish.pop();
        if (!visit_second_scc[top_elem]) {
            // cout << "element is "<< top_elem<<endl;
            dfs_scc(top_elem);
            cout << endl;
        }
    }
    return;
}

int main() {
    int v, e;
    cin >> v >> e;
    // construction of directed graph;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // dfs(2), cout << endl;
    // bfs(2), cout << endl;
    // toposort(1);
    // sort(ending_time.begin(), ending_time.end());
    // for(int i=ending_time.size()-1;i>=0;i--)
    //     cout << ending_time[i].second <<" ";
    //     cout << endl;

    for (int i = 0; i < v; i++)
        if (!visit_first_scc[i]) scc(i);
    reverse(v);
    scc_reverse();

    return 0;
}