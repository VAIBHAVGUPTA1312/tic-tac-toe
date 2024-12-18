#include <bits/stdc++.h>
using namespace std;

void drawBoard(char *pos);
void drawPlayer(char *pos, char p);
void drawComputer(char *pos, char c);
bool checkWinner(char *pos, char p, char c);
bool checkTie(char *pos);

int main()
{
    system("cls");
    bool running = true;
    char pos[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    cout << "This is the number grid for placement: " << endl;
    cout << " 1 | " << "2 | " << "3 " << endl;
    cout << "---|---|---\n";
    cout << " 4 | " << "5 | " << "6 " << endl;
    cout << "---|---|---\n";
    cout << " 7 | " << "8 | " << "9 " << endl;

    char p, c;
    cout << "Enter you desired shape x/o: ";
    cin >> p;
    c = (p == 'x') ? 'o' : 'x';
    drawBoard(pos);

    while (running)
    {
        drawPlayer(pos, p);
        drawBoard(pos);
        if (checkWinner(pos, p, c))
        {
            running = false;
            break;
        }
        else if (checkTie(pos))
        {
            running = false;
            break;
        }

        drawComputer(pos, c);
        drawBoard(pos);
        if (checkWinner(pos, p, c))
        {
            running = false;
            break;
        }
        else if (checkTie(pos))
        {
            running = false;
            break;
        }
    }

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();
}

void drawBoard(char *pos)
{
    system("cls");
    cout << endl;
    cout << " " << pos[0] << " |" << " " << pos[1] << " |" << " " << pos[2] << endl;
    cout << "---|---|---\n";
    cout << " " << pos[3] << " |" << " " << pos[4] << " |" << " " << pos[5] << endl;
    cout << "---|---|---\n";
    cout << " " << pos[6] << " |" << " " << pos[7] << " |" << " " << pos[8] << endl;
}

void drawPlayer(char *pos, char p)
{
    int tempPos;
    do
    {
        cout << "Enter next position to mark: ";
        cin >> tempPos;
        tempPos--;
        if (pos[tempPos] == ' ')
        {
            pos[tempPos] = p;
            break;
        }
    } while (!tempPos > 0 || !tempPos < 8);
}

void drawComputer(char *pos, char c)
{
    srand(time(0));

    while (true)
    {
        int temp = rand() % 9;
        if (pos[temp] == ' ')
        {
            pos[temp] = c;
            break;
        }
    }
}

bool checkWinner(char *pos, char p, char c)
{
    if (pos[0] != ' ' && pos[0] == pos[1] && pos[1] == pos[2])
    {
        pos[0] == p ? cout << "You Win :D\n" : cout << "You Lose :/\n";
    }
    else if (pos[3] != ' ' && pos[3] == pos[4] && pos[4] == pos[5])
    {
        pos[3] == p ? cout << "You Win :D\n" : cout << "You Lose :/\n";
    }
    else if (pos[6] != ' ' && pos[6] == pos[7] && pos[7] == pos[8])
    {
        pos[6] == p ? cout << "You Win :D\n" : cout << "You Lose :/\n";
    }
    else if (pos[0] != ' ' && pos[0] == pos[3] && pos[3] == pos[6])
    {
        pos[0] == p ? cout << "You Win :D\n" : cout << "You Lose :/\n";
    }
    else if (pos[1] != ' ' && pos[1] == pos[4] && pos[4] == pos[7])
    {
        pos[1] == p ? cout << "You Win :D\n" : cout << "You Lose :/\n";
    }
    else if (pos[2] != ' ' && pos[2] == pos[5] && pos[5] == pos[8])
    {
        pos[2] == p ? cout << "You Win :D\n" : cout << "You Lose :/\n";
    }
    else if (pos[0] != ' ' && pos[0] == pos[4] && pos[4] == pos[8])
    {
        pos[0] == p ? cout << "You Win :D\n" : cout << "You Lose :/\n";
    }
    else if (pos[2] != ' ' && pos[2] == pos[4] && pos[4] == pos[6])
    {
        pos[2] == p ? cout << "You Win :D\n" : cout << "You Lose :/\n";
    }
    else
    {
        return false;
    }

    return true;
}

bool checkTie(char *pos)
{
    for (int i = 0; i < 9; i++)
    {
        if (pos[i] == ' ')
        {
            return false;
        }
    }

    return true;
}