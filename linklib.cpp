#include <iostream>
#include <stdlib.h>
using namespace std;

int main_menu();

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
      node *get_next();
      void set_pre(node*);
      node *get_pre();
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
      node *nn;
      nn = new node(val);
      return nn;
}

void node::set_data(int val){
      this->data = val;
}

int node::get_data(){
      return data;
}

void node::set_next(node *nn){
      this->next = nn;
}

node* node::get_next(){
      return this->next;
}

void node::set_pre(node *nn){
      this->pre = nn;
}

node* node::get_pre(){
      return this->pre;
}

class linkedlist{
      node *start;
      node *last;
      node *ptr;
public:
      int count;
      linkedlist();
      void set_start(node*);
      node* get_start();
      void set_last(node*);
      node* get_last();
      void ll_add_node_start(int);
      void ll_add_node_before_value(int,int);
      void ll_add_node_after_value(int,int);
      void ll_add_node_at_position(int,int);
      void ll_add_node_last(int);
      void ll_search_node_value(int);
      void ll_search_node_position(int);
      void ll_delete_node_value(int);
      void ll_delete_node_position(int);
      void ll_clear_node();
      void ll_reverse_node();
      void ll_swap(int,int);
      void ll_traverse_node();
};

linkedlist::linkedlist(){
      this->start = NULL;
      this->last = NULL;
}

void linkedlist::set_start(node *nn){
      this->start = nn;
}

node* linkedlist::get_start(){
      return this->start;
}

void linkedlist::set_last(node* nn){
      this->last = nn;
}

node* linkedlist::get_last(){
      return this->last;
}

void linkedlist::ll_add_node_start(int val){
      node n1;
      node *nn = n1.create_node(val);
      if(get_start()==NULL){
            set_start(nn);
            set_last(nn);
      }else{
            node *temp;
            temp=get_start();
            nn->set_pre(NULL);
            nn->set_next(temp);
            temp->set_pre(nn);
      }
}

void linkedlist::ll_add_node_before_value(int val,int pos){
      node n1;
      int flag=0;
      node *nn = n1.create_node(val);
      if(get_start()==NULL){
            set_start(nn);
            set_last(nn);
      }else{
            node *temp,*preTemp;
            temp=get_start();
            while(temp->get_next()!=NULL){
                  if(temp->get_data()==pos){
                        flag=1;
                        break;
                  }
                  temp=temp->get_next();
            }
            if(flag==0){
                  cout<<"Value not found to add before."<<endl;
            }else{
                  preTemp=temp->get_pre();
                  preTemp->set_next(nn);
                  nn->set_pre(preTemp);
                  nn->set_next(temp);
                  temp->set_pre(nn);
            }
      }
}

void linkedlist::ll_add_node_after_value(int val,int pos){
      node n1;
      int flag=0;
      node *nn = n1.create_node(val);
      if(get_start()==NULL){
            set_start(nn);
            set_last(nn);
      }else{
            node *temp,*preTemp;
            temp=get_start();
            while(temp->get_next()!=NULL){
                  if(temp->get_data()==pos){
                        flag=1;
                        break;
                  }
                  temp=temp->get_next();
            }
            if(flag==0){
                  cout<<"Value not found to add before."<<endl;
            }else{
                  if(temp->get_next()==NULL){
                        nn->set_next(NULL);
                  }else{
                        preTemp=temp->get_next();
                        nn->set_next(preTemp);
                        preTemp->set_pre(nn);
                  }
                  temp->set_next(nn);
                  nn->set_pre(temp);
            }
      }
}

void linkedlist::ll_add_node_at_position(int val,int pos){
      node n1;
      int flag=0;
      node *nn = n1.create_node(val);
      if(get_start()==NULL){
            set_start(nn);
            set_last(nn);
      }else{
            if(pos>count){
                  cout<<"Position doesn't exists."<<endl;
            }else{
                  node *temp,*preTemp;
                  temp=get_start();
                  int i=1;
                  while(i<pos && temp->get_next()!=NULL){
                        temp=temp->get_next();
                        i++;
                  }
                  if(temp->get_next()==NULL){
                        nn->set_next(NULL);
                  }else{
                        preTemp = temp->get_next();
                        nn->set_next(preTemp);
                        preTemp->set_pre(nn);
                  }
                  temp->set_next(nn);
                  nn->set_pre(temp);
            }
      }
}

void linkedlist::ll_add_node_last(int val){
      node n1;
      node *nn = n1.create_node(val);
      if(get_start()==NULL){
            set_start(nn);
            set_last(nn);
      }else{
            node *temp;
            temp=get_start();
            while(temp->get_next()!=NULL){
                  temp=temp->get_next();
            }
            temp->set_next(nn);
            nn->set_pre(temp);
            set_last(nn);
      }
}

void linkedlist::ll_search_node_value(int val){
      node *temp = get_start();
      int flag=0,pos=0;
      if(temp==NULL){
            cout<<"Empty list.";
      }else{
            while(temp!=NULL){
                  if(temp->get_data()==val){
                        flag=1;
                        break;
                  }
                  pos++;
                  temp=temp->get_next();
            }
            if(flag==1){
                  cout<<"Item found at position: "<<pos<<".";
            }else{
                  cout<<"Item not found";
            }
            cout<<endl;
      }
}

void linkedlist::ll_search_node_position(int pos){
      node *temp = get_start();
      int flag=0,yo=1;
      if(pos>count){
            cout<<"Position doesn't exists."<<endl;
      }else{
            if(temp==NULL){
                  cout<<"Empty list.";
            }else{
                  while(yo<pos){
                        temp=temp->get_next();
                        yo++;
                  }
                  cout<<"Item at position "<<pos<<" is: "<<temp->get_data()<<".";
            }
            cout<<endl;
      }
}

void linkedlist::ll_delete_node_value(int val){
      node *temp=get_start();
      int flag=0;
      if(temp==NULL){
            cout<<"Empty list."<<endl;
      }else{
            node *preTemp,*postTemp;
            while(temp->get_next()!=NULL){
                  if(temp->get_data()==val){
                        flag=1;
                        break;
                  }
                  temp=temp->get_next();
            }
            if(flag==0){
                  cout<<"Value not found."<<endl;
            }else{
                  preTemp = temp->get_pre();
                  postTemp = temp->get_next();
                  preTemp->set_next(postTemp);
                  postTemp->set_pre(preTemp);
                  delete(temp);
            }
      }
}

void linkedlist::ll_delete_node_position(int pos){
      if(pos>count){
            cout<<"Position doesn't exists."<<endl;
      }else{
            node *temp=get_start();
            int flag=0,i=0;
            if(temp==NULL){
                  cout<<"Empty list."<<endl;
            }else{
                  node *preTemp,*postTemp;
                  while(temp->get_next()!=NULL){
                        if(i==pos){
                              flag=1;
                              break;
                        }
                        i++;
                        temp=temp->get_next();
                  }
                  if(flag==0){
                        cout<<"Value not found."<<endl;
                  }else{
                        preTemp = temp->get_pre();
                        postTemp = temp->get_next();
                        preTemp->set_next(postTemp);
                        postTemp->set_pre(preTemp);
                        delete(temp);
                  }
            }
      }
}

void linkedlist::ll_clear_node(){
      node *temp,*ptemp;
      temp=get_start();
      while(temp!=NULL){
            ptemp=temp;
            temp=temp->get_next();
            delete(ptemp);
      }
      cout<<"List Empty."<<endl;
}

void linkedlist::ll_reverse_node(){
      node *temp,*end;
      int val;
      temp=get_start();
      end=get_last();
      for(int i=0;i<(count/2);i++){
            val=temp->get_data();
            temp->set_data(end->get_data());
            end->set_data(val);
            temp=temp->get_next();
            end=end->get_pre();
      }
}

void linkedlist::ll_swap(int val,int new_val){
      node *temp = get_start();
      int flag=0;
      if(temp==NULL){
            cout<<"Empty list."<<endl;
      }else{
            while(temp!=NULL){
                  if(temp->get_data()==val){
                        flag=1;
                        break;
                  }
                  temp=temp->get_next();
            }
            if(flag==1){
                  temp->set_data(new_val);
            }else{
                  cout<<"Value not found."<<endl;
            }
      }
      cout<<endl;
}

void linkedlist::ll_traverse_node(){
      node *temp = get_start();
      if(temp==NULL){
            cout<<"Empty list.";
      }else{
            cout<<"List: ";
            while(temp!=NULL){
                  cout<<temp->get_data()<<" ";
                  temp=temp->get_next();
            }
      }
      cout<<endl;
}
