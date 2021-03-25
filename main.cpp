#include <iostream>
#include <locale.h>
#define TotalLinhas 4
#define TotalColunas 4

using namespace std;

void Imprimir_matriz (int M[TotalLinhas][TotalColunas])
{
    for (int Linha = 0; Linha < TotalLinhas; Linha++)
    {
        for (int Coluna = 0; Coluna < TotalColunas; Coluna++)
        {
            cout << M[Linha][Coluna] << " ";
        }
        cout << endl;
    }
}

void Contar_linha (int M[TotalLinhas][TotalColunas], int L[2])
{
    int Contador = 0;
    int Maior = 0;
    int Maior_linha;
    for (int Linha = 0; Linha < TotalLinhas; Linha++)
    {
        for (int Coluna = 0; Coluna < TotalColunas; Coluna++)
        {
            if (M[Linha][Coluna]==0)
            {
                Contador++;
            }
        }
        if (Contador > Maior)
        {
            Maior = Contador;
            Maior_linha = Linha;
        }
        // cout << "Total de zeros na linha " << Linha+1 << ": " << Contador << endl;
        Contador = 0;
    }
    // cout << "Linha com maior numero(s) de zeros: " << Maior_linha+1 << endl;
    L[0] = Maior_linha+1;
    L[1] = Maior;
}

void Contar_coluna (int M[TotalLinhas][TotalColunas], int C[2])
{
    int Contador = 0;
    int Maior = 0;
    int Maior_coluna;
    for (int Coluna = 0; Coluna < TotalColunas; Coluna++)
    {
        for (int Linha = 0; Linha < TotalLinhas; Linha++)
        {
            if (M[Linha][Coluna]==0)
            {
                Contador++;
            }
        }
        if (Contador > Maior)
        {
            Maior = Contador;
            Maior_coluna = Coluna;
        }
        // cout << "Total de zeros na coluna " << Coluna+1 << ": " << Contador << endl;
        Contador = 0;
    }
    // cout << "Coluna com o maior numero(s) de zeros: " << Maior_coluna+1 << endl;
    C[0] = Maior_coluna+1;
    C[1] = Maior;
}

int main ()
{
    system("cls");
    setlocale(LC_ALL,"Portuguese");
    int Matriz[TotalLinhas][TotalColunas] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int Linha[2], Coluna[2];
    Imprimir_matriz(Matriz);
    Contar_linha(Matriz,Linha);
    cout << endl;
    Contar_coluna(Matriz,Coluna);
    if (Linha[1] > Coluna[1])
    {
        cout << "Melhor escolher a linha" << endl;
        cout << "Linha: " << Linha[0] << endl;
    }
    else
    {
        if (Coluna[1] > Linha[1])
        {
            cout << "Melhor escolher a coluna" << endl;
            cout << "Coluna: " << Coluna[0] << endl;
        }
        else
        {
            if (Linha[1] and Coluna[1] > 0 and Linha[1] == Coluna[1])
            {
                cout << "Duas Melhores" << endl;
                cout << "Linha: " << Linha[0] << endl;
                cout << "Coluna: " << Coluna[0] << endl;
            }
            else
            {
                cout << "Não existe melhor" << endl;
            }
        }
    }
    return 0;
}