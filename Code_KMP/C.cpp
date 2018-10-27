#include <iostream>
#include <string>
using namespace std;

string matched_Prefix_Postfix(string str){
	int len=str.length();
	if (len<2){
		return "";
	}
	
	else{
		int pos_front=len+1,pos_next=len+1,i;
		for (i=1;i<len;i++){
			if (str[0]==str[i]){
				pos_next=i+1;
				break;
			}
		}
		for (i=len-2;i>=0;i--){
			if (str[len-1]==str[i]){
				pos_front=i+1;
				break;
			}
		}
		
		if (pos_front>len||pos_next>len){
			return "";
		}
		
		while (pos_front<pos_next){
			pos_front++;
			pos_next--;
		}
		int len_min=pos_front>pos_next?pos_next:pos_front;
		while (len_min){
			int tag=1;
			for (i=0;i<len_min;i++){
				if (str[i]!=str[len-len_min+i]){
					tag=0;
					break;
				}
			}
			if (tag)
				return str.substr(0,len_min);
			else
				len_min--;
		}
		return "";
	}
}
int main (){
	int t;
	string str;
	cin>>t;
	while (t--){
		cin>>str;
		string result=matched_Prefix_Postfix(str);
		if (result=="")
			cout<<"empty"<<endl;
		else
			cout<<result<<endl;
	}
	return 0;
}
