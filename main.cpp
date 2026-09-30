#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string leerArchivo(string t)
{
    string a;
    ifstream archivo(t);
    getline(archivo, a);
    return a;
}

void createLPSArray(string pat, vector<int> &lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1; 
    while (i < pat.length())
    {
        //If pat[i] = pat[len]
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> busqueda(string &pat, string &txt)
{
    int n = txt.length();
    int m = pat.length();


    vector<int> a;
    vector<int> lps(m);
    vector<int> res = a;

    createLPSArray(pat, lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;

            if (j == m)
            {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return res;

}

void comparison(string pat, string txt)
{
    vector<int> res = busqueda(pat, txt);
    if (res.empty())
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true " << res[0] << endl;
    }
}

void palindromo(string txt){
    int posicionInicial = 0, posicionFinal = 0, der, izq, longest = 0, size = txt.size();

    for (int i = 0; i < size; i++){
        for (int j = 0; j < 2; j++){
            izq = i;
            der = i + j;

            while (izq >= 0 && der < size && txt[izq] == txt[der]){
                izq--;
                der++;
            }

            if (der - izq - 1 > longest){
                longest = der - izq - 1;
                posicionInicial = izq + 1;
                posicionFinal = der - 1;
            }
        }
    }
    cout << posicionInicial << "\t" << posicionFinal << endl;
}

int main()
{
    string nombre_t1 = "transmission1";
    string nombre_t2 = "transmission2";
    string nombre_m1 = "mcode1";
    string nombre_m2 = "mcode2";
    string nombre_m3 = "mcode3";
    string t1 = leerArchivo(nombre_t1);
    string t2 = leerArchivo(nombre_t2);
    string m1 = leerArchivo(nombre_m1);
    string m2 = leerArchivo(nombre_m2);
    string m3 = leerArchivo(nombre_m3);

    comparison(m1, t1);
    comparison(m2, t1);
    comparison(m3, t1);
    comparison(m1, t2);
    comparison(m2, t2);
    comparison(m3, t2);

    palindromo(t1);
    palindromo(t2);
    
}