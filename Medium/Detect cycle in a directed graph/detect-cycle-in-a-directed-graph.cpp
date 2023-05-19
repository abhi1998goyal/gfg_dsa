//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDegree(V,0);
       /* for(auto it=adj->begin();it!=adj->end();it++){
          
                inDegree[(*it)[1]]++;
            
        }*/
        
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
               inDegree[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        for(int j=0;j<V;j++){
            if(inDegree[j]==0){
                q.push(j);
            }
        }
        
         int vis=0;
         while(!q.empty()){
             
             int x=q.front();
             q.pop();
             for(int i=0;i<adj[x].size();i++){
                 inDegree[adj[x][i]]--;
                 if(inDegree[adj[x][i]]==0){
                     q.push(adj[x][i]);
                 }
             }
             vis++;
         }
         
         if(vis==V){
             return false;
         }
         
         return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends