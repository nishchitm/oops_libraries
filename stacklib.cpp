#include<iostream>
using namespace std;

class node{
      int data;
      node *next;
      node *pre;
public:
      node();
      node(int);
      node* create_node(int);
      void set_data(int);
      int get_data();
      void set_next(node*);
      node* get_next();
      void set_pre(node*);
      node* get_pre();
};

node::node(){
      this->data = 0;
      this->next = NULL;
      this->pre = NULL;
}

node::node(int val){
      this->data = val;
      this->next = NULL;
      this->pre = NULL;
}

node* node::create_node(int val){
      node *nn = new node(val);
      return nn;
}

void node::set_data(int val){
      this->data=val;
}

int node::get_data(){
      return this->data;
}

void node::set_next(node *nn){
      this->next=nn;
}

node* node::get_next(){
      return this->next;
}

void node::set_pre(node *nn){
      this->pre=nn;
}

node* node::get_pre(){
      return this->pre;
}

class stacklib{
      node *top;
      int total;
public:
      stacklib();
      void set_top(node*);
      node* get_top();
      void stack_push(int);
      void stack_pop();
      void stack_traverse();
      void stack_seek(int);
};

stacklib::stacklib(){
      this->top=NULL;
}

void stacklib::set_top(node *nn){
      this->top=nn;
}

node* stacklib::get_top(){
      return this->top;
}

void stacklib::stack_push(int val){
      node n1;
      node *nn = n1.create_node(val);
      if(get_top()==NULL){
            nn->set_next(NULL);
            nn->set_pre(NULL);
            set_top(nn);
            total=1;
      }else{
            node *temp = get_top();
            temp->set_next(nn);
            nn->set_pre(temp);
            nn->set_next(NULL);
            set_top(nn);
            total++;
      }
      cout<<endl;
}

void stacklib::stack_pop(){
      node *temp = get_top();
      node *po;
      if(temp==NULL){
            cout<<"Empty stack."<<endl;
      }else{
            total--;
            po=temp;
            temp=temp->get_pre();
            set_top(temp);
            delete(po);
      }
      cout<<endl;
}

void stacklib::stack_seek(int val){
      node *temp=get_top();
      int flag=0,pos=total;
      if(temp==NULL){
            cout<<"Empty stack."<<endl;
      }else{
            while(temp!=NULL){
                  pos--;
                  if(temp->get_data()==val){
                        flag=1;
                        break;
                  }
                  temp=temp->get_pre();
            }
            if(flag==1){
                  cout<<"Found element at: "<<pos<<endl;
            }else{
                  cout<<"Element not found."<<endl;
            }
      }
      cout<<endl;
}

void stacklib::stack_traverse(){
      node *temp=get_top();
      if(temp==NULL){
            cout<<"Empty stack."<<endl;
      }else{
            while(temp!=NULL){
                  cout<<"Stack element: "<<temp->get_data()<<endl;
                  temp=temp->get_pre();
            }
            cout<<"Total nodes: "<<total<<endl;
      }
      cout<<endl;
}
