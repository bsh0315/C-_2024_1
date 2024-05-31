#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <thread>
#include <chrono>
using namespace std;

const int width = 80;
const int height = 20;
const int gameDuration = 300; // 게임 지속 시간(초)

int x, y;
int fruitCordX, fruitCordY;
int playerScore;
int snakeTailX[100], snakeTailY[100];
int snakeTailLen;
enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
snakesDirection sDir;
bool isGameOver;
chrono::steady_clock::time_point start_time;

void GameInit() {
    isGameOver = false;
    sDir = STOP;
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
    snakeTailLen = 0;
    start_time = chrono::steady_clock::now(); // 게임 시작 시간 기록
}

void GameRender(string playerName) {
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            if (j == 0 || j == width)
                cout << "|";
            else if (i == y && j == x)
                cout << "O";
            else if (i == fruitCordY && j == fruitCordX)
                cout << "#";
            else {
                bool prTail = false;
                for (int k = 0; k < snakeTailLen; k++) {
                    if (snakeTailX[k] == j && snakeTailY[k] == i) {
                        cout << "o";
                        prTail = true;
                    }
                }
                if (!prTail)
                    cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    auto current_time = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = current_time - start_time;
    int remaining_time = gameDuration - static_cast<int>(elapsed_seconds.count());

    cout << playerName << "'s Score: " << playerScore << "  |  Time Left: " << remaining_time << " seconds" << endl;
}

void UpdateGame() {
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

    if (x == fruitCordX && y == fruitCordY) {
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLen++;
    }
}

int SetDifficulty() {
    int dfc, choice;
    cout << "\nSET DIFFICULTY\n1: Easy\n2: Medium\n3: Hard "
            "\nNOTE: if not chosen or pressed any other "
            "key, the difficulty will be automatically set "
            "to Medium\nChoose difficulty level: ";
    cin >> choice;
    switch (choice) {
    case 1:
        dfc = 150;  // Easy: 150 밀리초
        break;
    case 2:
        dfc = 120;  // Medium: 120 밀리초
        break;
    case 3:
        dfc = 90;   // Hard: 90 밀리초
        break;
    default:
        dfc = 120;  // 기본값: Medium 난이도
    }
    return dfc;
}

void UserInput() {
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

int main() {
    srand(unsigned(time(NULL)));
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    int dfc = SetDifficulty();

    GameInit();
    while (!isGameOver) {
        auto current_time = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = current_time - start_time;

        if (elapsed_seconds.count() >= gameDuration) {  // 5 minutes = 300 seconds
            cout << "Time's up! Game over." << endl;
            break;
        }

        GameRender(playerName);
        UserInput();
        UpdateGame();

        auto end = chrono::steady_clock::now();
        chrono::duration<double> frame_duration = end - current_time;
        this_thread::sleep_for(chrono::milliseconds(dfc) - frame_duration);
    }

    cout << "Final Score: " << playerScore << endl;
    return 0;
}
