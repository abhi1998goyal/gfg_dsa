//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int t=0;
        int d=r-1;
        int l=0;
        int rt=c-1;
        int dir=0;
        vector<int> vc;
        
        while(t<=d && l<=rt){
        if(dir==0){
        for(int i=l;i<=rt;i++){
           vc.push_back(matrix[t][i]);
            
        }
        t++;
        dir=1;
        }
        else if (dir==1) {for(int i=t;i<=d;i++){
            vc.push_back(matrix[i][rt]);
            
        } rt--;
        dir=2;
        }
        
        else if (dir==2) { for(int i=rt;i>=l;i--){
            vc.push_back(matrix[d][i]);
            
        }
        d--;
        dir=3;
        }
        
        else if (dir==3) { for(int i=d;i>=t;i--){
            vc.push_back(matrix[i][l]);
           
        } l++;
        dir=0;
        
        }
        }
        
        return vc;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends