#include <iostream>
#include <fstream>
using namespace std;
struct studente
{
 int valore;
 studente* succ;
};
typedef studente* lista;
/* Questa procedura chiede e legge dall'input standard un valore intero positivo*/
void inserisci_dati(studente& s)
{ 
do {
cout << "Per favore, inserisci il numero intero positivo: ";
cin >> s.valore;
if (s.valore<0) cout << "Devi inserire valori positivi!" << endl; // messaggio d'errore se viene inserito un valore negativo
}
while (s.valore<0); //ferma  il ciclo quando il valore è positivo
 }
/* Questa funzione calcola il totale dei valori presenti nella lista*/
int somma_valori_totali(lista p0)
{
int i=0; 
while (p0!=0)
{
	i+=p0->valore;
	p0=p0->succ;
}
return i;
  }
  /* Questa procedura calcola il totale dei valori pari se il flag è 1 o dei valori dispari se il flag è 0, li stampa poi a video*/
void somma_valori(lista p0, int flag)
{
	int f,sompar=0,somdisp=0;
	while (p0!=0)
	{
		f=p0->valore;
		if (flag==1 && (f%2==0))
	{
		sompar+=f; //somma i numeri pari
	}
	else if (flag==0 && (f%2!=0))
	{
		somdisp+=f; //somma i numeri dispari
	}
	p0=p0->succ;
	}
	if (flag==0) cout << "La somma di tutti i valori dispari presenti nella lista e': "  << somdisp << endl;
    else if(flag==1) cout << "La somma di tutti i valori pari presenti nella lista e': " << sompar << endl;
 }
 /* Questa procedura visualizza la lista a schermo */
void stampa_lista(lista p0)
{ 
cout << "La lista e'" << endl;
while (p0!=0)
{
	cout << p0->valore << endl;
	p0=p0->succ;
}
}
/* Questa procedura inserisce nella lista in maniera ordinata (derescente) i valori interi */
void inserisci_ordinatamente(lista& inizio, studente e)
{ 
lista p=0,q,d;
for(q=inizio;q!=0 && q->valore>e.valore;q=q->succ) p=q;
d=new studente;
d->valore=e.valore; // si può scrivere anche *d=e
d->succ=q;
if(q==inizio)inizio=d;
else p->succ=d;
}
/* Questa procedura salva su file il contenuto della lista */
void salva_file(lista p0, char nome[])
{
fstream damiano;
damiano.open(nome,ios::out);
while(p0!=0)
{
damiano << p0->valore << endl;
p0=p0->succ;	
}
damiano.close();	
} 
int main()
{
	char r;
	int flag;
	char nome[20];
	lista p0=0;
	studente e;
do
{
cout<< "MENU\n"
"a) Inserisci un valore intero nella lista\n"
"b) Calcola la somma di tutti i valori presenti nella lista\n"
"c) Calcola la somma dei valori pari o dispari presenti nella lista\n"
"d) Visualizza a schermo il contenuto della lista\n"
"e) Scrivi su file il contenuto della lista\n"
"f) Esci\n" 
"Scelta: ";
cin >> r;
 switch (r)
 {
 	case 'a': {
		inserisci_dati(e);
		inserisci_ordinatamente(p0,e);
	 }break;
	 case 'b': {
	 	cout << "Il totale dei valori presenti nella lista e': " << somma_valori_totali(p0) << endl; 
	 }break;
	 case 'c':{
	 	cout << "Inserisci 1 se vuoi stampare il totale dei numeri pari, 0 per il totale dei numeri dispari: ";
	 	cin >> flag;
	 	somma_valori(p0,flag);
	 }break;
	 case 'd':
	 	{
	 		stampa_lista(p0);
		 }break;
		 case 'e':{
		 	cout << "Inserisci il nome del file su cui salvare il contenuto della lista: ";
		 	cin >> nome;
			salva_file(p0,nome);
			cout << "Valori salvati sul file: " << nome << endl;
		 }break;
		 case 'f':{}break;
		 default : cout << "carattere non consentito" << endl;break;
 }
}
while (r!='f');
}

