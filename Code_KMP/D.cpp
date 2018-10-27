#include <iostream>
#include <string>

using namespace std;

int main (){
	int t;
	cin>>t;
	string str;
	while (t--){
		cin>>str;
		int len=str.length();
		int number=0;
		if (len<2){
			cout<<"-1"<<endl;
			continue;
		}
		else{
			int i=0;
			while (i<len){
				int j=i+1;
				while (j<len){
					int temp_num=0;
					if (str[i]!=str[j]){
						j++;
						continue;
					}
					else{
						int savei=i,savej=j;
						while (str[savei]==str[savej]&&savej<len&&savei<j){
							temp_num++;
							savei++;
							savej++;
						}
						if (number<temp_num){
							number=temp_num;
						}
					}
					j++;
				}
				i++;
			}
		}
		if (number)
			cout<<number<<endl;
		else 
			cout<<"-1"<<endl;
	}
	return 0;
}
