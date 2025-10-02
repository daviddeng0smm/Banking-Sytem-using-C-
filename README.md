# Banking System using C++

A simple console-based banking system implemented in C++ that allows users to create accounts, check balances, make deposits, and perform withdrawals.

## Features

- **Account Creation**: Create new bank accounts with an initial deposit
- **Balance Inquiry**: Check current account balance
- **Deposit**: Add funds to an existing account
- **Withdrawal**: Withdraw funds from an account with balance validation
- **User-Friendly Menu**: Interactive console menu for easy navigation
- **Name-Based Account Management**: Accounts are identified by customer names (converted to uppercase)

## Prerequisites

To compile and run this program, you need:

- A C++ compiler (g++, clang++, or any C++11 compatible compiler)
- Standard C++ libraries

## Compilation

### Using g++

```bash
g++ -o banking banking.cpp
```

### Using clang++

```bash
clang++ -o banking banking.cpp
```

## Usage

After compilation, run the program:

```bash
./banking
```

### How to Use

1. **Start the Program**: The system will prompt you for your name
2. **Select an Option**: Choose from the following menu options:
   - `1` - Open an account
   - `2` - Check Balance
   - `3` - Deposit
   - `4` - Withdrawal
   - `5` - Exit

3. **Follow the Prompts**: The system will guide you through each operation

### Example Session

```
What is your name: John Doe
Hi, JOHN DOE how can I help you today? Please select from one of the following
1. Open an account
2. Check Balance
3. Deposit
4. Withdrawal
5. Exit
1
How much would you like to deposit? 1000
I have successfully created an account for you JOHN DOE, and I have deposited $1000 for you.
```

## Code Structure

The project consists of the following main components:

### Classes

#### `Client`
Represents a bank customer with the following features:
- **Attributes**: 
  - `name`: Customer's name
  - `money`: Account balance
- **Methods**:
  - `deposit(int amount)`: Add funds to the account
  - `withDrawl(int amount)`: Withdraw funds with balance validation
  - `returnBalance()`: Get current balance
  - `returnName()`: Get customer name

#### `Bank`
Manages multiple client accounts:
- **Attributes**:
  - `storage`: Hash map storing client accounts (key: name, value: Client*)
- **Methods**:
  - `createAccount(string name)`: Create a new account
  - `getClientInfo(string name)`: Retrieve or prompt to create an account

### Functions

- `openMenu(string name)`: Display the main menu and get user selection
- `main()`: Entry point that manages the main program loop

## Features in Detail

### Account Creation
- Prompts for initial deposit amount
- Stores account information in memory
- Prevents duplicate account creation

### Balance Checking
- Displays current account balance
- Offers to create an account if one doesn't exist

### Deposits
- Shows balance before and after deposit
- Updates account balance immediately

### Withdrawals
- Validates sufficient funds before withdrawal
- Re-prompts if withdrawal amount exceeds balance
- Displays new balance after successful withdrawal

## Technical Details

- **Data Storage**: Uses `unordered_map` for O(1) average-case account lookup
- **Input Handling**: Implements robust input buffer clearing with `cin.ignore()`
- **Name Processing**: Converts all names to uppercase for consistent storage
- **Memory Management**: Uses dynamic memory allocation for Client objects

## Limitations and Known Issues

- Account data is stored in memory and will be lost when the program exits
- No persistent storage (database or file system)
- The code contains a duplicate `main()` function that causes compilation errors
- Line 65 has a syntax error (missing semicolon)
- No memory cleanup (potential memory leaks from dynamically allocated Client objects)

## Future Enhancements

Potential improvements for the system:
- Add file-based or database persistence
- Implement account numbers in addition to names
- Add transaction history
- Support for multiple account types (savings, checking)
- Password protection for accounts
- Transfer money between accounts
- Interest calculation
- Memory leak fixes and proper cleanup

## Author

daviddeng0smm

## License

This is an educational project. Feel free to use and modify as needed.
