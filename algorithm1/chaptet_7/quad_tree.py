def divide_quad_tree(tree):
    divided_quad_tree = []
    idx = 0
    for i in range(0,4):
        if tree[idx] == 'w' or tree[idx] == 'b':
            divided_quad_tree.append(tree[idx])
            idx = idx +1
        else:
            start = idx
            idx = idx+1
            length = 4
            while length>0:
                length = length - 1
                if tree[idx] == 'x':
                    length = length + 4
                idx = idx +1
            subtree = tree[start:idx]
            divided_quad_tree.append(subtree)
    return divided_quad_tree



def reverse_quad_tree(tree):
    if (tree == 'w') or (tree == 'b'):
        return tree
    
    divided_quad_tree = divide_quad_tree(tree[1:])
    res = 'x'
    res = res + reverse_quad_tree(divided_quad_tree[2])
    res = res + reverse_quad_tree(divided_quad_tree[3])
    res = res + reverse_quad_tree(divided_quad_tree[0])
    res = res + reverse_quad_tree(divided_quad_tree[1])
    return res



def reverse(tree,idx):
    if tree[idx]=='w' or tree[idx]=='b':
        return tree[idx], idx+1
    idx = idx +1
    upperLeft,idx = reverse(tree,idx)
    upperRight,idx = reverse(tree,idx)
    lowerLeft,idx = reverse(tree,idx)
    lowerRight,idx = reverse(tree,idx)
    return 'x'+lowerLeft+lowerRight+upperLeft+upperRight,idx




if __name__=="__main__":
    tree = "xxwwwbxwxwbbbwwxxxwwbbbwwwwbb"
    tree_2 = "xwbbw"
    reverse_tree,idx = reverse(tree,0)
    print(reverse_tree)