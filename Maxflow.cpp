#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>

using namespace std;

#define N 25

int capacity[N][N];
int flow[N][N];
vector<int> graph[N];
int pred[N];
int curr_path_capacity[N];

int bfs(int s, int t){
  //cout<<"BFS starts"<<endl;
  memset(pred, -1, sizeof(pred));
  memset(curr_path_capacity, 0, sizeof(curr_path_capacity));
  queue<int> bfsq;

  bfsq.push(s);
  pred[s] = -100000;
  curr_path_capacity[s] = 1000000;

  while(!bfsq.empty()){
    int curr = bfsq.front();
    bfsq.pop();

    for(int i=0; i<graph[curr].size(); i++){
      int adj_node = graph[curr][i];
      if(pred[adj_node] == -1)
          if(capacity[curr][adj_node] - flow[curr][adj_node] > 0){
            pred[adj_node] = curr;
            curr_path_capacity[adj_node] = min(curr_path_capacity[curr], capacity[curr][adj_node] - flow[curr][adj_node]);

            if(adj_node == t){
              //cout<<"works maybe"<<endl;
              cout<<curr_path_capacity[adj_node]<<endl;
              return curr_path_capacity[adj_node];}

            bfsq.push(adj_node);
          }

    }
  }
  return 0;
}

int edkarp(int s, int t){
    int maxflow = 0;

    while(1){
      int temp_flow = bfs(s,t);

      if(temp_flow == 0)
        return maxflow;

        maxflow += temp_flow;

      int start = t;
      while(start != s){
        int prev = pred[start];
        flow[prev][start] += temp_flow;
        flow[start][prev] -= temp_flow;
        start = prev;
      }
    }

    return maxflow;
}

int main(){

  int v,e;
  cout<<"Enter number of vertices and edges"<<endl;
  cin>>v>>e;

  int s,t;
  cout<<"Enter source and sink vertex"<<endl;
  cin>>s>>t;

  cout<<"Enter edges"<<endl;
  for(int i=0; i<e; i++){
    cout<<"Enter i and j and c(i,j)"<<endl;
    int a,b,c;
    cin>>a>>b>>c;
    graph[a].push_back(b);
    graph[b].push_back(a);
    capacity[a][b] = c;
  }
  cout<<"Maxflow is "<<edkarp(s,t)<<endl;
  return 0;
}
