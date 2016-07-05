/*
Il programma dovrà, attraverso un Menù, leggere da tastiera se l'utente vuole:
a) inserire in maniera ordinata decrescente un numero intero nella lista di elementi definita come da
esempio. Tale lettura si dovrà ripetere finché il valore inserito è negativo;
b) calcolare la somma di tutti i valori presenti nella lista e stampare a video tale valore;
c) scegliere se calcolare la somma dei soli numeri pari o dispari presenti nella lista e stamparla a video. Per
scegliere tra pari e dispari si deve utilizzare una variabile FLAG:
• se in tale variabile, si inserisce da tastiera il numero 1 allora si vuole la somma dei soli numeri pari
• se in tale variabile, si inserisce da tastiera il numero 0 allora si vuole la somma dei soli numeri
dispari
d) stampare a video tutti i numeri interi contenuti nella lista;
e) scrivere su di un file di testo l'intero contenuto della lista. Leggere da tastiera il nome del file su cui si
vuole scrivere;
f) uscire dal programma.
Nel caso si inserisca una lettera diversa da: a,b,c,d,e,f il programma dovrà scrivere un messaggio di errore e
richiedere nuovamente il Menù.
*/
#include <iostream>
#include <fstream>
using namespace std;
struct studente
{
int valore;
studente* succ;
};
typedef studente* lista;

void inserisci_dati(studente&);
int somma_valori_totali(lista);
void somma_valori(lista, int);
void inserisci_ordinatamente(lista&, studente );
void stampa_lista(lista);
void salva_file(lista, char[]);

int main(){
    lista inizio=0;
    char s;
    studente elem;
    char file[15];
    int c;
    do{
        do{
            cout << "\nMENU'\n";
            cout << "a) Inserisci un valore intero nella lista\n";
            cout << "b) Calcola la somma di tutti i valori presenti nella lista\n";
            cout << "c) Calcola la somma dei valori pari o dispari presenti nella lista\n";
            cout << "d) Visualizza a schermo il contenuto della lista\n";
            cout << "e) Scrivi su file il contenuto della lista\n";
            cout << "f) Esci\n";
            cout << "Scelta:"<<endl;
            cin>>s;
            if(s!='a'&&s!='b'&&s!='c'&&s!='d'&&s!='e'&&s!='f')
                cout<<"lettera non consentita"<<endl;
        }while(s!='a'&&s!='b'&&s!='c'&&s!='d'&&s!='e'&&s!='f');
            switch(s){
            case 'a':{
                inserisci_dati(elem);
                inserisci_ordinatamente(inizio,elem);
            break;
            }
            case 'b':{
                cout<<"la somma dei valori della lista e' "<<somma_valori_totali(inizio)<<endl;
            break;
            }
            case 'c':{
                do{
                cout<<"inserisci 1 per sommare i pari, 0 per sommare i dispari"<<endl;
                cin>>c;
                if(c!=1&&c!=0)
                    cout<<"numero non consentito"<<endl;
                }while(c!=1&&c!=0);
                    somma_valori(inizio,c);
                break;
            }
            case 'd':{
                stampa_lista(inizio);
            break;
            }
            case 'e':{
                salva_file(inizio,file);
            break;
            }
            break;
            }
    }while(s!='f');
    return 0;
}

void inserisci_dati(studente& s){
do{
cout<<"inserisci il numero"<<endl;
cin>>s.valore;//inserisce il valore nella struct
if(s.valore<0)
    cout<<"sono consentiti solo numeri positivi"<<endl;
}while(s.valore<0);
}

void inserisci_ordinatamente(lista& inizio, studente e){//ordina in modo decrescente
lista p=0,q,r;
for (q=inizio; q!=0 && q->valore > e.valore; q = q->succ)//il > ordina in modo decrescente
p = q;
r = new studente;
*r=e;// questa riga copia tutto il contenuto della struct nella lista (in r)
r->succ=q;
if (q == inizio) inizio = r;
else p->succ = r;
}

int somma_valori_totali(lista p0){
int somma=0;
while(p0!=0){
    somma+=p0->valore;//somma i valori della lista
    p0=p0->succ;
}
return somma;
}

void somma_valori(lista p0, int flag){
int somma1=0,somma=0;
while(p0!=0){
    if(p0->valore%2==0){
        somma+=p0->valore;
    }
    else somma1+=p0->valore;
    p0=p0->succ;
    }
if(flag==1){
    cout<<"la somma dei numeri pari e' "<<somma<<endl;
}
if(flag==0){
    cout<<"la somma dei numeri dispari e' "<<somma1<<endl;
}
}


void stampa_lista(lista p0){
while(p0!=0){
    cout<<p0->valore<<endl;
    p0=p0->succ;
}
}

void salva_file(lista p0, char nome[]){
fstream output;
cout<<"inserisci il nome del file"<<endl;
cin>>nome;
output.open(nome,ios::out);
while(p0!=0){
    output<<p0->valore<<endl;
    p0=p0->succ;
}
output.close();
cout<<"lista salvata nel file "<<nome<<" con successo"<<endl;
}

//Coded by DarkCerfa
