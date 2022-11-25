
#include <iostream>
#include <list>
#include <queue>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

class Graph{
	int V;
	bool visited_dfs[21] = {false};
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string place[21];
	
public:
Graph(int v){
	V = v;
}

void addVertex(string str, int v1, int v2){
	adjM[v1][v2] = 1;
	place[v2] = str;
}

void bfs(string startVertex, string destination){
	bool visited[21] = {false};
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while(!q.empty()){
		int flag = 0;
		for(int i = 1; i<= 20; i++){
			if(!visited[i]){
				visited[i] = true;
				q.push(i);
			}
		}
		const char *d = destination.c_str();
		const char *c = place[q.front()].c_str();
		cout << place[q.front()] << " ";
		q.pop();
		if(strcmp(d, c)==0) break;
	}
}

int flag = 0;

void dfs(int source, string destination){
	visited_dfs[source] = true;
	const char *d = destination.c_str();
	const char *c = place[source].c_str();
	cout << c << " ";
	if(strcmp(c, d) == 0) {
		flag = 1;
		return;
	}
	for(int i = 1;i<=V;i++){
	    if(flag == 1) return;
		else if ((!visited_dfs[i]) && adjM[source][i] == 1) dfs(i, destination);
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
	cout << "BFS" << endl;
 	graph.bfs("rumah", "km_50");
 	cout << "\nDFS" << endl;
 	graph.dfs(1, "km_50");
}
