//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void BFS(int source,vector<vector<int>> &d,vector<vector<int>> &s ){
         vector<int> vis(s[source].size(),0);
        // vis[source]=1;
        queue<int> q;
        q.push(source);
        
        while(!q.empty()){
           
            int vtx=q.front();
             d[source][vtx]=1;
            if(vis[vtx]!=1){
                for(int i=0;i<s[vtx].size();i++){
                    if(s[vtx][i]==1 && i!=vtx){
                    q.push(i);
                    }
                }
            }
            
            
            vis[vtx]=1;
            q.pop();
        }
        
       /* if(s[source][source]==1){
                d[source][source]=1;
            }
        else{
            d[source][source]=0;
        }*/
        
    }
    
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        vector<vector<int>> trans(N,vector<int>(N,0));
        
        
        for(int i=0;i<N;i++){
           
            BFS(i,trans,graph);
        }
        
        return trans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends