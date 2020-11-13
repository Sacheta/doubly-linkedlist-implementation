//doubly linked list implementation

#include<iostream>
using namespace std;

class node{
public:
    int info;
    node *next;
    node *pre;
};

node *head=nullptr,*tail=nullptr,*ptr;  //declaring globally the head, tail and an arbitrary pointer of node type

void sel(void); //function for selection
void cl(void);  //function for creating of list
void ins(void);  //for inserting node at the start
void inm(void);  //for inserting node in between of the list, after a node
void ine(void);  //for inserting a node at the end
void dels(void);  //for deleting node from the start
void delm(void);  //for deleteting node from between/mid
void dele(void);  //for deleting node from the end
void searchs(void);  //for searching a node using it's info part, starting from start
void searche(void);  //for searching a node using it's info part, starting from end
void display(void);  //for displaying the list

void sel(void){
    int n;
    cin>>n;
    switch(n){
    case 1:
        cl();
        break;
    case 2:
        ins();
        break;
    case 3:
        inm();
        break;
    case 4:
        ine();
        break;
   case 5:
        dels();
        break;
    case 6:
        delm();
        break;
     case 7:
        dele();
        break;
    case 8:
        searchs();
        break;
    case 9:
        searche();
        break;
    default:
        display();

    }
}

void cl(){
    if(head!=nullptr){  //checking if list already created
        cout<<"List already created!"<<endl;
        sel();
        return;
    }
    ptr=new node;  //creating first node
    cout<<"Enter value: ";
    cin>>ptr->info;
    ptr->next=nullptr;
    ptr->pre=nullptr;
    head=ptr;
    tail=ptr;
    cout<<"List created!"<<endl;
    display();
    sel();

}

void display(){  
    if(head==nullptr){  //checking if list is empty
        cout<<"No list!"<<endl;
        return;
    }
    cout<<endl<<"----------------------------------------"<<endl;
    ptr=head;
    while(ptr!=nullptr){
        cout<<ptr->info<<"\t";  //printing the info part
        ptr=ptr->next;
    }
    cout<<endl<<"----------------------------------------"<<endl;
}

void ins(void){  //function for inserting node in the start of pre created list
    if(head==nullptr){  //checking if list been created or not
        cout<<"List not created!"<<endl;
        sel();
        return;
    }  
    ptr=new node;  //creting n inserting the new node in start
    cout<<"Enter value: ";
    cin>>ptr->info;
    ptr->pre=nullptr;
    ptr->next=head;
    head=ptr;
    display();
    sel();
}

void inm(void){  //function for inserting a node in between of the pre existing list
    if(head==nullptr){  //checking whether a list exists or not
        cout<<"No list Found!"<<endl;
        sel();
        return;
    }
    int n;
    cout<<"Enter value after which to insert: ";
    cin>>n;
    ptr=head;
    while(ptr->info!=n&&ptr!=nullptr){  //finding the node after which the user wants to insert the element
        ptr=ptr->next;
        if(ptr==nullptr){
            cout<<"No such node found!"<<endl;  //if no such node found
            sel();
            return;}
    }
    node *add;  //creating and inserting node at its appropriatelocation
    add=new node;
    cout<<"Enter value: ";
    cin>>add->info;
    add->next=ptr->next;  //adjusting all the pointers
    ptr->next->pre=add;
    add->pre=ptr;
    ptr->next=add;
    display();
    sel();
}

void ine(void){  //function to insert in the end of pre existing list
    if(head==nullptr){  //checking if list exists
        cout<<"List not created yet!"<<endl;
        sel();
        return;
    }
    ptr=new node;  //creating and adjusting the node
    cout<<"Enter data: ";
    cin>>ptr->info;
    ptr->next=nullptr;
    ptr->pre=tail;
    tail->next=ptr;
    tail=ptr;
    display();
    sel();
}

