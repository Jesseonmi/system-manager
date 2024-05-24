/*
Copyright 2024 @ Seonmi Jung. All rights reserved.

No one will have the rights to copy or reuse any part of this code, as any copy or reuse of the code found by our moderators would be immediately reported without a caution.

* Contact Information *
Moderator Team: seonmijung.projectmoderatorteam@yahoo.com
Instagram: @seonmi.jung
Discord: seonmijung
Website: jesseonmi.github.io

My email address is on my website. Click on 'Send Email' and it will automatically fill the receiver as my email on your default email app.
*/

#include <iostream>
#include <Windows.h>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <conio.h>
using namespace std;

int main() {
  bool loop = true;

  while (loop) {
    cout << "Welcome to your System Manager." << endl;
    cout << "See the status of your computer at once, and manage it." << endl;
    cout << endl << "Press any key to start." << endl;
    _getch();
    system("cls");

    DWORD username_len = 256;
    char *username = new char[username_len];
    if (GetUserNameA(username, &username_len)) cout << "Username: " << username << endl;
    else cerr << "Failed to get username." << endl;


    SYSTEM_POWER_STATUS power_status;
    if (GetSystemPowerStatus(&power_status)) {
      if (static_cast<int> (power_status.BatteryLifePercent != 255)) cout << "Battery Level: " << static_cast<int> (power_status.BatteryLifePercent) << '%' << endl;
      else cout << "Battery Level: Unknown" << endl;
    }

    if (system("ping -n 1 google.com | findstr \"Reply from\"") == true) {
      system("cls");
      cout << "Username: " << username << endl;
      if (static_cast<int> (power_status.BatteryLifePercent != 255)) cout << "Battery Level: " << static_cast<int> (power_status.BatteryLifePercent) << '%' << endl;
      else cout << "Battery Level: Unknown" << endl;
      cout << "Network: No Internet" << endl;

      delete[] username;
    }

    else {
      system("cls");
      cout << "Username: " << username << endl;
      if (static_cast<int> (power_status.BatteryLifePercent != 255)) cout << "Battery Level: " << static_cast<int> (power_status.BatteryLifePercent) << '%' << endl;
      else cout << "Battery Level: Unknown" << endl;
      cout << "Network: Connected" << endl;

      delete[] username;
    }

    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    string s(30, '\0');
    strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", localtime(&now));
    cout << "Date: " << s << endl;

    cout << "\nInsert any command to perform additional process. Any unknown command restart the program." << endl;
    cout << "-> ";
    string command;
    cin >> command;

    if (command == "!shutdown") system("shutdown -s");
    else if (command == "!rerun") loop = true;
    else if (command == "!restart") system("shutdown /r");
    else loop = true;
  }
}