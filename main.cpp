
#include <iostream>
using namespace std;
//mediante esta ordenamiento de Mergesort dividimos nuestro arreglo para ordenar de la manera mas eficinete ;
#include <fstream>

void dividir(int a[], int inicial, int final);

void fusionar(int a[], int pinicial, int pfinal, int medio);


int main()
{
   ofstream Mergesort;
   Mergesort .open ("Mergesort.txt.",ios::app);
    int numeros[7]={38,27,43,3,9,82,10};


    
    cout <<"lA LISTA INGRESADA\n";
    Mergesort<<"lA LISTA INGRESADA\n";
    for (int i=0; i<7;i++)
    {
        
        cout<<"|"<<numeros[i]<<"|";
        Mergesort<<"|"<<numeros[i]<<"|";
    }
   cout <<endl;
    dividir(numeros,0,6);
    

    cout <<"lA LISTA NUEVA\n";
    Mergesort<<"\nlA LISTA ORDENADA\n";
    Mergesort<<endl;
    for (int i=0; i<7;i++)
    {

        cout<<"|"<<numeros[i]<<"|";
        
        Mergesort<<"|"<<numeros[i]<<"|";
        
    }



    return 0;
}


void dividir(int a[], int inicial, int final)
{

    int mitad;

    if (inicial<final)
    {
        mitad=(inicial+final)/2;

        dividir(a,inicial,mitad);

        dividir(a,mitad+1,final);

        fusionar(a,inicial,final,mitad);
    }

}

void fusionar(int a[], int pinicial, int pfinal, int medio)
{
    int i, j, k, temp[pfinal-pinicial+1];
	i = pinicial;
	k = 0;
	j = medio + 1;

	while (i <= medio && j <= pfinal)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= medio)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <=pfinal)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = pinicial; i <= pfinal; i++)
	{
		a[i] = temp[i-pinicial];
	}
}