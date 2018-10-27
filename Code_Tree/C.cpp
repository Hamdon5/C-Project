#include <iostream>
#include <string>
using namespace std;
int counter;

class BiTreeNode{
	public:
		char data;//�ڵ�����
		BiTreeNode *LeftChild;//������ָ��
		BiTreeNode *RightChild;//������ָ��
		BiTreeNode():LeftChild(NULL),RightChild(NULL){}
		~BiTreeNode(){}
};

class BiTree{
	private:
		BiTreeNode *Root;//���ڵ�ָ��
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
		
		void CreateTree(string TreeArray);//������������������������ 
		void PreOrder();//ǰ����� 
		void InOrder();//������� 
		void PostOrder();//������� 
};

void BiTree::CreateTree(string TreeArray){//���к���������ӿ� 
	pos=0;
	strTree.assign(TreeArray);
	Root=CreateBiTree();
}

BiTreeNode* BiTree::CreateBiTree(){//�ݹ齨����˽�к���������ʵ��
	
	 BiTreeNode *T;
	 char ch;
	 ch=strTree[pos++];
	 if (ch=='0')
	 	T=NULL;
	
	else{
		T=new BiTreeNode();
		T->data=ch;//���ɸ��ڵ� 
		T->LeftChild=CreateBiTree();//���������� 
		T->RightChild=CreateBiTree();//���������� 
	}
	return T;
	
}

//���������ӿڵ�ʵ�� 
void BiTree::PreOrder(){
	PreOrder(Root);
}

void BiTree::InOrder(){
	InOrder(Root);
}

void BiTree::PostOrder(){
	PostOrder(Root);
}

//˽�к����Ľӿڵ�ʵ��
void BiTree::PreOrder(BiTreeNode* t){
	if (t){
//		cout<<t->data;//������ݣ���ʾ�Ѿ����ʹ���
		if (t->LeftChild==NULL&&t->RightChild==NULL)
			counter++;
		PreOrder(t->LeftChild);//�����������
		PreOrder(t->RightChild);//��������Һ��� 
	}
}

void BiTree::InOrder(BiTreeNode* t){
	if (t){
		InOrder(t->LeftChild);//�����������
		cout<<t->data;//������ݣ���ʾ�Ѿ����ʹ���
		InOrder(t->RightChild);//��������Һ��� 
	}
}

void BiTree::PostOrder(BiTreeNode* t){
	if (t){
		PostOrder(t->LeftChild);//�����������
		PostOrder(t->RightChild);//��������Һ��� 
		cout<<t->data;//������ݣ���ʾ�Ѿ����ʹ���
	}
}
int main(){
	 
	 int t;
	 string strTree;
	 cin>>t;
	 while (t--){
	 	counter=0;//���������� 
	 	cin>>strTree;
	 	BiTree bi;
	 	bi.CreateTree(strTree);
	 	bi.PreOrder();
	 	cout<<counter<<endl;
	 	
	 }
	 return 0;
} 
