#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class WeightedGraph{
    public:
    unordered_map<int, list<pair<int,int>>>adjList;
    void addEdge(int u, int v, int weight, bool direction){
        //direciton =0 ->undirected
        //direction=1 ->directed
        if(direction==0){
        adjList[u].push_back({v,weight});
        adjList[v].push_back({u,weight});
        }
        else{
            //directed edge
            adjList[u].push_back({v,weight});
        }
    }
    void printAdjLisst()
    {
        for(auto i:adjList){
            cout<<i.first<<":";
            cout<<"{";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")"<<",";
            }            cout<<"}"<<endl;
        }
    }
    void bfstraversal(int src){
    queue<int>q; 
    unordered_map<int,bool>visited;
    //initial state
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int frontNode=q.front();
        cout<<frontNode<<",";
        q.pop();
        for(auto neighbour:adjList[frontNode])
        {
            //neighbour->pair
            //first->node
            //second->weight
            int node=neighbour.first;
            int weight=neighbour.second;
            if(!visited[node]){
                q.push(node);
                visited[node]=true;
            }
        }
    }
    cout<<endl;
 }
   void dfs(int src,unordered_map<int,bool>&visited){
    visited[src]=true;
    cout<<src<<",";
    for(auto nbr:adjList[src]){
        int node=nbr.first;
        if(!visited[node])
        {
            dfs(node,visited);
        }
    }
   }
 void dfstraversal(int n){
    unordered_map<int,bool>visited;
    for(int src=0;src<n;src++){
        if(!visited[src]){
            dfs(src,visited);
        }
    }
 }
};
class Graph{
    public:
    unordered_map<int,list<int>> adjList;
    void addEdge(int u, int v, bool direction){
        //direction = 0 -> undirected
        //direction = 1 -> directed
        if(direction==0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);

        }
        else{
            //directed edge
            adjList[u].push_back(v); 

        }    
 }
 void printAdjList(){
        for(auto i:adjList){
            cout<<i.first<<":";
            cout<<"{";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<"}"<<endl;
        }
 }
 void printAdjList2(int n){
        for(int i=0;i<n;i++){
            cout<<i<<":";
            cout<<"{";
           for(auto j:adjList[i]){
                cout<<j<<",";
            }
            cout<<"}"<<endl;
        }
 }
 
};
int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    // g.printAdjList();
    // g.printAdjList2(4);
    WeightedGraph wg;
    wg.addEdge(0,3,3,1);
    wg.addEdge(0,5,3,1);
    wg.addEdge(0,2,3,1);
    wg.addEdge(2,5,3,1);
    wg.addEdge(3,5,3,1);
    wg.addEdge(5,4,3,1);
    wg.addEdge(5,6,3,1);
    wg.addEdge(4,1,3,1);
    wg.addEdge(6,1,3,1);
    int n=7;
    cout<<"printing the weighted graph"<<endl;
    wg.printAdjLisst();
    cout<<"printing the BFS "<<endl;
    wg.bfstraversal(0);
    cout<<"printing the DFS"<<endl;
    wg.dfstraversal(n);
   
    return 0; 

}