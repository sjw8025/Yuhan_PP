﻿#include <iostream>

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

using namespace std; //사용시 std:: 생략가능

void Drawblock() //블록 만드는 코드
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            cout << "@";
        }cout << "\n";
    }

    cout << "\x1b[0m";
}

int main()
{
    const int WHITE_MASK = 0b1;
    const int RED_MASK = 0b10;
    const int GREEN_MASK = 0b100;
    const int YELLOW_MASK = 0b1000;
    const int CYAN_MASK = 0b10000;
    const int MAGENTA_MASK = 0b100000;
    const int EXIT_FLAG = 64;

    cout << "화면에 그림을 그리는 프로그램입니다.\n";
    cout << "학번 : 202327029\n";
    cout << "이름 : 송재원\n\n";

    // 콘솔 가상 터미널 시퀀스
    // \x1b[ 커서 바꾸거나 색상바꿀떄 사용

    while (true)
    {
        cout << "화면에 그릴 물체 코드를 입력하세요 : ";

        int input = 0;
        cin >> input;;

        if (input > 64 || input < 0)
        {
            cout << "올바른 코드를 입력하세요.\n";
            continue;
        }
        if (input == EXIT_FLAG)
        {
            cout << "종료";
            break;
        }
        if (input & WHITE_MASK)
        {
            cout << "\x1b[" << (int)White << "m";
            Drawblock();
        }
        if (input & RED_MASK)
        {
            cout << "\x1b[" << (int)Red << "m";
            Drawblock();
        }
        if (input & GREEN_MASK)
        {
            cout << "\x1b[" << (int)Green << "m";
            Drawblock();
        }
        if (input & YELLOW_MASK)
        {
            cout << "\x1b[" << (int)Yellow << "m";
            Drawblock();
        }
        if (input & CYAN_MASK)
        {
            cout << "\x1b[" << (int)Cyan << "m";
            Drawblock();
        }
        if (input & MAGENTA_MASK)
        {
            cout << "\x1b[" << (int)Magenta << "m";
            Drawblock();
        }
    }

}
