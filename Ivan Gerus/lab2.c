/*
 Треугольник. Разработать программу, меню которой позволяет выполнить следующие функции:
 • Ввод координат вершин треугольника.
 • Определить вид треугольника (правильный, прямоугольный,  
 равнобедренный, произвольного вида).
 • Вывод периметра треугольника
 • Вывод площади треугольника.
 • Вычислить и вывести радиусы вписанной и описанной вокруг треугольника окружностей.
 • Информация о версии и авторе программы.
 • Выход из программы.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ax, bx, cx, ay, by, cy;
double a, b, c;
double P, S;
bool check = false;
double e = 0.001;

void input()
{
    printf("Input coordinates\n");
    if(scanf("%d", &ax) != 1 || scanf("%d", &ay) != 1 || scanf("%d", &bx) != 1 || scanf("%d", &by) != 1 || scanf("%d", &cx) != 1 || scanf("%d", &cy) != 1)
    {
        exit(1);
    }

    a = powl(pow(ax - bx, 2) + pow(ay - by, 2),0.5);
    b = powl(pow(ax - cx, 2) + pow(ay - cy, 2),0.5);
    c = powl(pow(cx - bx, 2) + pow(cy - by, 2),0.5);
}

void type()
{
    if(a == 0 || b == 0 || c == 0)
    {
        printf("It's line or dot");
        return;
    }
    if ((pow(a, 2)-pow(b, 2)-pow(c, 2))<=e && (pow(a, 2)-pow(b, 2)-pow(c, 2))>=0)
    {
        check = true;
        printf("Прямоугольный\n");
    }
    if ((pow(b, 2)-pow(a, 2)-pow(c, 2))<=e && (pow(b, 2)-pow(a, 2)-pow(c, 2))>=0)
    {
        check = true;
        printf("Прямоугольный\n");
    }
    if ((pow(c, 2)-pow(b, 2)-pow(a, 2))<=e && (pow(c, 2)-pow(b, 2)-pow(a, 2))>=0)
    {
        check = true;
        printf("Прямоугольный\n");
    }
    if (a == b || b == c || a == c)
    {
        check = true;
        if (a == b && a == c)
        {
            printf("Равносторонний\n");
        }
        printf("Равнобедренный\n");
        
    }
    if(check == false)
    {
        printf("Произвольный\n");
    }
}

double perimetr()
{
    return a + b + c;
}

double area()
{
    P = perimetr();
    return powl(P / 2 * (P / 2 - a)*(P / 2 - b)*(P / 2 - c), 0.5);
}

void circles()
{
    double rcircle = (S*2)/P;
    double Rcircle = a * b*c / (4 * S);
    S = area();
    rcircle = 2 * S / P;
    printf("%f - inscribed\n", rcircle);
    Rcircle = a * b * c / (4 * S);
    printf("%f - outscribed\n", Rcircle);
}

int main()
{
    int l = 1;
    input();
    while (l != 0)
    {
        printf("1 - input\n2 - type\n3 - perimeter\n4 - area\n5 - radius of inscribed and outscribed circles\n6 - info about version and author\n7 - exit\n");
        
        if(scanf("%d", &l) == 1 && (l>=1 && l<=7))
        {
            if (l == 1)
            {
                input();
            }
            if (l == 2)
            {
                type();
            }
            if (l == 3)
            {
                printf("");
                printf("%f\n", perimetr());
            }
            if (l == 4)
            {
                printf("");
                printf("%f\n", area());
            }
            if (l == 5)
            {
                circles();
            }
            if (l == 6)
            {
                printf("v.1\nGIA\n");
            }
            if (l ==7)
            {
                return 0;
            }
        }
    }
    return 0;
}
