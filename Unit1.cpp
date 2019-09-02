//---------------------------------------------------------------------------

#include <vcl.h>
#include <dstring.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// 1. сортируем массив
void sortmass(int *p, int startnum, int endnum)
{
    // поиск в массиве от startnum до endnum
    int indmax,indmin, nmax, nmin, i;
    indmax = startnum;
    indmin = startnum;
    nmax = p[startnum];
    nmin = p[startnum];

    // ищем максимальное и минимальное число

    for (i = startnum; i<=endnum; i++)
        {
        if (nmax < p[i])
            {
            nmax = p[i];
            indmax = i;
            }
        if (nmin > p[i])
            {
            nmin = p[i];
            indmin = i;
            }
        }
    // перестановка значений, минимальное в начало, максимальное в конец
    p[indmin] = p[startnum];
    p[startnum] = nmin;

    p[indmax] = p[endnum];
    p[endnum] = nmax;

    // повторяем сортировку сужая диапазон поиска
    if ((startnum+1) < endnum)
        sortmass(p, startnum+1, endnum-1);
}
//---------------------------------------------------------------------------

// 2. поиск в отсортированном массиве
AnsiString findInMass(int *p, int startnum, int endnum, int findelem)
{
    // проверяем краевые условия
    if ((findelem < startnum) && (findelem > endnum))
            return  "Искомый элемент находится за пределами означенного массива";

    // начинаем поиск с середины
    int centr, n0, n1;
    n0 = startnum;
    n1 = endnum;
    while ((n1 - n0) > 1)
    {
        centr = int((n0 + n1)/2);
        if (findelem == p[centr])
        {
            return "Искомый элемент находится в " + IntToStr(centr) + " ячейке";
        {
        if (findelem > p[centr])
            n0 = centr;
        else
            n1 = centr;
    }
    return "Искомый элемент не найден";
}
//---------------------------------------------------------------------------

// 3. разбор строки
void Stroka(AnsiString s)
{
    //
};
//---------------------------------------------------------------------------

// 4. факториал
int Factor(int n)
{
    if (n == 1)
    {
        Factor = 1;
        return;
    }
    //можно сделать так
    Factor = Factor(n - 1);

    // а можно сделать и так
    f = 1;
    for (int i = 1; i <= n; i++)
        f = f * i;
    Factor = f;
}
//---------------------------------------------------------------------------

// 5. скобки
AnsiString Skobki(AnsiString *s)
{
    // ищем скобки () [] {}
    // на открытую плюс в соответствующий индекс, на закрытую минус
    // в конце все три должны быть 0
    int krug = 0; // круглая скобка
    int kvad = 0; // квадратная
    int fig = 0;  // фигурная

    char *ch = s->c_str();
    while (ch == 0)
    {
        if (ch == '(') krug++;
        if (ch == '[') kvad++;
        if (ch == '{') fig++;
        if (ch == ')') krug--;
        if (ch == ']') kvad--;
        if (ch++ == '}') fig--;
    }
    Skobki = "Скобки: ( - " + (krug == 0 ? "закрыта " , "незакрыта") +
                    " [ - " + (kvad == 0 ? "закрыта " , "незакрыта") +
                    " { - " + (fig == 0 ? "закрыта " , "незакрыта");
}



//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (p) delete p;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
    p = new int[20];
    p = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 19, 18 ,17, 16, 15, 14, 13, 12, 11];
    Edit1->Text = "10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 19, 18 ,17, 16, 15, 14, 13, 12, 11";
}
//---------------------------------------------------------------------------

