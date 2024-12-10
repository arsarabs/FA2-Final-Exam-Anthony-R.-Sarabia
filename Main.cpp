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
const int COFFEE_CUSTOMERS[COFFEE_CUSTOMERS_SIZE] = { "Alice", "Bob", "Charlie", "Diana", "Ethan", "Fiona", "George" };
const int COFFEE_DRINKS[COFFEE_DRINKS_SIZE] = { "Latte", "Espresso", "Cappuccino", "Americano", "Mocha" };

const int MUFFIN_CUSTOMERS[MUFFIN_CUSTOMERS_SIZE] = { "Hannah", "Ian", "Jade", "Karl", "Luna", "Mason", "Nina" };
const int MUFFIN_ITEMS[MUFFIN_ITEMS_SIZE] = { "Blueberry Muffin", "Chocolate Muffin", "Banana Nut Muffin" };

const int BRACELET_CUSTOMERS[BRACELET_CUSTOMERS_SIZE] = { "Olivia", "Paul", "Queenie", "Rita", "Sam", "Tina", "Umar" };
const int BRACELET_ITEMS[BRACELET_ITEMS_SIZE] = { "Friendship Bracelet A", "Friendship Bracelet B", "Friendship Bracelet C" };

const int COOKIE_CUSTOMERS[COOKIE_CUSTOMERS_SIZE] = { "Victor", "Wendy", "Xander", "Yara", "Zane", "Abby", "Ben" };
const int COOKIE_ITEMS[COOKIE_ITEMS_SIZE] = { "Chocolate Chip Cookie", "Oatmeal Raisin Cookie", "Peanut Butter Cookie" };

struct Customer {
	string name;
	string order;
};

//Node for linked list queue for coffee both
struct Node {
	Customer cst;
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

//LINKED LSIT

//UTILITY FUNCTIONS

//TEMPLATE IMPLEMENTATIONS

//SPECIALIZED SERVE FUNCTIONS

//SPECIALIZED ADD FUNCTIONS

//SPECIALIZED PRINT FUNCTIONS


//MAIN

int main() {

	srand(time(NULL));

	//Intialize each queue with 3 customers
	CoffeeQueue coffeeQ;
	for (int i = 0; i < 3; i++) {
		coffeeQq.enqueue(getRandCustomer(coffeeNames, 5, coffeeDrinks, 5));
	}

	//Muffin booth uses a deque
	deque<Customer> MuffinQ;
	for (int i = 0; i < 3; i++) {
		Customer cust = getRandomCustomer(muffinNames, 4, muffinItems, 2);
		muffinQ.push_back(cust);
	}

	//Bracelet booth uses a vector
	vector<Customer> braceletQ;
	for (int i = 0; i < 3; i++) {
		braceletQ.push_back(getRandomCustomer(braceletNames, 3, braceletItems, 3));
	}
	//Cookie booth uses a list
	list<Customer> cookieQ;
	for (int i = 0; i < 3; i++) {
		cookie.push_back(getRandomCustomer(cookieNames, 3, cookieItems, 2));
	}

	for (int r = 1; r <= 10; r++) {
		
	}
	return 0;
}