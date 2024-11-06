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
- **ticket.txt**: Stores ticket information for reference.

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

## Example Output

```
-------------------------
 MOVIE TICKET BOOKING SYSTEM MENU:
-----------------------------------
1. Book Ticket
2. Show Movies List
3. Check Seats
4. Show Ticket
5. UserProfile
...
Enter your choice: 1
```

## Code Structure

- **EntryPattern**: Displays a welcome pattern using stars and delays.
- **displayMenu**: Main menu loop, displaying options and handling user input.
- **bookTicket**: Processes ticket booking, updating seat counts and user balance.
- **displayMoviesAlphabetically**: Displays movies in alphabetical order using merge sort on the linked list.
- **writeUserToFile** and **displayUserProfileFromFile**: Handle file I/O for user profiles.

## Dependencies

- **Windows.h**: Required for Windows-specific functions like `Sleep` and color changes in the console.

## Future Improvements

- **Advanced Search and Filters**: Filter movies by rating, genre, etc.
- **Enhanced Seat Booking Interface**: Add seat selection by seat number.
- **Data Persistence Enhancements**: Use binary files or databases for more robust data management.

## License

This project is open-source and available under the MIT License.
