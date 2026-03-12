#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class graph{
public:
unordered_map<int,list<int>>adjList;

void addEdge(int u,int v,bool direction){
    //direction=0->undirected
    //direction=1->directed
   if(direction==0){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
   }
   else{
    adjList[u].push_back(v);
   }

}
bool cycleDetectionUndirected(int src,unordered_map<int,bool>&visited){
    unordered_map<int,int>parent;
    queue<int>q;
    q.push(src);
    visited[src]=true;
    parent[src]=-1;
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        for(auto nbr:adjList[frontNode]){
            if(!visited[nbr]){
                q.push(nbr);

                visited[nbr]=true;
                parent[nbr]=frontNode;
            }
            else if(visited[nbr]==true&& nbr!=parent[frontNode])
            {
                return true;
            }
        }
    }

    return false;
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
};
int main(){
    graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    int n=4;
    g.printAdjList();
    unordered_map<int,bool>visited;
    bool ans=false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(!visited[i])
            {
                ans=g.cycleDetectionUndirected(i,visited);
                if(ans==true)
                {
                    
                    break;
                }
            }

        }
    }
    if(ans==true)
    {
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"cycle is not present"<<endl;
    }
    return 0;


}
