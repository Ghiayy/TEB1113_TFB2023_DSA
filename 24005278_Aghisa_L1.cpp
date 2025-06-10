/*
 ID: 24005278
 Name: Aghisa Zahra
 */

 #include <iostream>
using namespace std;

struct Student{
    int id;
    string name;
    int contact;
    string email;
};

int main() {
    
    Student students[5];
    
    for (int i=0; i<5;i++){
        cout<<"\nStudent #"<<i+1<<": "<<endl;
        cout<<"ID: ";
        cin>>students[i].id;
        
        cin.ignore();
        cout<<"Name: ";
        getline (cin,students[i].name);
        
        cout<<"Contact: ";
        cin>>students[i].contact;
        
        cin.ignore();
        cout<<"email: ";
        getline (cin,students[i].email);
    }
    
    for (int i=0; i<5; i++){
        cout<<"****************************"<<endl;
        cout<<"Student "<<i+1<<endl;
        cout<<"ID: "<<students[i].id<<endl;
        cout<<"Name: "<<students[i].name<<endl;
        cout<<"Contact: "<<students[i].contact<<endl;
        cout<<"Email: "<<students[i].email<<endl;
    }
      
    
    
    
    return 0;
}

