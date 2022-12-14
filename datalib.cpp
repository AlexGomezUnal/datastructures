#include<iostream>
#include <string>
#include <tuple>
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
int count;

public: 
Queue(int capacity){
	this->arr = new T[capacity];
	this->capacity = capacity; 
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
	this->arr[count]=item;
	count++;
	
} 
void dequeue(){
	if(this->arr->isFull()){
	
	for(int i =0; i<this->count-1; i++){
		this->arr[i] = this->arr[i+1];
	}	
	}
	else{
	for(int i =0; i<this->count; i++){
		this->arr[i] = this->arr[i+1];
	}
	}
	this->count--;  
}
T front(){
	return arr[0];
}
T rear(){
	return arr[count]; 
} 
T get(int index){
	return arr[index]; 
} 
void display(){
	for(int i=0; i<this->size(); i++){
		cout<<this->get(i);   
	}
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
Queue<leaf<T>> treeQueue(999999); 
int count;
int countItr;
public:
	Tree(){
		this->size = 0; 
		this->count = 0;
		this->countItr = 0;
	}

void insert(T value){
if(this->root ==NULL){
	this->root = new leaf<T>(value);
	this->itr = this->root;
}
if(this->root->left == NULL){
	this->root->left = new leaf<T>(value);
	this->treeQueue->enqueue(this->root->left);
	this->count++;
}
if(this->root->right == NULL){
 	this->root->right = new leaf<T>(value);
 	this->treeQueue->enqueue(this->root->right);  	
	this->count++;	
}
this->root = this->treeQueue->get(this->count--);
this->size+=1;  
	

}
void iterate(){
 this->itr->right = this->itr;
 this->itr = this->array[this->countItr];
 this->countItr++;
		   	  
}
void resetIterate(){
	this->itr = this->itr->right;
	this->countItr = 0;
}  
int search(T value){
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
	cout<<this->itr->next->value;  
	while(this->itr!=NULL){
		this->iterate();
		cout<<this->itr->value;
	}  
	
}       
	
}; 
template <typename I, typename K>
class Hash{
tuple<I,K> *table;
int capacity;
int count;

public: Hash(int capacity){
	this->table = new tuple<I,K>[capacity]; 
	this->count =0;
}
void  add(tuple<I,K> item){
	this->table[count] = item;
	count++;
}
void pop(){
	delete this->table[count]; 
	count--;
} 
void FHash(){
	
}
I search(K key){
	
}
void set(){
	
}  
void display(){
/*for(int i=0; i<capacity; i++){
	cout<<this->table[i]<0>;
	cout<<this->table[i]<1>;
	 
}*/	
}     	
};   
int main(){
linkedList<int> linkedlist;
Stack<int> stack;
Queue<int> queue(200); 
Tree<int> tree;
Hash<int,string> hash(200);

tuple<int,string> x; 
for(int i=0; i<101; i++){
	linkedlist.append(i);
	stack.push(i);
	queue.enqueue(i);
	tree.insert(i);
	make_tuple(x,i,to_string(i));
	hash.add(x);   
}
queue.display();
hash.display();
}     
 