void dels(void){  //function for deleting a node from start of pre existing list
    if(head==nullptr){  //if list not created yet
        cout<<"List not created yet!"<<endl;
        sel();
        return;
    }else if(head->next==nullptr){  //if there's only one node
        cout<<head->info<<" wala node being deleted!"<<endl;
        delete(head);  //deleting the head
        free(head);   //freeing up the pre occupied space
        head=nullptr;  
        display();
        sel();
    }
    ptr=head->next;  //if list had more than 1 nodes
    cout<<head->info<<" wala node being deleted!"<<endl;
    delete(head);
    free(head);
    head=ptr;
    head->pre=nullptr;
    display();
    sel();

}

void delm(void){  //function to delete from middle / b/w of the list
    if(head==nullptr){  //if list was empty
        cout<<"List already empty!"<<endl;
        sel();
        return;
    }
    cout<<"Enter value of node to be deleted: ";  
    int n;
    cin>>n;
    ptr=head->next;
    while(ptr->info!=n&&ptr->next!=nullptr)  //accessing the node matching info value to be deleted
        ptr=ptr->next;
    if(ptr->info!=n){  //if no any node having info=n found
        cout<<"No such node found in between head and tail!"<<endl;
        sel();
        return;
    }  
    ptr->pre->next=ptr->next;  //adjusting links before deleting
    ptr->next->pre=ptr->pre;
    delete(ptr);  //deleting the desired node
    free(ptr);  //freeing up space
    display();
    sel();
}

void dele(void){  //function to delete from the end of the pre existing list
    if(head==nullptr){  //checking if list exists or not
        cout<<"List already empty!"<<endl;
        sel();
        return;
    }
    if(head->next==nullptr){  //if only one node eisits in the list
        dels();  //calling the dels function to delete the only node 
        return;
    }
    cout<<tail->info<<" wala node being deleted!"<<endl;
    ptr=tail->pre; //adjusting links before deleting the node
    ptr->next=nullptr;
    delete(tail);  //deleting tail
    free(tail);  //freeing up space
    tail=ptr;  //setting ptr as new tail
    display();
    sel();

}

void searchs(void){  //function to search a node from start, info part of node as key
    if(head==nullptr){  //if list is created or not
        cout<<"List already empty!"<<endl;
        sel();
        return;
    }
    cout<<"Enter data of node to be found: ";
    int t=1,n;
    cin>>n;
    ptr=head;
    while(ptr->info!=n&&ptr->next!=nullptr){  //searching the node
        ptr=ptr->next;
        ++t;
    }
    if(ptr->next==nullptr&&ptr->info!=n)
        cout<<"Not found!"<<endl;  //if not found
    else{
        cout<<"Element found at "<<t<<"th location from start"<<endl;
    }
    sel();

}

void searche(void){  //function to search a node from end, info part of node as key
    if(head==nullptr){  //if list was not created
        cout<<"List already empty!"<<endl;
        sel();
        return;
    }
    cout<<"Enter data of node to be found: ";
    int t=1,n;
    cin>>n;
    ptr=tail;  //setting ptr to tail
    while(ptr->info!=n&&ptr->pre!=nullptr){  //searching from end/tail
        ptr=ptr->pre;
        ++t;
    }
    if(ptr->pre==nullptr&&ptr->info!=n)  //if not found
        cout<<"Not found!"<<endl;
    else{
        cout<<"Element found at "<<t<<"th location from last"<<endl;
    }
    sel();

}

int main(){
    cout<<"Heyyyyyyyyyyyyyyyy, Make selection:"<<endl;
    cout<<"1. Create a list"<<endl;
    cout<<"2. Insert at start"<<endl;
    cout<<"3. Insert in between"<<endl;
    cout<<"4. Insert at end"<<endl;
    cout<<"5. Delete from start"<<endl;
    cout<<"6. Delete from between"<<endl;
    cout<<"7. Delete from end"<<endl;
    cout<<"8. Search from start"<<endl;
    cout<<"9. Search from end"<<endl;
    sel();

}
