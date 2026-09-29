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
        

}