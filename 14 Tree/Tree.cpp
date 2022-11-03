#include <iostream.h>
template <class ItemType>
class Tree{
public:
		  Tree(){ root = NULL;  }
		 ~Tree(){ Destroy(root);}
	 int isEmpty() const            { return root == NULL;}
	void insertItem (ItemType item) { Insert(root, item); }
	 int deleteItem (ItemType item) { return Delete(root, item); }
	void NLR () const { cout <<" Pre-Order(NLR): "; recursiveNLR(root); }
	void LNR () const { cout <<"  In-Order(LNR): "; recursiveLNR(root); }
	void LRN () const { cout <<"Post-Order(LRN): "; recursiveLRN(root); }

	int retrieveItem(ItemType& item) const {return Retrieve(root, item);}
	int lengthIs() const {return CountNodes(root);}
private:
	struct node
	{
	 ItemType info;
		 node *left, *right;
	};
	node* root;
	//////// Helper Methode \\\\\\\\
	void Destroy (node*&);
	void recursiveNLR (node*) const;
	void recursiveLNR (node*) const;
	void recursiveLRN (node*) const;

	void Insert(node*&, ItemType);
	 int Delete(node*&, ItemType);
	void DeleteNode(node*& tree);

	 int CountNodes(node*) const;
	 int Retrieve  (node* ,ItemType& item) const;
};
/****************************************************************/
template<class ItemType>
void Tree<ItemType>::Destroy(node*& tree)
{ if (tree != NULL)
  {
	 Destroy(tree->left);
	 Destroy(tree->right);
	 delete tree;
  }
}
template<class ItemType>
void Tree<ItemType>::Insert(node*& tree, ItemType item)
 {
  if (tree == NULL)
  { // Insertion place found.
	 tree = new node;
	 tree->right = NULL;
	 tree->left = NULL;
	 tree->info = item;
  }
  else if (item < tree->info)
	 Insert(tree->left, item);  // Insert in left subtree.
  else
	 Insert(tree->right, item); // Insert in right subtree.
 }
template<class ItemType>    // 498
int Tree<ItemType>::Delete(node*& tree, ItemType item)
{
  if (tree== NULL)             // Node not found; return false
	return 0;
  else if (item == tree->info) // Node found; call DeleteNode.
	{ DeleteNode(tree); return 1;	}
  else if (item < tree->info)
	 return Delete(tree->left, item);  // Look in left subtree.
  else // if (item > tree->info)
	 return Delete(tree->right, item); // Look in right subtree.
}
template<class ItemType>
void Tree<ItemType>::DeleteNode(node*& tree)
{
  node* tempPtr = tree;
  if (tree->left == NULL)
  { tree = tree->right;
	 delete tempPtr;
  }
  else if (tree->right == NULL)
  { tree = tree->left;
	 delete tempPtr;
  }
  else
  {
	 node* Predecessor=tree->left;
	 while (Predecessor->right != NULL)
		Predecessor = Predecessor->right;
	 tree->info = Predecessor->info;
	 Delete(tree->left, Predecessor->info); // Delete predecessor node
  }
}
template<class ItemType>
void Tree<ItemType>::recursiveLNR (node* subRoot) const
{
 if (subRoot != NULL)
  {
	recursiveLNR(subRoot->left);  // Print left subtree.
	cout << subRoot->info << ' ';
	recursiveLNR(subRoot->right); // Print right subtree.
  }
}
template<class ItemType>
void Tree<ItemType>::recursiveNLR (node* subRoot) const
{
 if (subRoot != NULL)
  {
	cout << subRoot->info << ' ';
	recursiveNLR(subRoot->left);  // Print left subtree.
	recursiveNLR(subRoot->right); // Print right subtree.
  }
}
template<class ItemType>
void Tree<ItemType>::recursiveLRN (node* subRoot) const
{
 if (subRoot != NULL)
  {
	recursiveLRN(subRoot->left);  // Print left subtree.
	recursiveLRN(subRoot->right); // Print right subtree.
	cout << subRoot->info << ' ';
  }
}
template<class ItemType>
int Tree<ItemType>::CountNodes(node* tree) const
{
if (tree == NULL)
	return 0;
else
	return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}
template<class ItemType>
int Tree<ItemType>::Retrieve(node* tree,ItemType& item)  const
{
 if (tree == NULL)
	return 0; // item is not found.
 else if (item < tree->info)
	return Retrieve(tree->left, item); // Search left subtree.
 else if (item > tree->info)
	return Retrieve(tree->right, item);// Search right subtree.
 else
	return 1;
}
/****************************************************************/
void main ()
{
  Tree <int>t1;

  t1.insertItem(5);   t1.insertItem(9);
  t1.insertItem(7);   t1.insertItem(3);
  t1.insertItem(8);   t1.insertItem(12);
  t1.insertItem(6);   t1.insertItem(4);
  t1.insertItem(20);  t1.insertItem(1);

  t1.NLR(); cout << endl;
  t1.LNR(); cout << endl;
  t1.LRN(); cout << endl;

  cout << "\n";
  t1.deleteItem(12);  t1.deleteItem(4);
  t1.deleteItem(9);   t1.deleteItem(1000);

  t1.NLR(); cout << endl;
  t1.LNR(); cout << endl;
  t1.LRN(); cout << endl;
}
/*  The Output
 Pre-Order(NLR): 5 3 1 4 9 7 6 8 12 20
  In-Order(LNR): 1 3 4 5 6 7 8 9 12 20
Post-Order(LRN): 1 4 3 6 8 7 20 12 9 5

 Pre-Order(NLR): 5 3 1 8 7 6 20
  In-Order(LNR): 1 3 5 6 7 8 20
Post-Order(LRN): 1 3 6 7 20 8 5
*/
