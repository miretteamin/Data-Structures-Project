/**
 * @author Nader Atef 20190575 S28
 * @author Paula Adel 20190139 S28
 * Created on 11/7/2021
 */


#include <iostream>
#include "TreapTree.h"
#include "User.h"
#include "List.h"
#include <fstream>

using namespace std;

int getNLines(const string& filePath){
  fstream  in;
  in.open(filePath);
  string tmp;
  int counter =0;
  while (!in.eof()) {
        getline(in, tmp);
        tmp.clear();
        counter +=1;
  }
  in.close();
  return counter;
}


string rLeadingSpaces(const string& s)
{
    string WHITESPACE =" \n";
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string rTrailingSpaces(const string& s)
{
    string WHITESPACE =" \n";

    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string& s) {
    return rTrailingSpaces(rLeadingSpaces(s));
}


void userMenu(){
    cout << "1- List all friends\n" <<
            "2- Search for a friend by username\n" <<
            "3- Add friend\n" <<
            "4- Remove friend\n" <<
            "5- People you may know\n" <<
            "6- logout\n";
}

void splitLine(const string& s, char c, string *v) {
    int i = 0;
    int j = (int)s.find(c);
    int counter =0;
    while (j >= 0) {
        string str = s.substr(i, j-i);
        v[counter] = str;
        counter +=1;
        i = ++j;
        j = (int)s.find(c, j);
        if (j < 0) {
            v[counter] = trim(s.substr(i, s.length()));
            counter +=1;
        }
    }
}


void loadInFile(ifstream& in, string  **data,int nColumns) {

    string tmp;

    if (!in.is_open()){
        cout << "wrong path" <<endl;
        return;
    }
    int counter =0;
    while (!in.eof()) {
        getline(in, tmp);
        string *p = new string[nColumns] ;
        splitLine(tmp, ',', p);
        data[counter] = p ;
        counter+=1;
        tmp.clear();
    }
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();

    ifstream fs;

    int nLines = getNLines("..\\Project\\users.in");
//    int  nLines =9;
    string  **usersFile2DVector = new string*[nLines];

    fs.open("..\\Project\\users.in");
    loadInFile(fs, usersFile2DVector,3);
    List users;
    fs.close();
    for (int i=0;i<nLines;i++){
         User *u =  new User(usersFile2DVector[i][0],usersFile2DVector[i][1],usersFile2DVector[i][2]);
         users.insert(u);
    }

    ifstream fs2 ;
    nLines = getNLines("..\\Project\\usersrelations.in");
    fs2.open("..\\Project\\usersrelations.in");
    string **usersRelations2DVector =  new string*[nLines];

    loadInFile(fs2 , usersRelations2DVector,2);

    fs2.close();

    for (int i=0;i<nLines;i++){
        User *u = users.search(usersRelations2DVector[i][0]);
        User *u1 = users.search(usersRelations2DVector[i][1]);
        u->getFriends().insert(u1);
        u1->getFriends().insert(u);
    }

    while(true){
        cout << "Enter the username to login or 'exit' to close the app \n";
        string choice;
        cin >> choice;
        if (choice =="exit"){
            break;
        }
        User *loggedInUser = users.search(choice);
        if (loggedInUser == nullptr) {
            cout << "username doesn't exist\n";
            continue;
        }
        while (true){
            userMenu();
            string userChoice;
            cin >> userChoice;
            if(userChoice == "1"){
                loggedInUser->getFriends().printInOrder();
                cout << '\n';
            }else if (userChoice=="2"){
                cout << "Enter the username: " ;
                string usernameSearch ;
                cin >> usernameSearch;
                User *hisFriend = loggedInUser->getFriends().search(usernameSearch);
                if (hisFriend == nullptr ) {
                    cout << "not found" <<endl;
                }

                cout << hisFriend->getUsername() << ", " << hisFriend->getName() << ", " << hisFriend->getEmail() << '\n';

            }else if (userChoice == "3"){
                cout << "Enter your friend's username\n" ;
                string fusername;
                cin >> fusername;
                User *u =  users.search(fusername);
                if (u== nullptr){
                    cout << "user not found" <<endl;
                }else{
                    if (loggedInUser->getFriends().search(fusername) == nullptr){
                        loggedInUser->getFriends().insert(u);
                        u->getFriends().insert(loggedInUser);
                        cout << "You are now friends" <<endl;
                    }else {
                        cout << "You are already friends" <<endl;
                    }

                }
            }else if (userChoice =="4"){
                cout<<"Enter your friend's username\n";
                string fusername;
                cin>>fusername;
                User *u = loggedInUser->getFriends().search(fusername);
                if(u != nullptr){
                    loggedInUser->getFriends().deleteUser(fusername);
                    u->getFriends().deleteUser(loggedInUser->getUsername());
                    cout << "Done\n";
                }
            }else if (userChoice == "5"){
                int counter = 0;
                for (int i = 0; i<users.getSize() && counter < 5; i++){
                    User *u = users[i];
                    if(u->getUsername() != loggedInUser->getUsername() && loggedInUser->getFriends().search(u->getUsername()) == nullptr){
                        cout<<u->getUsername() << " , "<< u->getName()<<endl;
                        counter++;
                    }
                }
            }else if (userChoice == "6"){
                break;
            }
        }


    }



    return 0;
}