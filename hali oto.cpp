#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Hali {
    string marka;
    float fiyat;
    
};

void HaliEkle(const Hali& yeniHali) {
    ofstream dosyaYaz("hali_otomasyonu.txt", ios::app);
    dosyaYaz << yeniHali.marka << " " << yeniHali.fiyat << endl;
    cout << "Halý baþarýyla eklendi!" << endl;
    dosyaYaz.close();
}

void HaliListele() {
    ifstream dosyaOku("hali_otomasyonu.txt");
    string marka;
    float fiyat;
    	int i =0;
	cout << "--------listenen halýlar--------"  << endl<<endl;
    while (dosyaOku >> marka >> fiyat) {
    
    	cout <<i+1<< ".halý"  << endl;

        cout << "Marka: " << marka << ", Fiyat: " << fiyat << endl;
        i++;
    }

    dosyaOku.close();
}

void HaliSil(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    ofstream tempYaz("temp.txt");

    string tempMarka;
    float tempFiyat;

    bool bulundu = false;
    while (dosyaOku >> tempMarka >> tempFiyat) {
        if (tempMarka != marka) {
            tempYaz << tempMarka << " " << tempFiyat << endl;
        } else {
            bulundu = true;
        }
    }

    dosyaOku.close();
    tempYaz.close();

    if (bulundu) {
        remove("hali_otomasyonu.txt");
        rename("temp.txt", "hali_otomasyonu.txt");
        cout << "Halý baþarýyla silindi!" << endl;
    } else {
        remove("temp.txt");
        cout << "Halý bulunamadý!" << endl;
    }
}
void HaliSat(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    ofstream tempYaz("temp.txt");

    string tempMarka;
    float tempFiyat;
    float toplamFiyat = 0.0;

    bool bulundu = false;
    while (dosyaOku >> tempMarka >> tempFiyat) {
        if (tempMarka != marka) {
            tempYaz << tempMarka << " " << tempFiyat << endl;
        } else {
            bulundu = true;
            toplamFiyat += tempFiyat;
        }
    }

    dosyaOku.close();
    tempYaz.close();

    if (bulundu) {
        remove("hali_otomasyonu.txt");
        rename("temp.txt", "hali_otomasyonu.txt");
        cout << "Halý baþarýyla satýldý!" << endl;
        cout << "Toplam fiyat: " << toplamFiyat << endl;
    } else {
        remove("temp.txt");
        cout << "Halý bulunamadý!" << endl;
    }
}

void HaliDuzelt(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    ofstream tempYaz("temp.txt");

    string tempMarka;
    float tempFiyat;

    bool bulundu = false;
    while (dosyaOku >> tempMarka >> tempFiyat) {
        if (tempMarka == marka) {
            cout << "Yeni fiyat: ";
            cin >> tempFiyat;
            tempYaz << tempMarka << " " << tempFiyat << endl;
            bulundu = true;
        } else {
            tempYaz << tempMarka << " " << tempFiyat << endl;
        }
    }

    dosyaOku.close();
    tempYaz.close();

    if (bulundu) {
        remove("hali_otomasyonu.txt");
        rename("temp.txt", "hali_otomasyonu.txt");
        cout << "Halý baþarýyla düzeltildi!" << endl;
    } else {
        remove("temp.txt");
        cout << "Halý bulunamadý!" << endl;
    }
}

void HaliAra(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    string tempMarka;
    float tempFiyat;
    bool bulundu = false;

    while (dosyaOku >> tempMarka >> tempFiyat) {
        if (tempMarka == marka) {
            cout << "Marka: " << tempMarka << ", Fiyat: " << tempFiyat << endl;
            bulundu = true;
        }
    }

    dosyaOku.close();

    if (!bulundu) {
        cout << "Halý bulunamadý!" << endl;
    }
}
void FisleriGoster(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    string tempMarka;
    float tempFiyat;
    float toplamFiyat = 0.0;
    int fisNumarasi = 1;
cout << "--------Kalan halýlarýn fiþleri-------- "<< endl;
    while (dosyaOku >> tempMarka >> tempFiyat) {
    	
        cout << "Fiþ Numarasý: " << fisNumarasi << endl;
        cout << "Marka: " <<tempMarka << ", Fiyat: " << tempFiyat<< endl;
        toplamFiyat += tempFiyat;
        fisNumarasi++;
    }
    cout << "\nKalan halýlarýn Toplam fiyatlarý: " << toplamFiyat <<endl<< endl;

    dosyaOku.close();
}


int main() {
	 system("CLS");
    system("color 0A");
	setlocale(LC_ALL,"turkish");
    int secim = 0;
    string marka;
    float fiyat;
    int silinecekIndeks;

    while (true) {
        system("cls");
        cout << "----------- Halý Otomasyonu -----------" << endl;
        cout << "|   1. Halý Ekle                      |" << endl;
        cout << "|   2. Halý Listele                   |" << endl;
        cout << "|   3. Halý Sil                       |" << endl;
        cout << "|   4. Halý Sat                       |" << endl;
        cout << "|   5. Halý Düzelt                    |" << endl;
        cout << "|   6. Halý Ara                       |" << endl;
        cout << "|   7. Satýlan Halýlarýn Fiþini Göster|" << endl;
        cout << "|   8. Çýkýþ                          |" << endl;
        cout << "---------------------------------------" <<endl;
        cout << "Seçiminizi yapýn: ";
        cin >> secim;

        switch (secim) {
            case 1:
                system("cls");
                cout << "Marka: ";
                cin >> marka;
                cout << "Fiyat: ";
                cin >> fiyat;
                HaliEkle({marka, fiyat});
                break;
            case 2:
                system("cls");
                HaliListele();
                break;
            case 3:
                system("cls");
                HaliListele();
                cout << "Silinecek halýnýn markasýný girin: ";
                cin >> marka;
                HaliSil(marka);
                break;
            case 4:
                system("cls");
                cout << "Satýlacak halýnýn markasýný girin: ";
                cin >> marka;
                HaliSat(marka);
                break;
            case 5:
                system("cls");
                cout << "Düzeltilecek halýnýn markasýný girin: ";
                cin >> marka;
                HaliDuzelt(marka);
                break;
            case 6:
                system("cls");
                cout << "Aranacak halýnýn markasýný girin: ";
                cin >> marka;
                HaliAra(marka);
                break;
            case 7:
                system("cls");
                FisleriGoster(marka);
                break;
            case 8:
                return 0;
            default:
                cout << "Geçersiz seçim!" << endl;
        }

        cout << "Devam etmek için bir tuþa basýn...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
