#include<iostream>

using namespace std;

template <typename T>
class Node{
	public: T value;
	public: Node<T> *next;
	public: Node<T> *previous;

	Node(T value){
		this->value = value;
	}

	
};

template <typename T> 
class linkedList{
private: 
	int size;
	Node<T> *head = NULL;
	Node<T> *tail = NULL;
	Node<T> *itr = NULL;
	
	public:
		 linkedList(){
		 	this->size=0;
		 }

	void append(T value){
		if(this-> head ==NULL ){
			this->head = new Node<T>(value);
			this->tail = this-> head;
			}
		else{
 			this->tail->next = new Node<T>(value);
			this->tail->next->previous = this->tail;
			this->tail = this->tail->next; 
		}  
		this->size +=1;
	}

	void prepend(T value){
		if(this->head == NULL){
			this->head = new Node<T>(value);
			this->tail = this->head;
		}
		else{
			this->head->previous = new Node<T>(value);
			this->head->previous->next = this->head;
			this->head = this->head->previous;
		}
		this->size+=1;
		}
	Node<T> * iterate(){
		if(this-> itr == NULL){
			this-> itr = this->head;
		}
		else{
			this->itr = this->itr->next;
		} 
		return this->itr;
		 
	}
	Node<T> * iterateReverse(){
		if(this->itr ==NULL){
			this->itr=this->tail;
		}
		else{
			this->itr = this->itr->previous;
		}
		return this->itr;  
	}
	void resetIterator(){
		this->tail=NULL;
	}
	int Size(){
		return this->size;
	}  
	T get(){
		if(this->itr == NULL){
			this->itr = this->head;  
		}
		return this->itr->value;
	}
	T getAtIndex(int index){
		for(int i =0; i<index;i++){
			this->iterate();
		}
		this->resetIterator();
		return this->itr->value; 
	}
	void printGet(){
		cout<<this->get(); 
	}
	void printerGetAtIndex(int index){
		cout<<this->getAtIndex(index);   
	}     
	void set(T value){
		this->itr->value = value; 
	}
	void setAtIndex(T value, int index){
		for(int i=0; i<index; i++){
			this->iterate();
		}
		this->resetIterator();
		this->itr->value = value;
	}
	void display(){
		while(this->iterate()!=NULL){
		cout<<this->get();
		}  
	}
	void reverseDisplay(){
		for(int i=0; i<this->size; i++){
			this->iterateReverse();
			cout<<this->get();
		}  
	}
	void popH(){
	this->head = this->head->next;
	}
	void popT(){
	this->iterateReverse();
	delete this->itr;
	this->size-=1;
	}
	void remove(){
	delete this->itr;
	this->size-=1;	
	}
	void popAtIndex(int index){
	for(int i =0; i<index; i++){
		this->iterate();
	}
	this->remove(); 
	}   
	     
};
template <typename T> 
class Pile{
public:	T value;
public: Pile *next;
public: Pile(T value){
	this->value = value;
} 	
	
};
template <typename T>  
class Stack{
	Pile<T> *top;
	Pile<T> *itr;
	int size;
	  
public: Stack(){
	this->size =0;
} 

	void push(T value){
		if(this-> top==NULL ){
			this->top = new Pile<T>(value);
			}
		else{
 			this->top->next = new Pile<T>(value);
		}  
		this->size +=1;
	}
	void pop(T value){
		if(this->itr==NULL){
			this->itr= this->top;
			delete this->itr;
		}
		else{
			delete this->itr;
		}  
	}  
	Pile<T> * iterate(){
	if(this-> itr == NULL){
		this-> itr = this->top;
	}
	else{
		this->itr = this->itr->next;
		} 
		return this->itr;
	}
    int Size(){
		return this->size; 
	} 
	T get(){
	 if(this->itr==NULL){
	 	this->itr=this->top;
	 	return this->itr->value;
	 }
	 else{  
	 return this->itr->value;
	 }	
	}
	void set(T value){
		this->itr->value = value; 
	}  
	void display(){
		while(this->iterate()!=NULL){
		cout<<this->get();   
		}  
	}   
}; 
template<typename T>
class Queue{
T *arr;
int capacity;
T front;
T rear;
int count;

public: 
Queue(int capacity){
	this->arr = new T[capacity];
	this->capacity = capacity;
	this->front =0;
	this->rear =-1;
	this->count =0; 
}
~Queue(){
	delete[] arr;
} 
int size(){
	return this->count; 
} 
bool isEmpty(){
	return (this->size() == 0); 
}
bool isFull(){
	return (this->size() == capacity);
}
void enqueue(T item){
	this->rear = (this->rear+1)%capacity;
	this->arr[rear]=item;
	this->count++;
} 
void dequeue(){
	if(this->isEmpty()){
		cout<<"Underflow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	this->front = (this->front+1)%capacity;
	this->count--;   
}
T peek(){
	if(this->isEmpty()){
			cout<<"Underflow\nProgram Terminated\n";
			exit(EXIT_FAILURE);
		}
	return arr[front];
}
void display(){
	for(int i=0; i<this->size(); i++){
		cout<<this->peek();   
	}
}
T getAtIndex(int Index){
  return this->arr[Index]; 
}  
};

template<typename T>
class leaf{
public: T value;
public: leaf *left;
public: leaf *right; 
 public: 
 	leaf(T value){
 		this->value=value;
 	}  
};   
template <typename T>
class Tree{
int size;
leaf<T> *root;
leaf<T> *itr;
leaf<T> *level; 
public:
	Tree(){
		this->size = 0; 
	}

void insert(T value){
	if(this->root==NULL){
		this->root= new leaf<T>(value);
	}
	else if(this->root->right == NULL){
		this->root->right = new leaf<T>(value);
	}
	else{
		this->root->left = new leaf<T>(value);
	}
	this->size+=1;  
}
void iterate(){
	if(this->itr==NULL){
		this->itr=this->root;
		this->level=this->root;
	} 
	leaf<T> tempR;
	leaf<T> tempL; 
	while(this->itr != NULL){
		if(this->itr->right != NULL && this->level->right!= NULL){
			this->level = this->itr;
			this->itr = this->itr->right;
		}
		else if(this->level->left!=NULL){
			this->itr = this level;
			this->itr = this->itr->left; 
		}  
		else {
			this->itr = this->level
		}
		   
	}
	  
} 
int search(T value){
if(this->itr == NULL){
	this->itr = this->root;
}
int depth =0;
while(this->itr->value != NULL){
	if(this->itr->value == value ){
		return depth;
	}
	this->iterate();
	depth++;
}    
}
void sort(){
	
} 
void pop(){
	
}
void display(){
	if(this->itr == NULL){
		this->itr = this->root;
	}  
	while(this->itr!=NULL){
		this->iterate();
		cout<<this->itr->value;
	}  
	
}       
	
}; 
  
int main(){
linkedList<int> linkedlist;
Stack<int> stack;
Queue<int> queue(200); 
Tree<int> tree;
for(int i=0; i<101; i++){
	linkedlist.append(i);
	stack.push(i);
	queue.enqueue(i);
	tree.insert(i);  
}
cout<<linkedlist.getAtIndex(20);
tree.display();
}     
 
