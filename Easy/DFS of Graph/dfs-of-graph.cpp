//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        stack<int> st;
        int src=0;
        vector<int> visited(V,0);
        vector<int> ordr;
        st.push(src);
        
        while(!st.empty()){
            bool adjexist = false;
            int tp = st.top();
            for(int i=0;i<adj[tp].size();i++){
                if(!visited[adj[tp][i]]){
                    st.push(adj[tp][i]);
                    adjexist=true;
                    break;
                }
            }
            
            if(!adjexist){
                st.pop();
            }
            if(visited[tp]!=1){
                visited[tp]=1;
                ordr.push_back(tp);
            }
            
            
        }
        
        return ordr;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends