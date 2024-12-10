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

const int SIMULATION_ROUNDS = 10;
const double JOIN_PROBABILITY = 0.5;

const int COFFEE_CUSTOMERS_SIZE = 7;
const int COFFEE_DRINKS_SIZE = 5;
const int MUFFIN_CUSTOMERS_SIZE = 7;
const int MUFFIN_ITEMS_SIZE = 3;
const int BRACELET_CUSTOMERS_SIZE = 3;
const int BRACELET_ITEMS_SIZE = 3;
const int COOKIE_CUSTOMERS_SIZE = 7;
const int COOKIE_ITEMS_SIZE = 3;

// DATA arrays for names and orders
const string COFFEE_CUSTOMERS[COFFEE_CUSTOMERS_SIZE] = { "Alice", "Bob", "Charlie", "Diana", "Ethan", "Fiona", "George" };
const string COFFEE_DRINKS[COFFEE_DRINKS_SIZE] = { "Latte", "Espresso", "Cappuccino", "Americano", "Mocha" };

const string MUFFIN_CUSTOMERS[MUFFIN_CUSTOMERS_SIZE] = { "Hannah", "Ian", "Jade", "Karl", "Luna", "Mason", "Nina" };
const string MUFFIN_ITEMS[MUFFIN_ITEMS_SIZE] = { "Blueberry Muffin", "Chocolate Muffin", "Banana Nut Muffin" };

const string BRACELET_CUSTOMERS[BRACELET_CUSTOMERS_SIZE] = { "Olivia", "Paul", "Queenie" };
const string BRACELET_ITEMS[BRACELET_ITEMS_SIZE] = { "Friendship Bracelet A", "Friendship Bracelet B", "Friendship Bracelet C" };

const string COOKIE_CUSTOMERS[COOKIE_CUSTOMERS_SIZE] = { "Victor", "Wendy", "Xander", "Yara", "Zane", "Abby", "Ben" };
const string COOKIE_ITEMS[COOKIE_ITEMS_SIZE] = { "Chocolate Chip Cookie", "Oatmeal Raisin Cookie", "Peanut Butter Cookie" };


struct Customer {
	string name;
	string order;
};

//Node for linked list queue for coffee both
struct Node {
	Customer data;
	Node* next; //next ptr
};

class LinkedListQueue {
public:
	LinkedListQueue();
	~LinkedListQueue();
	void enqueue(const Customer& c);
	void dequeue();
	bool isEmpty() const;
	Customer front() const;
	void printQueue() const;
private:
	Node* head;
	Node* tail;
};

//int randomIndex
int randomIndex(int size);
bool probabilityCheck(double p);

//Customer function that returns a rnadom customer with a random name/order from given arrays
Customer getRandomCustomer(const string customers[], int cSize, const string items[], int iSize);

//serve function template supposed to remove customer front the front of a queue
template<typename QueueType>
void serveCustomer(QueueType& q, bool& isCustomStructure);

template<typename QueueType>
void addCustomer(QueueType& q, const Customer& c, bool& isCustomStructure);

template<typename QueueType>
void printQueue(QueueType& q, bool& isCustomStructure);

//specializations for different containers

template<>
void serveCustomer<LinkedListQueue>(LinkedListQueue& q, bool& isCustomStructure);

template<>
void serveCustomer<deque<Customer>>(deque<Customer>& dq, bool& isCustomStructure);

template<>
void serveCustomer<vector<Customer>>(vector<Customer>& vec, bool& isCustomStructure);

template<>
void serveCustomer<list<Customer>>(list<Customer>& lst, bool& isCustomStructure);

template<>
void addCustomer<LinkedListQueue>(LinkedListQueue& q, const Customer& c, bool& isCustomStructure);

template<>
void addCustomer<deque<Customer>>(deque<Customer>& dq, const Customer& c, bool& isCustomStructure);

template<>
void addCustomer<vector<Customer>>(vector<Customer>& vec, const Customer& c, bool& isCustomStructure);

template<>
void addCustomer<list<Customer>>(list<Customer>& lst, const Customer& c, bool& isCustomStructure);

template<>
void printQueue<LinkedListQueue>(const LinkedListQueue& q, bool& isCustomStructure);

template<>
void printQueue<deque<Customer>>(const deque<Customer>& dq, bool& isCustomStructure);

