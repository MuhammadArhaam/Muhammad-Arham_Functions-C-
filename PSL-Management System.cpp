#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void addPlayer() 
{
    ofstream playersfile1;
    playersfile1.open("players.txt", ios::app);
    string name, team, role;
    int runs, wickets;
    cin.ignore();
    cout << "Enter Player Name= ";
    getline(cin, name);
    cout << "Enter Team Name= ";
    getline(cin, team);
    cout << "Enter Role (batsman/bowler/all-rounder)= ";
    getline(cin, role);
    cout << "Enter Total Runs= ";
    cin >> runs;
    cout << "Enter Total Wickets= ";
    cin >> wickets;
    playersfile1 << name << "," << team << "," << role << "," << runs << "," << wickets << endl;
    playersfile1.close();
    cout << "Player added successfully" << endl;
}
void viewAllPlayers()
{
    ifstream playersfile2;
    playersfile2.open("players.txt");
    string name, team, role, runs, wickets;
    cout << endl;
    cout << "Name\t\tTeam\t\tRole\t\tRuns\t\tWickets" << endl;
    while (getline(playersfile2, name, ',')) 
    {
        getline(playersfile2, team, ',');
        getline(playersfile2, role, ',');
        getline(playersfile2, runs, ',');
        getline(playersfile2, wickets);
        cout << name << "\t" << team << "\t" << role << "\t" << runs << "\t" << wickets << endl;
    }
    playersfile2.close();
}
void searchPlayer()
{
    ifstream playersfile2;
    playersfile2.open("players.txt");
    string choice, keyword, name, team, role, runs, wickets;
    int option;
	cout << "Search by" << endl;
    cout << "1. Name" << endl;
    cout << "2. Team" << endl;
    cout<<"Enter choice=";
    cin >> option;
    cin.ignore();
    cout << "Enter search keyword= ";
    getline(cin, keyword);
    bool found = false;
    while (getline(playersfile2, name, ',')) 
    {
        getline(playersfile2, team, ',');
        getline(playersfile2, role, ',');
        getline(playersfile2, runs, ',');
        getline(playersfile2, wickets);
        if ((option == 1 && name == keyword) || (option == 2 && team == keyword))
        {
            cout << "\nName: " << name << "\nTeam: " << team << "\nRole: " << role << "\nRuns: " << runs << "\nWickets: " << wickets << endl;
            found = true;
        }
    }
    if (!found)
    {
    cout << "No matching player found" << endl;
    }
    playersfile2.close();
}
void updateStats() 
{
    ifstream playersfile2;
    playersfile2.open("players.txt");
    ofstream tempfile;
    tempfile.open("temp.txt");
    string name, team, role, runsStr, wicketsStr, target;
    int runs, wickets, choice, newStat;
    bool found = false;
    cin.ignore();
    cout << "Enter Player Name to update stats= ";
    getline(cin, target);
    while (getline(playersfile2, name, ',')) {
        getline(playersfile2, team, ',');
        getline(playersfile2, role, ',');
        getline(playersfile2, runsStr, ',');
        getline(playersfile2, wicketsStr);
        runs = stoi(runsStr);
        wickets = stoi(wicketsStr);
        if (name == target)
        {
            found = true;
            cout << "Update" << endl;
            cout << "1. Runs" << endl;
            cout<<"2. Wickets" << endl;
            cout<<"Enter choice=";
            cin >> choice;
            cout << "Enter new value= ";
            cin >> newStat;
            if (choice == 1)
            {
               runs = newStat;
            }
            else if (choice == 2)
            {
               wickets = newStat;
            }
            cout << "Stats updated successfully" << endl;
        }
        tempfile << name << "," << team << "," << role << "," << runs << "," << wickets << endl;
    }
    playersfile2.close();
    tempfile.close();
    remove("players.txt");
    rename("temp.txt", "players.txt");
    if (!found)
    {
    cout << "Player not found" << endl;
    }
}
void deletePlayer()
{
    ifstream playersfile2;
    playersfile2.open("players.txt");
    ofstream tempfile;
    tempfile.open("temp.txt");
    string name, team, role, runs, wickets, target;
    bool found = false;
    cin.ignore();
    cout << "Enter Player Name to delete= ";
    getline(cin, target);
    while (getline(playersfile2, name, ',')) 
    {
        getline(playersfile2, team, ',');
        getline(playersfile2, role, ',');
        getline(playersfile2, runs, ',');
        getline(playersfile2, wickets);
        if (name == target)
        {
            found = true;
            continue;
        }
        tempfile << name << "," << team << "," << role << "," << runs << "," << wickets << endl;
    }
    playersfile2.close();
    tempfile.close();
    remove("players.txt");
    rename("temp.txt", "players.txt");
    if (found)
    {
        cout << "Player deleted successfully" << endl;
    }
    else
    {
        cout << "Player not found" << endl;
    }
}
void menu()
{
    int choice;
    do 
    {
        cout << endl;
        cout << "PSL Management System" << endl;
        cout << "1. Add Player Record" << endl;
        cout << "2. View All Players" << endl;
        cout << "3. Search Player by Name or Team" << endl;
        cout << "4. Update Player Stats" << endl;
        cout << "5. Delete Player Record" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice= ";
        cin >> choice;
        switch (choice) 
        {
        case 1: 
            addPlayer(); 
            break;
        case 2: 
            viewAllPlayers(); 
            break;
        case 3: 
            searchPlayer(); 
            break;
        case 4: 
            updateStats();
            break;
        case 5: 
            deletePlayer(); 
            break;
        case 0: 
            cout << "Exiting" << endl;
            break;
        default: 
            cout << "Invalid choice. Try again" << endl;
        }
    } 
    while (choice != 0);
}
int main() 
{
    menu();
    return 0;
}
