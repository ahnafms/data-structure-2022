#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;

class Graph {
    protected:
        int v;
        vector<string> place;
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
        vector<int> dijkstraRes;
        
    public:
        Graph(int len) {
            v = len;
            place.assign(v+1, "");
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }
        
        void addVertex(string i, int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
            place[v] = i;
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                list<int>::iterator it;
                cout << i << " => ";
                for (it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    cout << *it << "(" << weight[make_pair(i, *it)] << ") ";
                }
                cout << endl;
            }
        }

        void DFS(int start, int end){
            cout << endl;
            cout << "## Shortest path using DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );
            
            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i] << " ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            visited[start] = true;
            path.push_back(start);
            list<int>::iterator it;
            for ( it = adj[start].begin(); it != adj[start].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
        }
};

int main(){
    Graph graph(20);
    graph.addVertex("rumah", 1, 1, 1);
	graph.addVertex("alun-alun", 1, 2, 4);
	graph.addVertex("pasar", 1, 3, 5);
	graph.addVertex("masjid", 1, 4, 3);
	graph.addVertex("alun-alun", 2, 2, 10);
	graph.addVertex("masjid", 2, 4, 3);
	graph.addVertex("rumah makan", 2, 5, 14);
	graph.addVertex("pasar", 3, 3, 5);
	graph.addVertex("masjid", 3, 4, 3);
	graph.addVertex("pelabuhan", 3, 6, 11);
	graph.addVertex("sekolah", 3, 8, 12);
	graph.addVertex("masjid", 4, 4, 3);
	graph.addVertex("rumah makan", 4, 5, 14);
	graph.addVertex("pom bensin", 4, 9, 16);
	graph.addVertex("rumah makan", 5, 5, 14);
	graph.addVertex("minimarket", 5, 7, 18);
	graph.addVertex("warung", 5, 10, 17);
	graph.addVertex("lapangan", 5, 11, 16);
	graph.addVertex("pelabuhan", 6, 6, 11);
	graph.addVertex("sekolah", 6, 8, 12);
	graph.addVertex("kilang minyak", 6, 12, 17);
	graph.addVertex("minimarket", 7, 7, 18);
	graph.addVertex("stadion", 7, 13, 17);
	graph.addVertex("sekolah", 8, 8, 12);
	graph.addVertex("mall", 8, 14, 20);
	graph.addVertex("supermarket", 8, 15, 21);
	graph.addVertex("pom bensin", 9, 9, 16);
	graph.addVertex("mall", 9, 14, 20);
	graph.addVertex("bandara", 9, 16, 24);
	graph.addVertex("taman bekapai", 9, 17, 25);
	graph.addVertex("warung", 10, 10, 17);
	graph.addVertex("pom bensin", 10, 9, 16);
	graph.addVertex("taman bekapai", 10, 17, 25);
	graph.addVertex("kawasan pertamina", 10, 18, 30);
	graph.addVertex("lapangan", 11, 11, 16);
	graph.addVertex("stadion", 11, 13, 17);
	graph.addVertex("kilang minyak", 12, 12, 17);
	graph.addVertex("supermarket", 12, 15, 21);
	graph.addVertex("stadion", 13, 13, 17);
	graph.addVertex("kawasan pertamina", 13, 18, 30);
	graph.addVertex("mall", 14, 14, 20);
	graph.addVertex("pantai", 14, 19, 26);
	graph.addVertex("supermarket", 14, 15, 21);
	graph.addVertex("supermarket", 15, 15, 21);
	graph.addVertex("pantai", 15, 19, 26);
	graph.addVertex("bandara", 16, 16, 24);
	graph.addVertex("taman bekapai", 16, 17, 25);
	graph.addVertex("pantai", 16, 19, 26);
	graph.addVertex("taman bekapai", 17, 17, 25);
	graph.addVertex("km_50", 17, 20, 31);
	graph.addVertex("kawasan_pertamina", 18, 18, 30);
	graph.addVertex("km_50", 18, 20, 31);
	graph.addVertex("pantai", 19, 19, 26);
	graph.addVertex("km_50", 19, 20, 31);
	graph.addVertex("km_50", 20, 20, 31);
    graph.showGraph();
    int start, end;
    cin >> start >> end;
    graph.DFS(start, end);

    
}
