#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

//Node Declaration krieny pehly.
struct node{
	int data;
	struct node *next;
}*start;

//start naam ka pointer banya ha pehly ta kay ye head kry.

//Class declaration horhi hai yahn
class Single_Link_List{
	public:
		Single_Link_List(){
			start=NULL;
		}
		//memory allocation ky lye create node krrhy hain
		
		node* create_node(int);
		
		//start me enter krny kay liye
		
		void insert_start();
		
		//apni desrire position me enter krny kay liye
		
		void insert_position();
		
		//lsat me insert krny kay liye
		
		void insert_last();
		
		//delete krny kay liye
		
		void delete_element();
		
		//to sort the node data
		
		void sort();
		
		//to search the node data
		
		void search();
		
		//update kryga , shuru me dalyga stack ki trha
		
		void update();
		
		//reverse the data of node
		
		void reverse();
		
		//display all the elements of nodes
		
		void display();
		
};
//main shuru huga yahn se

main(){
	
	int choice,enter;
	
	//creating objects of class;
	
	Single_Link_List s;
	//assigning the Null value to start
	
	start=NULL;
	
	while(1){
		cout<<"---------------------------------------"<<endl;
		cout<<"Press 1 to Enter Single Link List."<<endl<<endl;
		cout<<"Press 0 to exit ."<<endl;
		cin>>enter;
		if(enter==1){
			break;
		}
		else {
			exit(1);
		}
	}	
	
	while(1){
		
		cout<<endl<<"---------------------------------"<<endl;
		cout<<"Singly Link List"<<endl;
		cout<<endl<<"---------------------------------"<<endl;
		cout<<endl;
		cout<<"1. Insert Node at Start"<<endl;
		cout<<"2. Insert Node in the End"<<endl;
		cout<<"3. Insert Node Where you Want"<<endl;
		cout<<"4. Sort the Link List Data"<<endl;
		cout<<"5. Delete Node a Specific Node"<<endl;
		cout<<"6. Update Your Node"<<endl;
		cout<<"7. Search Your Node Data"<<endl;
		cout<<"8. Display Your Node Data"<<endl;
		cout<<"9. Reverse Your Data"<<endl;
		cout<<"10. EXIT"<<endl;
		cout<<endl<<"Enter Your Choice :"<<endl;
		cin>>choice;
		cout<<endl;
		switch(choice){
			case 1:
			cout<<"Node will be Insert Soon in the Start :"<<endl;
			cout<<"---------------------------------"<<endl;
			s.insert_start();
			break;
			
			case 2:
				cout<<"Node will be Insert in the Last :"<<endl;
				cout<<"--------------------------------"<<endl;
				s.insert_last();
				break;
			case 3:
				cout<<"Node will be insert in your Desire Positon :"<<endl;
				cout<<"----------------------------------"<<endl;
				s.insert_position();
				break;

			case 4:
				cout<<"Node will be Sorted :"<<endl;
				cout<<"----------------------------------"<<endl;
				s.sort();
				break;


			case 5:
				cout<<"Node will be Deleted of your Desire Positon :"<<endl;
				cout<<"----------------------------------"<<endl;
				s.delete_element();
				break;


			case 6:
				cout<<"Node will be Updated :"<<endl;
				cout<<"----------------------------------"<<endl;
				s.update();
				break;


			case 7:
				cout<<"Node will Search element, According to Your desire Value:"<<endl;
				cout<<"----------------------------------"<<endl;
				s.search();
				break;


			case 8:
				cout<<"Node will be Display :"<<endl;
				cout<<"----------------------------------"<<endl;
				s.display();
				break;

			case 9:
				cout<<"Node will be Reversed :"<<endl;
				cout<<"----------------------------------"<<endl;
				s.reverse();
				break;


			case 10:
				cout<<"Terminating :======================"<<endl;
				cout<<"----------------------------------"<<endl;
				exit(1);
				break;
				
			default:
				cout<<"Access Denied!";
		}
	}
		
		
	
}

