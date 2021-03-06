//
// Created by mac on 2018/8/28.
// Handler interface
//

#include "../user/user.h"
#include "../util/user.h"
#include "../user/base.h"
#include "../user/file.h"
#include "../user/methods.h"
#include "../util/checkAccount.h"
using namespace std;

int main(int argc, char const *argv[]) {
  User user;
  userNode *u;

  // set default user;
  int uid = 0;
  string upasswd;
  string uname;
  string uaddress;
  string utel;

  char choice;

  system("clear");

  if (argc < 2) {
    cerr << ("Please use '-h' or '--help' get help.\n");
    return -1;
  } else if ((strcmp(argv[1], "-g") == 0) || (strcmp(argv[1], "--gui") == 0)) {
    userMenu();
    return 0;
  } else if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
    cout << ("Usage:\n");
    cout << ("-g or --gui                  \t --Graphical display function.           \n");
    cout << ("-h or --help                 \t --get exec help.                        \n");
    cout << ("-v or --version              \t --get app version.                      \n");
    cout << ("-i or --init                 \t --Init user information.                \n");
    cout << ("-c or --create               \t --Create user information.              \n");
    cout << ("-d or --delete               \t --Delete user information.              \n");
    cout << ("-s or --show                 \t --Search user information.              \n");
    cout << ("-m or --modify               \t --Modify user information.              \n");
    cout << ("-e -s                        \t --extend function (sort by user id).    \n");
    cout << ("-e -c                        \t --extend function (classify by user id).\n");
    cout << ("-e -d                        \t --extend function (display by user id). \n");
    return 0;
  } else if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)) {
    cout << ("Book store version 0.1.0\n");
    cout << ("Thread model: posix\n");
    cout << ("InstalledDir: /Library/Developer/CommandLineTools/usr/bin\n");
    return 0;
  } else if ((strcmp(argv[1], "-i") == 0) || (strcmp(argv[1], "--init") == 0)) {
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(45) << ("|Init   user information|\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << ("Init user info?(y/N)? ");
    cin >> choice;
    if (choice == 'y') {
      user.userInit();
      cout << ("Updating user info...\n");
      user.userSave();
      return 0;
    } else if (choice == 'N') {
      cerr << ("User operator cancel.\n");
      return -1;
    }

  } else if ((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "--create") == 0)) {
    if (!systemEnder()) {
      cerr << ("System ender error.\n");
      return -1;
    }
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(45) << ("|Insert user information|\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << ("Id: ");
    cin >> uid;
    if (!checkAccount(to_string(uid))) {
      cerr << ("Account id is exist!\n");
      return -1;
    }
    cout << ("Password: ");
    cin >> upasswd;
    cout << ("Name: ");
    cin >> uname;
    cout << ("Address: ");
    cin >> uaddress;
    cout << ("Telephone: ");
    cin >> utel;
    user.userInsert(uid, upasswd, uname, uaddress, utel);
    cout << ("Insert user id [") << uid << ("] info complete!\n");
    user.userSave();
    return 0;
  } else if ((strcmp(argv[1], "-d") == 0) || (strcmp(argv[1], "--delete") == 0)) {
    user.userRead();
    if (!systemEnder()) {
      cerr << ("System ender error.\n");
      return -1;
    }
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(45) << ("|Delete user information|\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << ("Id: ");
    cin >> uid;
    if (!checkAccount(to_string(uid))) {
      cerr << ("Account id is exist!\n");
    } else {
      cerr << ("Account id don't exist.\n");
      return -1;
    }
    cout << ("Delete or delete after deletion(y/N)? ");
    cin >> choice;
    if (choice == 'y') {
      user.userDelete(uid);
      cout << ("Delete user id [") << uid << ("] info complete!\n");
      user.userSave();
      cout << ("Updating user info...\n");
      return 0;
    } else if (choice == 'N') {
      cerr << ("User operator cancel.\n");
      return -1;
    }
  } else if ((strcmp(argv[1], "-s") == 0) || (strcmp(argv[1], "--show") == 0)) {
    user.userRead();
    if (!systemEnder()) {
      cerr << ("System ender error.\n");
      return -1;
    }
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(45) << ("|Search user information|\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << ("Id: ");
    cin >> uid;
    if (!checkAccount(to_string(uid))) {
      cerr << ("Account id is exist!\n");
    } else {
      cerr << ("Account id don't exist.\n");
      return -1;
    }
    u = user.userFind(uid);
    cout.flags(ios::left);
    cout << ("id:") << u->id << (" password:") << u->passwd << (" name:") << u->name << (" address:") << u->address
         << (" telephone:") << u->tel;
    return 0;
  } else if ((strcmp(argv[1], "-m") == 0) || (strcmp(argv[1], "--modify") == 0)) {
    user.userRead();
    if (!systemEnder()) {
      cerr << ("System ender error.\n");
      return -1;
    }
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(45) << ("|Modify user information|\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << ("Id: ");
    cin >> uid;
    if (!checkAccount(to_string(uid))) {
      cerr << ("Account id is exist!\n");
    } else {
      cerr << ("Account id don't exist.\n");
      return -1;
    }
    cout << ("Password: ");
    cin >> upasswd;
    cout << ("Name: ");
    cin >> uname;
    cout << ("Address: ");
    cin >> uaddress;
    cout << ("Telephone: ");
    cin >> utel;
    // modify user info.
    cout << ("Do you want to modify this information(y/N)? ");
    cin >> choice;
    if (choice == 'y') {
      user.userModify(uid, upasswd, uname, uaddress, utel);
      cout << ("Modify user id [") << uid << ("] info complete!\n");
      user.userSave();
      cout << ("Updating user info...\n");
      return 0;
    } else if (choice == 'N') {
      cerr << ("User operator cancel.\n");
      return -1;
    }
  } else if ((strcmp(argv[1], "-e") == 0) && (strcmp(argv[2], "-s") == 0)) {
    user.userRead();
    cout << "Ascending Order or Descending Order (a/d/N): ";
    cin >> choice;
    if (choice == 'a') {
      user.userSort('>');
      return 0;
    } else if (choice == 'd') {
      user.userSort('>');
      return 0;
    } else if (choice == 'N') {
      cerr << ("User operator cancel.\n");
      return -1;
    } else
      user.userSort('>');
    return 0;
  } else if ((strcmp(argv[1], "-e") == 0) && (strcmp(argv[2], "-c") == 0)) {
    user.userRead();
    cout << "classification: (y/N): ";
    cin >> choice;
    if (choice == 'y') {
      user.userClassify();
      return -1;
    } else if (choice == 'N') {
      cerr << ("User operator cancel.\n");
      return -1;
    }
  } else if ((strcmp(argv[1], "-e") == 0) && (strcmp(argv[2], "-d") == 0)) {
    user.userRead();
    cout << "Display user info: (y/N): ";
    cin >> choice;
    if (choice == 'y') {
      user.disUserInfo();
      return 0;
    } else if (choice == 'N') {
      cerr << ("User operator cancel.\n");
      return -1;
    }
  } else {
    if (argc > 1) {
      cerr.flags(ios::adjustfield);
      cerr << setw(50) << ("Unknown command!\n");
    } else {
      cerr << ("Please use '-h' or '--help' get help\n");
      return -1;
    }
  }
}