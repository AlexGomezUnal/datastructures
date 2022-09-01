#include<iostream>
#include<any>

using namespace std;

class PrintAny{
public: PrintAny(){}

void printAny(any item){
	if(auto p =any_cast<int>(&item)){
		cout<<*p<<" ";
	}
	else if(auto p =any_cast<float>(&item)){
	  		cout<<*p<<" ";
	  	}
	else if(auto p =any_cast<bool>(&item)){
	  		cout<<*p<<" ";
	  		}
	else if(auto p =any_cast<std::string>(&item)){
	    	cout<<*p<<" ";
	    		}
   else{
   	cout<<"Object is at ";
   }               	
	  	    
} 
	
};
class Node{
	public: any value;
	public: Node *next;
	public: Node *previous;

	Node(any value){
		this->value = value;
	}

	
};

class linkedList{
private: 
	int size;
	Node *head = NULL;
	Node *tail = NULL;
	Node *itr = NULL;
	PrintAny *printer = new PrintAny();

	public:
		 linkedList(){
		 	this->size=0;
		 	this->printer = printer;
		 }

	void append(any value){
		if(this-> head ==NULL ){
			this->head = new Node(value);
			this->tail = this-> head;
			}
		else{
 			this->tail->next = new Node(value);
			this->tail->next->previous = this->tail;
			this->tail = this->tail->next; 
		}  
		this->size +=1;
	}

	void prepend(any value){
		if(this->head == NULL){
			this->head = new Node(value);
			this->tail = this->head;
		}
		else{
			this->head->previous = new Node(value);
			this->head->previous->next = this->head;
			this->head = this->head->previous;
		}
		this->size+=1;
		}
	Node * iterate(){
		if(this-> itr == NULL){
			this-> itr = this->head;
		}
		else{
			this->itr = this->itr->next;
		} 
		return this->itr;
		 
	}
	Node * iterateReverse(){
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
	any get(){
		return this->itr->value;
	}
	any getAtIndex(int index){
		for(int i =0; i<index;i++){
			this->iterate();
		}
		this->resetIterator();
		return this->itr->value; 
	}
	void printGet(){
		this->printer->printAny(this->get()); 
	}
	void printerGetAtIndex(int index){
		this->printer->printAny(this->getAtIndex(index));   
	}     
	void set(any value){
		this->itr->value = value; 
	}
	void setAtIndex(any value, int index){
		for(int i=0; i<index; i++){
			this->iterate();
		}
		this->resetIterator();
		this->itr->value = value;
	}
	void display(){
		while(this->iterate()!=NULL){
		this->printer->printAny(this->get());
		}  
	}
	void reverseDisplay(){
		for(int i=0; i<this->size; i++){
			this->iterateReverse();
			this->printer->printAny(this->get());
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
class Pile{
public:	any value;
public: Pile *next;
public: Pile(any value){
	this->value = value;
} 	
	
}; 
class Stack{
	Pile *top;
	Pile *itr;
	int size;
	PrintAny *printer = new PrintAny();  
public: Stack(){} 

	void push(any value){
		if(this-> top==NULL ){
			this->top = new Pile(value);
			}
		else{
 			this->top->next = new Pile(value);
		}  
		this->size +=1;
	}
	Pile * iterate(){
	if(this-> itr == NULL){
		this-> itr = this->top;
	}
	else{
		this->itr = this->itr->next;
		} 
		return this->itr;
	}
	any get(){
	 if(this->itr==NULL){
	 	this->itr=this->top;
	 	return this->itr->value;
	 }
	 else{  
	 return this->itr->value;
	 }	
	}
	void set(any value){
		this->itr->value = value; 
	}  
	void display(){
		while(this->iterate()!=NULL){
		this->printer->printAny(this->get());   
		}  
	}   
}; 

class Queue
{
    int *arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue
 
public:
    Queue(int size = SIZE);     // constructor
    ~Queue();                   // destructor 
// Constructor to initialize a queue
Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
 
// Destructor to free memory allocated to the queue
~Queue() {
    delete[] arr;
}
	
bool isEmpty() {
    return (size() == 0);
}
 
// Utility function to check if the queue is full or not
bool isFull() {
    return (size() == capacity);
}
 
// Utility function to dequeue the front element
int dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    int x = arr[front];
    cout << "Removing " << x << endl;
 
    front = (front + 1) % capacity;
    count--;
 
    return x;
}
 
// Utility function to add an item to the queue
void enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << item << endl;
 
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
 
// Utility function to return the front element of the queue
int peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
 
// Utility function to return the size of the queue
int size() {
    return count;
}

};

int main(){
linkedList linkedlist;
Stack stack; 
for(int i=0; i<101; i++){
	linkedlist.append(i);
	stack.push(i); 
}
stack.display();
}     
 
