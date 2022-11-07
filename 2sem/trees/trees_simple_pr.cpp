// trees_simple_pr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class Tree;

class TreeNode
{
	friend Tree;
public:
	TreeNode() :left_(0), right_(0) {}
	TreeNode(const int &data) : data_(data), left_(0), right_(0) {}
	int getdata_() const { return data_; }
private:
	int data_;
	TreeNode *left_;
	TreeNode  *right_;
};

class Tree
{
public:
	Tree() : root_(0) {}
	~Tree();
	void insert(const int &);
	//void remove(const int &);
	void print() const;
private:
	TreeNode *root_;
	void insert_helper(TreeNode *&, const int &); 
	void insert_helper2(TreeNode **, const int &);
	//void remove_helper(TreeNode< T > **, const T &);
	//
	void delete_helper(TreeNode *);
	//int depth_helper(TreeNode< T > *) const;
	void print_helper(TreeNode*, int) const;
	void insert(int data, TreeNode*);
};


int main()
{
	std::cout << "Hello World!\n";
	int a[10] = { 1,6,2,3,9,4,7,0,5,8 };

	Tree t;

	for (int k = 0; k < 10; k++)
		t.insert(a[k]);

	t.print();
}

void Tree::delete_helper(TreeNode *node)
{
	if (node != 0)
	{
		delete_helper(node->left_);
		delete_helper(node->right_);
		delete node;
	}
}

Tree::~Tree()
{
	delete_helper(root_);
}

//void pre_order_helper(TreeNode< T > *) const;
//void in_order_helper(TreeNode< T > *) const;
//void post_order_helper(TreeNode< T > *) const;
//template< typename T >

//
//template< typename T >

//
//template< typename T >
void Tree::insert(const int &data)
{
	/*insert_helper(root_, data);
	cout << data << endl;
	cout << root_ << endl;*/

	if (root_ != NULL)
		insert(data, root_);
	else
	{
		root_ = new TreeNode;
		root_->data_= data;
		root_->left_ = NULL;
		root_->right_ = NULL;
	}
	//insert(data, root_);
}
//
//template< typename T >
void Tree::insert_helper(TreeNode *&node, const int &data)
{
	if (node == 0) {
		node = new TreeNode(data);
		
		//cout << root_ << endl;
		//cout << node << endl;
	}
	else
	{
		if (node->data_ > data)
			insert_helper(node->left_, data);
		else
		{
			insert_helper(node->right_, data);
		}
	}
}

void Tree::insert(int data, TreeNode *leaf)
{
	TreeNode *current = new TreeNode;
	current->data_ = data;
	current->left_ = NULL;    //Sets the left child of the child node to null
	current->right_ = NULL;   //Sets the right child of the child node to null

	if (data < leaf->data_)
	{
		if (leaf->left_ != NULL)
			insert(data, leaf->left_);
		else
		{	
			leaf->left_ = current;
			//leaf->left_ = new TreeNode;
			//leaf->left_->data_ = data;
			//leaf->left_->left_ = NULL;    //Sets the left child of the child node to null
			//leaf->left_->right_ = NULL;   //Sets the right child of the child node to null
		}
	}
	else if (data >= leaf->data_)
	{
		if (leaf->right_ != NULL)
			insert(data, leaf->right_);
		else
		{
			leaf->right_ = current;
			//leaf->right_ = new TreeNode;
			//leaf->right_->data_ = data;
			//leaf->right_->left_ = NULL;  //Sets the left child of the child node to null
			//leaf->right_->right_ = NULL; //Sets the right child of the child node to null
		}
	}
}

