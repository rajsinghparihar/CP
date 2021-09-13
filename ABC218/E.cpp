#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    long long int src, dest, weight;
};

class Graph
{
public:
    long long int V, E;
    Edge *edge;
};

Graph *createGraph(long long int V, long long int E)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}

class subset
{
public:
    long long int parent;
    long long int rank;
};

long long int find(subset subsets[], long long int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(subset subsets[], long long int x, long long int y)
{
    long long int xroot = find(subsets, x);
    long long int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void *a, const void *b)
{
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->weight > b1->weight;
}

long long int KruskalMST(Graph *graph)
{
    long long int V = graph->V;
    Edge result[V];
    long long int e = 0;
    long long int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
          myComp);

    subset *subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];

        long long int x = find(subsets, next_edge.src);
        long long int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    long long int minimumCost = 0LL;
    for (i = 0; i < e; ++i)
    {
        if (result[i].weight > 0)
            minimumCost = minimumCost + result[i].weight;
    }
    return minimumCost;
}

int main(void)
{

    int V;
    int E;
    cin >> V >> E;
    Graph *graph = createGraph(V, E);
    long long int cost = 0LL;
    for (int i = 0; i < E; i++)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (c > 0)
            cost += c;
        graph->edge[i].src = a;
        graph->edge[i].dest = b;
        graph->edge[i].weight = c;
    }

    long long int ans = KruskalMST(graph);
    cout << (cost - ans) << endl;
    return 0;
}