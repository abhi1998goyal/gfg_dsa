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
        auto comp = [](pair<int,int> a , pair<int,int> b) -> bool {return a.second>b.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> pq(comp);
        pq.push(make_pair(0,0));
        vector<int> visited(V,0);
      //  visited[0]=1;
        int sum=0;
        int x=0;
        while(x!=V){
            int vrtx = pq.top().first;
            int dist = pq.top().second;
            pq.pop();
            if(visited[vrtx]==1){
                continue;
            }
            x++;
            sum+=dist;
            visited[vrtx]=1;
            
            for(int i=0;i<adj[vrtx].size();i++){
                if(visited[adj[vrtx][i][0]]!=1){
                    pq.push(make_pair(adj[vrtx][i][0],adj[vrtx][i][1]));
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