#include <iostream>
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

class queuelib{
      node *head,*tail;
      int total;
public:
      queuelib();
      void set_head(node*);
      node* get_head();
      void set_tail(node*);
      node* get_tail();
      void queue_push_back(int);
      void queue_pop_front();
      void queue_traverse();
};

queuelib::queuelib(){
      this->head=NULL;
      this->tail=NULL;
}

void queuelib::set_head(node *nn){
      this->head=nn;
}

node* queuelib::get_head(){
      return this->head;
}

void queuelib::set_tail(node *nn){
      this->tail=nn;
}

node* queuelib::get_tail(){
      return this->tail;
}

void queuelib::queue_push_back(int val){
      node n1;
      node *nn = n1.create_node(val);
      if(get_head()==NULL){
            nn->set_next(NULL);
            nn->set_pre(NULL);
            set_tail(nn);
            set_head(nn);
            total=1;
      }else{
            node *temp=get_head();
            while(temp->get_next()!=NULL){
                  temp=temp->get_next();
            }
            temp->set_next(nn);
            nn->set_pre(temp);
            nn->set_next(NULL);
            set_tail(nn);
            total++;
      }
}

void queuelib::queue_pop_front(){
      node *temp=get_head();

      if(temp==NULL){
            cout<<"Empty queue."<<endl;
      }else{
            set_head(temp->get_next());
            delete(temp);
            total--;
      }
}

void queuelib::queue_traverse(){
      node *temp=get_head();
      if(temp==NULL){
            cout<<"Empty queue."<<endl;
      }else{
            while(temp!=NULL){
                  cout<<"Queue element: "<<temp->get_data()<<endl;
                  temp=temp->get_next();
            }
            cout<<"Total elements: "<<total<<endl;
      }
      cout<<endl;
}
