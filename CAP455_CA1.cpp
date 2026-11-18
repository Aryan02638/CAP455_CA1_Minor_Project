#include <iostream> 
#include <string> 
using namespace std; 
  
class Product 
{ 
public: 
    int id, stock, sold; 
    string name; 
    double price, revenue; 
  
    Product() 
    { 
        id = stock = sold = 0; 
        price = revenue = 0; 
    } 
  
    Product(int i, string n, double p, int s) 
    { 
        id = i; 
        name = n; 
        price = p; 
        stock = s; 
        sold = 0; 
        revenue = 0; 
    } 
  
    void display() 
    { 
        cout << "\nID: " << id 
             << "\nName: " << name 
             << "\nPrice: Rs. " << price 
             << "\nAvailable Stock: " << stock 
             << "\nUnits Sold: " << sold 
             << "\nRevenue: Rs. " << revenue << endl; 
    } 
}; 
  
class Vendor 
{ 
    Product p[50]; 
    int count = 0; 
  
    int search(int id) 
    { 
        for (int i = 0; i < count; i++) 
            if (p[i].id == id) 
                return i; 
        return -1; 
    } 
  
public: 
    void addProduct() 
    { 
        if (count == 50) 
        { 
            cout << "Product limit reached!\n"; 
            return; 
        } 
  
        int id, stock; 
        string name; 
        double price; 
  
        cout << "Enter Product ID: "; 
        cin >> id; 
  
        if (search(id) != -1) 
        { 
            cout << "Product already exists!\n"; 
            return; 
        } 
  
        cout << "Enter Product Name: "; 
        cin >> name; 
  
        cout << "Enter Price: "; 
        cin >> price; 
  
        cout << "Enter Stock: "; 
        cin >> stock; 
  
        if (price <= 0 || stock < 0) 
        { 
            cout << "Invalid price or stock!\n"; 
            return; 
        } 
  
        p[count++] = Product(id, name, price, stock); 
        cout << "Product Added Successfully!\n"; 
    } 
  
    void displayProducts() 
    { 
        if (count == 0) 
        { 
            cout << "No Products Available!\n"; 
            return; 
        } 
  
        for (int i = 0; i < count; i++) 
            p[i].display(); 
    } 
  
    void searchProduct() 
    { 
        int id; 
        cout << "Enter Product ID: "; 
        cin >> id; 
  
        int index = search(id); 
  
        if (index == -1) 
            cout << "Product Not Found!\n"; 
        else 
            p[index].display(); 
    } 
  
    void updatePrice() 
    { 
        int id; 
        double price; 
  
        cout << "Enter Product ID: "; 
        cin >> id; 
  
        int index = search(id); 
  
        if (index == -1) 
        { 
            cout << "Product Not Found!\n"; 
            return; 
        } 
  
        cout << "Enter New Price: "; 
        cin >> price; 
  
        if (price <= 0) 
        { 
            cout << "Invalid Price!\n"; 
            return; 
        } 
  
        p[index].price = price; 
        cout << "Price Updated Successfully!\n"; 
    } 
  
    void addStock() 
    { 
        int id, quantity; 
  
        cout << "Enter Product ID: "; 
        cin >> id; 
  
        int index = search(id); 
  
        if (index == -1) 
        { 
            cout << "Product Not Found!\n"; 
            return; 
        } 
  
        cout << "Enter Quantity: "; 
        cin >> quantity; 
  
        if (quantity <= 0) 
        { 
            cout << "Invalid Quantity!\n"; 
            return; 
        } 
  
        p[index].stock += quantity; 
        cout << "Stock Updated Successfully!\n"; 
    } 
  
    void recordSale() 
    { 
        int id, quantity; 
  
        cout << "Enter Product ID: "; 
        cin >> id; 
  
        int index = search(id); 
  
        if (index == -1) 
        { 
            cout << "Product Not Found!\n"; 
            return; 
        } 
  
        cout << "Enter Quantity Sold: "; 
        cin >> quantity; 
  
        if (quantity <= 0 || quantity > p[index].stock) 
        { 
            cout << "Invalid Quantity or Insufficient Stock!\n"; 
            return; 
        } 
  
        p[index].stock -= quantity; 
        p[index].sold += quantity; 
        p[index].revenue += quantity * p[index].price; 
  
        cout << "Sale Recorded Successfully!\n"; 
        cout << "Remaining Stock: " << p[index].stock; 
        cout << "\nSale Amount: Rs. " 
             << quantity * p[index].price << endl; 
    } 
  
    void salesReport() 
    { 
        int totalSold = 0; 
        double totalRevenue = 0; 
  
        cout << "\n===== DAILY SALES REPORT =====\n"; 
  
        for (int i = 0; i < count; i++) 
        { 
            cout << "\nProduct: " << p[i].name; 
            cout << "\nSold: " << p[i].sold; 
            cout << "\nRevenue: Rs. " << p[i].revenue << endl; 
  
            totalSold += p[i].sold; 
            totalRevenue += p[i].revenue; 
        } 
  
        cout << "\nTotal Items Sold: " << totalSold; 
        cout << "\nTotal Revenue: Rs. " << totalRevenue << endl; 
    } 
}; 
  
int main() 
{ 
    Vendor v; 
    int choice; 
  
    do 
    { 
        cout << "\n===== STREET VENDOR SYSTEM =====\n"; 
        cout << "1. Add Product\n"; 
        cout << "2. Display Products\n"; 
        cout << "3. Search Product\n"; 
        cout << "4. Update Price\n"; 
        cout << "5. Add Stock\n"; 
        cout << "6. Record Sale\n"; 
        cout << "7. Daily Sales Report\n"; 
        cout << "8. Exit\n"; 
  
        cout << "\nEnter Choice: "; 
        cin >> choice; 
  
        switch (choice) 
        { 
            case 1: v.addProduct(); break; 
            case 2: v.displayProducts(); break; 
            case 3: v.searchProduct(); break; 
            case 4: v.updatePrice(); break; 
            case 5: v.addStock(); break; 
            case 6: v.recordSale(); break; 
            case 7: v.salesReport(); break; 
            case 8: cout << "Thank You!\n"; break; 
            default: cout << "Invalid Choice!\n"; 
        } 
  
    } while (choice != 8); 
  
    return 0; 
} 
