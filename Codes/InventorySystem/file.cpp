#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define the Product class
class Product {
private:
    string productID;
    string name;
    string description;
    double unitPrice;
    int quantityInStock;

public:
    // Constructor
    Product(const string &id, const string &n, const string &desc, double price, int qty)
        : productID(id), name(n), description(desc), unitPrice(price), quantityInStock(qty) {}

    // Method to display product information
    void displayProductInfo() const {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Unit Price: $" << unitPrice << endl;
        cout << "Quantity in Stock: " << quantityInStock << endl;
    }

    // Method to update stock quantity
    void updateStock(int quantity) {
        quantityInStock += quantity;
    }

    // Getter for unit price
    double getUnitPrice() const {
        return unitPrice;
    }

    // Getter for quantity in stock
    int getQuantityInStock() const {
        return quantityInStock;
    }
};

// Define the Order class
class Order {
private:
    string orderID;
    string customerName;
    vector<Product> products;

public:
    // Constructor
    Order(const string &id, const string &custName) : orderID(id), customerName(custName) {}

    // Method to add a product to the order
    void addProduct(const Product &product, int quantity) {
        // Check if the product is already in the order
        for (auto &prod : products) {
            if (prod.getUnitPrice() == product.getUnitPrice() && prod.getQuantityInStock() > 0) {
                // Reduce the quantity of the existing product
                prod.updateStock(-quantity);
                return;
            }
        }
        // Add the new product if not found in the order
        Product newProduct = product;
        newProduct.updateStock(-quantity);
        products.push_back(newProduct);
    }

    // Method to calculate the total order amount
    double calculateTotalAmount() const {
        double totalAmount = 0;
        for (const auto &product : products) {
            totalAmount += (product.getUnitPrice() * (product.getQuantityInStock()));
        }
        return totalAmount;
    }

    // Method to display order details
    void displayOrderDetails() const {
        cout << "Order ID: " << orderID << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Products in Order:" << endl;
        for (const auto &product : products) {
            cout << "- " << product.getQuantityInStock() << " x " << product.getUnitPrice() << endl;
        }
        cout << "Total Amount: $" << calculateTotalAmount() << endl;
    }
};

// Function to calculate the total value of the entire inventory
double calculateTotalInventoryValue(const vector<Product> &inventory) {
    double totalValue = 0;
    for (const auto &product : inventory) {
        totalValue += (product.getUnitPrice() * product.getQuantityInStock());
    }
    return totalValue;
}

// Main function to test the Product and Order classes
int main() {
    // Create products
    Product product1("P001", "Widget", "A useful widget", 19.99, 100);
    Product product2("P002", "Gadget", "A handy gadget", 29.99, 50);

    // Display product information
    product1.displayProductInfo();
    product2.displayProductInfo();

    // Create an order
    Order order1("O001", "Alice Smith");

    // Add products to the order
    order1.addProduct(product1, 10);
    order1.addProduct(product2, 5);

    // Display order details
    order1.displayOrderDetails();

    // Create inventory list and calculate total inventory value
    vector<Product> inventory = { product1, product2 };
    cout << "Total Inventory Value: $" << calculateTotalInventoryValue(inventory) << endl;

    return 0;
}