template<>
void printQueue<vector<Customer>>(const vector<Customer>& vec, bool& isCustomStructure);

template<>
void printQueue<list<Customer>>(const list<Customer>& lst, bool& isCustomStructure);


//*****************************************************************************
//LINKED LSIT
LinkedListQueue::LinkedListQueue() : head(nullptr), tail(nullptr) {
	// constructor
}

LinkedListQueue::~LinkedListQueue() {
	while (!isEmpty()) {
		dequeue();
	}
}

void LinkedListQueue::enqueue(const Customer& c) {
	Node* newNode = new Node{ c, nullptr };
	if (isEmpty()) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

void LinkedListQueue::dequeue() {
	if (isEmpty()) return;
	Node* temp = head;
	head = head->next;
	if (head == nullptr) tail = nullptr;
	delete temp;
}

bool LinkedListQueue::isEmpty() const {
	return (head == nullptr);
}

Customer LinkedListQueue::front() const {
	if (!isEmpty()) {
		return head->data;
	}
	// return empty customer if empty
	return Customer{ "", "" };
}

void LinkedListQueue::printQueue() const {
	Node* current = head;
	cout << "[";
	while (current != nullptr) {
		cout << "(" << current->data.name << " - " << current->data.order << ")";
		current = current->next;
		if (current != nullptr) cout << ", ";
	}
	cout << "]";
}


//*****************************************************************************
//UTILITY FUNCTIONS
int randomIndex(int size) {
	return rand() % size;
}
bool probabilityCheck(double p) {
	// random integer mod 100, if less than p*100, returns true
	return ((rand() % 100) < static_cast<int>(p * 100));
}

Customer getRandomCustomer(const string customers[], int cSize, const string items[], int iSize) {
	Customer c;
	c.name = customers[randomIndex(cSize)];
	c.order = items[randomIndex(iSize)];
	return c;
}

//*****************************************************************************
//TEMPLATE IMPLEMENRATIONS steps 4-6

//*****************************************************************************
//SPECIALIZED SERVE FUNCTIONS 

template<>
void serveCustomer<LinkedListQueue>(LinkedListQueue& q, bool& isCustomStructure) {
	if (!q.isEmpty()) {
		q.dequeue();
	}
}

template<>
void serveCustomer<deque<Customer>>(deque<Customer>& dq, bool& isCustomStructure) {
	if (!dq.empty()) {
		dq.pop_front();
	}
}

template<>
void serveCustomer<vector<Customer>>(vector<Customer>& vec, bool& isCustomStructure) {
	// serving from front: remove first element
	if (!vec.empty()) {
		vec.erase(vec.begin());
	}
}

template<>
void serveCustomer<list<Customer>>(list<Customer>& lst, bool& isCustomStructure) {
	if (!lst.empty()) {
		lst.pop_front();
	}
}



//*****************************************************************************
//SPECIALIZED ADD FUNCTIONS

template<>
void addCustomer<LinkedListQueue>(LinkedListQueue& q, const Customer& c, bool& isCustomStructure) {
	q.enqueue(c);
}

template<>
void addCustomer<deque<Customer>>(deque<Customer>& dq, const Customer& c, bool& isCustomStructure) {
	dq.push_back(c);
}

template<>
void addCustomer<vector<Customer>>(vector<Customer>& vec, const Customer& c, bool& isCustomStructure) {
	vec.push_back(c);
}

template<>
void addCustomer<list<Customer>>(list<Customer>& lst, const Customer& c, bool& isCustomStructure) {
	lst.push_back(c);
}


//*****************************************************************************
//SPECIALIZED PRINT FUNCTIONS

template<>
void printQueue<LinkedListQueue>(LinkedListQueue& q, bool& isCustomStructure) {
	q.printQueue();
}

template<>
void printQueue<deque<Customer>>(deque<Customer>& dq, bool& isCustomStructure) {
	cout << "[";
	for (size_t i = 0; i < dq.size(); ++i) {
		cout << "(" << dq[i].name << " - " << dq[i].order << ")";
		if (i < dq.size() - 1) cout << ", ";
	}
	cout << "]";
}

template<>
void printQueue<vector<Customer>>(vector<Customer>& vec, bool& isCustomStructure) {
	cout << "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << "(" << vec[i].name << " - " << vec[i].order << ")";
		if (i < vec.size() - 1) cout << ", ";
	}
	cout << "]";
}

