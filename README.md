# Movie Ticket Booking System

## Overview

The **Movie Ticket Booking System** is a C++ console application that simulates a basic movie ticket reservation system. It enables users to browse movies, check seat availability, book tickets, and view their account balance. The program uses data structures such as linked lists, stacks, and queues to manage user and movie information effectively. 

## Key Features

- **User Profile Management**: Create and store user profiles with age and balance information.
- **Movie Management**: Add, edit, delete, and sort movies. Displays movie information including duration, rating, genre, and ticket price.
- **Ticket Booking**: Book seats for movies and update the user's balance.
- **Seat Availability**: View seat availability for specific movies.
- **File I/O**: Save user and ticket information to files for persistence.
- **Exception Handling**: Handles invalid input types for error prevention.
- **Menu Interface**: User-friendly menu for accessing different functions.

  ![image](https://github.com/user-attachments/assets/073f0c6d-334d-41c0-9983-2c677b0fd6e8)


## Data Structures Used

1. **Stack** (User Information): Users are managed with a stack-based structure allowing operations like pushing new users and popping the current user.
2. **Queue** (Movie Addition): Movies are added in a queue-like fashion, following FIFO order.
3. **Linked List**: Movies are stored in a linked list, allowing easy traversal and modifications.

## Project Structure

- **UserList Class**: Manages user stack operations (add, display, pop user).
- **MovieList Class**: Manages movies as a linked list, supporting add, edit, delete, sort, and seat operations.
- **File Operations**: Saves and loads user and ticket data from text files.

## File Details

- **userprofile.txt**: Stores user profile data.

- ## File Handling Explanation

The **Movie Ticket Booking System** uses file handling to store and retrieve user and ticket information across program sessions. This ensures data persistence, so user details and ticket records are available even after the program closes. Below is a brief explanation of the files used and their purpose:

1. **User Profile File** (`userprofile.txt`):
   - **Purpose**: Stores user information such as username, age, and account balance.
   - **Write Operation**: The function `writeUserToFile` appends user data to `userprofile.txt` whenever a new user is created.
   - **Read Operation**: The function `displayUserProfileFromFile` reads from `userprofile.txt` and displays all stored user profiles on the console.
   - **Mode Used**: 
     - `ios::app` mode for appending new user data.
     - `ios::in` mode for reading and displaying user profiles.


These file operations allow the program to maintain user and ticket records across sessions.

## Installation and Setup

1. **Clone the repository**:
   ```bash
   git clone https://github.com/username/movie-ticket-booking-system.git
   ```
2. **Navigate to the directory**:
   ```bash
   cd movie-ticket-booking-system
   ```
3. **Compile the code**:
   Ensure you have a C++ compiler installed. Then compile the code:
   ```bash
   g++ movie_booking_system.cpp -o movie_booking_system
   ```
4. **Run the application**:
   ```bash
   ./movie_booking_system
   ```

## Usage Guide

1. **User Profile Creation**: At the start, you’ll be prompted to enter your user profile details (username, age, balance).
2. **Menu Options**:
   - **1. Book Ticket**: Enter movie name and number of tickets. Ensure you have enough balance.
   - **2. Show Movies List**: Displays all movies sorted alphabetically.
   - **3. Check Seats**: Shows the seat layout for a selected movie.
   - **4. Show Ticket**: Displays ticket information from file.
   - **5. UserProfile**: View user information saved in `userprofile.txt`.
   - **Developer Options**: Options 6-9 allow adding, editing, deleting, and sorting movies in the database.
   - **0. Exit**: Exit the program.
   
3. **Exceptions**: Incorrect data types for menu inputs or invalid actions will trigger exception handling.

## Code Structure

- **EntryPattern**: Displays a welcome pattern using stars and delays.
- **displayMenu**: Main menu loop, displaying options and handling user input.
- **bookTicket**: Processes ticket booking, updating seat counts and user balance.
- **displayMoviesAlphabetically**: Displays movies in alphabetical order using merge sort on the linked list.
- **writeUserToFile** and **displayUserProfileFromFile**: Handle file I/O for user profiles.

- ## Benefits of the Code

The **Movie Ticket Booking System** provides a streamlined solution for managing and booking movie tickets. Here’s how the code is beneficial:

1. **User-Friendly Interface**: The console-based menu system is straightforward, allowing users to easily navigate options such as booking tickets, viewing available movies, checking seats, and viewing ticket information.

2. **Data Persistence**: Through file handling, the system retains user profiles and booking information across program sessions. This persistence ensures users' details and records aren’t lost after program closure, enabling smoother interaction and data recall.

3. **Efficient Seat Management**: The system dynamically manages seat availability by tracking booked seats for each movie. This allows for real-time updates of seating capacity, helping prevent overbooking.

4. **Developer Options for Management**: Includes administrative functions like adding, editing, deleting, and sorting movies, providing developers or administrators with control over the available movie list.

5. **Stack and Queue Operations**: By using stack (for user information) and queue-like behavior (for movie listing), the code demonstrates efficient data structure utilization for managing data flow, making it easily adaptable for different operations.

## Workflow of the Movie Ticket Booking System
The code is designed with a clear process to manage user and movie information, seat bookings, and data persistence. Here’s how it works:


### 1. **Initialization and Setup**
   - When the program starts, it shows a welcome message, changes the console background color, and sets up user and movie data.
   - Initial movies are added to the movie list for immediate selection.

### 2. **User Creation and Data Persistence**
   - Users enter their profile details (name, age, and balance).
   - The system stores the details in the UserList and saves them to userprofile.txt.

### 3. **Menu Navigation and Options**
   -A main menu appears, and users can choose from options to book tickets, view movies, check seats, and manage tickets.
   
### 4. **Booking Process**
   - The Book Ticket option prompts users for the movie name and ticket count.
   - The system checks seat availability and the user’s balance before the booking.
   - Upon successful booking, the system deducts the cost from the user’s balance and updates the booked seat count for the movie.

### 5. **Checking and Managing Movies**
   - Users can view a list of movies in alphabetical order. Developers can also add, edit, delete, and sort movies.
   - Seat availability is checked for each movie.
   
### 6. **File Management for Tickets and User Profiles**
   - The UserProfile options let users view profile details stored in files.

### 7. **Program Exit**
   - When users select exit, the program ends and saves all changes for the next session.


This workflow ensures the system manages user data, movies, and bookings effectively, while maintaining data across sessions.

## Dependencies

- **Windows.h**: Required for Windows-specific functions like `Sleep` and color changes in the console.

## Future Improvements

- **Advanced Search and Filters**: Filter movies by rating, genre, etc.
- **Enhanced Seat Booking Interface**: Add seat selection by seat number.
- **Data Persistence Enhancements**: Use binary files or databases for more robust data management.

