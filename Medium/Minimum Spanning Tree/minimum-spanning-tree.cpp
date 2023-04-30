//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int src=0;
        vector<int> visited(V,0);
        auto comp =[](pair<int,int> a , pair<int,int> b)->bool{return a.second>b.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> pq(comp);
        pq.push(make_pair(0,0));
        int sum=0;
        
        while(!pq.empty()){
            int vrtx=pq.top().first;
            int wght=pq.top().second;
            pq.pop();
            if(visited[vrtx]==1){
                continue;
            }
            visited[vrtx]=1;
          //  cout<<wght<<endl;
            sum+=wght;
            
            for(auto x:adj[vrtx]){
                  int vtx=x[0];
                  int wt =x[1];
                  if(visited[vtx]!=1){
                      pq.push(make_pair(vtx,wt));
                  }
                }
            
            
        }
        
        return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends