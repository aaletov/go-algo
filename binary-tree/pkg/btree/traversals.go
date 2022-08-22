package btree

// NLR
func (root *Node[T]) PreOrderTraversal(f func(T)) {
	if root == nil {
		panic("Root cannot be nil")
	}

	f(root.Value)

	if root.Left != nil {
		root.Left.PreOrderTraversal(f)
	} 

	if root.Right != nil {
		root.Right.PreOrderTraversal(f)
	}
}

// LNR
func (root *Node[T]) InOrderTraversal(f func(T)) {
	if root == nil {
		panic("Root cannot be nil")
	}

	if root.Left != nil {
		root.Left.InOrderTraversal(f)
	}

	f(root.Value)

	if root.Right != nil {
		root.Right.InOrderTraversal(f)
	}
}

// LRN
func (root *Node[T]) PostOrderTraversal(f func(T)) {
	if root == nil {
		panic("Root cannot be nil")
	}

	if root.Left != nil {
		root.Left.PostOrderTraversal(f)
	}

	if root.Right != nil {
		root.Right.PostOrderTraversal(f)
	}

	f(root.Value)
}

