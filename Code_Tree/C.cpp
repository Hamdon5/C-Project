#include <iostream>
#include <string>
using namespace std;
int counter;

class BiTreeNode{
	public:
		char data;//节点数据
		BiTreeNode *LeftChild;//左子树指针
		BiTreeNode *RightChild;//右子树指针
		BiTreeNode():LeftChild(NULL),RightChild(NULL){}
		~BiTreeNode(){}
};

class BiTree{
	private:
		BiTreeNode *Root;//根节点指针
		int pos;
		string strTree;
		BiTreeNode* CreateBiTree();
		void PreOrder(BiTreeNode* t);
		void InOrder(BiTreeNode* t);
		void PostOrder(BiTreeNode* t);	
	public:
		BiTree(){
		}
		~BiTree(){
		}
		
		void CreateTree(string TreeArray);//运用先序遍历结果创建二叉树 
		void PreOrder();//前序遍历 
		void InOrder();//中序遍历 
		void PostOrder();//后序遍历 
};

void BiTree::CreateTree(string TreeArray){//共有函数，对外接口 
	pos=0;
	strTree.assign(TreeArray);
	Root=CreateBiTree();
}

BiTreeNode* BiTree::CreateBiTree(){//递归建树，私有函数，类内实现
	
	 BiTreeNode *T;
	 char ch;
	 ch=strTree[pos++];
	 if (ch=='0')
	 	T=NULL;
	
	else{
		T=new BiTreeNode();
		T->data=ch;//生成根节点 
		T->LeftChild=CreateBiTree();//构造左子树 
		T->RightChild=CreateBiTree();//构造右子树 
	}
	return T;
	
}

//公共函数接口的实现 
void BiTree::PreOrder(){
	PreOrder(Root);
}

void BiTree::InOrder(){
	InOrder(Root);
}

void BiTree::PostOrder(){
	PostOrder(Root);
}

//私有函数的接口的实现
void BiTree::PreOrder(BiTreeNode* t){
	if (t){
//		cout<<t->data;//输出数据，表示已经访问过了
		if (t->LeftChild==NULL&&t->RightChild==NULL)
			counter++;
		PreOrder(t->LeftChild);//先序遍历左孩子
		PreOrder(t->RightChild);//先序遍历右孩子 
	}
}

void BiTree::InOrder(BiTreeNode* t){
	if (t){
		InOrder(t->LeftChild);//中序遍历左孩子
		cout<<t->data;//输出数据，表示已经访问过了
		InOrder(t->RightChild);//中序遍历右孩子 
	}
}

void BiTree::PostOrder(BiTreeNode* t){
	if (t){
		PostOrder(t->LeftChild);//后序遍历左孩子
		PostOrder(t->RightChild);//后序遍历右孩子 
		cout<<t->data;//输出数据，表示已经访问过了
	}
}
int main(){
	 
	 int t;
	 string strTree;
	 cin>>t;
	 while (t--){
	 	counter=0;//计数器清零 
	 	cin>>strTree;
	 	BiTree bi;
	 	bi.CreateTree(strTree);
	 	bi.PreOrder();
	 	cout<<counter<<endl;
	 	
	 }
	 return 0;
} 
