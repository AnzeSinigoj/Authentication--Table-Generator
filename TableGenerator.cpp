#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string vodKos[] = {" ", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M"};
string navKos[] = {"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
string tab;

void genAuthTab(int dolz)
{
    tab = "";

    for (auto i : vodKos)
    {
        tab.append(i + " ");
    }
    tab.append("\n");

    for (int i = 0; i < 13; i++)
    {
        tab.append(navKos[i] + " ");
        for (int j = 0; j < 13; j++)
        {
            for (int i = 0; i < dolz; i++)
            {
                bool stAlicrk = rand() % 2 == 0;
                if (stAlicrk)
                {
                    tab.append(to_string(rand() % 10));
                }
                else
                {
                    tab.append(1, static_cast<char>('A' + rand() % 26));
                }
            }
            tab.append(" ");
        }
        tab.append("\n");
    }
}

int main()
{
    srand(time(0));

    int ndolz, ntab, nseriji;
    cout << "Enter how much series of tables you want to generate: ";
    cin >> nseriji;
    cout << "Enter how much tables you want to generate per series: ";
    cin >> ntab;

    for (int i = 0; i < nseriji; i++)
    {
        cout << "No. ";
        for (int i = 0; i < 8; i++)
        {
            cout << (to_string(rand() % 10));
        }
        cout << "\n";

        for (int i = 0; i < ntab; i++)
        {
            cout << "Table " << i << ":\n";
            genAuthTab(1);
            cout << tab << "\n\n";
        }
    }

    cout << "Press ENTER to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
