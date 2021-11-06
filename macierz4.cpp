#include <iostream>
#include <locale.h>
int n=0, m=0, i=0, j=0, p=0,k=0,q=0,y=0,zli=0,k2=0,zli2=0,q2=0,n2=0,m2=0,wybor=0;
using namespace std;

void obliczanie(int m, int n,int * A = new int[p], int * B = new int[p], int * B2 = new int[p])
    {


    y=0;
    k=m;
    k2=m;
    m2=m;
    n2=n;

    for(i = 0; i < n; i++)
    {

        for(j = k; j <= m ; j++)
        {
            zli = zli + A[i+y*k];           //zliczanie sumy n pierwszych elementów n kolumny
            y++;
        }
        B[q]=zli;
        q++;
        m++;
        y=0;
        zli=0;
    }


        for(i = 0; i < n-1; i++)
        {

            for(j = 0; j < k2-1 ; j++)
        {
                zli2 = zli2 + A[m2*n2-k2];      //zliczanie pozosta³ych elementów
                n2--;
        }
        n2=n;
        k2--;
        B2[q2]=zli2;
        zli2=0;
        q2++;
    }
        for(i=0;i<n-1;i++){
        if(B[i]>B2[i]){
            cout<<"Kolumna"<<i+1<<endl; //wypisywanie indeksów kolumn
        }
    }
    }



main()

{


    cout<<"Jesli chcesz sam wprowadzić wybierz 1"<<endl;
    cout<<"Jesli chcesz zobaczyć przykładowe dzialanie 2"<<endl;
    cin>>wybor;
    if(wybor == 1)
{
    cout<<"Podaj ilosc kolumn: "<<endl;
    cin>>m;                                 //Pobieranie rozmiarów macierza
    cout<<"Podaj ilosc wierszy: "<<endl;
    cin>>n;
    p = n * m;
    int * A = new int[p];
    int * B = new int[p];         //definiowanie tablic dynamicznych
    int * B2 = new int[p];

    for(i = 0; i < n; i++)
    {
    for(j = 0; j < m; j++)
        {
            cout<<"Podaj liczbe: ";
            cin >> A[i * m + j];            //Uzupe³nianie tablicy A wartoœciami z klawiatury

        }
    }
    obliczanie(m,n,A,B,B2);
}else if (wybor == 2)
{



        p = n * m;
        int * A = new int[p];
        int * B = new int[p];         //definiowanie tablic dynamicznych
        int * B2 = new int[p];
        n=4;
        m=4;
       A[0]=2;A[1]=4;A[2]=3;A[3]=1;A[4]=4;A[5]=7;A[6]=1;A[7]=3;A[8]=3;A[9]=0;A[10]=9;A[11]=0;A[12]=2;A[13]=5;A[14]=9;A[15]=9;//wartoœci z polecenia

       cout<<"Tak wyglada testowy macierz:"<<endl;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
                                    //Wypisanie testowego macierza w formacie 2 wymiarowym
            cout<<A[i * m + j];
        }
        cout<<endl;

    }
    obliczanie(m,n,A,B,B2);
}




    return 0;
}
