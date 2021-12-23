#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void Array(int& A, int n);
void Exercise1a(int& A, int n);
void Exercise1b(int& A, int n);
void Horizontal(int& A, int n);
void Vertical(int& A, int n);
void Change(int& A, int n);
void ShakerSorting(int& A, int n);

int main() 
{
    setlocale (LC_ALL, "Rus");
    const int N = 6;
    int next;
    cout << "Задание 1a" << endl;
    int Arr1[N][N] = {};

    Exercise1a(Arr1[0][0], N);
    cout << "Чтобы продолжить дальше введите любую цифру ";
    cin >> next;
    cout << endl;
    
    cout << "Задание 1b" << endl;
    int Arr[N][N] = {};
    Exercise1b(Arr[0][0], N);
    cout << "Чтобы продолжить дальше введите любую цифру ";
    cin >> next;
    cout << endl;
    
    cout << "Задание 2a" << endl;
    Change(Arr[0][0], N);
    Horizontal(Arr[0][0], N);
    Array(Arr[0][0], N);
    cout << "Чтобы продолжить дальше введите любую цифру ";
    cin >> next;
    cout << endl;
    
    cout << "Задание 2b" << endl;
    Horizontal(Arr[0][0], N);
    Vertical(Arr[0][0], N);
    Array(Arr[0][0], N);
    cout << "Чтобы продолжить дальше введите любую цифру ";
    cin >> next;
    cout << endl;
    
    cout << "Задание 2c" << endl;
    Vertical(Arr[0][0], N);
    Array(Arr[0][0], N);
    cout << "Чтобы продолжить дальше введите любую цифру ";
    cin >> next;
    cout << endl;
    
    cout << "Задание 2d" << endl;
    Horizontal(Arr[0][0], N);
    Array(Arr[0][0], N);
    cout << "Чтобы продолжить дальше введите любую цифру ";
    cin >> next;
    cout << endl;
    
    cout << "Задание 3" << endl;
    (Arr[0][0], N);
    Array(Arr[0][0], N);
    void ShakerSorting(int& A, int n);
    
    cout << "Чтобы продолжить дальше введите любую цифру ";
    cin >> next;
    cout << endl;
    
    cout << "Задание 4" << endl;
    char action;
    int num;
    cout << "Введите число, далее желаемую операцию ( ваш выбор операций: + , - , * , / ) ";
    cin >> num >> action;
    switch (action)
    {
    case '+':
        for (int i = 0, *Next = &Arr[0][0], *End = Next + N * N; Next < End; i++, Next++)
            *Next += num;
        Array(Arr[0][0], N);
        break;
    case '-':
        for (int i = 0, *Next = &Arr[0][0], *End = Next + N * N; Next < End; i++, Next++)
            *Next -= num;
        Array(Arr[0][0], N);
        break;
    case '*':
        for (int i = 0, *Next = &Arr[0][0], *End = Next + N * N; Next < End; i++, Next++)
            *Next *= num;
        Array(Arr[0][0], N);
        break;
    case '/':
        for (int i = 0, *Next = &Arr[0][0], *End = Next + N * N; Next < End; i++, Next++)
            *Next /= num;
        Array(Arr[0][0], N);
        break;
    default:
        cout << "Возникла ошибка введено не то значение" << endl;
        break;
    }
    return 0;
}

void Array(int& A, int n)
{
    int* a = &A;
    for (int i = 0, *Next = a, *End = Next + n * n; Next < End; i++, Next++) 
    {
        cout << setw(4) << *Next;
        if (i % n == n - 1) cout << endl;
    }
    cout << endl;
}
void Exercise1a(int& A, int n)
{
    int* Begin = &A, * End = Begin + n * n - 1;
    for (int i = 0; i < n - 1; Begin++, i++) 
    {
        *Begin = 1 + rand() % (n * n - 1);
        Array(A, n);
    }
    int temp = n - 1, sign = 1;
    while (temp > 0) 
    {
        for (int i = 0; i < temp; Begin += n * sign, i++) 
        {
            *Begin = 1 + rand() % (n * n - 1);
            Array(A, n);
        }
        for (int i = 0; i < temp; Begin -= sign, i++) 
        {
            *Begin = 1 + rand() % (n * n - 1);
            Array(A, n);
        }
        temp--;
        sign = -sign;
    }
    *Begin = 1 + rand() % (n * n - 1);
    Array(A, n);
}
void Exercise1b(int& A, int n)
{
    int* Begin = &A, * End = Begin + n * n - 1;
    int sign = 1;
    for (int c = 0; c < n; c++) 
    {
        for (int i = 0; i < n - 1; Begin += n * sign, i++) 
        {
            *Begin = 1 + rand() % (n * n - 1);
            Array(A, n);
        }
        *Begin = 1 + rand() % (n * n - 1);
        Array(A, n);
        Begin++;
        sign = -sign;
    }
}
void Horizontal(int& A, int n)
{
    int* a = &A, mid = n / 2;
    for (int i = 0, *Begin = a; i < n; i++, Begin += n)
        for (int j = 0; j < mid; j++)
            std::swap(*(Begin + j), *(Begin + mid + j));
}
void Vertical(int& A, int n)
{
    int* a = &A, mid = n / 2;
    for (int i = 0, *Begin = a; i < mid * n; i++, Begin++)
        std::swap(*(Begin), *(Begin + mid * n));
}
void Change(int& A, int n)
{
    int* a = &A, mid = n / 2, dif = (n * n - n) / 2;
    for (int c = 0; c <= (mid - 1) * n; c += n)
        for (int i = 0, *Begin = a + mid + c; i < mid; i++, Begin++)
            std::swap(*(Begin), *(Begin + dif));
}
void ShakerSorting(int& A, int n)
{

    bool sort_or_not = true;
    int* left = &A, * right = left + n * n;
    do
    {
        sort_or_not = false;
        for (int* Next = left; Next < right; Next++)
            if (*Next < *(Next + 1))
            {
                std::swap(*Next, *(Next + 1));
                sort_or_not = false;
            }
        right--;
        for (int* Next = right; Next > left; Next--)
            if (*Next > *(Next - 1))
            {
                std::swap(*Next, *(Next - 1));
                sort_or_not = false;
            }
        left++;
    } while (sort_or_not == false);

}
