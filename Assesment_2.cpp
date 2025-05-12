#include <iostream>
#include <string>
#include <iomanip>  // For setting decimal precision

using namespace std;

// Class to represent the customer
class Customer {
private:
    string name;
    double totalBill;

public:
    // Constructor to initialize customer name and bill
    Customer(string customerName) {
        name = customerName;
        totalBill = 0.0;
    }

    // Method to add the price of an order to the total bill
    void addOrder(double price) {
        totalBill += price;
    }

    // Method to get the total bill
    double getTotalBill() {
        return totalBill;
    }

    // Method to get the customer's name
    string getName() {
        return name;
    }
};

// Class to handle the ordering process
class Order {
public:
    // Display the menu
    void displayMenu() {
        cout << "\n--- Food Menu ---\n";
        cout << "1. Pizza - $12.50\n";
        cout << "2. Burger - $5.50\n";
        cout << "3. Pasta - $8.00\n";
        cout << "4. Salad - $3.00\n";
        cout << "5. Fries - $2.50\n";
        cout << "6. Soda - $1.50\n";
    }

    // Take the customer's order and update the total
    void takeOrder(Customer &customer) {
        int choice;
        int quantity;
        double price = 0.0;
        bool continueOrdering = true;

        while (continueOrdering) {
            displayMenu();
            cout << "\nEnter your choice (1-6): ";
            cin >> choice;

            // Handle invalid choice
            if (choice < 1 || choice > 6) {
                cout << "Invalid choice! Please choose a number between 1 and 6.\n";
                continue;
            }

            // Ask for the quantity of the selected item
            cout << "Enter quantity: ";
            cin >> quantity;

            // Determine the price of the selected item
            switch (choice) {
                case 1: price = 12.50; break;
                case 2: price = 5.50; break;
                case 3: price = 8.00; break;
                case 4: price = 3.00; break;
                case 5: price = 2.50; break;
                case 6: price = 1.50; break;
            }

            // Calculate total price for this order
            double totalPrice = price * quantity;
            cout << "\n" << quantity << " x item(s) = $" << fixed << setprecision(2) << totalPrice << endl;

            // Add the price to the customer's total bill
            customer.addOrder(totalPrice);

            // Ask if the customer wants to order more items
            char orderMore;
            cout << "\nWould you like to order more items? (y/n): ";
            cin >> orderMore;
            if (orderMore == 'n' || orderMore == 'N') {
                continueOrdering = false;
            }
        }
    }

    // Display the final bill
    void displayFinalBill(Customer &customer) {
        cout << "\n--- Final Bill ---\n";
        cout << "Customer: " << customer.getName() << endl;
        cout << "Total Bill: $" << fixed << setprecision(2) << customer.getTotalBill() << endl;
        cout << "Thank you for ordering! Have a great day!\n";
    }
};

// Main function to drive the program
int main() {
    string customerName;
    cout << "Enter your name: ";
    getline(cin, customerName);

    // Create a customer object
    Customer customer(customerName);

    // Create an Order object to handle the ordering process
    Order order;
    order.takeOrder(customer);

    // Display the final bill
    order.displayFinalBill(customer);

    return 0;
}

