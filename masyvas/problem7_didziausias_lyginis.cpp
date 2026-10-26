#include <iostream>
#include <fstream>
using namespace std;

void skaitymas(int &n, int masyvas[])
{
    ifstream failas("U1.txt");
    failas >> n;
    for (int i = 1; i <= n; i++)
    {
        failas >> masyvas[i];
    }
    failas.close();
}

// Grazina true, jei rastas bent vienas lyginis skaicius; max - didziausias lyginis
bool didziausiasLyginis(int n, int masyvas[], int &max)
{
    bool rastas = false;
    for (int i = 1; i <= n; i++)
    {
        if (masyvas[i] % 2 == 0 && (!rastas || masyvas[i] > max))
        {
            max = masyvas[i];
            rastas = true;
        }
    }
    return rastas;
}

int main()
{
    int n;
    int masyvas[80];

    skaitymas(n, masyvas);

    ofstream rez("U1rez.txt");
    int maksimalus;
    if (didziausiasLyginis(n, masyvas, maksimalus))
        rez << maksimalus << endl;
    else
        rez << "Ne" << endl;
    rez.close();

    return 0;
}
