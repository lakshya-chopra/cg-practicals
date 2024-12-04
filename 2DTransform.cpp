#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>
using namespace std;

void multiplyMatrix(int mat[3][3], int points[][1], int result[][1])
{
    for (int i = 0; i < 3; i++)
    {
        result[i][0] = 0;
        for (int j = 0; j < 3; j++)
        {
            result[i][0] += mat[i][j] * points[j][0];
        }
    }
}

void drawRectangle(int x1, int y1, int x2, int y2)
{
    rectangle(x1, y1, x2, y2);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    cout << "2D Transformations using Homogeneous Coordinates\n";
    cout << "1. Translation\n2. Rotation\n3. Scaling\n4. Reflection\n5. Shearing\n";
    cout << "Selection: ";
    int s;
    cin >> s;

    int x1 = 200, y1 = 150, x2 = 300, y2 = 250;
    int points[3][1] = {{x1}, {y1}, {1}};
    int result[3][1];
    int mat[3][3];

    switch (s)
    {
    case 1:
    {
        int tx, ty;
        cout << "Enter translation values (tx, ty): ";
        cin >> tx >> ty;
        mat[0][0] = 1;
        mat[0][1] = 0;
        mat[0][2] = tx;
        mat[1][0] = 0;
        mat[1][1] = 1;
        mat[1][2] = ty;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        multiplyMatrix(mat, points, result);
        setcolor(3);
        drawRectangle(x1, y1, x2, y2);
        setcolor(4);
        drawRectangle(result[0][0], result[1][0], x2 + tx, y2 + ty);
        getch();
        break;
    }
    case 2:
    {
        int angle;
        cout << "Enter angle of rotation: ";
        cin >> angle;
        angle = (angle * 3.14) / 180; // Convert angle to radians
        mat[0][0] = cos(angle);
        mat[0][1] = -sin(angle);
        mat[0][2] = 0;
        mat[1][0] = sin(angle);
        mat[1][1] = cos(angle);
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        multiplyMatrix(mat, points, result);
        setcolor(3);
        drawRectangle(x1, y1, x2, y2);
        setcolor(2);
        drawRectangle(result[0][0], result[1][0], x2, y2);
        getch();
        break;
    }
    case 3:
    {
        int sx, sy;
        cout << "Enter scaling factors (sx, sy): ";
        cin >> sx >> sy;
        mat[0][0] = sx;
        mat[0][1] = 0;
        mat[0][2] = 0;
        mat[1][0] = 0;
        mat[1][1] = sy;
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        multiplyMatrix(mat, points, result);
        setcolor(3);
        drawRectangle(x1, y1, x2, y2);
        setcolor(10);
        drawRectangle(result[0][0], result[1][0], x2 * sx, y2 * sy);
        getch();
        break;
    }
    case 4:
    {
        int choice;
        cout << "Enter reflection choice (1 for horizontal, 2 for vertical): ";
        cin >> choice;
        if (choice == 1)
        {
            mat[0][0] = 1;
            mat[0][1] = 0;
            mat[0][2] = 0;
            mat[1][0] = 0;
            mat[1][1] = -1;
            mat[1][2] = 0;
            mat[2][0] = 0;
            mat[2][1] = 0;
            mat[2][2] = 1;
        }
        else
        {
            mat[0][0] = -1;
            mat[0][1] = 0;
            mat[0][2] = 0;
            mat[1][0] = 0;
            mat[1][1] = 1;
            mat[1][2] = 0;
            mat[2][0] = 0;
            mat[2][1] = 0;
            mat[2][2] = 1;
        }
        multiplyMatrix(mat, points, result);
        setcolor(3);
        drawRectangle(x1, y1, x2, y2);
        setcolor(5);
        drawRectangle(result[0][0], result[1][0], x2, y2);
        getch();
        break;
    }
    case 5:
    {
        int shx, shy;
        cout << "Enter shearing factors (shx, shy): ";
        cin >> shx >> shy;
        mat[0][0] = 1;
        mat[0][1] = shx;
        mat[0][2] = 0;
        mat[1][0] = shy;
        mat[1][1] = 1;
        mat[1][2] = 0;
        mat[2][0] = 0;
        mat[2][1] = 0;
        mat[2][2] = 1;
        multiplyMatrix(mat, points, result);
        setcolor(3);
        drawRectangle(x1, y1, x2, y2);
        setcolor(13);
        drawRectangle(result[0][0], result[1][0], x2 + shx, y2 + shy);
        getch();
        break;
    }
    default:
        break;
    }
    closegraph();
    return 0;
}