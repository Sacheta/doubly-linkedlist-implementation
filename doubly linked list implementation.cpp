//doubly linked list implementation

#include<iostream>
using namespace std;

class node{
public:
    int info;
    node *next;
    node *pre;
};

node *head=nullptr,*tail=nullptr,*ptr;

void sel(void);
void cl(void);
void ins(void);
void inm(void);
void ine(void);
void dels(void);
void delm(void);
void dele(void);
void searchs(void);
void searche(void);
void display(void);

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
    if(head!=nullptr){
        cout<<"List already created!"<<endl;
        sel();
        return;
    }
    ptr=new node;
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
    if(head==nullptr){
        cout<<"No list!"<<endl;
        return;
    }
    cout<<endl<<"----------------------------------------"<<endl;
    ptr=head;
    while(ptr!=nullptr){
        cout<<ptr->info<<"\t";
        ptr=ptr->next;
    }
    cout<<endl<<"----------------------------------------"<<endl;
}

void ins(void){
    if(head==nullptr){
        cout<<"List not created!"<<endl;
        sel();
        return;
    }
    ptr=new node;
    cout<<"Enter value: ";
    cin>>ptr->info;
    ptr->pre=nullptr;
    ptr->next=head;
    head=ptr;
    display();
    sel();
}

void inm(void){
    if(head==nullptr){
        cout<<"No list Found!"<<endl;
        sel();
        return;
    }
    int n;
    cout<<"Enter value after which to insert: ";
    cin>>n;
    ptr=head;
    while(ptr->info!=n&&ptr!=nullptr){
        ptr=ptr->next;
        if(ptr==nullptr){
            cout<<"No such node found!"<<endl;
            sel();
            return;}
    }
    node *add;
    add=new node;
    cout<<"Enter value: ";
    cin>>add->info;
    add->next=ptr->next;
    ptr->next->pre=add;
    add->pre=ptr;
    ptr->next=add;
    display();
    sel();
}

void ine(void){
    if(head==nullptr){
        cout<<"List not created yet!"<<endl;
        sel();
        return;
    }
    ptr=new node;
    cout<<"Enter data: ";
    cin>>ptr->info;
    ptr->next=nullptr;
    ptr->pre=tail;
    tail->next=ptr;
    tail=ptr;
    display();
    sel();
}

void dels(void){
    if(head==nullptr){
        cout<<"List not created yet!"<<endl;
        sel();
        return;
    }else if(head->next==nullptr){
        cout<<head->info<<" wala node being deleted!"<<endl;
        delete(head);
        free(head);
        head=nullptr;
        display();
        sel();
    }
    ptr=head->next;
    cout<<head->info<<" wala node being deleted!"<<endl;
    delete(head);
    free(head);
    head=ptr;
    head->pre=nullptr;
    display();
    sel();

}

void delm(void){
    if(head==nullptr){
        cout<<"List already empty!"<<endl;
        sel();
        return;
    }
    cout<<"Enter value of node to be deleted!"<<endl;
    int n;
    cin>>n;
    ptr=head->next;
    while(ptr->info!=n&&ptr->next!=nullptr)
        ptr=ptr->next;
    if(ptr->info!=n){
        cout<<"No such node found in between head and tail!"<<endl;
        sel();
        return;
    }
    ptr->pre->next=ptr->next;
    ptr->next->pre=ptr->pre;
    delete(ptr);
    free(ptr);
    display();
    sel();
}

void dele(void){
    if(head==nullptr){
        cout<<"List already empty!"<<endl;
        sel();
        return;
    }
    if(head->next==nullptr){
        dels();
        return;
    }
    cout<<tail->info<<" wala node being deleted!"<<endl;
    ptr=tail->pre;
    tail->pre->next=nullptr;
    delete(tail);
    free(tail);
    tail=ptr;
    display();
    sel();

}

void searchs(void){
    if(head==nullptr){
        cout<<"List already empty!"<<endl;
        sel();
        return;
    }
    cout<<"Enter data of node to be found: ";
    int t=1,n;
    cin>>n;
    ptr=head;
    while(ptr->info!=n&&ptr->next!=nullptr){
        ptr=ptr->next;
        ++t;
    }
    if(ptr->next==nullptr&&ptr->info!=n)
        cout<<"Not found!"<<endl;
    else{
        cout<<"Element found at "<<t<<"th location from start"<<endl;
    }
    sel();

}

void searche(void){
    if(head==nullptr){
        cout<<"List already empty!"<<endl;
        sel();
        return;
    }
    cout<<"Enter data of node to be found: ";
    int t=1,n;
    cin>>n;
    ptr=tail;
    while(ptr->info!=n&&ptr->pre!=nullptr){
        ptr=ptr->pre;
        ++t;
    }
    if(ptr->pre==nullptr&&ptr->info!=n)
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
