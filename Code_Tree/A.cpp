#include <iostream>
#include <math.h>

using namespace std;
int n;//number of tree

void searchTree(int *num,int pos,int turn){//参数分别为数组、当前位置以及节点中的方向（0为左，1为右） 
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
