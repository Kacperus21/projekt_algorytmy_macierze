#include <iostream>
#include <vector>
using namespace std;

main()
{
    std::vector < int > dane;
    int n, m, i, j, p,k,q=0,y=0,z=0,zli=0;

    cout<<"Podaj ilosc kolumn: "<<endl;
    cin>>m;
    cout<<"Podaj ilosc wierszy"<<endl;
    cin>>n;

  p = n * m;

  int * A = new int[p];
  int * B = new int[p];

  for(i = 0; i < n; i++)
    {
    for(j = 0; j < m; j++)
    {

            cout<<"Podaj liczbe: ";
            cin >> A[i * m + j];
    }




    }
    y=0;
    k=m;
    for(i = 0; i < n; i++)
    {

        for(j = k; j <= m ; j++)
    {

            dane.push_back(A[i+y*k]);
            zli = zli + A[i+y*k];
            y++;

    }
        B[q]=zli;
        q++;
        m++;
        y=0;
        zli=0;
    }

    for( size_t i = 0; i < dane.size(); i++ )
         printf( "%d, ", dane[ i ] );

         for(i=0;i<k;i++){
            cout<<B[i]<<":";
         }

    return 0;
}
