#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;

class Graph{
	int V;
	list<pair<int, string>> adj[100];
	vector<bool> visited_dfs;
public:
Graph(int v){
	V = v;
	visited_dfs.resize(V,false);
}

void addVertex(string str, int v1, int v2){
	adj[v1].push_back(make_pair(v2, str));
}

void bfs_no_destination(string startVertex){
	vector<bool> visited;
	visited.resize(V,false);
	queue<pair<int, string>> q;
	q.push(make_pair(1, startVertex));
	visited[1] = true;
	while(!q.empty()){
		for(auto const &i: adj[q.front().first]){
			if(!visited[i.first]){
				visited[i.first] = true;
				q.push(make_pair(i.first, i.second));
			}
		}
		cout << q.front().second << " ";
		q.pop();
	}
}
void bfs(string startVertex, string destination){
	vector<bool> visited;
	visited.resize(V,false);
	queue<pair<int, string>> q;
	q.push(make_pair(1, startVertex));
	visited[1] = true;
	while(!q.empty()){
		for(auto const &i: adj[q.front().first]){
			if(!visited[i.first]){
				visited[i.first] = true;
				q.push(make_pair(i.first, i.second));
			}
		}
		cout << q.front().second << " ";
		const char *c = q.front().second.c_str();
		const char *d = destination.c_str();
		q.pop();
		if(strcmp(c, d) == 0) break;
	}
}

int flag = 0;
void dfs(int source, string destination){
	vector<bool> visited;
	visited.resize(V,false);
	visited[source] = true;
	const char *c = adj[source].front().second.c_str();
	const char *d = destination.c_str();
	cout << c << " ";
	if(strcmp(c, d) == 0) {
		flag = 1;
		return;
	}
	else {
		for(auto const &i: adj[source]){	
			if(flag == 1) return;
			else if(!visited[i.first]) dfs(i.first, destination);
		}
	}
}

void dfs_no_destination(int source){
	visited_dfs[source] = true;
	const char *c = adj[source].front().second.c_str();
	cout << c << " ";
	for(auto const &i: adj[source]){	
		if(!visited_dfs[i.first]) dfs_no_destination(i.first);
	}
}

};
int main(){
	Graph graph(20);
	graph.addVertex("rumah", 1, 1);
	graph.addVertex("alun-alun", 1, 2);
	graph.addVertex("pasar", 1, 3);
	graph.addVertex("masjid", 1, 4);
	graph.addVertex("alun-alun", 2, 2);
	graph.addVertex("masjid", 2, 4);
	graph.addVertex("rumah makan", 2, 5);
	graph.addVertex("pasar", 3, 3);
	graph.addVertex("masjid", 3, 4);
	graph.addVertex("pelabuhan", 3, 6);
	graph.addVertex("sekolah", 3, 8);
	graph.addVertex("masjid", 4, 4);
	graph.addVertex("rumah makan", 4, 5);
	graph.addVertex("pom bensin", 4, 9);
	graph.addVertex("rumah makan", 5, 5);
	graph.addVertex("minimarket", 5, 7);
	graph.addVertex("warung", 5, 10);
	graph.addVertex("lapangan", 5, 11);
	graph.addVertex("pelabuhan", 6, 6);
	graph.addVertex("sekolah", 6, 8);
	graph.addVertex("kilang minyak", 6, 12);
	graph.addVertex("minimarket", 7, 7);
	graph.addVertex("stadion", 7, 13);
	graph.addVertex("sekolah", 8, 8);
	graph.addVertex("mall", 8, 14);
	graph.addVertex("supermarket", 8, 15);
	graph.addVertex("pom bensin", 9, 9);
	graph.addVertex("mall", 9, 14);
	graph.addVertex("bandara", 9, 16);
	graph.addVertex("taman bekapai", 9, 17);
	graph.addVertex("warung", 10, 10);
	graph.addVertex("pom bensin", 10, 9);
	graph.addVertex("taman bekapai", 10, 17);
	graph.addVertex("kawasan pertamina", 10, 18);
	graph.addVertex("lapangan", 11, 11);
	graph.addVertex("stadion", 11, 13);
	graph.addVertex("kilang minyak", 12, 12);
	graph.addVertex("supermarket", 12, 15);
	graph.addVertex("stadion", 13, 13);
	graph.addVertex("kawasan pertamina", 13, 18);
	graph.addVertex("mall", 14, 14);
	graph.addVertex("pantai", 14, 19);
	graph.addVertex("supermarket", 14, 15);
	graph.addVertex("supermarket", 15, 15);
	graph.addVertex("pantai", 15, 19);
	graph.addVertex("bandara", 16, 16);
	graph.addVertex("taman bekapai", 16, 17);
	graph.addVertex("pantai", 16, 19);
	graph.addVertex("taman bekapai", 17, 17);
	graph.addVertex("km_50", 17, 20);
	graph.addVertex("kawasan_pertamina", 18, 18);
	graph.addVertex("km_50", 18, 20);
	graph.addVertex("pantai", 19, 19);
	graph.addVertex("km_50", 19, 20);
	graph.addVertex("km_50", 20, 20);
	cout << "bfs no destination" << endl;
	graph.bfs_no_destination("rumah");
	cout << "\n\nbfs" << endl;
	graph.bfs("rumah", "stadion");
	cout << "\n\ndfs no destination" << endl;
	graph.dfs_no_destination(1);
	cout << "\n\ndfs" << endl;
	graph.dfs(1, "km_50");
}
