#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void welcome(); // prototype

class Car
{
  public:
    void setName(string n)
    {
      name = n;
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
    void setState(string s)
    {
      state = s;
    };
    string getState()
    {
      return state;
    };
  private:
    string name, state;
    float price;
};

class User{
  private:
  string username, password;
  public:
  User(string u){
    username = u;
    password = "12345";
  };
  void setUsername(string n)
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
  void setPassword(string p){
    password = p;
  };
};

class AdminUser : public User
{
  public:
  AdminUser(string n):User(n)
  {
    //username = n;
   // setPassword("12345");
  };
  
  void see_reservations()
  {
    ifstream reservations; string line;
    reservations.open("reservations.txt");
    
    cout << " === All Reservations === " << endl;
    
    cout << " s/n " << " car " << " reserved by " << endl;
    cout << "___________________________________" <<endl;
    if(reservations.is_open())
    {
      while(getline(reservations, line))
      {
        cout << line << endl;
        cout <<endl;
      }
      reservations.close();
    }
    else{
      cout << " ERROR..." << endl;
    }
  };
  
  void add_car()
  {
    fstream carsFile; string line; static int counter= 0;
    ifstream cars; //reading file
    carsFile.open("allcars.txt", ios::out | ios::app);
    cars.open("allcars.txt");
    string carName; float carPrice;
    cout << "Add car " << endl;
    cout << " =============== " << endl;
    cout << "Enter car name ";
    cin >> carName;
    cout << "Enter car price ";
    cin >> carPrice;
    // setting car price name and price
    c.setName(carName); c.setPrice(carPrice);
    
    // writing to allcars 
    if(carsFile.is_open())
    {
      while(getline(cars, line))
      {
       // cout << " counter is " << counter <<endl;
        ++counter;
      }
      carsFile << counter <<" " << c.getName() << " " << c.getPrice() << " " << c.getState() << endl;
      carsFile.close();
    }else{
      cout << " Error in opening file " << endl;
    };
  };
  
  void remove_car()
  {
    cout << " remove car " << endl;
    displayAllCars();
    cout << "which cars do you want to remove ";
    //cin >> name;
  };
  
  void displayAllCars()
  {
    ifstream carFile; string line;
    carFile.open("allcars.txt");
    
    //
    if(carFile.is_open())
    {
      cout <<" id " <<  " name" << " price " << "status" << endl;
      while(getline(carFile, line))
      {
        cout << line << endl;
      }
    }
  };
  
  void displayMenu()
  {
    int op;
    cout << "Welcome, " << getUsername() << endl;
    cout << " Enter appropriate option to perfom operations " << endl;
    cout << " 1 = add cars \n " << " 2 = remove car \n " << " 3 = exit \n " << " 4 = display your reservations \n j ";
    do{
      cout << "\nEnter appropriate option to perfom operations \n enter your option >> ";
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
  private:
    Car c;
};

class Customer : public User
{
  public:
  Customer(string n):User(n)
  {
    //username = n;
  }
  void make_payment()
  {
    float amount;
    cout << " You are about to make payment " << endl;
  };
  void make_reservations()
  {
    string line, choice;
    
    ifstream carlist; 
    fstream reservationslist;
    reservationslist.open("reservations.txt", ios::in | ios::app);
    
    cout << " MAKE RESERVATIONS " << endl;
    cout << " ≠=============== " << endl;
    views_cars(); // display all available cars
    carlist.open("allcars.txt");
    // get user option on which cars he waants to resersed
    cout << "Enter choice (1,2,....10)";
    cin >> choice;
    
    if(carlist.is_open())
    {
      
      while(getline(carlist, line))
      {
        if(line.find(choice, 0) != string::npos)
        {
          // display all available cars
          cout << "you've reserved " << choice <<endl;
          reservationslist << line << endl;
          reservationslist.close();
          break;
        }else{
          cout << "no www!!! " <<endl;
        }
      }
      carlist.close();
    }else{
      cout << "errorr!!!!"<<endl;
    }
  };
  
  void cancel_reservation()
  {
    cout << " You are about to cancel reservations " << endl;
  };
  
  void views_cars()
  {
    ifstream cars; string line;
  
    cars.open("allcars.txt");
    cout << "All AVAILABLE CARS " << endl;
    //search through car file and display car listing if status available
    if(cars.is_open())
    {
      while(getline(cars, line))
      {
        if(line.find("available", 0) != string::npos)
        {
          // display all available cars
          cout << line << endl;
        }
      }
      cars.close();
    }
  };
  void see_reservations()
  {
    // function to see all reservations you've made
    cout << " you do not have any reservations" << endl;
  };
  
  void displayMenu()
  {
    int op;
    cout << "Welcome, " << getUsername() << endl;
    cout << " 1 = make reservations \n " << "2 = cancel reservations \n " << "3 = exit \n " << "4 = display your reservations \n " << endl;
    do{
      cout << " Enter appropriate option to perfom operations \n enter your option >> ";
      cin >> op;
      switch(op){
        case 1:
          make_reservations(); break;
        case 2: cancel_reservation(); break;
        case 3: cout << " ==== Exiting ==== " << endl; welcome(); break;
        case 4:
          see_reservations(); break;
      }
    }while(op != 3);
};
};

void welcome()
{ 
  int op; string n, p;
  cout << " ======= CAR RENTAL SYSTEM ====== \n\n" << endl;
  do 
  {
    cout << " Enter your role (user(1) / admin(2)) ";
    cin >> op;
    if(op == 1)
    {
      cout << "Enter your name >> ";
      cin >> n;
      Customer c(n);
      c.displayMenu(); // will display menu nwith functionality of Customer
    }
    else if(op == 2)
    {
      cout << " You must login you view admin panel " << endl;
      cout << "Enter your username >> ";
      cin >> n;
      cout << "Enter your password >> ";
      cin >> p;
      AdminUser a(n);
      if(a.getPassword() == p){
        a.displayMenu();
      };
    }else {
      cout << " invalid choose " << endl;
    };
  }while(op != 00);
};

int main()
{
  welcome();
  return 0;
}