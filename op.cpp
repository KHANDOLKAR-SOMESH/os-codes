#include <iostream>
using namespace std;
#define MAX 50

int main()
{
    int no_of_frames, no_of_pages, frames[MAX], pages[MAX], temp[MAX], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    cout << "Enter number of frames: ";
    cin >> no_of_frames;
    cout << "Enter number of pages: ";
    cin >> no_of_pages;
    cout << "Enter page reference string: ";
    for (i = 0; i < no_of_pages; ++i)
    {
        cin >> pages[i];
    }

    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }
    
    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }         }

        if (flag2 == 0)
        {
            flag3 = 0;

            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;

                for (k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0){
                max = temp[0];
                pos = 0;

                for (j = 1; j < no_of_frames; ++j){
                    if (temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++; }
        cout << endl;
        for (j = 0; j < no_of_frames; ++j){
            cout << frames[j] << "\t";}
    }
    cout << "\n\nTotal Page Faults = " << faults;
    return 0;
}
