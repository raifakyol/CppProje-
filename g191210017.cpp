//*****************************************************************************//
//*
//*					     SAKARYA �N�VERS�TES�
//*				B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
//*				     B�LG�SAYAR M�HEND�SL��� B�L�M�
//*				       PROGRAMLAMAYA G�R�� DERS�
//*					       2020 YAZ D�NEM�
//*	
//*				�DEV NUMARASI..........: PROJE
//*				��RENC� ADI............: RA�F AKYOL
//*				��RENC� NUMARASI.......: G191210017
//*             
//*****************************************************************************//

#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>   //gerekli k�t�phaneler.
#include <string>
#include <sstream>
#include<locale.h>
#include<conio.h>
#include <cstdio>

using namespace std;
void DosyadanOku()
{
    ifstream fileread;
    fileread.open("�r�nbilgileri.txt", ios::in);//�r�nbilgileri.txt dosyas�n� a�
    string okunan;
    while (!fileread.eof())//dosyan�n sonuna kadar oku
    {
        getline(fileread, okunan);
        cout << okunan << "\n";//okunan karakterleri ekrana yaz.
    }
    fileread.close();//dosyay� kapa.
}
void DosyadanOku2()
{
    ifstream fileread;
    fileread.open("proje.txt", ios::in);//proje.txt dosyas�n� a�
    string okunan;
    while (!fileread.eof())//dosyan�n sonuna kadar oku
    {
        getline(fileread, okunan);
        cout << okunan << "\n";//okunan karakterleri ekrana yaz.
    }
    fileread.close();//dosyay� kapa.
}
void DosyadanOku3()
{
    ifstream fileread;
    fileread.open("projehakedisrapor.txt", ios::in);//projehakedisrapor.txt dosyas�n� a�
    string satir = "";
    while (!fileread.eof())//dosyan�n sonuna kadar oku
    {
        getline(fileread, satir);
        cout << satir << "\n";//okunan karakterleri ekrana yaz.
    }
    fileread.close();//dosyay� kapa.
}
double Carp(double s1, double s2)//Urun adeti ve birim fiyat�n� �arp�p urunun fiyat�n� hesaplamak i�in gerekli
{
    return s1 * s2;
}
double Topla(double s1, double s2)//Urun fiyatlar� Toplama i�in gerekli
{
    return s1 + s2;
}
int main()
{
    int secim,i=0;
    string urunAd;
    string birim;
    double birimFiyat[30];  //urunlerin degiskenleri tan�mlan�r.
    string marka;
    string urunNo[30];

    string projeNo[30];
    string projeAdi;
    string projeYrtcFirma;//projenin degiskenleri tan�mlan�r.
    string projeSorumlusu;
    string projeKontrol�r�;

    string hTarih, hNo, hAdi;
    double hAdet, hUrnFiyat; //raporlar�n de�i�kenleri tan�mlan�r.
    string eklUrunNo;
    char cevap = 'e';
    do
    {
        cout << "--------------------------------------------------------------" << endl;
        cout << " Secim Yapiniz... " << endl;
        cout << " 1- Urun  Ekleme " << endl;
        cout << " 2- Urun  Silme " << endl;
        cout << " 3- Urun  Arama " << endl;
        cout << " 4- Urun  Raporlama " << endl;
        cout << " 5- Proje Ekleme " << endl;
        cout << " 6- Proje Silme " << endl;
        cout << " 7- Proje Arama " << endl;
        cout << " 8- Proje Raporlama " << endl;
        cout << "--------------------------------------------------------------" << endl;
        cin >> secim; cout<<endl;
    } while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8);
    
    ofstream dosyaYaz("�r�nbilgileri.txt", ios::app);
    ofstream dosyaYazz("proje.txt", ios::app);
    if (secim == 1)//eger secim 1- Urun  Ekleme ise
    { 
        cout << "-------------------------Urun Listesi-------------------------" << endl;
        DosyadanOku(); //�ncelikle �r�n listesini ekrana yaz.
        cout << "--------------------------------------------------------------" << endl;
        do
        {
            cout <<endl<< "urunNo urunAd birim birimFiyat marka"<<endl; //�r�n eklemek i�in gerekli olan bilgileri s�ras�yla ekrana yaz.
            cin >> urunNo[i], cin >> urunAd, cin >> birim, cin >> birimFiyat[i], cin >> marka;//gerekli bilgileri kullan�c�dan yazd�r.
            dosyaYaz <<"\n "<< urunNo[i] << " " << urunAd << " " << birim << " " << birimFiyat[i] << " " << marka << endl;//dosyaya kullan�c�n�n yazd�klar�n� s�ras�yla yaz.
            cout << "\n baska ekleme yapacak misin ? (e/h)";cin >> cevap;//baska ekleme yapacaksa devam etmek icin e (evet) se�ilsin devam etmeyecekse h (hay�r) se�ilsin.
        } while (!(cevap == 'h'));//(cevap h degil ise devam et)
        dosyaYaz.close();
        cout << "----------------------Yeni Urun Listesi-----------------------"<<endl;
        DosyadanOku();//yenilenen �r�n bilgilerini yazd�r.
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 2)//eger secim 2 - Urun  Silme ise
    { 
        cout << "-------------------------Urun Listesi-------------------------" << endl;
        DosyadanOku(); //�ncelikle �r�n listesini ekrana yaz.  
        cout << "--------------------------------------------------------------" << endl;
        int gcc2 = 0;
        char cvp;
        string silUrunNo;//�r�n silmek i�in gerekli olan �r�n numaras� de�i�keni.
        ifstream dosyaSil("�r�nbilgileri.txt", ios::in);
        cout << "Silinecek urun nosunu giriniz :"; cin >> silUrunNo;//kullan�c�ya �r�n numaras�n� girdir.

        while (!(dosyaSil.eof())) 
        {
            for (int i = 0;i < 30;i++)
            {
                dosyaSil >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka;//dosyay� sonuna kadar okut.
                if (urunNo[i] == silUrunNo)//eger urunNumaras� e�itse silinecek �r�n numaras�na
                {
                    cout << "------------------------Urun Bilgileri------------------------" << endl;
                    cout << "urunNo :" << silUrunNo << " ";
                    cout << "urunAd :" << urunAd << " ";
                    cout << "birim :" << birim << " ";  //urun un bilgilerini yazd�r.
                    cout << "birimFiyat :" << birimFiyat[i] << " ";
                    cout << "marka :" << marka << "\n";
                }   
            }   
            cout << "Urun silmek istiyor musunuz ? (e/h)";//�r�n� silip silmeyece�ini sor.
            cin >> cvp;
        }
        if (cvp == 'e')//urunu silmek istiyorsa
        {
            ifstream DosyaOku("�r�nbilgileri.txt", ios::beg);
            ofstream geciciDosyaYaz("yeni�r�nbilgileri.txt");
            while (DosyaOku >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka)
            {
                if (silUrunNo != urunNo[i])//silinen urun numaras� dosyadaki �r�n numaras�yla e�le�miyorsa
                {
                    geciciDosyaYaz << urunNo[i] << " " << urunAd << " " << birim << " " << birimFiyat[i] << " " << marka << "\n";//dosyaya �r�nlerin bilgilerini eslesmedi�i i�in silinmeden ayn� �ekilde yaz
                }
                if (silUrunNo == urunNo[i])//eger silinecek �r�n numaras� e�itse urunNumaras�na
                    gcc2 = 1;//gcc2 degi�kenini 1 yap
            }
            dosyaSil.close();
            geciciDosyaYaz.close();//dosyalar� kapatt�k
            DosyaOku.close();
            if (gcc2 == 0)//gcc2 degiskeni esitse 0 a
                cout << "Boyle bir urun yoktur." << endl;//b�yle bir �r�n yok
            if (gcc2 == 1)//gcc2 degiskeni esitse 1 e
            {
                cout << "Urun Silindi." << endl;//urun silindi
                cout << "----------------------Yeni Urun Listesi-----------------------" << endl;
                ifstream fileread;
                fileread.open("yeni�r�nbilgileri.txt", ios::in);
                string okunan;
                while (!fileread.eof())
                {
                    getline(fileread, okunan);
                    cout << okunan << "\n";//yeni urun listesini ekrana yaz.
                }
            }
        }
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 3)//eger secim 3- Urun  Arama ise
    {
        cout << "-------------------------Urun Listesi-------------------------" << endl;
        DosyadanOku();//�ncelikle �r�n listesini ekrana yaz.  
        cout << "--------------------------------------------------------------" << endl;
       
        ifstream dosyaAra("�r�nbilgileri.txt",ios::in);
        string araUrunNo;//�r�n aramak i�in gerekli olan �r�n numaras� de�i�keni.
        cout << "Arama yapilacak urunNo :"; cin >> araUrunNo;//kullan�c�ya �r�n numaras�n� girdir.
        int gcrldgl = 0;
        while (!(dosyaAra.eof())) 
        {
            for (int i = 0;i < 30;i++)
            {
                dosyaAra >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka;//dosyay� sonuna kadar okut.
                if (urunNo[i] == araUrunNo)//eger urunNumaras� e�itse silinecek �r�n numaras�na
                {
                    cout << "-----------------Arama Yapilan Urun Bilgileri-----------------" << endl;
                    cout << "urunNo :" << araUrunNo << " ";
                    cout << "urunAd :" << urunAd << " ";
                    cout << "birim : " << birim << " ";//aranan urun un bilgilerini yazd�r.
                    cout << "birimFiyat :" << birimFiyat[i] << " ";
                    cout << "marka :" << marka << "\n";
                    gcrldgl = 1;//gcrldgl degi�kenini 1 yap
                } 
            }  
            
        }
        if (gcrldgl == 0)//gcrldgl degiskeni esitse 0 a
        {
            cout << "Boyle Bir Urun Bulunmamaktadir..." << endl;//b�yle bir urun yok
        }
        dosyaAra.close();//dosyay� kapat.
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 4)//eger secim 4- Urun  Raporlama  ise
    {
        cout << "-------------------------Urun Listesi-------------------------" << endl;
        DosyadanOku();//�ncelikle �r�n listesini ekrana yaz.  
        char cvp;
        ifstream dosya1("�r�nbilgileri.txt", ios::in);
        cout << "------------------------Hakedis Raporu------------------------" << endl;
        cout << "Hakedis Tarihi :", cin >> hTarih;
        cout << "Hakedis No :", cin >> hNo; //hakedis raporu bilgilerini kullan�c�dan iste
        cout << "Yapilan Isin Adi :", cin >> hAdi;
        while (!(dosya1.eof()))
        {
            cout << "Eklenecek urunNo :"; cin >> eklUrunNo;
            cout << "Urun Adeti :", cin >> hAdet;
            for (int i = 0;i < 30;i++)
            {
                dosya1 >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka;//dosyay� sonuna kadar okut.
                if (urunNo[i] == eklUrunNo)
                {
                    hUrnFiyat= Carp(hAdet, birimFiyat[i]);//urunun fiyat� i�in adet bilgisiyle birimfiyat bilgisini carp ve urun fiyata esitle
                    ofstream dosyaYazz("�r�nhakedisrapor.txt", ios::app);
                    dosyaYazz << hTarih << " "
                        << hNo << " "
                        << hAdi << " "
                        << eklUrunNo << " " //dosyaya hakedis raporunu yaz.
                        << hAdet << " " 
                        << birimFiyat[i] << " "
                        << hUrnFiyat<<"\n";
                }
            }
            cout << "Urunu eklemek istiyor musunuz ? (e/h)";//�r�n ekleyip eklemeyece�ini sor.
            cin >> cvp;
        }
        do //urunu eklemek istiyorsa
        {
            cout << "Eklenecek urunNo :"; cin >> eklUrunNo;
            cout << "Urun Adeti :", cin >> hAdet;//hakedis raporu bilgilerini kullan�c�dan iste
            for (int i = 0;i < 30;i++)
            {
                dosya1 >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka;//dosyay� sonuna kadar okut.
                if (urunNo[i] == eklUrunNo)
                {
                    ofstream dosyaYazz("�r�nhakedisrapor.txt", ios::app);
                    dosyaYazz << hTarih << " "
                        << hNo << " "
                        << hAdi << " "
                        << eklUrunNo << " " //dosyaya hakedis raporunu yaz.
                        << hAdet << " "
                        << birimFiyat[i] << " "
                        << hUrnFiyat << "\n ";
                }   
            }
            cout << "baska ekleme yapacak misin ? (e/h)";cin >> cvp;//baska ekleme yapacaksa devam etmek icin e (evet) se�ilsin devam etmeyecekse h (hay�r) se�ilsin.
        } while (!(cvp == 'h'));
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 5)//eger secim  5- Proje Ekleme ise
    {
        cout << "-------------------------Proje Listesi------------------------" << endl;
        DosyadanOku2();//�ncelikle proje listesini ekrana yaz.  
        cout << "--------------------------------------------------------------" << endl;
        do
        {
            cout <<endl<< "projeNo projeAdi projeYurutucuFirma projeSorumlusu projeKontroloru" << endl;//proje eklemek i�in gerekli olan bilgileri s�ras�yla ekrana yaz.
            cin >> projeNo[i], cin >> projeAdi, cin >> projeYrtcFirma, cin >> projeSorumlusu, cin >> projeKontrol�r�;//gerekli bilgileri kullan�c�dan yazd�r.
            dosyaYazz << projeNo[i] << " " << projeAdi << " " << projeYrtcFirma << " " << projeSorumlusu << " " << projeKontrol�r� << endl;//dosyaya kullan�c�n�n yazd�klar�n� s�ras�yla yaz.
            cout << "\n baska ekleme yapacak misin ? (e/h)";cin >> cevap;//baska ekleme yapacaksa devam etmek icin e (evet) se�ilsin devam etmeyecekse h (hay�r) se�ilsin.
        } while (!(cevap == 'h'));//(cevap h degil ise devam et)
        dosyaYazz.close();
        cout << "----------------------Yeni Proje Listesi----------------------" << endl;
        DosyadanOku2();//yenilenen proje bilgilerini yazd�r.
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 6)//eger secim  6- Proje Silme ise
    {
        cout << "-------------------------Proje Listesi------------------------" << endl;
        DosyadanOku2();//�ncelikle proje listesini ekrana yaz. 
        cout << "--------------------------------------------------------------" << endl;
        int gcc3 = 0;
        char cvp2;
        ifstream dosyaSil2("proje.txt", ios::in);
        string silProjeAdi;//proje silmek i�in gerekli olan proje numaras� de�i�keni.
        cout << "Silinecek proje nosunu giriniz :"; cin >> silProjeAdi;//kullan�c�ya proje numaras�n� girdir.

        while (!(dosyaSil2.eof()))
        {
            for (int i = 0;i < 15;i++)
            {
                dosyaSil2 >> projeNo[i] >> projeAdi >> projeYrtcFirma >> projeSorumlusu >> projeKontrol�r�;//dosyay� sonuna kadar okut.
                if (projeNo[i] == silProjeAdi)//eger projeNumaras� e�itse silinecek proje numaras�na
                {
                    cout << "------------------------Proje Bilgileri------------------------" << endl;
                    cout << "projeNo :" << silProjeAdi << " ";
                    cout << "projeAdi :" << projeAdi << " ";
                    cout << "projeYrtcFirma :" << projeYrtcFirma << " ";//proje bilgilerini yaz.
                    cout << "projeSorumlusu :" << projeSorumlusu << " ";
                    cout << "projeKontroloru :" << projeKontrol�r� << "\n";
                }
            }
            cout << "Proje silmek istiyor musunuz ? (e/h)";//projenin silip silmeyece�ini sor.
            cin >> cvp2;
        }
        if (cvp2 == 'e')//projeyi silmek istiyorsa
        {
            ifstream DosyaOku2("proje.txt", ios::beg);
            ofstream geciciDosyaYaz2("yeniproje.txt");
            while (DosyaOku2 >> projeNo[i] >> projeAdi >> projeYrtcFirma >> projeSorumlusu >> projeKontrol�r�)
            {
                if (silProjeAdi != projeNo[i])//silinen proje numaras� dosyadaki proje numaras�yla e�le�miyorsa
                {
                    geciciDosyaYaz2 << projeNo[i] << " " << projeAdi << " " << projeYrtcFirma << " " << projeSorumlusu << " " << projeKontrol�r� << "\n";//dosyaya projelerin bilgilerini eslesmedi�i i�in silinmeden ayn� �ekilde yaz
                }
                if (silProjeAdi == projeNo[i])//eger silinecek proje numaras� e�itse projeNumarasina
                    gcc3 = 1;//gcc3 degiskeninin 1 yap
            }
            dosyaSil2.close();
            geciciDosyaYaz2.close();//dosyalar� kapat.
            DosyaOku2.close();
            if (gcc3 == 0)//gcc3 esitse  0 a
                cout << "Boyle bir proje yoktur." << endl;//boyle bir proje yok
            if (gcc3 == 1)//gcc3 esitse  1 e
            {
                cout << "Proje Silindi." << endl;//proje silindi
                cout << "----------------------Yeni Proje Listesi-----------------------" << endl;
                ifstream fileread;
                fileread.open("yeniproje.txt", ios::in);
                string okunan;
                while (!fileread.eof())
                {
                    getline(fileread, okunan);
                    cout << okunan << "\n";//yeni proje listesini ekrna yaz.
                }
            }
        }
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 7)//eger secim 7- Proje Arama ise
    {
        cout << "-------------------------Proje Listesi------------------------" << endl;
        DosyadanOku2();//�ncelikle proje listesini ekrana yaz. 
        cout << "--------------------------------------------------------------" << endl;
        ifstream dosyaAra("proje.txt");
        string araProjeNo;//proje aramak i�in gerekli olan proje numaras� de�i�keni.
        cout << "arama yapilacak projeNo:"; cin >> araProjeNo;//kullan�c�ya proje numaras�n� girdir.
        int gcrldgl = 0;
        while (!(dosyaAra.eof())) 
        {
            for (int i = 0;i < 30;i++)
            {
                dosyaAra >> projeNo[i] >> projeAdi >> projeYrtcFirma >> projeSorumlusu >> projeKontrol�r�;//dosyay� sonuna kadar okut.
                if (projeNo[i]== araProjeNo)//eger projeNumaras� e�itse aranack proje numaras�na
                {
                    cout << "-----------------Arama Yapilan Proje Bilgileri-----------------" << endl;
                    cout << "projeNo :" << araProjeNo << " ";
                    cout << "projeAdi :" << projeAdi << " ";
                    cout << "projeYrtcFirma : " << projeYrtcFirma << " ";//arannan proje bilgilerini yaz.
                    cout << "projeSorumlusu :" << projeSorumlusu << " ";
                    cout << "projeKontroloru :" << projeKontrol�r� << "\n";
                    gcrldgl = 1;//gcrldgl degi�kenini 1 yap
                }
            }
        }
        if (gcrldgl == 0)//gcrldgl degiskeni esitse 0 a
        {
            cout << "Boyle Bir Proje Bulunmamaktadir..." << endl;//b�ye bir proje yok
        }
        dosyaAra.close();//dosyay� kapat.
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 8)///eger secim 8- Proje Raporlama ise
    {
        ofstream dosyaYazz("projehakedisrapor.txt", ios::app);
       
        int secim2;
        do
        {
            cout << "--------------------------------------------------------------" << endl;
            cout << " Secim Yapiniz... " << endl;
            cout << " 1- Kullanilan Urun  Listeleme " << endl;
            cout << " 2- Kullanilan Urun  Silme " << endl;
            cout << " 3- Kullanilan Urun  Arama " << endl;
            cout << " 4- Kullanilan Urun  Guncelleme " << endl;
            cout << "--------------------------------------------------------------" << endl;
            cin >> secim2; cout << endl;
        } while (secim2 != 1 && secim2 != 2 && secim2 != 3 && secim2 != 4);
        if (secim2 == 1)///eger secim 1- Kullanilan Urun  Listeleme ise
        {
            ifstream fileread;
            fileread.open("�r�nhakedisrapor.txt", ios::in);//�r�nhakedisrapor.txt dosyas�n� a�
            string okunan;
            while (!fileread.eof())//dosyan�n sonuna kadar oku
            {
                getline(fileread, okunan);
                cout << okunan << "\n";//okunan karakterleri ekrana yaz.
            }
            fileread.close();//dosyay� kapa.
        }
        if (secim2 == 2)///eger secim 2- Kullanilan Urun  Silme  ise
        {
            int gcc4 = 0;
            char cvp2;
            string silUrunNo2;//urun silmek i�in gerekli olan proje numaras� de�i�keni.
            ifstream dosyaSil2("�r�nhakedisrapor.txt", ios::in);
            cout << "Silinecek urun nosunu giriniz :"; cin >> silUrunNo2;//kullan�c�ya urun numaras�n� girdir.

            while (!(dosyaSil2.eof()))
            {
                for (int i = 0;i < 30;i++)
                {
                    dosyaSil2 >> hTarih >> hNo >> hAdi >> urunNo[i] >> hAdet >> birimFiyat[i] >> hUrnFiyat;//hakedis raporunu okuma
                    if (urunNo[i] == silUrunNo2)//eger urunNumaras� e�itse silinecek urun numaras�na
                    {
                        cout << "-----------------Silinen Urun Bilgileri-----------------" << endl
                            << "Hakedis Tarihi :" << hTarih << "\n"
                            << "Hakedis No :" << hNo << "\n"
                            << "Yapilan Isin Adi :" << hAdi << "\n"
                            << "Urun No :" << silUrunNo2 << " | " //silinen urun bilgilerini ekrana yazma
                            << "Urun Adeti :" << hAdet << " | "
                            << "Birim Fiyati :" << birimFiyat[i] << " | "
                            << "Urun Fiyat :" << hUrnFiyat << "\n";
                    }
                }
                cout << "Urun silmek istiyor musunuz ? (e/h)";//urunu silip silmeyece�ini sor.
                cin >> cvp2;
            }
            if (cvp2 == 'e')//projeyi silmek istiyorsa
            {
                ifstream DosyaOku("�r�nhakedisrapor.txt", ios::beg);
                ofstream geciciDosyaYaz2("yeni�r�nhakedisrapor.txt");
                while (DosyaOku >> hTarih >> hNo >> hAdi >> urunNo[i] >> hAdet >> birimFiyat[i] >> hUrnFiyat)
                {
                    if (silUrunNo2 != urunNo[i])//silinen urun numaras� dosyadaki urun numaras�yla e�le�miyorsa
                    {
                        geciciDosyaYaz2 << hTarih << " " << hNo << " " << hAdi << " " << urunNo[i] << " " << hAdet << " " << birimFiyat[i] << " " << hUrnFiyat<<"\n";//dosyaya urun bilgilerinin eslesmedi�i i�in silinmeden ayn� �ekilde yaz
                    }
                    if (silUrunNo2 == urunNo[i])//eger silinecek urun numaras� e�itse urunNumARar�sna 
                        gcc4 = 1;  //gcc4 degiskeninin 1 yap
                }
                dosyaSil2.close();
                geciciDosyaYaz2.close();//dosyalar� kapt.
                DosyaOku.close();
                if (gcc4 == 0)//gcc4 esitse  0 a
                    cout << "Boyle bir urun yoktur." << endl;//b�yle bir urun yok.
                if (gcc4 == 1)//gcc4 esitse  1 e
                {
                    cout << "Urun Silindi." << endl;//urun silindi
                    cout << "----------------------Yeni Hakedis Raporu-----------------------" << endl;
                    ifstream fileread;
                    fileread.open("yeni�r�nhakedisrapor.txt", ios::in);
                    string okunan;
                    while (!fileread.eof())//dosyan�n sonuna kadar oku
                    {
                        getline(fileread, okunan);
                        cout << okunan << "\n";//yeni proje listesini ekrna yaz.
                    }
                    fileread.close();//dosyayi kapat.
                }
            }
            cout << "--------------------------------------------------------------" << endl;
        }
        if (secim2 == 3)//eger secim 3- Kullanilan Urun  Arama ise
        {
            ifstream dosyaAra2("�r�nhakedisrapor.txt", ios::in);
            string araUrunNo2;//urun aramak i�in gerekli olan urun numaras� de�i�keni.
            cout << "Arama yapilacak urunNo :"; cin >> araUrunNo2;///kullan�c�ya urun numaras�n� girdir.
            int gcrldgl = 0;
            while (!(dosyaAra2.eof()))
            {
                for (int i = 0;i < 30;i++)
                {
                    dosyaAra2 >> hTarih >> hNo >> hAdi >> urunNo[i] >> hAdet>> birimFiyat[i]>> hUrnFiyat;//dosyay� sonuna kadar okut.
                    if (urunNo[i] == araUrunNo2)//eger urun NUmarasi e�itse aranack urun numaras�na
                    {
                        cout << "-----------------Arama Yapilan Urun Bilgileri-----------------" << endl
                             << "Hakedis Tarihi :" << hTarih << " "
                             << "Hakedis No :" << hNo << " "
                             << "Yapilan Isin Adi :" << hAdi << " "
                             << "Urun No :" << araUrunNo2 << " " // aranan urun bilgilerini yaz.
                             << "Urun Adeti :" << hAdet << " "
                             << "Birim Fiyati :" << birimFiyat[i] << " "
                             << "Urun Fiyat :" << hUrnFiyat << "\n";
                        gcrldgl = 1;//gcrldgl degi�kenini 1 yap
                    }
                }
            }
            if (gcrldgl == 0)//gcrldgl degiskeni esitse 0 a
            {
                cout << "Boyle Bir Urun Bulunmamaktadir..." << endl;//b�yle bir urun yok
            }
            dosyaAra2.close();//dosyay� kapat.
            cout << "--------------------------------------------------------------" << endl;
        }
        if (secim2 == 4)///eger secim 4- Kullanilan Urun  Guncellemeyse
        {
            string gUrunNo;//urun guncellemek i�in gerekli olan urun numaras� de�i�keni.
            cout << "Guncellenecek Urun No :"; cin >> gUrunNo;///kullan�c�ya urun numaras�n� girdir.
            ifstream DosyaOku("�r�nhakedisrapor.txt");
            int gcc = 0;
            string guncelUrunNo;
            while (!(DosyaOku.eof()))
            {
                DosyaOku >> hTarih >> hNo >> hAdi >> urunNo[i] >> hAdet >> birimFiyat[i] >> hUrnFiyat;//dosyay� sonuna kadar okut.
                if (urunNo[i] == gUrunNo)//eger urun NUmarasi e�itse guncellenecek urun numaras�na
                {
                    cout << "-----------------Guncellenecek Urun Bilgileri-----------------" << endl
                        << "Hakedis Tarihi :" << hTarih << " "
                        << "Hakedis No :" << hNo << " "
                        << "Yapilan Isin Adi :" << hAdi << " "
                        << "Urun No :" << gUrunNo << " " // g�ncellenecek urun bilgilerini yaz.
                        << "Urun Adeti :" << hAdet << " "
                        << "Birim Fiyati :" << birimFiyat[i] << " "
                        << "Urun Fiyat :" << hUrnFiyat << "\n";
                }
            }
            DosyaOku.close();
            ofstream GeciciDosyaYaz4("projehakedisrapor.txt");
            ifstream DosyaOku2("�r�nhakedisrapor.txt");
            ifstream dosya1("�r�nbilgileri.txt", ios::in);
            while (DosyaOku2 >> hTarih >> hNo >> hAdi >> urunNo[i] >> hAdet >> birimFiyat[i] >> hUrnFiyat)
            {
                if (gUrunNo != urunNo[i])//g�ncellenen urun numaras� dosyadaki urun numaras�yla e�le�miyorsa
                    GeciciDosyaYaz4 << hTarih << " " << hNo << " " << hAdi << " " << urunNo[i] << " " << hAdet << " " << birimFiyat[i] << " " << hUrnFiyat << "\n";//dosyaya urun bilgilerinin eslesmedi�i i�in g�ncellemeden ayn� �ekilde yaz

                if (gUrunNo == urunNo[i])//eger g�ncellenecek urun numaras� e�itse urunNumaras�na
                {
                    cout << " Yeni Urun Bilgilerini Giriniz \n";
                    cout << " hTarih :"; cin >> hTarih;
                    cout << " hNo :"; cin >> hNo;
                    cout << " hAdi :"; cin >> hAdi;
                    cout << " urunNo :"; cin >> guncelUrunNo; //ekrana hakedis raporunu yaz.
                    cout << " hAdet :"; cin >> hAdet;

                    while (!(dosya1.eof()))
                    {
                        for (int i = 0;i < 30;i++)
                        {
                            dosya1 >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka;
                            if (urunNo[i] == guncelUrunNo)//eger urun NUmarasi e�itse aranack urun numaras�na
                            {
                                hUrnFiyat = Carp(hAdet, birimFiyat[i]);//urunun fiyat� i�in adet bilgisiyle birimfiyat bilgisini carp ve urun fiyata esitle
                                GeciciDosyaYaz4 << hTarih << " " << hNo << " " << hAdi << " " << urunNo[i] << " " << hAdet << " " << birimFiyat[i] << " " << hUrnFiyat << "\n";
                                gcc = 1;//gcc degiskeninin 1 yap
                            }
                        }                        
                    }
                }
            }
            dosya1.close();
            GeciciDosyaYaz4.close();//dosyalar� kapat
            DosyaOku2.close();
            if (gcc == 0)//gcc esitse  0 a
                cout << "Boyle Bir Urun Bulunmamaktadir." << endl;//b�yle bir urun yok.
            if (gcc == 1)//gcc esitse  1 e
            {
                cout << "Urun Guncellendi." << endl;//urun g�ncellendi
                cout << "----------------------Yeni Proje Listesi-----------------------" << endl;
                ifstream fileread;
                fileread.open("projehakedisrapor.txt", ios::in);//projehakedisrapor.txt dosyas�n� a�
                string okunan;
                while (!fileread.eof())//dosyan�n sonuna kadar oku
                {
                    getline(fileread, okunan);
                    cout << okunan << "\n";//okunan karakterleri ekrana yaz.
                }
                fileread.close();//dosyay� kapa.
            }
        }
        cout << "--------------------------------------------------------------" << endl;
    }
    return 0;
}