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
// 1. ��������� ������
void sortmass(int *p, int startnum, int endnum)
{
    // ����� � ������� �� startnum �� endnum
    int indmax,indmin, nmax, nmin, i;
    indmax = startnum;
    indmin = startnum;
    nmax = p[startnum];
    nmin = p[startnum];

    // ���� ������������ � ����������� �����

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
    // ������������ ��������, ����������� � ������, ������������ � �����
    p[indmin] = p[startnum];
    p[startnum] = nmin;

    p[indmax] = p[endnum];
    p[endnum] = nmax;

    // ��������� ���������� ����� �������� ������
    if ((startnum+1) < endnum)
        sortmass(p, startnum+1, endnum-1);
}
//---------------------------------------------------------------------------

// 2. ����� � ��������������� �������
AnsiString findInMass(int *p, int startnum, int endnum, int findelem)
{
    // ��������� ������� �������
    if ((findelem < startnum) && (findelem > endnum))
            return  "������� ������� ��������� �� ��������� ����������� �������";

    // �������� ����� � ��������
    int centr, n0, n1;
    n0 = startnum;
    n1 = endnum;
    while ((n1 - n0) > 1)
    {
        centr = int((n0 + n1)/2);
        if (findelem == p[centr])
        {
            return "������� ������� ��������� � " + IntToStr(centr) + " ������";
        {
        if (findelem > p[centr])
            n0 = centr;
        else
            n1 = centr;
    }
    return "������� ������� �� ������";
}
//---------------------------------------------------------------------------

// 3. ������ ������
void Stroka(AnsiString s)
{
    //
};
//---------------------------------------------------------------------------

// 4. ���������
int Factor(int n)
{
    if (n == 1)
    {
        Factor = 1;
        return;
    }
    //����� ������� ���
    Factor = Factor(n - 1);

    // � ����� ������� � ���
    f = 1;
    for (int i = 1; i <= n; i++)
        f = f * i;
    Factor = f;
}
//---------------------------------------------------------------------------

// 5. ������
AnsiString Skobki(AnsiString *s)
{
    // ���� ������ () [] {}
    // �� �������� ���� � ��������������� ������, �� �������� �����
    // � ����� ��� ��� ������ ���� 0
    int krug = 0; // ������� ������
    int kvad = 0; // ����������
    int fig = 0;  // ��������

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
    Skobki = "������: ( - " + (krug == 0 ? "������� " , "���������") +
                    " [ - " + (kvad == 0 ? "������� " , "���������") +
                    " { - " + (fig == 0 ? "������� " , "���������");
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

