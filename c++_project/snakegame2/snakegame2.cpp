#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <chrono>
#include <thread>
#include <vector> // Include vector header for obstacles
using namespace std;

const int width = 80;
const int height = 20;
const int gameDuration = 180; // 게임 지속 시간(초)

int x, y;
int fruitCordX, fruitCordY;
int playerScore;
int snakeTailX[100], snakeTailY[100];
int snakeTailLen;
enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
snakesDirection sDir;
bool isGameOver;

vector<pair<int, int>> obstacles; // Vector to hold obstacle coordinates

void GameInit()
{
    isGameOver = false;
    sDir = STOP;
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
    snakeTailLen = 0;
}

void GameRender(string playerName, int remainingTime)
{
    string buffer;

    buffer += "+";
    for (int i = 0; i < width; i++)
        buffer += "-";
    buffer += "+\n";

    for (int i = 0; i < height; i++) {
        buffer += "|";
        for (int j = 0; j < width; j++) {
            if (i == y && j == x)
                buffer += "O";
            else if (i == fruitCordY && j == fruitCordX)
                buffer += "#";
            else {
                bool prTail = false;
                for (int k = 0; k < snakeTailLen; k++) {
                    if (snakeTailX[k] == j && snakeTailY[k] == i) {
                        buffer += "o";
                        prTail = true;
                        break; // 한 번만 출력하도록 하기 위해 추가
                    }
                }
                if (!prTail) {
                    bool isObstacle = false;
                    for (int k = 0; k < obstacles.size(); k++) {
                        if (obstacles[k].first == j && obstacles[k].second == i) {
                            buffer += "!";
                            isObstacle = true;
                            break;
                        }
                    }
                    if (!isObstacle)
                        buffer += " ";
                }
            }
        }
        buffer += "|\n";
    }

    buffer += "+";
    for (int i = 0; i < width; i++)
        buffer += "-";
    buffer += "+\n";

    buffer += playerName + "'s Score: " + to_string(playerScore) + "\n";
    buffer += "Remaining Time: " + to_string(remainingTime) + " seconds\n";

    system("cls");
    cout << buffer;
}

void UpdateGame()
{
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;

    for (int i = 1; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (sDir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    if (x >= width || x < 0 || y >= height || y < 0)
        isGameOver = true;

    for (int i = 0; i < snakeTailLen; i++) {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            isGameOver = true;
    }

    // Check for collision with obstacles
    for (int i = 0; i < obstacles.size(); i++) {
        if (obstacles[i].first == x && obstacles[i].second == y)
            isGameOver = true;
    }

    if (x == fruitCordX && y == fruitCordY) {
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLen++;
    }
}

int SetDifficulty()
{
    int dfc, choice;
    cout << "\nSET DIFFICULTY\n1: Easy\n2: Medium\n3: Hard "
        "\nNOTE: if not chosen or pressed any other "
        "key, the difficulty will be automatically set "
        "to medium\nChoose difficulty level: ";
    cin >> choice;
    switch (choice) {
    case 1:
        dfc = 150; // Easy: 150 milliseconds
        break;
    case 2:
        dfc = 100; // Medium: 100 milliseconds
        break;
    case 3:
        dfc = 50; // Hard: 50 milliseconds
        break;
    default:
        dfc = 100; // Default: Medium difficulty
    }
    return dfc;
}

void UserInput()
{
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (sDir != RIGHT) sDir = LEFT;
            break;
        case 'd':
            if (sDir != LEFT) sDir = RIGHT;
            break;
        case 'w':
            if (sDir != DOWN) sDir = UP;
            break;
        case 's':
            if (sDir != UP) sDir = DOWN;
            break;
        case 'x':
            isGameOver = true;
            break;
        }
    }
}

int main()
{
    srand(unsigned(time(NULL)));
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    int dfc = SetDifficulty();

    // Add obstacles
    obstacles.push_back(make_pair(10, 5));
    obstacles.push_back(make_pair(20, 15));
    obstacles.push_back(make_pair(30, 8));

    GameInit();
    auto start_time = chrono::steady_clock::now(); // 게임 시작 시간 기록
    while (!isGameOver) {
        auto current_time = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = current_time - start_time;
        int remaining_time = gameDuration - static_cast<int>(elapsed_seconds.count());

        GameRender(playerName, remaining_time); // 남은 시간을 전달하여 렌더링

        if (remaining_time <= 0) {
            cout << "Time's up! Game over." << endl;
            isGameOver = true;
            break;
        }

        UserInput();
        UpdateGame();

        auto end = chrono::steady_clock::now();
        chrono::duration<double> frame_duration = end - current_time;
               this_thread::sleep_for(chrono::milliseconds(dfc) - frame_duration);
    }

    cout << "Final Score: " << playerScore << endl;
    return 0;
}