void Tree::insert_helper2(TreeNode **node, const int &data)
{
	if (*node == 0)
		*node = new TreeNode(data);
	else
	{
		if ((*node)->data_ > data)
			insert_helper2(&((*node)->left_), data);
		else
		{
			if ((*node)->data_ < data)
				insert_helper2(&((*node)->right_), data);
		}
	}
}
//
//template< typename T >
//void Tree< T >::remove(const T &data)
//{
//	remove_helper(&_root, data);
//}
//
//template< typename T >
//void Tree< T >::remove_helper(TreeNode< T > **node, const T &data)
//{
//	if ((*node)->data_ == data)
//	{
//		TreeNode< T > *del_node = *node;
//
//		if ((*node)->left_ == 0 && (*node)->right_ == 0)
//		{
//			*node = 0;
//
//			delete del_node;
//		}
//		else
//		{
//			if ((*node)->left_ == 0)
//			{
//				*node = (*node)->right_;
//
//				delete del_node;
//			}
//			else
//			{
//				if ((*node)->right_ == 0)
//				{
//					*node = (*node)->left_;
//
//					delete del_node;
//				}
//				else
//				{
//					TreeNode< T > *p = *node;
//					TreeNode< T > *i = (*node)->left_;
//
//					while (i->right_ != 0)
//					{
//						p = i;
//						i = i->right_;
//					}
//
//					*node = i;
//					p->right_ = i->left_;
//					i->right_ = del_node->right_;
//					i->left_ = p;
//
//					delete del_node;
//				}
//			}
//		}
//	}
//	else
//	{
//		if ((*node)->data_ > data)
//			remove_helper(&((*node)->left_), data);
//		else
//		{
//			if ((*node)->data_ < data)
//				remove_helper(&((*node)->right_), data);
//		}
//	}
//}
//
//template< typename T >
//void Tree< T >::pre_order() const
//{
//	pre_order_helper(_root);
//}
//
//template< typename T >
//void Tree< T >::pre_order_helper(TreeNode< T > *node) const
//{
//	if (node != 0)
//	{
//		std::cout << node->data_ << "  ";
//
//		pre_order_helper(node->left_);
//		pre_order_helper(node->right_);
//	}
//}
//
//template< typename T >
//void Tree< T >::in_order() const
//{
//	in_order_helper(_root);
//}
//
//template< typename T >
//void Tree< T >::in_order_helper(TreeNode< T > *node) const
//{
//	if (node != 0)
//	{
//		in_order_helper(node->left_);
//
//		std::cout << node->data_ << "  ";
//
//		in_order_helper(node->right_);
//	}
//}
//
//template< typename T >
//void Tree< T >::post_order() const
//{
//	post_order_helper(_root);
//}
//
//template< typename T >
//void Tree< T >::post_order_helper(TreeNode< T > *node) const
//{
//	if (node != 0)
//	{
//		post_order_helper(node->left_);
//		post_order_helper(node->right_);
//
//		std::cout << node->data_ << "  ";
//	}
//}
//
//template< typename T >
//int Tree< T >::depth() const
//{
//	return depth_helper(_root);
//}
//
//template< typename T >
//int Tree< T >::depth_helper(TreeNode< T > *node) const
//{
//	if (node->left_ == 0 && node->right_ == 0)
//		return 1;
//	else
//	{
//		if (node->left_ == 0)
//			return 1 + depth_helper(node->right_);
//		else
//		{
//			if (node->right_ == 0)
//				return 1 + depth_helper(node->left_);
//			else
//				return 1 + max(depth_helper(node->left_), depth_helper(node->right_));
//		}
//	}
//}
//
//template< typename T >
void Tree::print() const
{
	print_helper(root_, 0);
}
//
//template< typename T >
void Tree::print_helper(TreeNode *node, int spaces) const
{
	while (node != 0)
	{
		print_helper(node->right_, spaces + 5);

		for (int i = 1; i < spaces; ++i)
			std::cout << ' ';

		std::cout << node->data_ << std::endl;

		node = node->left_;
		spaces += 5;
	}
}
//
//template< typename Type >
//Type max(const Type &left, const Type &right)
//{
//	return left > right ? left : right;
//}
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}
//
//
//void pre_order() const;
//void in_order() const;
//void post_order() const;
//
//int depth() const;
//
//void print() const;
