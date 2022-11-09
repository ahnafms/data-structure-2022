
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
struct Stack
{
unsigned capacity;
int top;
int *array;
};
 
struct Stack* initStack(unsigned capacity)
{
    struct Stack* stack =
        (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array =
        (int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack)
{
return (stack->top == stack->capacity - 1);
}
 
int isEmpty(struct Stack* stack)
{
return (stack->top == -1);
}
 

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack -> array[++stack -> top] = item;
}
 
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack -> array[stack -> top--];
}

void trackPindah(int posisi1, int posisi2, int piringan)
{
    cout <<"Pindah piringan " << piringan <<" dari " << posisi1 << " ke "<< posisi2 << endl;
}
 
void pindahPiringan(struct Stack *awal,
            struct Stack *akhir, int a, int c)
{
    int topTiangAwal = pop(awal);
    int topTiangAkhir = pop(akhir);
 
    if (topTiangAwal == INT_MIN)
    {
        push(awal, topTiangAkhir);
        trackPindah(c, a, topTiangAkhir);
    }
 
    else if (topTiangAkhir == INT_MIN)
    {
        push(akhir, topTiangAwal);
        trackPindah(a, c, topTiangAwal);
    }
 
    else if (topTiangAwal > topTiangAkhir)
    {
        push(awal, topTiangAwal);
        push(awal, topTiangAkhir);
        trackPindah(c, a, topTiangAkhir);
    }
 
    else
    {
        push(akhir, topTiangAkhir);
        push(akhir, topTiangAwal);
        trackPindah(a, c, topTiangAwal);
    }
}
 
void iterate(int jmlh_piringan, struct Stack
            *awal, struct Stack *tengah,
            struct Stack *akhir)
{
    int i, total_pindah;
    int a = 1, b = 2, c = 3;
 
    if (jmlh_piringan % 2 == 0)
    {
        int temp = b;
        b = c;
        c = temp;
    }
    total_pindah = pow(2, jmlh_piringan) - 1;
 
    for (i = jmlh_piringan; i >= 1; i--)
        push(awal, i);
 
    for (i = 1; i <= total_pindah; i++)
    {
        if (i % 3 == 1)
        pindahPiringan(awal, akhir, a, c);
 
        else if (i % 3 == 2)
        pindahPiringan(awal, tengah, a, b);
 
        else if (i % 3 == 0)
        pindahPiringan(tengah, akhir, b, c);
    }
}

int main()
{
   
    unsigned jmlh_piringan;
 	cout << "Masukkan Jumlah Piringan : ";
 	cin >> jmlh_piringan;
    struct Stack *awal, *akhir, *tengah;
 
    awal = initStack(jmlh_piringan);
    tengah = initStack(jmlh_piringan);
    akhir = initStack(jmlh_piringan);
 
    iterate(jmlh_piringan, awal, tengah, akhir);
    return 0;
}
