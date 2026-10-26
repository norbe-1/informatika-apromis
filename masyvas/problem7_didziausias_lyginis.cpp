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

// Pradine reiksme mazesne uz bet kuri galima elementa (ai >= -1000000)
int didziausiasLyginis(int n, int masyvas[])
{
    int max = -1000001;
    for (int i = 1; i <= n; i++)
    {
        if (masyvas[i] % 2 == 0 && masyvas[i] > max)
        {
            max = masyvas[i];
        }
    }
    return max;
}

int main()
{
    int n;
    int masyvas[80];

    skaitymas(n, masyvas);
    int maksimalus = didziausiasLyginis(n, masyvas);

    ofstream rez("U1rez.txt");
    if (maksimalus == -1000001)
        rez << "Ne" << endl;
    else
        rez << maksimalus << endl;
    rez.close();

    return 0;
}
