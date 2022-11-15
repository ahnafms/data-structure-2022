#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Vertex {
    protected:
        list<int> adj;
    
    public:
        void addEdge(int u, int v){
            if(adj.empty()) adj.push_back(u);
            adj.push_back(v);
        }

        void showList(){
            list<int>::iterator it;
            for(it = adj.begin(); it != adj.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
};

class Graph {
	
    protected:
        int len;
        Vertex vertex[100];
        
    public:
        Graph(int _len) {
            len = _len;
        }
		
        AddEdgetoVertex(int u, int v){
            vertex[u].addEdge(u,v);
            vertex[v].addEdge(v,u);
        }
		
        showAllVertex(){
            for (int i = 0; i < len; i++)
            {
                vertex[i].showList();
            }
        }
};


int main(){
    Graph ans_graph(5);

    ans_graph.AddEdgetoVertex( 0, 1);
    ans_graph.AddEdgetoVertex( 0, 4);
    ans_graph.AddEdgetoVertex( 1, 2);
    ans_graph.AddEdgetoVertex( 1, 3);
    ans_graph.AddEdgetoVertex( 1, 4);
    ans_graph.AddEdgetoVertex( 2, 3);
    ans_graph.AddEdgetoVertex( 3, 4);
    
    ans_graph.showAllVertex();
}
