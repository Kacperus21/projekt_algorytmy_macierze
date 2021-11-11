#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>


int n=0, m=0, i=0, j=0, p=0,k=0,q=0,y=0,zli=0,k2=0,zli2=0,q2=0,n2=0,m2=0,wybor=0;

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
        ofstream zapis;
        zapis.open("testowany_macierz.txt");// tworzy i otwiera plik testowany_macierz

    cout<<"Jesli chcesz sam wprowadzic wybierz 1"<<endl;
    cout<<"Jesli chcesz zobaczyc przykladowe dzialanie 2"<<endl;    //wybór miedzy dzialaniem testowym a dzialaniem na podstawie wlasnego macierza
    cin>>wybor;
    if(wybor == 1) //wybranie samodzielnego uzupełniania
{
    cout<<"Podaj ilosc kolumn: "<<endl;
    cin>>m;
    while(cin.fail()) // jesli wartość jest niepoprawna to wykonuje sie petla
    {
       cout << "Wprowadz poprawna wartosc ponownie:";
        cin.clear();
        cin.ignore(100,'\n'); // ignoruje niepoprawne dane
        cin >> m; // nakazuje wprowadzic ponownie dane
    }
                                     //Pobieranie rozmiarów macierza
    cout<<"Podaj ilosc wierszy: "<<endl;
    cin>>n;
    while(cin.fail()) // jesli wartość jest niepoprawna to wykonuje sie petla
    {
       cout << "Wprowadz poprawna wartosc ponownie:";
        cin.clear();
        cin.ignore(100,'\n'); // ignoruje niepoprawne dane
        cin >> n; // nakazuje wprowadzic ponownie dane
    }
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
            while(cin.fail()) // jesli wartość jest niepoprawna to wykonuje sie petla
            {
                cout << "Wprowadz poprawna wartosc ponownie:";
                cin.clear();
                cin.ignore(100,'\n'); // ignoruje niepoprawne dane
                cin >> A[i * m + j]; // nakazuje wprowadzic ponownie dane
            }

        }
        zapis<<endl;
    }
    obliczanie(m,n,A,B,B2); //wywołanie funkcji obliczanie()


}else if (wybor == 2) //wybranie przykladowego dzialania
{



        p = n * m;
        int * A = new int[p];
        int * B = new int[p];         //definiowanie tablic dynamicznych
        int * B2 = new int[p];
        n=4;
        m=4;
       A[0]=2;A[1]=4;A[2]=3;A[3]=1;A[4]=4;A[5]=7;A[6]=1;A[7]=3;A[8]=3;A[9]=0;A[10]=9;A[11]=0;A[12]=2;A[13]=5;A[14]=9;A[15]=9;//wartosci z polecenia

       cout<<"Tak wyglada testowy macierz:"<<endl;


    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
                                    //Wypisanie testowego macierza w formacie 2 wymiarowym
            cout<<"["<<A[i * m + j]<<"]";
            zapis<<"["<<A[i * m + j]<<"]";
        }
        zapis<<endl;
        cout<<endl;

    }
    obliczanie(m,n,A,B,B2);  //wywołanie funkcji obliczanie()
}else{
    cout<<"Podano zla liczbe podaj 1 lub 2!"; //wykluczenie dzialania programu gdy uzytkownik poda zla liczbe
}
    zapis.close();//zamyka plik testowany_macierz
    return 0;
}
