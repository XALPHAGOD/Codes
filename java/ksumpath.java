import java.util.*;
public class ksumpath {
    static class Node 
    { 
        int data; 
        Node left,right; 
        Node(int x) 
        { 
            data = x; 
            left = right = null; 
        } 
    };
    static Vector<Integer> vec;
    public static void print(Vector<Integer> vec,int i){
        for(int j=i;j<vec.size();j++)
            System.out.print(vec.get(j)+" ");
        System.out.println();
    }
    public static void printpath(Node root,int k,Vector<Integer> vec){
        if(root==null)
            return;
        
        vec.add(root.data);
        printpath(root.left, k, vec);
        printpath(root.right, k, vec);

        int s=0;
        for(int i=vec.size()-1;i>=0;i--)
        {
            s+=vec.get(i);
            if(s==k)
                print(vec,i);
        }
        vec.remove(vec.size()-1);
    }
    public static void printK(Node root,int k){
        vec=new Vector<>();
        printpath(root,k,vec);
    }
    public static void main(String[] args){
        
        Node root = new Node(1); 
        root.left = new Node(3); 
        root.left.left = new Node(2); 
        root.left.right = new Node(1); 
        root.left.right.left = new Node(1); 
        root.right = new Node(-1); 
        root.right.left = new Node(4); 
        root.right.left.left = new Node(1); 
        root.right.left.right = new Node(2); 
        root.right.right = new Node(5); 
        root.right.right.right = new Node(2);

        int k=5;
        printK(root,k);
    }
    
}
