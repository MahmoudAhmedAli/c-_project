#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void insert(){
	char name[30] , phone[30] , id[30];
	ofstream data;
	data.open("ttest.txt",ios::app);
	cout<<"please enter name , phone , id"<<endl;
	cin.ignore() ;
	cout<<"name : ";
	cin.getline(name,30);
	cout<<"phone : ";
	cin.getline(phone,30);
	cout<<"id : ";
	cin.getline(id,30);
	data<<name<<'|'<<phone<<'|'<<id<<endl;
	data.close() ;   
}
void display(){
		char name[30] , phone[30] , id[30];
	ifstream data;
	data.open("ttest.txt",ios::app);
	while(!data.eof() ){
		data.getline(name,30,'|');
		data.getline(phone,30,'|');
		data.getline(id,30);
		cout<<name<<'|'<<phone<<'|'<<id<<endl;   
	}
}
void update(){
	char name[30] , phone[30] , id[30] , x[30];
	fstream data;
	fstream temp;
	data.open("ttest.txt",ios::in);
	temp.open("temp.txt",ios::out);
	cin.ignore() ;
	cout<<"please enter name to update"<<endl;
	cin.getline(x,30);
	while(!data.eof()){
		data.getline(name,30,'|');
		data.getline(phone,30,'|');
		data.getline(id,30);
		if(strcmp(name,x)==0){
			cout<<"enter new values"<<endl;
		cout<<"name : ";
		cin.getline(name,30);
		cout<<"phone : ";
		cin.getline(phone,30);
		cout<<"id : ";
		cin.getline(id,30);
		temp<<name<<'|'<<phone<<'|'<<id<<endl;
		}else{
	
		temp<<name<<'|'<<phone<<'|'<<id<<endl;
	}
	
	}  
	temp.close() ;
	data.close() ;
	
	data.open("ttest.txt",ios::out);
	temp.open("temp.txt",ios::in);
	while(!temp.eof() ){
		temp.getline(name,30,'|');
		temp.getline(phone,30,'|');
		temp.getline(id,30);
		data<<name<<'|'<<phone<<'|'<<id<<endl;
		} 
			temp.close() ;
			data.close() ;
			remove("temp.txt");	
}
void delete_record(){
	char name[30] , phone[30] , id[30] , x[30];
	fstream data;
	fstream temp;
	data.open("ttest.txt",ios::in);
	temp.open("temp.txt",ios::out);
	cin.ignore() ;
	cout<<"please enter name to delete"<<endl;
	cin.getline(x,30);
	while(!data.eof()){
		data.getline(name,30,'|');
		data.getline(phone,30,'|');
		data.getline(id,30);
		if(strcmp(name,x)==0){
		continue;
		}else{
	
		temp<<name<<'|'<<phone<<'|'<<id<<endl;
	}
	
	}  
	temp.close() ;
	data.close() ;
	
	data.open("ttest.txt",ios::out);
	temp.open("temp.txt",ios::in);
	while(!temp.eof() ){
		temp.getline(name,30,'|');
		temp.getline(phone,30,'|');
		temp.getline(id,30);
		data<<name<<'|'<<phone<<'|'<<id<<endl;
		} 
			temp.close() ;
			data.close() ;
			remove("temp.txt");	
}
	
	






int main(){
	int x;
	bool flag = true;
	while(flag){
		cout<<"############ welcome ########"<<endl;
		cout<<"to insert press 1 "<<endl;
		cout<<"to display press 2 "<<endl;
		cout<<"to delete press 3 "<<endl;
		cout<<"to update press 4 "<<endl;
		cin>>x;
		switch(x){
			case 1 :
				insert();
					break;			
			case 2	:
				display();
					break;
			case 3 :
				delete_record();
					break; 
			case 4 :
				update();
					break;			
				
		}
			cout<<"to continue press 'y'"<<endl;
			char f;
			cin>>f;
			if(f!='y')
			flag=false;
	}
			return 0;
}
