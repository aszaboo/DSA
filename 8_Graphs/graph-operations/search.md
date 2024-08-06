# Search

## Idea 

1. Start from a starting node.
2. Follow edges, if the target node is found return true.
3. If all reachable nodes are checked without finding the target, return false.

## Search Using BFS

1. Push a starting node into a queue and add it to a list of seen nodes.
2. Start a while loop:
   - Pop the front node from the queue and push its adjacent nodes into the queue, ensuring they are not in the list of seen nodes.
   - Add the current node to the list of seen nodes.
   - Return true if the target node is found.
   - Return false if the queue is empty, signifying all nodes have been checked.

### BFS Using Adjacency Matrix

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool searchGraph(vector<vector<int>> &graph, int start, int target) {
    queue<int> q;
    vector<bool> seen(graph.size(), false);

    // Initialize the queue with the start node
    q.push(start);
    seen[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == target) return true;

        for (unsigned int i = 0; i < graph[node].size(); ++i) {
            if (graph[node][i] != 0 && !seen[i]) {
                q.push(i);
                seen[i] = true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    
    int start = 0;
    int target = 3;

    if (searchGraph(graph, start, target))
        cout << "Target found." << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}
```

### BFS Using Adjacency List (Linked Node)

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool searchLinkedGraph(int start, int target);
};

Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v); // For undirected graph
}

bool Graph::searchLinkedGraph(int start, int target) {
    queue<int> q;
    vector<bool> seen(V, false);

    q.push(start);
    seen[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == target) return true;

        for (int neighbor : adjList[node]) {
            if (!seen[neighbor]) {
                q.push(neighbor);
                seen[neighbor] = true;
            }
        }
    }

    return false;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    int start = 0;
    int target = 3;

    if (g.searchLinkedGraph(start, target))
        cout << "Target found." << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}
```

## Search Using DFS

1. From a starting node, push all adjacent nodes into a stack.
2. Remove the last inserted node from the stack and add it to a list of seen nodes.
3. Push all adjacent nodes of the current node into the stack, ensuring they are not in the list of seen nodes.
4. Continue this process until the node is found or the stack is empty, signifying that all nodes have been checked.

### DFS Using Adjacency Matrix

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool dfsSearchGraph(vector<vector<int>> &graph, int start, int target) {
    stack<int> s;
    vector<bool> seen(graph.size(), false);

    s.push(start);
    seen[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (node == target) return true;

        for (unsigned int i = 0; i < graph[node].size(); ++i) {
            if (graph[node][i] != 0 && !seen[i]) {
                s.push(i);
                seen[i] = true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    
    int start = 0;
    int target = 3;

    if (dfsSearchGraph(graph, start, target))
        cout << "Target found." << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}
```

### DFS Using Adjacency List (Linked Node)

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool dfsSearchLinkedGraph(int start, int target);
};

Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v); // For undirected graph
}

bool Graph::dfsSearchLinkedGraph(int start, int target) {
    stack<int> s;
    vector<bool> seen(V, false);

    s.push(start);
    seen[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (node == target) return true;

        for (int neighbor : adjList[node]) {
            if (!seen[neighbor]) {
                s.push(neighbor);
                seen[neighbor] = true;
            }
        }
    }

    return false;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    int start = 0;
    int target = 3;

    if (g.dfsSearchLinkedGraph(start, target))
        cout << "Target found." << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}
```