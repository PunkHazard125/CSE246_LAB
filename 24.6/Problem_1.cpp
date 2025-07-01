#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vp;
typedef complex<double> point;

#define ln "\n"
#define RESULT cout << "Result: "
#define FIXED(x) cout << fixed << setprecision(x)

const int64_t LIMIT = 1e6;

void bfs(int start, const vector<vector<int>>& adj_list, vector<bool>& visited) {

    queue<int> q;
    q.push(start);
    visited[start] = true;
    auto node = q.front();

    while (!q.empty())
    {
        for (auto j : adj_list[start])
        {
            if (!visited[j])
            {
                q.push(j);
                visited[j] = true;
            }
        }

        cout << q.front() << " ";
        q.pop();
    }

}

int main(void) {
    
    vector<vector<int>> adj_list(4);
    vector<vector<int>> matrix(4, vector<int>(4, 0));

    adj_list[0].push_back(1);
    adj_list[0].push_back(2);
    adj_list[0].push_back(3);

    adj_list[1].push_back(0);
    adj_list[1].push_back(3);

    adj_list[3].push_back(0);
    adj_list[3].push_back(1);

    for (int i = 0; i < adj_list.size(); i++)
    {
        cout << "Vertex " << i << " -> ";
        for (auto current : adj_list[i])
        {
            cout << current << " ";
        }

        cout << ln;
    }

    vector<bool> visited(4, false);
    bfs(0, adj_list, visited);
    
    return 0;

}
