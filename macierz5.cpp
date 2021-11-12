#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <chrono>
#include <time.h>
#include <windows.h>

int n=0, m=0, i=0, j=0, p=0,k=0,q=0,y=0,zli=0,k2=0,zli2=0,q2=0,n2=0,m2=0,wybor=0,wybor2=0;
float czas;

using namespace std;


void obliczanie(int m, int n,int * A = new int[p], int * B = new int[p], int * B2 = new int[p])

    {


    ofstream plik;
    plik.open("kolumny.txt");// tworzy i otwiera plik kolumny

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
                zli2 = zli2 + A[m2*n2-k2];      //zliczanie pozostalych elementów
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
            plik<<"Kolumna"<<i+1<<endl;//wpisuje do pliku kolumny odpowiednie kolumny



        }

    }

    plik.close();//zapyka plik kolumny
    delete[]A;
    delete[]B;
    delete[]B2;



    }

main()

{
        srand(time(NULL));
        ofstream zapis;
        zapis.open("testowany_macierz.txt");// tworzy i otwiera plik testowany_macierz



    cout<<"Podaj ilosc kolumn: "<<endl;
    cin>>m;
    while(cin.fail()) // jesli wartoœæ jest niepoprawna to wykonuje sie petla
    {
       cout << "Wprowadz poprawna wartosc ponownie:";
        cin.clear();
        cin.ignore(100,'\n'); // ignoruje niepoprawne dane
        cin >> m; // nakazuje wprowadzic ponownie dane
    }
                                     //Pobieranie rozmiarów macierza
    cout<<"Podaj ilosc wierszy: "<<endl;
    cin>>n;
    while(cin.fail()) // jesli wartoœæ jest niepoprawna to wykonuje sie petla
    {
       cout << "Wprowadz poprawna wartosc ponownie:";
        cin.clear();
        cin.ignore(100,'\n'); // ignoruje niepoprawne dane
        cin >> n; // nakazuje wprowadzic ponownie dane
    }
    cout<<"Jesli chcesz wprowadzic sam liczby do macierza wybierz 1"<<endl;
    cout<<"Jesli chcesz wylosowac cyfry z przedzia³u 0-9 do macierza wybierz 2"<<endl;
    cin>>wybor2;
    if(wybor2 == 1){
    p = n * m;
    int * A = new int[p];
    int * B = new int[p];         //definiowanie tablic dynamicznych
    int * B2 = new int[p];

    for(i = 0; i < n; i++)
    {
    for(j = 0; j < m; j++)
        {
            cout<<"Podaj liczbe: ";
            cin >> A[i * m + j];            //Uzupelnianie tablicy A wartosciami z klawiatury
            zapis<<"["<<A[i * m + j]<<"]";//wpisuje do pliku elementy macierza
            while(cin.fail()) // jesli wartoœæ jest niepoprawna to wykonuje sie petla
            {
                cout << "Wprowadz poprawna wartosc ponownie:";
                cin.clear();
                cin.ignore(100,'\n'); // ignoruje niepoprawne dane
                cin >> A[i * m + j]; // nakazuje wprowadzic ponownie dane
            }

        }
        zapis<<endl;
    }
    obliczanie(m,n,A,B,B2); //wywo³anie funkcji obliczanie()
    }
    else if(wybor2 == 2)
        {
        auto begin = std::chrono::high_resolution_clock::now();
        p = n * m;
        int * A = new int[p];
        int * B = new int[p];         //definiowanie tablic dynamicznych
        int * B2 = new int[p];
        for(i = 0; i < n; i++)
        {
        for(j = 0; j < m; j++)
        {

            A[i * m + j] = rand()%10;
            Sleep(1);
            zapis<<"["<<A[i * m + j]<<"]";


        }
        zapis<<endl;
        }
        obliczanie(m,n,A,B,B2); //wywo³anie funkcji obliczanie()
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        czas=elapsed.count() * 1e-9;
        cout<<"Czas trwania: "<<czas<<" sekund.";
        }





    zapis.close();//zamyka plik testowany_macierz
    return 0;
}
