#include<iostream>
#include<vector>
using namespace std;

class product{
    public:
    double price;
    string product_id;
    product(double price,string product_id){
        this->price=price;
        this->product_id=product_id;
    }
};
class shopping_cart{
    private:
    vector<product*> products;
    public:
    void add_product(product* p){
        products.push_back(p);
    }
    const vector<product*>& get_products(){
        return products;
    }
    double calculate_total(){
        double total=0;
        for(auto p:products){
            total+=p->price;
        }
        cout<<"Total: Rs "<<total<<endl;
        return total;
    }
};
class invoice{
    private:
    shopping_cart* invoive_cart;
    public:
    invoice(shopping_cart* invoice_cart){
        this->invoive_cart=invoice_cart;
    }
    void print_invoice(){
        cout<<"Invoice:\n";
        for(auto p:invoive_cart->get_products()){
            cout<<p->product_id<<" - Rs "<<p->price<<endl;
        }
        cout << "Total: Rs " << invoive_cart->calculate_total() << endl;
    }
};
class cart_db_storage{
    private:
    shopping_cart* storage_cart;
    public:
    cart_db_storage(shopping_cart* storage_cart){
        this->storage_cart=storage_cart;
    }
    void save_to_db(){
        cout<<"Saving shopping cart to database..."<<endl;
    }
    
};


int main() {
    shopping_cart* cart = new shopping_cart();

    cart->add_product(new product(50000, "Laptop"));
    cart->add_product(new product(2000, "Mouse"));

    invoice* printer = new invoice(cart);
    printer->print_invoice();

    cart_db_storage* db = new cart_db_storage(cart);
    db->save_to_db();

    return 0;
}