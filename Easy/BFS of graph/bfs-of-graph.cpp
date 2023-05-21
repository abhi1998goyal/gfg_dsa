//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        q.push(0);
        vector<int> arr(V,0);
        vector<int> lst;
        
        while(!q.empty()){
             if(arr[q.front()]==1){
                    q.pop();
                }
            else{
            for(int i=0;i<adj[q.front()].size();i++){
                int vert = adj[q.front()][i];
               
                 if( arr[vert]!=1 ){
                    q.push(vert);
                }
                
            }
             arr[q.front()]=1;
            lst.push_back(q.front());
            q.pop();
            }
           
        }
        return lst;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends