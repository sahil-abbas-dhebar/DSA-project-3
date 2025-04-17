#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>
#include <stack> // Added for stack implementation
#include <windows.h>
#include <stdexcept>

using namespace std;

// User structure
struct User {
    string username;
    int age;
    float moneyBalance;
};

// Movie structure
struct Movie {
    string name;
    int duration;
    int seats;
    int seatsBooked; //  member to track booked seats
    float rating;
    string genre;
    float price; //  member to represent ticket price
};

// Node structure for User Linked List
struct Node_User {
    User user;
    Node_User* next;
};

// Node structure for Movie linked list
struct Node_Movie {
    Movie movie;
    Node_Movie* next;
};

// Linked list for users (implemented as a stack)
class UserList {
private:
    Node_User* top; // Top of the stack

public:
    UserList() : top(nullptr) {}

    // Function to push a user onto the stack
    void pushUser(User user) {
        Node_User* newNode = new Node_User{user, top};
        top = newNode;
    }

    // Function to pop a user from the stack
    User popUser() {
        if (!top) {
            cerr << "Stack is empty. Cannot pop.\n";
            return {"", 0, 0.0}; // Returning a dummy user
        }

        User poppedUser = top->user;
        Node_User* temp = top;
        top = top->next;
        delete temp;
        return poppedUser;
    }

    // Function to display user information during runtime
    void displayUserInfo()  {
    if (top) {
         User& currentUser = top->user;
        cout << "User Info: " << currentUser.username << " | Age: " << currentUser.age << " | Balance: $"  << setprecision(2) << currentUser.moneyBalance << "\n";
		} else {
        cout << "No user information available.\n";
		}
	}

};

// Function to get user input for creating a new user
User createUser() {
    User newUser;
    cout << "-------------------------"<< endl;
    cout << "User Information System : "<< endl;
    cout << "-------------------------" << endl;
    cout << "Enter Username: ";
    getline(cin,newUser.username);
    cout << "Enter Age: ";
    cin >> newUser.age;
    cout << "Enter Money Balance: $";
    cin >> newUser.moneyBalance;
    return newUser;
}

// Function to write user information to a file
void writeUserToFile(const User& user) {
    ofstream file("userprofile.txt", ios::app); // Append mode
    if (file.is_open()) {
        file << "Username: " << user.username << " | Age: " << user.age << " | Balance: $" << fixed << setprecision(2) << user.moneyBalance << "\n";
        file.close();
    } else {
        cerr << "Unable to open userprofile.txt for writing.\n";
    }
}

// Function to display user information from file
void displayUserProfileFromFile() {
    ifstream file("userprofile.txt");
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

// Linked list for movies
class MovieList {
private:
    Node_Movie* head;

public:
    MovieList() : head(nullptr) {}

    // Function to add a movie to the linked list using a queue (FIFO)
    void addMovie(Movie movie) {
        Node_Movie* newNode = new Node_Movie{movie, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node_Movie* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to dequeue (remove) a movie from the linked list
    Movie dequeueMovie() {
        if (!head) {
            cerr << "Queue is empty. Cannot dequeue.\n";
            return {"", 0, 0, 0, 0.0, ""}; // Returning a dummy movie
        }

        Movie dequeuedMovie = head->movie;
        Node_Movie* temp = head;
        head = head->next;
        delete temp;
        return dequeuedMovie;
    }

    // Function to display all movies in alphabetical order
    void displayMoviesAlphabetically() {
        // Sort the movies before displaying
        mergeSortMovies(&head);
        // Display the sorted movies
        Node_Movie* temp = head;
        while (temp) {
            displayMovie(temp->movie);
            temp = temp->next;
        }
    }

    // Function to display seats for a movie
    void displaySeats(const Movie& movie) const {
        cout << "Seats for " << movie.name << ":\n";
        for (int i = 0; i < movie.seats; ++i) {
            if (i % 10 == 0) {
                cout << "\n"; // Start a new row after every 10 seats
            }
            cout << (i < movie.seats - movie.seatsBooked ? "0" : "X") << " ";
        }
        cout << "\n";
    }

    // Function to book seats for a movie
    bool bookSeats(Movie& movie, int numSeats) {
        if (numSeats <= movie.seats - movie.seatsBooked) {
            movie.seatsBooked += numSeats;
            return true; // Booking successful
        } else {
            cout << "Not enough seats available for the selected movie.\n";
            return false; // Booking failed
        }
    }

    // Function to display details of a movie
    void displayMovie(const Movie& movie) {
        cout << "Name: " << movie.name << "\n";
        cout << "Duration: " << movie.duration << " mins\n";
        cout << "Rating: " << movie.rating << "\n";
        cout << "Genre: " << movie.genre << "\n";
        cout << "Ticket-Price: "<< movie.price << " $\n";
        cout<<"SHOW TIMIMGS-  12:00-3:00 /  3:00-6:00 / 6:00-9:00 /9:00-12:00"<<"\n";
        cout << "-------------------------\n";
    }

    // Function to search for a movie in the linked list
    Node_Movie* findMovie(const string& movieName) const {
        Node_Movie* temp = head;
        while (temp) {
            if (temp->movie.name == movieName) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr; // Movie not found
    }

    // Function to edit a movie in the linked list
    void editMovie(const string& movieName, const Movie& newMovie) {
        Node_Movie* movieNode = findMovie(movieName);
        if (movieNode) {
            movieNode->movie = newMovie;
        }
    }

    // Function to delete a movie from the linked list
    void deleteMovie(const string& movieName) {
        Node_Movie* temp = head;
        Node_Movie* prev = nullptr;

        while (temp) {
            if (temp->movie.name == movieName) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    // Function to merge two sorted linked lists
    Node_Movie* mergeSortedLists(Node_Movie* a, Node_Movie* b) {
        if (!a) return b;
        if (!b) return a;

        Node_Movie* result = nullptr;
        if (a->movie.name <= b->movie.name) {
            result = a;
            result->next = mergeSortedLists(a->next, b);
        } else {
            result = b;
            result->next = mergeSortedLists(a, b->next);
        }
        return result;
    }

    // Function to perform merge sort on linked list
    void mergeSortMovies(Node_Movie** node) {
        Node_Movie* headRef = *node;
        Node_Movie* a;
        Node_Movie* b;

        if (!headRef || !headRef->next) {
            return;
        }

        splitList(headRef, &a, &b);

        mergeSortMovies(&a);
        mergeSortMovies(&b);

        *node = mergeSortedLists(a, b);
    }

private:
    // Function to split linked list into two halves
    void splitList(Node_Movie* source, Node_Movie** frontRef, Node_Movie** backRef) {
        Node_Movie* fast;
        Node_Movie* slow;
        slow = source;
        fast = source->next;

        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = nullptr;
    }
};

// Function Prototypes
void bookTicket(UserList& userList, MovieList& movieList);
void checkSeats(const MovieList& movieList);
void editMovie(MovieList& movieList);
void deleteMovie(MovieList& movieList);


// Function to display the menu and handle user input
void displayMenu(UserList& userList, MovieList& movieList) {
    int choice;

try{
	bool exitProgram = false;
    do {

        cout << "\n-------------------------------\n";
        cout << " MOVIE TICKET BOOKING SYSTEM MENU:\n";
        cout << "-----------------------------------\n";

        system("color 1F"); 
        cout << "1. Book Ticket\n";
        cout << "2. Show Movies List\n";
        cout << "3. Check Seats\n";
        cout << "4. UserProfile (Display user info from file)\n";
        cout << "----------------------------------\n";
        cout << "------Developer Options Menu------\n";
        cout << "5. Add Movie\n";
        cout << "6. Edit Movie\n";
        cout << "7. Delete Movie\n";
        cout << "8. Sort the Movies (Alphabetic Order)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        // For Wrong Data Type Detecting error
        if(cin.fail())
        {
        	cin.clear();
        	cin.ignore();
        	throw runtime_error("Invalid Data Type Entered!");//For throwing error
		}

        switch (choice) {
            case 1:
                // Implement Book Ticket
                bookTicket(userList, movieList);
                break;
            case 2:
                // Implement Show Movies List
                movieList.displayMoviesAlphabetically();
                break;
            case 3:
                // Implement Check Seats
                checkSeats(movieList);
                break;
          
            case 4:
                // Implement UserProfile (Display user info from file)
                displayUserProfileFromFile();
                break;
            case 5: {
                // Implement Add Movie
                Movie newMovie;
                cout << "Enter Movie Name: ";
                cin.ignore();
                getline(cin, newMovie.name);
                cout << "Enter Duration (mins): ";
                cin >> newMovie.duration;
                cout << "Enter Number of Seats: ";
                cin >> newMovie.seats;
                newMovie.seatsBooked = 0; // Initialize booked seats to 0
                cout << "Enter Rating: ";
                cin >> newMovie.rating;
                cout << "Enter Genre: ";
                cin.ignore();
                getline(cin, newMovie.genre);
                cout<<"Enter Ticket price:";
                cin>>newMovie.price;
                movieList.addMovie(newMovie);
                break;
            }
            case 6:
                // Implement Edit Movie
                editMovie(movieList);
                break;
            case 7:
                // Implement Delete Movie
                deleteMovie(movieList);
                break;
            case 8:
                // Implement Sort the Movies (Alphabetic Order)
                movieList.displayMoviesAlphabetically();
                break;
            case 0:
                cout << "Exiting program.\n";
                cout << "Thanks For Using Our System. ^_^\n";
                cout<<"DO VISIT AGAIN";
                exitProgram = true;// Changing flag to exit the loop
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
			}
		} while (!exitProgram);
	}catch(const exception &E){
		cout << "Exception Caught: "<< E.what() << endl;
	}
}
// Function to handle booking tickets
void bookTicket(UserList& userList, MovieList& movieList) {
    // Check if a user is available
    User currentUser = userList.popUser();
    if (currentUser.username.empty()) {
        cout << "No user available. Please create a user first.\n";
        return;
    }

    string movieName;
    int numTickets;

    cout << "Enter Movie Name for Booking: ";
    cin.ignore();
    getline(cin, movieName);

    Node_Movie* movieNode = movieList.findMovie(movieName);

    if (movieNode) {
        cout << "Enter the number of tickets to book: ";
        cin >> numTickets;

        float totalCost = numTickets * movieNode->movie.price;

        if (totalCost <= currentUser.moneyBalance) {

            currentUser.moneyBalance -= totalCost; // Deduct the ticket price from user's balance
            ofstream file("userprofile.txt", ios::app); // Append mode
    if (file.is_open()) {
        file << "Username: " << currentUser.username << " | Age: " << currentUser.age << " | Balance: $" << fixed << setprecision(2) << currentUser.moneyBalance << "\n";
        file.close();
    } else {
        cerr << "Unable to open userprofile.txt for writing.\n";
    }
            userList.pushUser(currentUser); // Push updated user information back onto the stack
            movieList.bookSeats(movieNode->movie, numTickets);
            cout << "Booking successful! Total cost: $" << fixed << setprecision(2) << totalCost << "\n";
        } else {
            cout << "Not enough balance to book tickets.\n";
            userList.pushUser(currentUser); // Push back the original user information onto the stack
        }
    } else {
        cout << "Movie not found.\n";
        userList.pushUser(currentUser); // Push back the original user information onto the stack
    }
}


// Function to display available seats for a movie
void checkSeats(const MovieList& movieList) {
    string movieName;
    cout << "Enter Movie Name to Check Seats: ";
    cin.ignore();
    getline(cin, movieName);

    Node_Movie* movieNode = movieList.findMovie(movieName);

    if (movieNode) {
        movieList.displaySeats(movieNode->movie);
    } else {
        cout << "Movie not found.\n";
    }
}

// Function to edit a movie
void editMovie(MovieList& movieList) {
    string movieName;
    cout << "Enter Movie Name to Edit: ";
    cin.ignore();
    getline(cin, movieName);
    Node_Movie* movieNode = movieList.findMovie(movieName);

    if (movieNode) {
        Movie newMovie;
        cout << "Enter new details:\n";
        cout<<"Enter name:";
        cin>>newMovie.name;
        cout << "Enteharr Duration (mins): ";
        cin >> newMovie.duration;
        cout << "Enter Number of Seats: ";
        cin >> newMovie.seats;
        cout << "Enter Rating: ";
        cin >> newMovie.rating;
        cout << "Enter Genre: ";
        cin.ignore();
        getline(cin, newMovie.genre);
        movieList.editMovie(movieName, newMovie);
    } else {
        cout << "Movie not found.\n";
    }
}

// Function to delete a movie
void deleteMovie(MovieList& movieList) {
    string movieName;
    cout << "Enter Movie Name to Delete: ";
    cin.ignore();
    getline(cin, movieName);
    movieList.deleteMovie(movieName);
    cout << "Movie Deleted Successfully."<< endl;
}



// Intro Pattern
void EntryPattern(){
	
	int rows = 12;
	int col = 100;
	
	//Spacing
	cout << "                      \n";
	
	for(int i = 1; i <= rows; i++){
		
		for(int j = 1; j <= col; j++){
			
			if(i == 1 || i == rows || j == 1 || j == col){
				
				cout << "*";
				Sleep(35);	
			}
			else if (i == 4 && j >= 50 && j <= 52){
				
		cout<<"    Welcome                                           *";
				break;
			}
			else if (i == 6 && j >= 40 && j <= 70)
			{
				cout << "BOOK MY SHOW                                                *";
				break;
			}
			else{
				
				cout << " ";
			} 
		}
		cout << endl;
	}
}

int main() {
	
	// For Background Color-Change
	system("color 70");
	
	// Starting Intro
	EntryPattern();
	
    UserList userList;
    MovieList movieList;

    // Adding some initial movies
    movieList.addMovie({"Sikandar", 142, 100, 0, 9.3, "Action", 10});
    movieList.addMovie({"Kesari-Chapter 2", 148, 120, 0, 8.8, "Sci-Fi", 12});
    movieList.addMovie({"Jaat", 152, 150, 0, 9.0, "Action",5});
    movieList.addMovie({"Raid -2", 141, 154, 0, 9.3, "Drama",7});
    // Create a user option
    User newUser = createUser();
	// Get user input and push user onto the stack
    userList.pushUser(newUser);
	// Write user information to file
	writeUserToFile(newUser);

    // Display the menu
    displayMenu(userList, movieList);

    return 0;
}