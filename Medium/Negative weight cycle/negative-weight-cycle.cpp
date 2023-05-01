//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int lop=n;
	    vector<int> dist(n,INT_MAX-1000);
	    dist[0]=0;
	   
	    while(lop>0){
	        //bool chng=false;
	        for(int i=0;i<edges.size();i++){
	            int src = edges[i][0];
	            int des = edges[i][1];
	            int wt = edges[i][2];
	            if(dist[src]>dist[des]+wt){
	                dist[src]=dist[des]+wt;
	               if(lop==1)
	               { return 1;}
	            }
	            /*else if (dist[des]>dist[src]+wt){
	                dist[des]=dist[src]+wt;
	                chng=true;
	            }*/
	            
	           /* if( && chng){
	                return 1;
	            }*/
	            
	            
	            
	            
	        }
	        lop--;
	
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends