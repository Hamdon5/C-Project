#include <iostream>
#include <string>

using namespace std;

class MyString{
	private:
	string mainstr;
	int size;
	public:
		MyString();
		MyString(string p);
		~MyString();
		void set(string p);
		int KMPFind(string p,int pos);
		void getNext(string p,int next[]);
		void replace(string p,int pos,int len);
		void print();
	
};

MyString::MyString(){
	mainstr="";
	size=0;
}

MyString::MyString(string p){
	size=p.length();
	mainstr=p;
}

MyString::~MyString(){
	
}

void MyString::getNext(string p,int next[]){
	next[0]=-1;
	next[1]=0;
	int len=p.length();
	int i;
	for (i=1;i<len-1;i++){
		int j=i;
		while (j){
			if (p[next[j]]==p[i]){
				next[i+1]=next[j]+1;
				break;
			}
			else{
				j=next[j];
			}
		}
		
		if (!j){
			next[i+1]=0;
		}
	}
}

int MyString::KMPFind(string p,int pos){
	int i=pos-1,j=0;
	int len=p.length();//save the length of p
	int *kmpnext;
	kmpnext=new int [len];
	getNext(p,kmpnext);
	while (i<size&&j<len){
		if (j<0){
			i++;
			j++;
			continue;
		}
		if (j==-1||mainstr[i]==p[j]){
			i++;
			j++;
		}
		else{
			j=kmpnext[j];
		}
	}
	
	if (j>len-1)
		return i-len+1;
	else 
		return 0;
	
}

void MyString::set(string p){
	mainstr=p;
	size=p.length();
}

void MyString::print(){
	cout<<mainstr<<endl;
}

void MyString::replace(string p,int pos,int len){
	if (!pos){
		return;
	}
	else{
		pos--;
		int p_len=p.length();
		mainstr.replace(pos,len,p);
	}
}

int main(){
	int t;
	string mainstr,p;
	cin>>t;
	int *next;
	while (t--){
		cin>>mainstr>>p;
		int len=p.length();
		next=new int[len];
		MyString ms(mainstr);
		ms.print();
		int pos=ms.KMPFind(p,1);
		cin>>p;
		ms.replace(p,pos,len);
		ms.print();
		delete []next;
	}
	
	
	return 0;
}
