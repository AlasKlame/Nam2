
int main(){
    Node *root = NULL;
    int arr[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    root = createBST(arr, n);
    
    int x = 5;
    int min = minNode(root);
    cout << "Min of BST: " << min << endl;
    int max = maxNode(root);
    cout << "Max of BST: " << max << endl;

    if(isBST(root, min, max)){
        cout << "true" <<endl;
    }
    else{
        cout << "false" << endl;
    }
    if(isFullBST(root)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    int lessCount = countLess(root, x);
    cout << "Number of nodes less than " << x << ": " << lessCount << endl;
    
    int greaterCount = countGreater(root, x);
    cout << "Number of nodes greater than " << x << ": " << greaterCount << endl;
    
    removeBST(root);
    
    return 0;
}