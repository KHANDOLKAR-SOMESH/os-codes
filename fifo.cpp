#include <iostream>
using namespace std;

int main()
{
    int i, j, n, a[50], frame[50], no, k, avail, count = 0;

    cout << "\n ENTER THE NUMBER OF PAGES:\n";
    cin >> n;
    cout << "\n ENTER THE PAGE NUMBER :\n";
    for (i = 1; i <= n; i++)
        cin >> a[i];
    cout << "\n ENTER THE NUMBER OF FRAMES :";
    cin >> no;

    for (i = 0; i < no; i++)
        frame[i] = -1;

    j = 0;
    cout << "\tref string\t page frames\n";

    for (i = 1; i <= n; i++)
    {
        cout << a[i] << "\t\t";
        avail = 0;

        for (k = 0; k < no; k++)
        {
            if (frame[k] == a[i])
            {
                avail = 1;
            }
        }

        if (avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;

            for (k = 0; k < no; k++)
            {
                cout << frame[k] << "\t";
            }
        }

        cout << endl;
    }

    cout << "Page Fault Is " << count << endl;
    return 0;
}
