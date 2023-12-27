#include<iostream>
#include<conio.h>
#define max 25

using namespace std;

int main()
{
    int frame[10];
    int i,j,k,nf,np=0,page[max],temp;
    int flag=0,pf=0,top=0;

    cout<<"Enter no. of Frames:";
    cin>>nf;

    for(i=0;i<nf;i++)
        frame[i]=-1;
cout<<" the numbers of pages";
int nn;
cin>>nn;

    for(i=0;i<nn;i++)
    {
        cin>>temp;
        page[i]=temp;
        np++;
    }

    for(i=0;i<np;i++)
    {
        flag=0;
        for(j=0;j<nf;j++)
        {
            if(frame[j]==page[i])
            {
                cout<<"\t\n";
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            frame[top]=page[i];
            top++;
            cout<<"\t\n";
            pf++;
            if(top>=nf)
                top=0;
        }
        for(k=0;k<nf;k++)
            cout<<frame[k]<<"\t";
        cout<<endl;
    }
    cout<<"total no of fage fault are"<<pf;
    return 0;
}
