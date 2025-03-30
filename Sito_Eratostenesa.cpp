#include <iostream>

using namespace std;

void sito(bool *tab, unsigned int n)
{
	for (int i=2; i*i<=n; i++)
    {
        if(!tab[i])
		for (int j = i*i ; j<=n; j+=i)
            tab[j] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n,suma=0;
	bool *tab;


	cin>>n;

	tab = new bool [n+1];

	for(int i=2; i<=n; i++)
		tab[i] = 0;

	sito(tab, n);

    for(int i=2;i<=n;i++)
		if(!tab[i])
            suma++;

          cout<<suma<<endl;
	for(int i=2;i<=n;i++)
		if(!tab[i])

			cout<<i<<" ";

	delete []tab;



    return 0;
}
