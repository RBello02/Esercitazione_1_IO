#include <iostream>
#include <iomanip>
#include <fstream>


long double mean (long double a, long double b)
{
    return (a+b)/2;
}

long double map (long double x)
{
    long double a = 3./4.;
    long double b = -7./4.;
    return a*x+b;
}


int main()
{
    std::ifstream inFile("data.csv");          // creo una variabile stringa che contiene il nome del file
    std::ifstream inFile1;              // crea un oggetto istream e lo apre in lettura
    inFile1.open("data.csv");

    if (inFile1.fail())                           // restituisce 1 se l'apertura del file fallisce, l'if se legge 1 elabora quello che c'è tra parentesi
    {
        std::cerr << "Apertura del file fallita" << std::endl;  // cerr restituisce un output di errore
        return 1;
    }

    long double value = 0;
    int counter = 1;
    long double media = 0;
    long double precedente = 0;

    std::ofstream outFile("result.csv");
    if (outFile.fail())
    {
        std::cerr << "Apertura del file fallita" << std::endl;
        return 2;
    }


    outFile << "# N Mean" << std::endl;

    while(inFile >> value)       // faccio un while che legge il file fino alla fine
    {
        if (counter == 1)
        {
            media = map(value);
        }
        else
        {
            media = mean(map(value),precedente);
        }
        //std::cout << counter << " " << std::setprecision(16)<< std::scientific << media << std::endl;
        outFile << counter << " " << std::setprecision(16)<< std::scientific << media << std::endl; // scrivo sul file
        precedente = media;
        counter++;
    }
    inFile.close();
    outFile.close();





    return 0;
}
