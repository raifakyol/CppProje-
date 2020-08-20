//*****************************************************************************//
//*
//*					     SAKARYA ÜNÝVERSÝTESÝ
//*				BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
//*				     BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
//*				       PROGRAMLAMAYA GÝRÝÞ DERSÝ
//*					       2020 YAZ DÖNEMÝ
//*	
//*				ÖDEV NUMARASI..........: PROJE
//*				ÖÐRENCÝ ADI............: RAÝF AKYOL
//*				ÖÐRENCÝ NUMARASI.......: G191210017
//*             
//*****************************************************************************//

#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>   //gerekli kütüphaneler.
#include <string>
#include <sstream>
#include<locale.h>
#include<conio.h>
#include <cstdio>

using namespace std;
void DosyadanOku()
{
    ifstream fileread;
    fileread.open("ürünbilgileri.txt", ios::in);//ürünbilgileri.txt dosyasýný aç
    string okunan;
    while (!fileread.eof())//dosyanýn sonuna kadar oku
    {
        getline(fileread, okunan);
        cout << okunan << "\n";//okunan karakterleri ekrana yaz.
    }
    fileread.close();//dosyayý kapa.
}
void DosyadanOku2()
{
    ifstream fileread;
    fileread.open("proje.txt", ios::in);//proje.txt dosyasýný aç
    string okunan;
    while (!fileread.eof())//dosyanýn sonuna kadar oku
    {
        getline(fileread, okunan);
        cout << okunan << "\n";//okunan karakterleri ekrana yaz.
    }
    fileread.close();//dosyayý kapa.
}
void DosyadanOku3()
{
    ifstream fileread;
    fileread.open("projehakedisrapor.txt", ios::in);//projehakedisrapor.txt dosyasýný aç
    string satir = "";
    while (!fileread.eof())//dosyanýn sonuna kadar oku
    {
        getline(fileread, satir);
        cout << satir << "\n";//okunan karakterleri ekrana yaz.
    }
    fileread.close();//dosyayý kapa.
}
double Carp(double s1, double s2)//Urun adeti ve birim fiyatýný çarpýp urunun fiyatýný hesaplamak için gerekli
{
    return s1 * s2;
}
double Topla(double s1, double s2)//Urun fiyatlarý Toplama için gerekli
{
    return s1 + s2;
}
int main()
{
    int secim,i=0;
    string urunAd;
    string birim;
    double birimFiyat[30];  //urunlerin degiskenleri tanýmlanýr.
    string marka;
    string urunNo[30];

    string projeNo[30];
    string projeAdi;
    string projeYrtcFirma;//projenin degiskenleri tanýmlanýr.
    string projeSorumlusu;
    string projeKontrolörü;

    string hTarih, hNo, hAdi;
    double hAdet, hUrnFiyat; //raporlarýn deðiþkenleri tanýmlanýr.
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
    
    ofstream dosyaYaz("ürünbilgileri.txt", ios::app);
    ofstream dosyaYazz("proje.txt", ios::app);
    if (secim == 1)//eger secim 1- Urun  Ekleme ise
    { 
        cout << "-------------------------Urun Listesi-------------------------" << endl;
        DosyadanOku(); //öncelikle ürün listesini ekrana yaz.
        cout << "--------------------------------------------------------------" << endl;
        do
        {
            cout <<endl<< "urunNo urunAd birim birimFiyat marka"<<endl; //ürün eklemek için gerekli olan bilgileri sýrasýyla ekrana yaz.
            cin >> urunNo[i], cin >> urunAd, cin >> birim, cin >> birimFiyat[i], cin >> marka;//gerekli bilgileri kullanýcýdan yazdýr.
            dosyaYaz <<"\n "<< urunNo[i] << " " << urunAd << " " << birim << " " << birimFiyat[i] << " " << marka << endl;//dosyaya kullanýcýnýn yazdýklarýný sýrasýyla yaz.
            cout << "\n baska ekleme yapacak misin ? (e/h)";cin >> cevap;//baska ekleme yapacaksa devam etmek icin e (evet) seçilsin devam etmeyecekse h (hayýr) seçilsin.
        } while (!(cevap == 'h'));//(cevap h degil ise devam et)
        dosyaYaz.close();
        cout << "----------------------Yeni Urun Listesi-----------------------"<<endl;
        DosyadanOku();//yenilenen ürün bilgilerini yazdýr.
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 2)//eger secim 2 - Urun  Silme ise
    { 
        cout << "-------------------------Urun Listesi-------------------------" << endl;
        DosyadanOku(); //öncelikle ürün listesini ekrana yaz.  
        cout << "--------------------------------------------------------------" << endl;
        int gcc2 = 0;
        char cvp;
        string silUrunNo;//ürün silmek için gerekli olan ürün numarasý deðiþkeni.
        ifstream dosyaSil("ürünbilgileri.txt", ios::in);
        cout << "Silinecek urun nosunu giriniz :"; cin >> silUrunNo;//kullanýcýya ürün numarasýný girdir.

        while (!(dosyaSil.eof())) 
        {
            for (int i = 0;i < 30;i++)
            {
                dosyaSil >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka;//dosyayý sonuna kadar okut.
                if (urunNo[i] == silUrunNo)//eger urunNumarasý eþitse silinecek ürün numarasýna
                {
                    cout << "------------------------Urun Bilgileri------------------------" << endl;
                    cout << "urunNo :" << silUrunNo << " ";
                    cout << "urunAd :" << urunAd << " ";
                    cout << "birim :" << birim << " ";  //urun un bilgilerini yazdýr.
                    cout << "birimFiyat :" << birimFiyat[i] << " ";
                    cout << "marka :" << marka << "\n";
                }   
            }   
            cout << "Urun silmek istiyor musunuz ? (e/h)";//ürünü silip silmeyeceðini sor.
            cin >> cvp;
        }
        if (cvp == 'e')//urunu silmek istiyorsa
        {
            ifstream DosyaOku("ürünbilgileri.txt", ios::beg);
            ofstream geciciDosyaYaz("yeniürünbilgileri.txt");
            while (DosyaOku >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka)
            {
                if (silUrunNo != urunNo[i])//silinen urun numarasý dosyadaki ürün numarasýyla eþleþmiyorsa
                {
                    geciciDosyaYaz << urunNo[i] << " " << urunAd << " " << birim << " " << birimFiyat[i] << " " << marka << "\n";//dosyaya ürünlerin bilgilerini eslesmediði için silinmeden ayný þekilde yaz
                }
                if (silUrunNo == urunNo[i])//eger silinecek ürün numarasý eþitse urunNumarasýna
                    gcc2 = 1;//gcc2 degiþkenini 1 yap
            }
            dosyaSil.close();
            geciciDosyaYaz.close();//dosyalarý kapattýk
            DosyaOku.close();
            if (gcc2 == 0)//gcc2 degiskeni esitse 0 a
                cout << "Boyle bir urun yoktur." << endl;//böyle bir ürün yok
            if (gcc2 == 1)//gcc2 degiskeni esitse 1 e
            {
                cout << "Urun Silindi." << endl;//urun silindi
                cout << "----------------------Yeni Urun Listesi-----------------------" << endl;
                ifstream fileread;
                fileread.open("yeniürünbilgileri.txt", ios::in);
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
        DosyadanOku();//öncelikle ürün listesini ekrana yaz.  
        cout << "--------------------------------------------------------------" << endl;
       
        ifstream dosyaAra("ürünbilgileri.txt",ios::in);
        string araUrunNo;//ürün aramak için gerekli olan ürün numarasý deðiþkeni.
        cout << "Arama yapilacak urunNo :"; cin >> araUrunNo;//kullanýcýya ürün numarasýný girdir.
        int gcrldgl = 0;
        while (!(dosyaAra.eof())) 
        {
            for (int i = 0;i < 30;i++)
            {
                dosyaAra >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka;//dosyayý sonuna kadar okut.
                if (urunNo[i] == araUrunNo)//eger urunNumarasý eþitse silinecek ürün numarasýna
                {
                    cout << "-----------------Arama Yapilan Urun Bilgileri-----------------" << endl;
                    cout << "urunNo :" << araUrunNo << " ";
                    cout << "urunAd :" << urunAd << " ";
                    cout << "birim : " << birim << " ";//aranan urun un bilgilerini yazdýr.
                    cout << "birimFiyat :" << birimFiyat[i] << " ";
                    cout << "marka :" << marka << "\n";
                    gcrldgl = 1;//gcrldgl degiþkenini 1 yap
                } 
            }  
            
        }
        if (gcrldgl == 0)//gcrldgl degiskeni esitse 0 a
        {
            cout << "Boyle Bir Urun Bulunmamaktadir..." << endl;//böyle bir urun yok
        }
        dosyaAra.close();//dosyayý kapat.
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 4)//eger secim 4- Urun  Raporlama  ise
    {
        cout << "-------------------------Urun Listesi-------------------------" << endl;
        DosyadanOku();//öncelikle ürün listesini ekrana yaz.  
        char cvp;
        ifstream dosya1("ürünbilgileri.txt", ios::in);
        cout << "------------------------Hakedis Raporu------------------------" << endl;
        cout << "Hakedis Tarihi :", cin >> hTarih;
        cout << "Hakedis No :", cin >> hNo; //hakedis raporu bilgilerini kullanýcýdan iste
        cout << "Yapilan Isin Adi :", cin >> hAdi;
        while (!(dosya1.eof()))
        {
            cout << "Eklenecek urunNo :"; cin >> eklUrunNo;
            cout << "Urun Adeti :", cin >> hAdet;
            for (int i = 0;i < 30;i++)
            {
                dosya1 >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka;//dosyayý sonuna kadar okut.
                if (urunNo[i] == eklUrunNo)
                {
                    hUrnFiyat= Carp(hAdet, birimFiyat[i]);//urunun fiyatý için adet bilgisiyle birimfiyat bilgisini carp ve urun fiyata esitle
                    ofstream dosyaYazz("ürünhakedisrapor.txt", ios::app);
                    dosyaYazz << hTarih << " "
                        << hNo << " "
                        << hAdi << " "
                        << eklUrunNo << " " //dosyaya hakedis raporunu yaz.
                        << hAdet << " " 
                        << birimFiyat[i] << " "
                        << hUrnFiyat<<"\n";
                }
            }
            cout << "Urunu eklemek istiyor musunuz ? (e/h)";//ürün ekleyip eklemeyeceðini sor.
            cin >> cvp;
        }
        do //urunu eklemek istiyorsa
        {
            cout << "Eklenecek urunNo :"; cin >> eklUrunNo;
            cout << "Urun Adeti :", cin >> hAdet;//hakedis raporu bilgilerini kullanýcýdan iste
            for (int i = 0;i < 30;i++)
            {
                dosya1 >> urunNo[i] >> urunAd >> birim >> birimFiyat[i] >> marka;//dosyayý sonuna kadar okut.
                if (urunNo[i] == eklUrunNo)
                {
                    ofstream dosyaYazz("ürünhakedisrapor.txt", ios::app);
                    dosyaYazz << hTarih << " "
                        << hNo << " "
                        << hAdi << " "
                        << eklUrunNo << " " //dosyaya hakedis raporunu yaz.
                        << hAdet << " "
                        << birimFiyat[i] << " "
                        << hUrnFiyat << "\n ";
                }   
            }
            cout << "baska ekleme yapacak misin ? (e/h)";cin >> cvp;//baska ekleme yapacaksa devam etmek icin e (evet) seçilsin devam etmeyecekse h (hayýr) seçilsin.
        } while (!(cvp == 'h'));
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 5)//eger secim  5- Proje Ekleme ise
    {
        cout << "-------------------------Proje Listesi------------------------" << endl;
        DosyadanOku2();//öncelikle proje listesini ekrana yaz.  
        cout << "--------------------------------------------------------------" << endl;
        do
        {
            cout <<endl<< "projeNo projeAdi projeYurutucuFirma projeSorumlusu projeKontroloru" << endl;//proje eklemek için gerekli olan bilgileri sýrasýyla ekrana yaz.
            cin >> projeNo[i], cin >> projeAdi, cin >> projeYrtcFirma, cin >> projeSorumlusu, cin >> projeKontrolörü;//gerekli bilgileri kullanýcýdan yazdýr.
            dosyaYazz << projeNo[i] << " " << projeAdi << " " << projeYrtcFirma << " " << projeSorumlusu << " " << projeKontrolörü << endl;//dosyaya kullanýcýnýn yazdýklarýný sýrasýyla yaz.
            cout << "\n baska ekleme yapacak misin ? (e/h)";cin >> cevap;//baska ekleme yapacaksa devam etmek icin e (evet) seçilsin devam etmeyecekse h (hayýr) seçilsin.
        } while (!(cevap == 'h'));//(cevap h degil ise devam et)
        dosyaYazz.close();
        cout << "----------------------Yeni Proje Listesi----------------------" << endl;
        DosyadanOku2();//yenilenen proje bilgilerini yazdýr.
        cout << "--------------------------------------------------------------" << endl;
    }
    if (secim == 6)//eger secim  6- Proje Silme ise
    {
        cout << "-------------------------Proje Listesi------------------------" << endl;
        DosyadanOku2();//öncelikle proje listesini ekrana yaz. 
        cout << "--------------------------------------------------------------" << endl;
        int gcc3 = 0;
        char cvp2;
        ifstream dosyaSil2("proje.txt", ios::in);
        string silProjeAdi;//proje silmek için gerekli olan proje numarasý deðiþkeni.
        cout << "Silinecek proje nosunu giriniz :"; cin >> silProjeAdi;//kullanýcýya proje numarasýný girdir.

        while (!(dosyaSil2.eof()))
        {
            for (int i = 0;i < 15;i++)
            {
                dosyaSil2 >> projeNo[i] >> projeAdi >> projeYrtcFirma >> projeSorumlusu >> projeKontrolörü;//dosyayý sonuna kadar okut.
                if (projeNo[i] == silProjeAdi)//eger projeNumarasý eþitse silinecek proje numarasýna
                {
                    cout << "------------------------Proje Bilgileri------------------------" << endl;
                    cout << "projeNo :" << silProjeAdi << " ";
                    cout << "projeAdi :" << projeAdi << " ";
                    cout << "projeYrtcFirma :" << projeYrtcFirma << " ";//proje bilgilerini yaz.
                    cout << "projeSorumlusu :" << projeSorumlusu << " ";
                    cout << "projeKontroloru :" << projeKontrolörü << "\n";
                }
            }
            cout << "Proje silmek istiyor musunuz ? (e/h)";//projenin silip silmeyeceðini sor.
            cin >> cvp2;
        }
        if (cvp2 == 'e')//projeyi silmek istiyorsa
        {
            ifstream DosyaOku2("proje.txt", ios::beg);
            ofstream geciciDosyaYaz2("yeniproje.txt");
            while (DosyaOku2 >> projeNo[i] >> projeAdi >> projeYrtcFirma >> projeSorumlusu >> projeKontrolörü)
            {
                if (silProjeAdi != projeNo[i])//silinen proje numarasý dosyadaki proje numarasýyla eþleþmiyorsa
                {
                    geciciDosyaYaz2 << projeNo[i] << " " << projeAdi << " " << projeYrtcFirma << " " << projeSorumlusu << " " << projeKontrolörü << "\n";//dosyaya projelerin bilgilerini eslesmediði için silinmeden ayný þekilde yaz
                }
                if (silProjeAdi == projeNo[i])//eger silinecek proje numarasý eþitse projeNumarasina
                    gcc3 = 1;//gcc3 degiskeninin 1 yap
            }
            dosyaSil2.close();
            geciciDosyaYaz2.close();//dosyalarý kapat.
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
        DosyadanOku2();//öncelikle proje listesini ekrana yaz. 
        cout << "--------------------------------------------------------------" << endl;
        ifstream dosyaAra("proje.txt");
        string araProjeNo;//proje aramak için gerekli olan proje numarasý deðiþkeni.
        cout << "arama yapilacak projeNo:"; cin >> araProjeNo;//kullanýcýya proje numarasýný girdir.
        int gcrldgl = 0;
        while (!(dosyaAra.eof())) 
        {
            for (int i = 0;i < 30;i++)
            {
                dosyaAra >> projeNo[i] >> projeAdi >> projeYrtcFirma >> projeSorumlusu >> projeKontrolörü;//dosyayý sonuna kadar okut.
                if (projeNo[i]== araProjeNo)//eger projeNumarasý eþitse aranack proje numarasýna
                {
                    cout << "-----------------Arama Yapilan Proje Bilgileri-----------------" << endl;
                    cout << "projeNo :" << araProjeNo << " ";
                    cout << "projeAdi :" << projeAdi << " ";
                    cout << "projeYrtcFirma : " << projeYrtcFirma << " ";//arannan proje bilgilerini yaz.
                    cout << "projeSorumlusu :" << projeSorumlusu << " ";
                    cout << "projeKontroloru :" << projeKontrolörü << "\n";
                    gcrldgl = 1;//gcrldgl degiþkenini 1 yap
                }
            }
        }
        if (gcrldgl == 0)//gcrldgl degiskeni esitse 0 a
        {
            cout << "Boyle Bir Proje Bulunmamaktadir..." << endl;//böye bir proje yok
        }
        dosyaAra.close();//dosyayý kapat.
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
            fileread.open("ürünhakedisrapor.txt", ios::in);//ürünhakedisrapor.txt dosyasýný aç
            string okunan;
            while (!fileread.eof())//dosyanýn sonuna kadar oku
            {
                getline(fileread, okunan);
                cout << okunan << "\n";//okunan karakterleri ekrana yaz.
            }
            fileread.close();//dosyayý kapa.
        }
        if (secim2 == 2)///eger secim 2- Kullanilan Urun  Silme  ise
        {
            int gcc4 = 0;
            char cvp2;
            string silUrunNo2;//urun silmek için gerekli olan proje numarasý deðiþkeni.
            ifstream dosyaSil2("ürünhakedisrapor.txt", ios::in);
            cout << "Silinecek urun nosunu giriniz :"; cin >> silUrunNo2;//kullanýcýya urun numarasýný girdir.

            while (!(dosyaSil2.eof()))
            {
                for (int i = 0;i < 30;i++)
                {
                    dosyaSil2 >> hTarih >> hNo >> hAdi >> urunNo[i] >> hAdet >> birimFiyat[i] >> hUrnFiyat;//hakedis raporunu okuma
                    if (urunNo[i] == silUrunNo2)//eger urunNumarasý eþitse silinecek urun numarasýna
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
                cout << "Urun silmek istiyor musunuz ? (e/h)";//urunu silip silmeyeceðini sor.
                cin >> cvp2;
            }
            if (cvp2 == 'e')//projeyi silmek istiyorsa
            {
                ifstream DosyaOku("ürünhakedisrapor.txt", ios::beg);
                ofstream geciciDosyaYaz2("yeniürünhakedisrapor.txt");
                while (DosyaOku >> hTarih >> hNo >> hAdi >> urunNo[i] >> hAdet >> birimFiyat[i] >> hUrnFiyat)
                {
                    if (silUrunNo2 != urunNo[i])//silinen urun numarasý dosyadaki urun numarasýyla eþleþmiyorsa
                    {
                        geciciDosyaYaz2 << hTarih << " " << hNo << " " << hAdi << " " << urunNo[i] << " " << hAdet << " " << birimFiyat[i] << " " << hUrnFiyat<<"\n";//dosyaya urun bilgilerinin eslesmediði için silinmeden ayný þekilde yaz
                    }
                    if (silUrunNo2 == urunNo[i])//eger silinecek urun numarasý eþitse urunNumARarýsna 
                        gcc4 = 1;  //gcc4 degiskeninin 1 yap
                }
                dosyaSil2.close();
                geciciDosyaYaz2.close();//dosyalarý kapt.
                DosyaOku.close();
                if (gcc4 == 0)//gcc4 esitse  0 a
                    cout << "Boyle bir urun yoktur." << endl;//böyle bir urun yok.
                if (gcc4 == 1)//gcc4 esitse  1 e
                {
                    cout << "Urun Silindi." << endl;//urun silindi
                    cout << "----------------------Yeni Hakedis Raporu-----------------------" << endl;
                    ifstream fileread;
                    fileread.open("yeniürünhakedisrapor.txt", ios::in);
                    string okunan;
                    while (!fileread.eof())//dosyanýn sonuna kadar oku
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
            ifstream dosyaAra2("ürünhakedisrapor.txt", ios::in);
            string araUrunNo2;//urun aramak için gerekli olan urun numarasý deðiþkeni.
            cout << "Arama yapilacak urunNo :"; cin >> araUrunNo2;///kullanýcýya urun numarasýný girdir.
            int gcrldgl = 0;
            while (!(dosyaAra2.eof()))
            {
                for (int i = 0;i < 30;i++)
                {
                    dosyaAra2 >> hTarih >> hNo >> hAdi >> urunNo[i] >> hAdet>> birimFiyat[i]>> hUrnFiyat;//dosyayý sonuna kadar okut.
                    if (urunNo[i] == araUrunNo2)//eger urun NUmarasi eþitse aranack urun numarasýna
                    {
                        cout << "-----------------Arama Yapilan Urun Bilgileri-----------------" << endl
                             << "Hakedis Tarihi :" << hTarih << " "
                             << "Hakedis No :" << hNo << " "
                             << "Yapilan Isin Adi :" << hAdi << " "
                             << "Urun No :" << araUrunNo2 << " " // aranan urun bilgilerini yaz.
                             << "Urun Adeti :" << hAdet << " "
                             << "Birim Fiyati :" << birimFiyat[i] << " "
                             << "Urun Fiyat :" << hUrnFiyat << "\n";
                        gcrldgl = 1;//gcrldgl degiþkenini 1 yap
                    }
                }
            }
            if (gcrldgl == 0)//gcrldgl degiskeni esitse 0 a
            {
                cout << "Boyle Bir Urun Bulunmamaktadir..." << endl;//böyle bir urun yok
            }
            dosyaAra2.close();//dosyayý kapat.
            cout << "--------------------------------------------------------------" << endl;
        }
        if (secim2 == 4)///eger secim 4- Kullanilan Urun  Guncellemeyse
        {
            string gUrunNo;//urun guncellemek için gerekli olan urun numarasý deðiþkeni.
            cout << "Guncellenecek Urun No :"; cin >> gUrunNo;///kullanýcýya urun numarasýný girdir.
            ifstream DosyaOku("ürünhakedisrapor.txt");
            int gcc = 0;
            string guncelUrunNo;
            while (!(DosyaOku.eof()))
            {
                DosyaOku >> hTarih >> hNo >> hAdi >> urunNo[i] >> hAdet >> birimFiyat[i] >> hUrnFiyat;//dosyayý sonuna kadar okut.
                if (urunNo[i] == gUrunNo)//eger urun NUmarasi eþitse guncellenecek urun numarasýna
                {
                    cout << "-----------------Guncellenecek Urun Bilgileri-----------------" << endl
                        << "Hakedis Tarihi :" << hTarih << " "
                        << "Hakedis No :" << hNo << " "
                        << "Yapilan Isin Adi :" << hAdi << " "
                        << "Urun No :" << gUrunNo << " " // güncellenecek urun bilgilerini yaz.
                        << "Urun Adeti :" << hAdet << " "
                        << "Birim Fiyati :" << birimFiyat[i] << " "
                        << "Urun Fiyat :" << hUrnFiyat << "\n";
                }
            }
            DosyaOku.close();
            ofstream GeciciDosyaYaz4("projehakedisrapor.txt");
            ifstream DosyaOku2("ürünhakedisrapor.txt");
            ifstream dosya1("ürünbilgileri.txt", ios::in);
            while (DosyaOku2 >> hTarih >> hNo >> hAdi >> urunNo[i] >> hAdet >> birimFiyat[i] >> hUrnFiyat)
            {
                if (gUrunNo != urunNo[i])//güncellenen urun numarasý dosyadaki urun numarasýyla eþleþmiyorsa
                    GeciciDosyaYaz4 << hTarih << " " << hNo << " " << hAdi << " " << urunNo[i] << " " << hAdet << " " << birimFiyat[i] << " " << hUrnFiyat << "\n";//dosyaya urun bilgilerinin eslesmediði için güncellemeden ayný þekilde yaz

                if (gUrunNo == urunNo[i])//eger güncellenecek urun numarasý eþitse urunNumarasýna
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
                            if (urunNo[i] == guncelUrunNo)//eger urun NUmarasi eþitse aranack urun numarasýna
                            {
                                hUrnFiyat = Carp(hAdet, birimFiyat[i]);//urunun fiyatý için adet bilgisiyle birimfiyat bilgisini carp ve urun fiyata esitle
                                GeciciDosyaYaz4 << hTarih << " " << hNo << " " << hAdi << " " << urunNo[i] << " " << hAdet << " " << birimFiyat[i] << " " << hUrnFiyat << "\n";
                                gcc = 1;//gcc degiskeninin 1 yap
                            }
                        }                        
                    }
                }
            }
            dosya1.close();
            GeciciDosyaYaz4.close();//dosyalarý kapat
            DosyaOku2.close();
            if (gcc == 0)//gcc esitse  0 a
                cout << "Boyle Bir Urun Bulunmamaktadir." << endl;//böyle bir urun yok.
            if (gcc == 1)//gcc esitse  1 e
            {
                cout << "Urun Guncellendi." << endl;//urun güncellendi
                cout << "----------------------Yeni Proje Listesi-----------------------" << endl;
                ifstream fileread;
                fileread.open("projehakedisrapor.txt", ios::in);//projehakedisrapor.txt dosyasýný aç
                string okunan;
                while (!fileread.eof())//dosyanýn sonuna kadar oku
                {
                    getline(fileread, okunan);
                    cout << okunan << "\n";//okunan karakterleri ekrana yaz.
                }
                fileread.close();//dosyayý kapa.
            }
        }
        cout << "--------------------------------------------------------------" << endl;
    }
    return 0;
}