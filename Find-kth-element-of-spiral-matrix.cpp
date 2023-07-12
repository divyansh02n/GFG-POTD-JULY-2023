class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int arr[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int l = 0, r = m-1;
 		int u = 0, d = n-1;
 		while(k){
 		    for(int i=l;i<=r;i++){
 		        k--;
 		        if(k == 0) return arr[u][i];
 		        
 		    }
 		    u++;
 		    for(int j=u;j<=d;j++){
 		        k--;
 		        if(k == 0) return arr[j][r];
 		        
 		    }
 		    r--;
 		    for(int i=r;i>=l;i--){
 		        k--;
 		        if(k == 0) return arr[d][i];
 		        
 		    }
 		    d--;
 		    for(int j=d;j>=u;j--){
 		        k--;
 		        if(k == 0) return arr[j][l];
 		        
 		    }
 		    l++;
 		}
 		return 0;
    }
};