template<>
void printQueue<list<Customer>>(list<Customer>& lst, bool& isCustomStructure) {
	cout << "[";
	auto it = lst.begin();
	while (it != lst.end()) {
		cout << "(" << it->name << " - " << it->order << ")";
		++it;
		if (it != lst.end()) cout << ", ";
	}
	cout << "]";
}



//*****************************************************************************
//MAIN

int main() {
	srand((unsigned)time(nullptr));
	bool isCustomStructure = false;

	

	 // Initialize each booth queue with 3 random customers
	// Coffee booth: LinkedListQueue

	LinkedListQueue coffeeQueue;
	deque<Customer> muffinQueue;
	list<Customer> cookieQueue;

	for (int i = 0; i < 3; i++) {
		coffeeQueue.enqueue(getRandomCustomer(COFFEE_CUSTOMERS, COFFEE_CUSTOMERS_SIZE, COFFEE_DRINKS, COFFEE_DRINKS_SIZE));
	}

	 // Muffin booth: deque
	for (int i = 0; i < 3; i++) {
		muffinQueue.push_back(getRandomCustomer(MUFFIN_CUSTOMERS, MUFFIN_CUSTOMERS_SIZE, MUFFIN_ITEMS, MUFFIN_ITEMS_SIZE));
	}

	// Bracelet booth: vector
	vector<Customer> braceletQueue;
	for (int i = 0; i < 3; i++) {
		braceletQueue.push_back(getRandomCustomer(BRACELET_CUSTOMERS, BRACELET_CUSTOMERS_SIZE, BRACELET_ITEMS, BRACELET_ITEMS_SIZE));
	}

	 // Cookie booth: list
	for (int i = 0; i < 3; i++) {
		cookieQueue.push_back(getRandomCustomer(COOKIE_CUSTOMERS, COOKIE_CUSTOMERS_SIZE, COOKIE_ITEMS, COOKIE_ITEMS_SIZE));
	}


	//*************************************
	 // Run the simulation here!!!!!!

	for (int round = 1; round <= SIMULATION_ROUNDS; round++) {
		cout << "----- Round " << round << " -----" << endl;

		// Serve one customer per booth if available
		serveCustomer(coffeeQueue, isCustomStructure);
		serveCustomer(muffinQueue, isCustomStructure);
		serveCustomer(braceletQueue, isCustomStructure);
		serveCustomer(cookieQueue, isCustomStructure);

		// Possibly add new customers with given probability
		if (probabilityCheck(JOIN_PROBABILITY)) {
			addCustomer(coffeeQueue, getRandomCustomer(COFFEE_CUSTOMERS, COFFEE_CUSTOMERS_SIZE, COFFEE_DRINKS, COFFEE_DRINKS_SIZE), isCustomStructure);
		}
		if (probabilityCheck(JOIN_PROBABILITY)) {
			addCustomer(muffinQueue, getRandomCustomer(MUFFIN_CUSTOMERS, MUFFIN_CUSTOMERS_SIZE, MUFFIN_ITEMS, MUFFIN_ITEMS_SIZE), isCustomStructure);
		}
		if (probabilityCheck(JOIN_PROBABILITY)) {
			addCustomer(braceletQueue, getRandomCustomer(BRACELET_CUSTOMERS, BRACELET_CUSTOMERS_SIZE, BRACELET_ITEMS, BRACELET_ITEMS_SIZE), isCustomStructure);
		}
		if (probabilityCheck(JOIN_PROBABILITY)) {
			addCustomer(cookieQueue, getRandomCustomer(COOKIE_CUSTOMERS, COOKIE_CUSTOMERS_SIZE, COOKIE_ITEMS, COOKIE_ITEMS_SIZE), isCustomStructure);
		}

		// Print queues
		cout << "Coffee Queue: ";
		printQueue(coffeeQueue, isCustomStructure);
		cout << endl;

		cout << "Muffin Queue: ";
		printQueue(muffinQueue, isCustomStructure);
		cout << endl;

		cout << "Bracelet Queue: ";
		printQueue(braceletQueue, isCustomStructure);
		cout << endl;

		cout << "Cookie Queue: ";
		printQueue(cookieQueue, isCustomStructure);
		cout << endl << endl;

	}
	return 0;
}