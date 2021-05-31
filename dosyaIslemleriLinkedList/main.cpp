#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct node{
    int data;
    node *next, *prev;
};

struct node *head= NULL;

void ekle(int key){
    node *eleman= new node();
    eleman->data=key;

    if(head==NULL){
        head=eleman;
        head->next = head;
        head->prev = head;
        cout << "Listeye ilk eleman eklendi!" << endl;}

    else{
        node* iter= head;
        while(iter->next!=head)
            iter= iter->next;
        iter->next=eleman;
        eleman->next=head;
        head->prev=eleman;
        eleman->prev=iter;
        cout << "Liste sonuna eleman eklendi!" << endl;}
}

void sil(int key){
    if(head==NULL){ //Liste bossa
        cout << "Liste bos!" << endl;}

    else{ //Liste bos degilse
        if(head->next==head && head->data==key){ //liste tek elemanliysa
            head->next=NULL;
            head->prev=NULL;
            head=NULL;
            free(head);
            cout << "Listedeki ilk ve son elemani silindi!" << endl;}

        else if(head->next!=head){ //Liste tek elemanli degilse

            node* iter= head;
            while(iter->next!=head && iter->data!=key){ //Sona kadar git
                iter=iter->next;}

            if(head->data==key){ //Listenin ilk elemani silinmek isteniyorsa
                node* temp= head->prev;
                node* temp2= head->next;
                temp->next=temp2;
                temp2->prev=temp;
                delete head;
                head=temp2;
                cout << "Listenin ilk elemani silindi!" << endl;}


            else if(iter->next==head && iter->data!=key){ //Sona gelindiyse ve silinmek istenen sayi bulunamadiysa
                cout << "Silmek istediginiz sayi bulunamadi!" << endl;}

            else if(iter->next!=head && iter->data==key){ //Sona gelinmediyse ve silinmek istenen eleman bulunduysa
                node* temp= iter->next;
                temp->prev=iter->prev;
                iter->prev->next=temp;
                free(iter);
                cout << "Listeden eleman silindi!" << endl;}

            else if(iter->next==head && iter->data==key){ //Listenin sonundaki eleman silinmek isteniyorsa
                node *temp= iter->prev;
                temp->next=head;
                head->prev=temp;
                free(iter);
                cout << "Listenin son elemani silindi!" << endl;}


        }

    }
}

void yazdir(){
    node* iter=head;
    if(iter==NULL){
        cout << "Liste bos!" << endl;
    }

    else if(iter==head){
        cout << iter->data << " -> ";
        iter=iter->next;}

    while(iter!=head){
        cout << iter->data << " -> ";
        iter=iter->next;}
    cout << endl;
}


void dosyayaYaz(){
    cout << endl;
    if(head==NULL)
        cout << "Dosyaya yazilacak bir veri bulunamadi, liste bos!" << endl;

    else{
        ofstream yaz("DoublyCircularLinkedListFile.txt",ios::app);
        node* iter=head;
        if(iter==head){
            yaz << iter->data  << endl;
            iter= iter->next; }

        while(iter->next!=head){
            yaz << iter->data  << endl;
            iter= iter->next; }

        yaz.close();
        cout << "Cift yonlu dairesel bagli listedeki veriler kaydedildi!" << endl;}
}

void dosyadanOku(){
    cout << "Dosyada kayitli olan veriler okunuyor..." << endl;
    ifstream oku("DoublyCircularLinkedListFile.txt",ios::app);
    string satir;
    while(getline(oku,satir))
        cout << satir << " ";
    cout << endl;
    oku.close();
    cout << "Cift yonlu dairesel bagli listedeki veriler okundu!" << endl;}

void dosyadanBagliListeyeAktar(){
    cout << "Dosyadan kayitli veriler bagli listeye aktariliyor..." << endl;
    ifstream oku("DoublyCircularLinkedListFile.txt",ios::app);
    string satir;
    while(getline(oku,satir)){
        int sayi= stoi(satir);
        ekle(sayi);}
    oku.close();
    cout << "Dosyadaki veriler bagli listeye aktarildi!" << endl;
    }

int main()
{
    cout << "Sil: 20" << endl;
    sil(20);

    cout << "\nEkle: 15" << endl;
    ekle(15);
    yazdir();

    cout << "\nSil: 15" << endl;
    sil(15);
    yazdir();

    cout << "\nEkle: 16" << endl;
    ekle(16);

    cout << "\nEkle: 20" << endl;
    ekle(20);

    cout << "\nSil: 16" << endl;
    sil(16);
    yazdir();

    cout << "\nEkle: 38" << endl;
    ekle(38);

    cout << "\nEkle: 74" << endl;
    ekle(74);

    cout << "\nEkle: 41" << endl;
    ekle(41);
    yazdir();

    cout << "\nSil: 20" << endl;
    sil(20);
    yazdir();

    cout << "\nSil: 100" << endl;
    sil(100);
    yazdir();

    cout << "\nSil: 74" << endl;
    sil(74);
    yazdir();

    cout << "\nSil: 41" << endl;
    sil(41);
    yazdir();

    cout << "\nSil: 38" << endl;
    sil(38);
    yazdir();









    return 0;
}
