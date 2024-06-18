

//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node
{


    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

class GFG {
    
	public static void main (String[] args) throws Exception{
	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        
	        int t=Integer.parseInt(br.readLine());
	        while(t > 0){
	            int n=Integer.parseInt(br.readLine().trim());
	            String s[] = br.readLine().trim().split(" ");

	            int target=Integer.parseInt(br.readLine().trim());
    	    	Node root = null;
                for(int i=0;i<n;i++){
                    root=insert(root,Integer.parseInt(s[i]));
                }
        	    Solution g = new Solution();
        	    System.out.println(g.maxDifferenceBST(root,target));
                t--;
            
        }
    }

    public static Node insert(Node tree, int val) {
        Node temp = null;
        if (tree == null) return new Node(val);
    
        if (val < tree.data) {
            tree.left = insert(tree.left, val);
        } else if (val > tree.data) {
            tree.right = insert(tree.right, val);
        }
    
        return tree;
    }
  
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    private static void helper(Node root, int target, int rootToTarget, int targetToLeaf, int ans[], boolean found){
        if(root == null) return;
        
        if(root.data == target) found = true;
        
        if(found == true){
            
            targetToLeaf += root.data;
            helper(root.left, target, rootToTarget, targetToLeaf, ans, found);
            helper(root.right, target, rootToTarget, targetToLeaf, ans, found);
            
            if(root.left == null && root.right == null){
                targetToLeaf -= target;
                ans[0] = Math.max(ans[0], rootToTarget-targetToLeaf);
            }
            
        }else{
           rootToTarget += root.data;
           if(target < root.data) helper(root.left, target, rootToTarget, targetToLeaf, ans, found);
           else helper(root.right, target, rootToTarget, targetToLeaf, ans, found);
        }
    }
    
    
    public static int maxDifferenceBST(Node root,int target)
    {
        //Please code here
        int rootToTarget =0, targetToLeaf=0;
        
        int ans[] = new int[1];
        ans[0] = Integer.MIN_VALUE;
        
        boolean found = false;
        
        helper(root, target, rootToTarget,targetToLeaf,ans,found);
        
        if(ans[0] == Integer.MIN_VALUE) return -1;
        return ans[0];
        
    }
}
