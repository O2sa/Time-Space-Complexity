#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

void AlgorithmAnalysis(int inputs, int choice)
{
    cout << "Time Complexity: ";
    switch (choice)
    {
    case 0:
        cout << "O(2^n)"
             << "=" << pow(2, inputs) << endl;
        break;
    case 1:
        cout << "O(n^2)"
             << "=" << pow(inputs, 2) << endl;

        break;
    case 2:
        cout << "O(n)"
             << "=" << inputs << endl;

        break;
    case 3:
        cout << "O(logn)"
             << "=" << log2(inputs) << endl;

        break;
    }

    cout << "Auxiliary Space: O(n)"
         << "=" << inputs << endl;
    cout << "---------Wait----------" << endl;
}
// -------------------------------------------------------
// Fibonacci Sequence by Recursive
//--------------------------------------------------------
int FibonacciRecursive(int n)
{
    if (n <= 1)
        return n;
    return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}
//----------------------------------------------------------------

// -------------------------------------------------------
// Fibonacci Sequence by Iterative
//--------------------------------------------------------
int FibonacciIterative(int n)
{

    // Declare an array to store
    // Fibonacci numbers.
    // 1 extra to handle
    // case, n = 0
    int f[n + 2];
    int i;

    // 0th and 1st number of the
    // series are 0 and 1
    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {

        // Add the previous 2 numbers
        //  in the series and store it
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

//----------------------------------------------------------------

// -------------------------------------------------------
// Armstrong Number by Iterative
//--------------------------------------------------------
void ArmstrongIterative(int n)
{
    //	int n = 153;

    int temp = n;
    int p = 0;

    /*function to calculate
      the sum of individual digits
     */
    while (n > 0)
    {

        int rem = n % 10;
        p = (p) + (rem * rem * rem);
        n = n / 10;
    }

    /* condition to check whether
       the value of P equals
       to user input or not. */
    if (temp == p)
    {
        cout << ("Yes. It is Armstrong No.") << endl;
    }
    else
    {
        cout << ("No. It is not an Armstrong No.") << endl;
    }
}

//----------------------------------------------------------------

// -------------------------------------------------------
// Armstrong Number by Recursive
//--------------------------------------------------------
int ArmstrongRecursive(int num)
{

    if (num > 0)
    {
        return (pow(num % 10, 3) + ArmstrongRecursive(num / 10));
    }
}

//----------------------------------------------------------------

// -------------------------------------------------------
// Power of Number by Divide&Conquer
//--------------------------------------------------------
int powerDivideConquer(int x, int n)
{

    // If x^0 return 1
    if (n == 0)
        return 1;
    // If we need to find of 0^y
    if (x == 0)
        return 0;
    // For all other cases
    return x * powerDivideConquer(x, n - 1);
}

//----------------------------------------------------------------

// -------------------------------------------------------
// Power of Number by Decrease&Conquer
//--------------------------------------------------------
double powerDecreaseConquer(double x, int n)
{

    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    double temp = powerDecreaseConquer(x, n / 2);
    if (n % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        return x * temp * temp;
    }
}

//----------------------------------------------------------------

// -------------------------------------------------------
// Power of Number by Brute-Force(Iterative)
//--------------------------------------------------------
double powerBruteIterative(int k, int n)
{

    double result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= k;
    }
    return result;
}

//----------------------------------------------------------------

// -------------------------------------------------------
// Power of Number by Brute-Force(Recursive)
//--------------------------------------------------------
int powerBruteRecursive(int base, int a)
{

    if (a != 0)
        return (base * powerBruteRecursive(base, a - 1));
    else
        return 1;
}
void CallPower(int choice)
{
    int base, power;
    cout << "Enter the base number!" << endl;
    cin >> base;
    cout << "Enter the base number!" << endl;
    cin >> power;

    clock_t start, end;
    start = clock();
    switch (choice)
    {
    case 0:
        cout << "----------------------------" << endl;
        cout << "Power of number by Divide&Conquer\n";
        AlgorithmAnalysis(power, 0);
        cout << "The power Number for " << base << "^" << power << ": " << powerDivideConquer(base, power) << endl;
        break;
    case 1:
        cout << "----------------------------" << endl;
        cout << "Power of number by Decrease and Conquer \n";
        AlgorithmAnalysis(power, 3);
        cout << "The power Number for " << base << "^" << power << ": " << powerDecreaseConquer(base, power) << endl;

        break;
    case 2:
        cout << "----------------------------" << endl;
        cout << "Power of number by Brute-Force(Iterative) \n";
        AlgorithmAnalysis(power, 2);

        cout << "The power Number for " << base << "^" << power << ": " << powerBruteIterative(base, power) << endl;
        break;
    case 3:
        cout << "----------------------------" << endl;
        cout << "Power of number by Brute-Force(Recursive) \n";
        AlgorithmAnalysis(power, 0);
        cout << "The power Number for " << base << "^" << power << ": " << powerBruteRecursive(base, power) << endl;
        break;
    }

    end = clock();
    cout << "Time taken by program is : " << fixed
         << double(end - start) / double(CLOCKS_PER_SEC)
         << setprecision(5) << " sec " << endl;
}
//----------------------------------------------------------------

// -------------------------------------------------------
// Pattern Matching by Brute-Force
//--------------------------------------------------------
int PatternMatchingBrute(string pattern, string subject)
{

    int n = subject.length();
    int m = pattern.length();
    for (int i = 0; i < n - m; i++)
    {
        int j = 0;
        while (j < m && subject[i + j] == pattern[j])
        {
            j++;
        }
        if (j == m)
            return i;
    }
    return -1;
}

void callPatternMatchingBrute()
{
    cout << "----------------------------" << endl;
    cout << "Pattern Matching by Brute-Force\n";
    string text, patt;
    cout << "Enter the subject text !" << endl;
    cin >> text;
    cout << "Enter the pattern text !" << endl;
    cin >> patt;
    AlgorithmAnalysis(text.length(), 1);

    clock_t start, end;
    start = clock();
    cout << "The result  "
         << ": " << PatternMatchingBrute(patt, text) << endl;

    end = clock();
    cout << "Time taken by program is : " << fixed
         << double(end - start) / double(CLOCKS_PER_SEC)
         << setprecision(5) << " sec " << endl;
}
//----------------------------------------------------------------
// -------------------------------------------------------
// Padlock Problem by Brute-Force
//--------------------------------------------------------
void CombinationRepetitionUtil(int chosen[], int arr[],
                               int index, int r, int start, int end)
{
    // Since index has become r, current combination is
    // ready to be printed, print
    if (index == r)
    {
        for (int i = 0; i < r; i++)
            cout << " " << arr[chosen[i]];
        cout << "\n";
        return;
    }

    // One by one choose all elements (without considering
    // the fact whether element is already chosen or not)
    // and recur
    for (int i = start; i <= end; i++)
    {
        chosen[index] = i;
        CombinationRepetitionUtil(chosen, arr, index + 1,
                                  r, i, end);
    }
    return;
}

// The main function that prints all combinations of size r
// in arr[] of size n with repetitions. This function mainly
// uses CombinationRepetitionUtil()
void CombinationRepetition(int arr[], int n, int r)
{

    // Allocate memory
    int chosen[r + 1];

    // Call the recursive function
    CombinationRepetitionUtil(chosen, arr, 0, r, 0, n - 1);
}

void callPadlock()
{
    cout << "----------------------------" << endl;
    cout << "Padlock problem by Brute Force\n";
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int r;
    printf("\nWhat is the length of the digit: ");
    scanf("%d", &r);
    AlgorithmAnalysis(r, 1);
    int n = sizeof(num) / sizeof(num[0]);
    clock_t start, end;
    start = clock();
    CombinationRepetition(num, n, r);
    end = clock();
    cout << "Time taken by program is : " << fixed
         << double(end - start) / double(CLOCKS_PER_SEC)
         << setprecision(5) << " sec " << endl;
}
//----------------------------------------------------------------

// -------------------------------------------------------
// 0/1 Knapsack Problem by Brute-Force
//--------------------------------------------------------

// Input:
// Values (stored in array v)
// Weights (stored in array w)
// Total number of distinct items n
// Knapsack capacity W
int knapsackBrute(int v[], int w[], int n, int W)
{

    // T[i][j] stores the maximum value that can be attained with
    // weight less than or equal to j using items up to first i items
    int T[n + 1][W + 1];

    for (int j = 0; j <= W; j++)
    {
        T[0][j] = 0;
    }

    // memset (T[0], 0, sizeof T[0]);

    // do for i'th item
    for (int i = 1; i <= n; i++)
    {
        // consider all weights from 0 to maximum capacity W
        for (int j = 0; j <= W; j++)
        {
            // don't include the i'th element if j-w[i-1] is negative
            if (w[i - 1] > j)
            {
                T[i][j] = T[i - 1][j];
            }
            else
            {
                // find the maximum value by excluding or including the i'th item
                T[i][j] = max(T[i - 1][j], T[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }

    // return maximum value
    return T[n][W];
}

// 0/1 Knapsack problem
void callknapsackBrute()
{
    cout << "----------------------------" << endl;
    cout << "0/1 Knapsack Problem by Brute-Force \n";
    AlgorithmAnalysis(6, 1);
    // input: a set of items, each with a weight and a value
    int v[] = {20, 5, 10, 40, 15, 25};
    int w[] = {1, 2, 3, 8, 7, 4};

    // knapsack capacity
    int W = 10;

    // total number of items
    int n = sizeof(v) / sizeof(v[0]);
    clock_t start, end;
    start = clock();
    cout << endl
         << "Knapsack value is " << knapsackBrute(v, w, n, W) << endl;
    end = clock();
    cout << "Time taken by program is : " << fixed
         << double(end - start) / double(CLOCKS_PER_SEC)
         << setprecision(5) << " sec " << endl;
}
//----------------------------------------------------------------

// -------------------------------------------------------
// Fractonal Knapsack Problem by Greedy algorithm
//--------------------------------------------------------
void FracKnapsackGreedy(int n, float weight[], float profit[], float capacity)
{

    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
        x[i] = u / weight[i];

    tp = tp + (x[i] * profit[i]);

    printf("\nThe result vector is:- ");
    for (i = 0; i < n; i++)
        printf("%f\t", x[i]);

    printf("\nMaximum profit is:- %f", tp);
}

void callFracKnapsackGreedy()
{
    cout << "----------------------------" << endl;
    cout << "Fractonal Knapsack Problem by Greedy algorithm\n";
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;

    printf("\nEnter the no. of objects:- ");
    scanf("%d", &num);

    printf("\nEnter the wts and profits of each object:- ");
    for (i = 0; i < num; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the capacityacity of knapsack:- ");
    scanf("%f", &capacity);

    AlgorithmAnalysis(num, 2);

    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    clock_t start, end;
    start = clock();
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    FracKnapsackGreedy(num, weight, profit, capacity);
    end = clock();
    cout << endl
         << "Time taken by program is : " << fixed
         << double(end - start) / double(CLOCKS_PER_SEC)
         << setprecision(5) << " sec " << endl;
}
//----------------------------------------------------------------
void callOne(int choice)
{
    int j;
    cout << "Enter a posative number!" << endl;
    cin >> j;

    clock_t start, end;
    start = clock();

    switch (choice)
    {
    case 0:
        cout << "----------------------------" << endl;
        cout << "Fibonacci Sequence by Iterative\n";
        AlgorithmAnalysis(j, 2);
        cout << "The Fibonacci Number for " << j << ": " << FibonacciIterative(j) << endl;
        break;
    case 1:
        cout << "----------------------------" << endl;
        cout << "Fibonacci Sequence by Recursive\n";
        AlgorithmAnalysis(j, 0);
        cout << "The Fibonacci Number for " << j << ": " << FibonacciRecursive(j) << endl;
        break;
    case 2:
        cout << "----------------------------" << endl;
        cout << "Armstrong Number by Iterative\n";
        AlgorithmAnalysis(j, 2);
        ArmstrongIterative(j);
        break;
    case 3:
        cout << "----------------------------" << endl;
        cout << "Armstrong Number by Recursive\n";
        AlgorithmAnalysis(j, 0);
        if (ArmstrongRecursive(j) == j)
            cout << "It is an Armstrong Number" << endl;
        else
            cout << "It is not an Armstrong Number" << endl;
        break;
    }

    end = clock();
    cout << "Time taken by program is : " << fixed
         << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec " << endl;
}
void mainMenu()
{
    while (1)
    {
        int opt;
        string menu1 =
            "Enter '0' to exit\n"
            "1- Fibonacci Sequence by Iterative\n"
            "2- Fibonacci Sequence by Recursive\n"
            "3- Armstrong Number by Iterative\n"
            "4- Armstrong Number by Recursive\n"
            "5- Power of Number by Divide&Conquer\n"
            "6- Power of Number by Decrease&Conquer\n"
            "7- Power of Number by Brute-Force(Iterative)\n"
            "8- Power of Number by Brute-Force(Recursive)\n"
            "9- Pattern Matching by Brute-Force\n"
            "10- Padlock Problem by Brute-Force\n"
            "11- 0/1 Knapsack Problem by Brute-Force\n"
            "12- Fractonal Knapsack Problem by Greedy algorithm\n";
        cout << endl
             << "----------------------------" << endl;
        cout << endl
             << " Main Menu " << endl;
        cout << endl
             << "----------------------------" << endl;
        cout << menu1;
        cout << endl
             << "----------------------------" << endl
             << "chose a number:\n";

        cin >> opt;
        cout << "\n"
             << endl;
        switch (opt)
        {
        case 0:
            exit(1);
        case 1:
            callOne(0);
            break;
        case 2:
            callOne(1);
            break;
        case 3:
            callOne(2);
            break;
        case 4:
            callOne(3);
            break;
        case 5:
            CallPower(0);
            break;
        case 6:
            CallPower(1);
            break;
        case 7:
            CallPower(2);
            break;
        case 8:
            CallPower(3);
            break;
        case 9:
            callPatternMatchingBrute();
            break;
        case 10:
            callPadlock();
            break;
        case 11:
            callknapsackBrute();
            break;
        case 12:
            callFracKnapsackGreedy();
            break;
        default:
            break;
        }
    }
}
int main()
{
    cout << " Writen by Osama Faisal " << endl;
    mainMenu();
}
