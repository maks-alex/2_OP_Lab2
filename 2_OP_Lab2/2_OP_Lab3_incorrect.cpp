#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

#define SIZE 6
int main()
{
    //   int a[SIZE][SIZE]; // ������� ������
    int d[SIZE]; // ����������� ����������
    int v[SIZE]; // ���������� �������
    int temp, minindex, min;
    int begin_index = 0;
    system("chcp 1251");
    system("cls");
    // ������������� ������� ������
    /*
    for (int i = 0; i < SIZE; i++)
    {
        a[i][i] = 0;
        for (int j = i + 1; j < SIZE; j++) {
            printf("������� ���������� %d - %d: ", i + 1, j + 1);
            scanf("%d", &temp);
            a[i][j] = temp;
            a[j][i] = temp;
        }
    }
    */
    int a[6][6] =
    {
        {0,7,9,0,0,14},
        {7,0,10,15,0,0},
        {9,10,0,11,0,2},
        {0,15,11,0,6,0},        //4 ������� (6 - ���� � 5 �������)
        {0,0,0,6,0,9},
        {14,0,2,0,9,0},
    };







    // ����� ������� ������
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
    //������������� ������ � ����������
    for (int i = 0; i < SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
    // ��� ���������
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++)
        { // ���� ������� ��� �� ������ � ��� ������ min
            if ((v[i] == 1) && (d[i] < min))
            { // ��������������� ��������
                min = d[i];
                minindex = i;
            }
        }
        // ��������� ��������� ����������� ���
        // � �������� ���� �������
        // � ���������� � ������� ����������� ����� �������
        if (minindex != 10000)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = min + a[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);
    // ����� ���������� ���������� �� ������
    printf("\n���������� ���������� �� ������: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%5d ", d[i]);

    // �������������� ����
    int ver[SIZE]; // ������ ���������� ������
    int end = 4; // ������ �������� ������� = 5 - 1
    ver[0] = end + 1; // ��������� ������� - �������� �������
    int k = 1; // ������ ���������� �������
    int weight = d[end]; // ��� �������� �������

    while (end != begin_index) // ���� �� ����� �� ��������� �������
    {
        for (int i = 0; i < SIZE; i++) // ������������� ��� �������
            if (a[i][end] != 0)   // ���� ����� ����
            {
                int temp = weight - a[i][end]; // ���������� ��� ���� �� ���������� �������
                if (temp == d[i]) // ���� ��� ������ � ������������
                {                 // ������ �� ���� ������� � ��� �������
                    weight = temp; // ��������� ����� ���
                    end = i;       // ��������� ���������� �������
                    ver[k] = i + 1; // � ���������� �� � ������
                    k++;
                }
            }
    }
    // ����� ���� (��������� ������� ��������� � ����� ������� �� k ���������)
    printf("\n����� ����������� ����\n");
    for (int i = k - 1; i >= 0; i--)
        printf("%3d ", ver[i]);
    getchar();
    return 0;
}

void Input_data()
{
    int a[8][8];
    ifstream inf;
    inf.open("input.txt");
    if (!inf.is_open())
    {
        cout << "Cannot open file\n";
    }
    cout << "Chart" << endl;
    string ch = "";
    while (!inf.eof())
    {
        cin >> ch;
        for (int i = 0; i < 8; i++)
        {
            a[i][i] = 0;
            for (int j = i + 1; j < 8; j++)
                if (ch == "X")
                {
                    a[i][j] = 0;
                    a[j][i] = 0;
                }

                else
                {
                    a[i][j] = 1;
                    a[j][i] = 1;
                }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
            cout << a[i][j];
    }
    inf.close();

}