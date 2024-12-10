//Final Exam

/*

Using a struct, code a coffee booth queue simulation that uses a linked list as its core data structure. 
The linked list's struct should be a node that contains the customer's name and drink order. 
Create data arrays with names and drink orders from which to randomly create customer data.
Run the simulation for 10 rounds. Initialize the queue with 3 customers. 
For any given round, there's a 50% probability that someone will join the queue.
The customer at the head of the queue is always served in each round. If the queue 
is currently empty, no customer is served, but there is still a 50% probability that 
someone will join the queue.Now there's another vendor selling muffins in the next booth over. 
Add code to simulate that booth's queue. This time, use an std::deque. Incorporate this new booth into 
the 10-round simulation. The probabilities are the same. Now there's a third vendor selling 
friendship bracelets in the next booth over. Add this simulation as well using an std::vector.
Now, there's a fourth vendor selling something of your choice; add this using a
data structure of your choice that hasn't yet been used in this project.
At this point, each round should show queue activity for all four booths.
Invent data to popula the data structures, and use a struct as 
your object in the non-linked-list data structures (similar to the linked list struct, just this one will have no pointer at all).
*/

//necessary libraries
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <deque>
#include <list>
#include <cstdlib>


using namespace std;

struct Customer {
	string name;
	string order;
};

//Node for linked list queue for coffee both
struct Node {
	Customer cst;
	Node* next; //next ptr
};

//Rough layout 

class CoffeeQueue {
public: 

	CoffeeQueue() {

	}
	void enqueue(Customer c) {
		//Here, I'm creeating a new node for incoming customer
		Node* newNode = new Node;
		newNode->cst = c;
		newNode->next = nullptr;

		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			//if isnt empty, attatch new node to end and move to tail
			tail->next = new Node;
			tail = newNode;
		}
		
	}

	void dequeue() {
		//Here, we remove the front node if any
		if (head == nullptr) {
			return;
		}
		//and if not, remove the head node and move headf ormard
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	bool isEmpty() {
		return head == NULL; //if head is null, we know queue must be empty
	}

	Customer front() {
		//return the front customers data if availiable
		if (!isEmpty()) {
			return head->cst;
		}

		//if empty, return empty customer
		return Customer{ "","" };
	}

	void displayQueue() {
		//DSIPLAY ALLL CUSOTMERS IN QUEUE
		Node* cur = head;
		cout << "[";
		while (cur != NULL) {
			cout << "(" << cur->cst.name << " - " << cur->cst.order << ")";
			cur = cur->next;
			if (cur != NULL) {
				cout << ", ";
			}
			cout << "}";
		}
	}

private:
	Node* head;
	Node* tail;
};

//int randomIndex
int randomIndex(int s) {
	return rand() % s;
}

//bool probCheck
bool probCheck(double p) {
	int r = rand() % 2;
	if (r == 1) {
		return true;
	}
	else {
		return false;
	}
}

//Customer function that returns a rnadom customer with a random name/order from given arrays
Customer getRandCustomer(string names[], int nSize, string items[], int iSize) {
	Customer c;
	c.name = names[randomIndex(nSize)];
	c.order = items[randomIndex(iSize)];
	return c;
}

//serve function template supposed to remove customer front the front of a queue
template<typename QType>
void serve(QType& q) {
	if (!q.empty() {
		q.erase(q.begin());
	})
}
void serve(CoffeeQueue& cq) {
	cq.dequeue();
}


//addCust will be here: attempts to add customer to the conntainer by pushing at the back
template<typename QType>
void addCust(QType& q, Customer c) {
	q.push_back(c); //using push back
}
void addCust(CoffeeQueue& cq, Customer c) {
	cq.enqueue(c);
}


//Display Q will be here
template<typename QType>
void Display(Qtype &q){
	cout << "[";
	for (auto& x : q) {
		cout << "(" << x.name << " - " << x.order << ")";
	}
	cout << "]";
}
void displayQ(CoffeeQueue& cq) {
	cq.displayQueue();
}

//arrays for names and orders
string coffeeNames[5] = { "Franklin, Jack, Lincoln, Teddy, Tommy" };
string coffeeDrinks[5] = {"Latte", "Espresso", "Mocha", "Americano", "Cappuccino"};

string muffinNames[4] = { "Andrew", "Bush", "Washington", "John" };
string muffinItems[2] = { "Blueberry", "Chcolate" };

string braceletNames[3] = { "Joe", "Donnie" "Billy"};
string braceletItems[3] = { "A", "B", "C"};

string cookieNames[3] = { "Franklin, Jack, Lincoln, Teddy," };
string cookieItems[2] = { "Chocolate chip", "Gingerbread"};

int main() {

	srand(time(NULL));

	//Intialize each queue with 3 customers
	CoffeeQueue coffeeQ;
	for (int i = 0; i<)
	return 0;
}