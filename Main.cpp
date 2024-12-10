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

#include <iostream>

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

// class CoffeeeQueue here

class CoffeeQueue {
public: 

private:
	Node* head;
	Node* tail;
};



int main() {


	return 0;
}