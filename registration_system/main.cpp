#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

bool search(string n);

class Registration
{
  private: 
    string name, username, password, confirm_password;
    fstream user_records;
    //friend bool search(Registration, string n);
  public:
    //Registration();
    
    void login();
    void _register();
};

// methods implementations of registration class
void Registration::login()
{
  string en_user, en_password; // entered password or username
  do{
    cout << "Enter username: ";
    cin >> en_user;
    cout << "Enter password: ";
    cin >> en_password;
    if(search(en_user))
    {
      if(en_password == password)
      {
        cout << en_user  <<" you have successfully logged in" << endl; 
      }else{
        cout << en_user  <<" you entered a wrong password" << endl;
      }
    }else{
      cout <<" INVALID DETAILS!!!" << endl;
    }
  }
  while (!(search(en_user) && password == en_password));
  
}

void Registration::_register()
{
  char state = 'n';
  cout <<"  ===== REGISTER  ====  \n\n" << endl;
  do{
    cout << "Enter your name: ";
    cin >> name;
    do{
      cout << "Enter your username: ";
      cin >> username;
    }while((search(username)));
    do{
      cout << "Enter your password: ";
      cin >> password;
      cout << "confirm your password: ";
      cin >> confirm_password;
    }while(password != confirm_password);
    
    // store information in user_records
    user_records.open("user_records.txt", ios::in | ios::app);
    if(user_records.is_open())
    {
      user_records << name << " " << username << " " << " " << password << endl;
      user_records.close();
      cout << username << " your account creation was successfully.. " << endl;
      state = 's';
    }else{
      cout << "ERROR OCCURRED!!! file cannot be opened.. try again";
    }
  }while(state != 's');
}


bool search(string n)
{
  string line; bool st;
  ifstream user_records;
  user_records.open("user_records.txt");
  if(user_records.is_open())
  {
    while(getline(user_records, line))
    {
      if(line.find(n, 0) != string::npos)
      {
        cout << "username already exist \ntry again"<<endl;
        st = true;
        break;
      }
      else{
        st = false;
      }
    }
    user_records.close();
  }
  return st;
}

int main()
{
  Registration r;
  //r.login();
  r._register();
}