#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<vector<int>> lst;

    Graph(int v, int e)
    {
        lst.resize(v);

        for(int i=0; i<e; i++)
        {
            cout<< "Enter 2 verticrs of the edge: ";
            int a, b;
            cin>>a>>b;
            edge(a, b);
        }


    }

    void edge(int a, int b)
    {
        if(find(lst[b].begin(), lst[b].end(), a) == lst[b].end())
        {
            lst[a].push_back(b);
            lst[b].push_back(a);
            cout<<"edge "<<a<<" "<<b<<" added.\n";
        }
    }

    void dfs(Graph const &graph, stack<int> &s, vector<bool> &discovered1)
    {
        if (s.empty())
        {
            return;
        }
        int vi = s.top();
        s.pop();
        cout<< vi << " ";
        for(int u : graph.lst[vi])
        {
            if (!discovered1[u])
            {
                discovered1[u] = true;
                s.push(u);
            }
        }
        dfs(graph,s,discovered1);
    }

    void bfs(Graph const &graph, queue<int> &q, vector<bool> &discovered)
    {
        if(q.empty()) return;

        int vi = q.front();
        q.pop();
        cout<< vi << " ";

        for(int u: graph.lst[vi])
        {
            if(!discovered[u])
            {
                discovered[u] = true;
                q.push(u);
            }
        }
        bfs(graph, q, discovered);

    }
};

int main()
{
    int v, e;
    cout<<"enter the number of vertices & edges: ";
    cin>>v>>e;
    Graph g(v,e);

    vector<bool> discovered(v, false);
    vector<bool> discovered1(v, false);
    queue<int> q;
    stack<int> s;

    cout<<"BFS: ";
    for(int i=0; i<v; i++)
    {
        if(!discovered[i])
        {
            discovered[i] = true;
            q.push(i);
            g.bfs(g, q, discovered);
        }
    }

    cout<<"DFS: \n";
    for(int i=0; i<v; i++)
    {
        if(!discovered1[i])
        {
            discovered1[i] = true;
            s.push(i);
            g.dfs(g, s, discovered1);
        }
    }
}