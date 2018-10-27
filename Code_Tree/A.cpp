#include <iostream>
#include <math.h>

using namespace std;
int n;//number of tree

void searchTree(int *num,int pos,int turn){//�����ֱ�Ϊ���顢��ǰλ���Լ��ڵ��еķ���0Ϊ��1Ϊ�ң� 
	if (pos>=n)
		return;
	if (num[pos]!=0)
		cout<<num[pos]<<" ";
	searchTree(num,2*pos+1,0);
	if (!turn)
		searchTree(num,pos+1,1);
}
int main(){
	
	int t;
	cin>>t;
	while (t--){
		int *num;
		cin>>n;
		num=new int[n];
		for (int i=0;i<n;i++)
			cin>>num[i];
		searchTree(num,0,1);
		cout<<endl;
		delete[] num;
	}
	return 0;
}
