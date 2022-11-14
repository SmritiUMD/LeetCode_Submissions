/*
We will use the array tree[] to store the nodes of our segment tree (initialized to all zeros). The following scheme (0 - based indexing) is used:

The node of the tree is at index 00. Thus tree[0] is the root of our tree.
The children of tree[i] are stored at tree[2*i+1] and tree[2*i+2].
We will pad our arr[] with extra 0 or null values so that n = 2^k, n=2 
k
  (where n is the final length of arr[] andk is a non negative integer.)

*/

void buildSegTree(vector<int>& arr, int treeIndex, int lo, int hi)
{
    if (lo == hi) {                 // leaf node. store value in node.
        tree[treeIndex] = arr[lo];
        return;
    }

    int mid = lo + (hi - lo) / 2;   // recurse deeper for children.
    buildSegTree(arr, 2 * treeIndex + 1, lo, mid);
    buildSegTree(arr, 2 * treeIndex + 2, mid + 1, hi);

    // merge build results
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
}

// call this method as buildSegTree(arr, 0, 0, n-1);
// Here arr[] is input array and n is its size.
