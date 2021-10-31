#include <iostream>

using namespace std;

main()
{

    int n=0, m=0, i=0, j=0, p=0,k=0,q=0,y=0,zli=0,k2=0,zli2=0,q2=0,n2=0,m2=0;

    cout<<"Podaj ilosc kolumn: "<<endl;
    cin>>m;
    cout<<"Podaj ilosc wierszy: "<<endl;
    cin>>n;

  p = n * m;

  int * A = new int[p];
  int * B = new int[p];
  int * B2 = new int[p];

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
    k2=m;
    m2=m;
    n2=n;

    for(i = 0; i < n; i++)
    {

        for(j = k; j <= m ; j++)
        {
            zli = zli + A[i+y*k];
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
                zli2 = zli2 + A[m2*n2-k2];
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
            cout<<"Kolumna"<<i+1<<endl;
        }
    }
    return 0;
}
