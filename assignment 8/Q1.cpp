    //PreOrder traversal : root,left,right
    void printPRE(Node root){
        if(root==null) return ;
        System.out.print(root.val+" ");
        printPRE(root.left);
        printPRE(root.right);
    }
    //InOrder traversal : left,root,right
    void printIN(Node root){
        if(root==null) return;
        printIN(root.left);
        System.out.print(root.val+" ");
        printIN(root.right);
    }
    //PostOrder traversal : left,right,root
    void printPOST(Node root){
        if(root==null) return;
        printPOST(root.left); 
        printPOST(root.right);
        System.out.print(root.val+" ");
    }
