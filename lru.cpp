#include<iostream>
using namespace std;
int main ()
{
  int nopages, fsize, page[20], i, count = 0;
  cout << "\n Enter no of pages ";
  cin >> nopages;

  cout << "\n enter the reference String:";
  for (i = 0; i < nopages; i++){
      cout << "\t"; cin >> page[i];
    }
  cout << "\n Enter the Numer of frames:"; cin >> fsize;
  int frame[fsize], fcount[fsize];//frame sized array
  for (i = 0; i < fsize; i++) {
      frame[i] = -1;
      fcount[i] = 0;
      
    }
  i = 0;
  while (i < nopages)
    {
      int j = 0, flag = 0;
      while (j < fsize)

	{
	  if (page[i] == frame[j])
	    {
	      //it will check for page
	      flag = 1;
	      fcount[j] = i + 1;
	    }
	  j++;
	}
      j = 0;
      cout << "\n\tpage inserted : ";
      cout  << page[i] << ":-";
      if (flag == 0){
	  int min = 0, k = 0;
	  while (k < fsize - 1) {
         if (fcount[min] > fcount[k + 1])
		// calculate the page which is least recently used
		min = k + 1;
	      k++;
	    }
	  frame[min] = page[i];
	  fcount[min] = i + 1;
	 
	  count++;
	  while (j < fsize)
	    {
	      cout << "\t" << frame[j] ;
	      j++;
	    }
	}
      i++;
    }
  cout << "\n\t:-\n";
  cout << "\n\t Page Fault:" << count;
  return 0;
}