//allocating / Creating Node

node *Single_Link_List::create_node(int val){
	
	struct node *temp;
	
	//Allocating Memory
	
	temp=new(struct node);
	if(temp==NULL){
		cout<<endl<<"Memory Not Allocated : ";
		return 0;
	}
	else
	{
		//start kay data me wo value aygi then uska next Null hujyega
		
		temp->data=val;
		
		temp->next=NULL;
	}
	
}

//Inserting IN BEGINNING

void Single_Link_List::insert_start(){
	
	int insert;
	
	cout<<endl<<"Enter Your Value =";
	
	cin>>insert;
	
	struct node *temp, *pos;
	
	temp=create_node(insert);
	
	if(start == NULL){
		//agr list khali hu tou wo value chly jaye whn then next null hujaye
		
		start= temp;
		start->next= NULL;
	}
	else{
		//wrna pos me start ki value ajaye
		pos=start;
		
		//aur start me jo abhi enter ki ha wo ajaye
		start=temp;
		
		//aur start kay next me wo ajayw jo pehly tha start me
		start->next= pos;
	}
	cout<<endl<<"Data has been Inserted!";
	
}
//Insert in the End
void Single_Link_List::insert_last(){
	
	int val;
	cout<<endl<<"Enter Value to add in the End of the Node :";
	cin>>val;
	
	struct node *temp ,*s;
	
	s=start;
	while(s->next!=NULL){
		s=s->next;
	}
	s->next=temp;
	temp->next=NULL;
	
	cout<<endl<<"Element has been Inserted in the Last ";
	
	
	
}

//Insert at given Positon

void Single_Link_List::insert_position(){
	
	int i,val,pos,count=0;
	
	cout<<endl<<"Enter Value  to add Data in Node : ";
	cin>>val;
	
	struct node *temp,*ptr,*s;
	
	temp=create_node(val);
	
	cout<<endl<<"Enter Position :";
	cin>>pos;
	
	s=start;
	
	while(s!=NULL){
		//ye pura node chalyega end tk aur count++ huga
		s=s->next;
		count++;
		
	}
	
	if(pos==1){
		
		if(start == NULL){
			//agr null hu tou jo enter hwe jo ajeyga isme

		
			start=temp;
			start->next= NULL;
		}
		else{
			//ptr pointer me start ki value ajayega
			ptr=start;
			//aur start me enter value
			start=temp;
			//enter value ki next me start wali purani value ajeygi
			
			start->next=ptr;
			
		}
		//agr position 1 se zyada hu jahn enter krni hai value aur count se bari na hu
	}
		else if(pos>1 && pos<=count){
			s=start;
			for(i=1;i<pos;i++){
				//ptr me wo value ajaye
				ptr=s;
//				aur wo change huti rhy s ki value end tk
				s=s->next;
			}
			//ptr me jo value value aye ha update hu kr usky next me temp wali ajaye
			ptr->next=temp;
			//aur temp kay next me purany last value
			temp->next=s;
			
			
		}
		else{
			cout<<endl<<"Position Range se Bahir :";
		}
		
	}
//sorting List
void Single_Link_List::sort(){
	
	struct node *ptr ,*s;
	int value;
	//agr null hwe to ajeyga kay empty hai
	
	if(start == NULL){
		cout<<endl<<"Cant be Sort,The List is Empty";
		return ;
	}
	
	ptr	=start;
	
	while(ptr!=NULL){
		
		for(s=ptr->next;s!=NULL; s=s->next){
			
			if(ptr->data > s->data ){
				value=ptr->data;
				ptr->data=s->data;
				s->data=value;
			}
			
			
		}
		ptr=ptr->next;
		
	}
	
}
//Deleting a specific Node
void Single_Link_List::delete_element(){
	
	int pos,i,count=0;
	if(start == NULL){
		cout<<endl<<"Cant be Delete,given List is Empty :";
		return;
	}
	
	cout<<endl<<"Enter Position to delete Element form there :";
	cin>>pos;
	
	struct node *ptr, *s;
	
	//start ka s me ajeyga
	
	s=start;
	if(pos == 1){
		s=s->next;
	}
	else{
		while(s!=NULL){
			s=s->next;
			count++;
		}
		
		if(pos>0 && pos<=count){
			s=start;
			for(i=1;i<pos;i++){
				//jhn tk position ha whn tk chly ga phr khtm loop
				ptr=s;
				s=s->next;
			
			}
			//no data set ka next huga usme usky next ka next ajaye tou pechla delete hujayega
			
			ptr->next=s->next;
			
			
		}
		else{
			cout<<endl<<"Range se Bahir Delete Krhy hu ap!";
		}
		free(s);
		cout<<endl<<"Element has been Deleted!";
		
		
		
		
	}
}
//Update Your Node

