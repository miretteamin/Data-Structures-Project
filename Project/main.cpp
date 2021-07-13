#include <iostream>
#include "TreapTree.h"
#include "User.h"
#include "List.h"
#include <fstream>
#include <vector>

using namespace std;



string ltrim(const string &s)
{
    string WHITESPACE = " \n\r\t\f\v";
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s)
{
    string WHITESPACE = " \n\r\t\f\v";
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s) {
    return rtrim(ltrim(s));
}


void userMenu(){
    cout << "1- List all friends\n" <<
            "2- Search by username\n" <<
            "3- Add friend\n" <<
            "4- Remove friend\n" <<
            "5- People you may know\n" <<
            "6- logout\n";
}

void splitLine(const string& s, char c, vector<string> &v) {
    int i = 0;
    int j = (int)s.find(c);

    while (j >= 0) {
        string str = s.substr(i, j-i);
        v.push_back(str);
        i = ++j;
        j = (int)s.find(c, j);
        if (j < 0) {
            v.push_back(trim(s.substr(i, s.length())));
        }
    }
}


void loadInFile(ifstream& in, vector<vector<string>>& data) {

    string tmp;

    if (!in.is_open()){
        cout << "wrong path" <<endl;
        return;
    }
    while (!in.eof()) {
        getline(in, tmp);
//        cout << tmp <<endl;
        vector<string> p ;

        splitLine(tmp, ',', p);

        data.push_back(p);

        tmp.clear();
    }
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
//	TreapTree t;
//	for (int i = 0; i < 50; i++)
//	{
//		User* u = new User("", "", "");
//		string s = " ";
//		s[0] = (char)i + 48;
//		u->setUsername(s);
//		t.insert(u);
//	}
//
//	t.print2D();
//	cout << "====================================" << endl;
//	t.deleteUser("@");
//	t.print2D();

    ifstream fs;

    vector<vector<string>> usersFile2DVector;


    fs.open("..\\Project\\users.in");
    loadInFile(fs, usersFile2DVector);
    List users;
    fs.close();
    for (auto & i : usersFile2DVector){
         User *u =  new User(i[0],i[1],i[2]);
         users.insert(u);
    }

    ifstream fs2 ;

    fs2.open("..\\Project\\usersrelations.in");
    vector<vector<string>> usersRelationsFile2DVector;

    loadInFile(fs2 , usersRelationsFile2DVector);

    fs2.close();

    for (auto & i : usersRelationsFile2DVector){
        User *u = users.search(i[0]);
        User *u1 = users.search(i[1]);

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
                    loggedInUser->getFriends().insert(u);
                    u->getFriends().insert(loggedInUser);
                    cout << "you are now friends" <<endl;
                }
            }else if (userChoice =="4"){

            }else if (userChoice == "5"){

            }else if (userChoice == "6"){
                break;
            }
        }


    }



    return 0;
}