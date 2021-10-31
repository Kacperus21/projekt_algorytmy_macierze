#include <iostream>

using namespace std;

main()
{
  int n, m, i, j, p,k,q=0,y;

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
            B[q]=A[(i * m + j)];
            q++;

    }


    }
  cout << endl;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < m; j++) cout << A[i * m + j] << " ";
    cout << endl;
  }

  for(i=0;i<p;i++){
    cout<<B[i]<<":";
  }


    return 0;
}