void Single_Link_List::update(){
	
	int value,pos,i;
	if(start == NULL){
		cout<<endl<<"List is Empty :";
		return;
		
	}
	cout<<endl<<"Enter Your Position to delete data :";
	cin>>pos;
	cout<<endl<<"Enter Your Value to update the List :";
	cin>>value;
	
	struct node *s , *ptr ;
	
	s=start;
	if(pos == 1){
		//agr one pr hi krna hu update tou direct start kay next me value daldengy
		start->data=value;
	}
	//wrna update kriengy position kay hisab se
	
	else
	
	{
		for(i=0;i<pos;i++){
			
			if(s == NULL){
				cout<<endl<<"There are less than"<<pos;
				return;
			}
			//s me update hujaye start ki next value jhn tk positon hai usey ik pehly
			
			s=s->next;
		}
		s->data=value;
	}
	cout<<endl<<"Node has been updated Successfully";
}
//searching your data in list
void Single_Link_List::search(){
	
	int value,pos=0;
	
	bool flag = false;
	
	if(start == NULL){
		cout<<endl<<"List is empty,cant be search!";
		return;
	}
	cout<<endl<<"Enter Value to Search in List :";
	cin>>value;
	
	struct node *s;
	s=start;
	
	while(s!= NULL){
		pos++;
		
		//agr mil gyi value tou flag ture aur exit program
		if(s->data == value){
			flag = true;
			cout<<endl<<"Searched"<<value<<"At"<<pos;
		}
		//yhn se update hugi value
		
		s=s->next;
		
	}
	//wrna nh milay kyu kay hai e nh list me
	
	if(!flag){
		cout<<endl<<"Searched Element cant be Found!";
		return;
	}
	
	cout<<endl<<"List has been Updated!";
}

//To reverse Your List
void Single_Link_List::reverse(){
	
	struct node *ptr1, *ptr2, *ptr3;
	
	if(start == NULL){
		cout<<endl<<"List cant be reversed because its Empty!";
		return;
	}
	//agr start kay bd nect huga tou end program
	
	if(start->next == NULL){
		return;
	}


	 //below all are assumptions
	 
	ptr1=start; // ptr1=a 
	ptr2 = ptr1->next; // ptr2=b;
	ptr3=ptr2->next; // ptr3 =c ;
	ptr1->next=NULL; //b=null ;
	ptr2->next=ptr1;  //ptr2=c
	 
	 while(ptr3!= NULL){
	 	ptr1=ptr2; //a=b;
	 	ptr2=ptr3; //b=c;
	 	ptr3=ptr3->next; //c=d;
	 	
	 }
	 start=ptr2;
	 cout<<endl<<"Node has been Reversed!";
	
}

//dispplay your Node List
void Single_Link_List::display(){
	
	struct node *elemnt;
	if(start == NULL){
		
		cout<<endl<<"Cant be display because the given list is empty!";
		return;
	}
	
	elemnt=start;
	
	cout<<endl<<"Data of Your List :"<<endl;
	
	while(elemnt !=NULL)
	{
		cout<<elemnt->data<<" -> ";
		 elemnt=elemnt->next;
		
		}
		cout<<endl<<"NULL"<<endl;
}