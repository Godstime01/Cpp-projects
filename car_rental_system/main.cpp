#include <iostream>
#include <string>

using namespace std;

class User{
  private:
  string username, password;
  public:
  User(string u){
    username = u;
    password = NULL;
  };
  string setUsername(string n)
  {
    username = n;
  };
  string getUsername(){
    return username;
  };
  string getPassword()
  {
    return password;
  };
  //string setPassword();
};


class AdminUser : public User
{
  public:
  AdminUser(string n):User(n)
  {
    username = n;
    password = "12345";
  };
  void see_reservations()
  {
    cout << "No reservations " << endl;
  };
  void add_car()
  {
    cout << " add car " << endl;
  };
  void remove_car()
  {
    cout << " remove car " << endl;
  };
  
  void displayMenu()
  {
    int op;
    cout << "Welcome, " << username << endl;
    cout << " Enter appropriate option to perfom operations " << endl;
    cout << " 1 = add cars \n " << " 2 = remove car \n " << " 3 = exit \n " << " 4 = display your reservations \n enter your option >> ";
    do{
      cin >> op;
      switch(op){
        case 1:
          add_car(); break;
        case 2: remove_car(); break;
        case 3: cout << " ==== Exiting ==== " << endl;break;
        case 4:
          see_reservations(); break;
      }
    }while(op != 3);
  };
  
};


class Customer : public User
{
  public:
  Customer(string n):User(n)
  {
    username = n;
  }
  void make_payment()
  {
    float amount;
    cout << " You are about to make payment " << endl;
  };
  void make_reservations()
  {
    cout << " You are about to make reservations " << endl;
  };
  void cancel_reservation()
  {
    cout << " You are about to cancel reservations " << endl;
  };
  void views_cars()
  {
    cout << "All cars" << endl;
  };
  void see_reservations()
  {
    // function to see all reservations you've made
    cout << " you do not have any reservations" << endl;
  };
  void displayMenu()
  {
    int op;
    cout << "Welcome, " << username << endl;
    cout << " Enter appropriate option to perfom operations " << endl;
    cout << " 1 = make reservations \n " << " 2 = cancel reservations \n " << " 3 = exit \n " << " 4 = display your reservations \n enter your option >> ";
    do{
      cin >> op;
      switch(op){
        case 1:
          make_reservations(); break;
        case 2: cancel_reservation(); break;
        case 3: cout << " ==== Exiting ==== " << endl;break;
        case 4:
          see_reservations(); break;
      }
    }while(op != 3)
  };
}

class Car
{
  public:
    void setName(string n, float p)
    {
      name = n;
      price = p;
      state = "available";
    };
    string getName(){
      return name;
    };
    float getPrice()
    {
      return price;
    };
    void setPrice(float p)
    {
      price = p;
    };
    void setState(float s)
    {
      state = s;
    };
    floating getState()
    {
      return state;
    };
  private:
    string name, state;
    float price;
}



void welcome()
{ int op; string n;
  cout << " ======= CAR RENTAL SYSTEM ====== \n\n" <<endl;
  do 
  {
    cout << " Enter your role (user(1) / admin(2)) ";
    cin >> op;
    switch(op)
    {
      case 1:
      cout << "Enter your name >> ";
      cin >> n;
        Customer c(n);
        c.displayMenu(); // will display menunwith functionality of Customer
        break;
       case 2:
       cout << " You must login you view admin panel " << endl;
       cout << "Enter your username >> ";
       cin >> n;
       cout << "Enter your password >> ";
       cin >> p;
       AdminUser a(n);
       if(a.getPassword() == p){
         a.displayMenu();
       }else{
         cout << " wrong password " << endl;
       }
       break;
    }
  }while(op != 00)
}

int main()
{
  welcome();
  return 0;
}