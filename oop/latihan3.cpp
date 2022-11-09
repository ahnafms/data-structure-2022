#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Graph {
    protected:
        int v;
        list<int> adj[100];

    public:
    Graph(int len) {
        v = len;
    }

    void setLen(int len){
        v = len;
        adj[v];
    }

    void addEdge(int u, int v){
        if(adj[u].empty()) adj[u].push_back(u);
        if(adj[v].empty()) adj[v].push_back(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void displayGraph(){
        for (int i = 0; i <= v; i++)
        {
            list<int>::iterator it;
            for(it = adj[i].begin(); it != adj[i].end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};


int main(){
    Graph ans_graph(5);

    ans_graph.addEdge( 0, 1);
    ans_graph.addEdge( 0, 4);
    ans_graph.addEdge( 1, 2);
    ans_graph.addEdge( 1, 3);
    ans_graph.addEdge( 1, 4);
    ans_graph.addEdge( 2, 3);
    ans_graph.addEdge( 3, 4);
    ans_graph.displayGraph();

}
