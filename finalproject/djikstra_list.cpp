#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> intPair;

class Graph{
	int V;
	list<pair<int,int>> adj[21];
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}
	
	void addVertex(string str, int u, int v, int w){
	    adj[u].push_back(make_pair(v, w));
	    places[v] = str;
	}
	
	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	    	cout << i << " :";
	        for(auto const &j: adj[i]){
	            cout << " " << j.first << " ";
	        }
	        cout << endl;
	    }
	}
	
	void djikstra(int src){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, src));
		int dist[V];
		for(int i = 1; i<=V; i++){
		    dist[i] = 100;
		}
		dist[src] = 1;
		
		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			
			list<pair<int,int>> :: iterator i;
			for(i = adj[u].begin(); i != adj[u].end(); i++){
				int v = (*i).first;
				int w = (*i).second;
				if(dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		printf("Vertex Distance from Source\n");
    for (int i = 1; i <= V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
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
	graph.showAllVertex();
	int src;
	cout << "insert src : ";
	cin >> src;
    graph.djikstra(src);
}
