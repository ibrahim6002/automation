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
    cout << "Halı başarıyla eklendi!\n" << endl;
    dosyaYaz.close();
}

void HaliListele() {
    ifstream dosyaOku("hali_otomasyonu.txt");
    string marka;
    float fiyat;
    	int i =0;
	cout << "--------listenen halılar--------"  << endl<<endl;
    while (dosyaOku >> marka >> fiyat) {
    
    	cout <<i+1<< ".halı"  << endl;

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
        cout << "Halı başarıyla silindi!\n" << endl;
    } else {
        remove("temp.txt");
        cout << "Halı bulunamadı!" << endl;
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
        cout << "Halı başarıyla satıldı!" << endl;
        cout << "Toplam fiyat: " << toplamFiyat << endl;
    } else {
        remove("temp.txt");
        cout << "Halı bulunamadı!" << endl;
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
        cout << "Halı başarıyla düzeltildi!\n" << endl;
    } else {
        remove("temp.txt");
        cout << "Halı bulunamadı!" << endl;
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
        cout << "Halı bulunamadı!" << endl;
    }
}
void FisleriGoster(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    string tempMarka;
    float tempFiyat;
    float toplamFiyat = 0.0;
    int fisNumarasi = 1;
cout << "--------Kalan halıların fişleri-------- "<< endl;
    while (dosyaOku >> tempMarka >> tempFiyat) {
    	
        cout << "Fiş Numarası: " << fisNumarasi << endl;
        cout << "Marka: " <<tempMarka << ", Fiyat: " << tempFiyat<< endl;
        toplamFiyat += tempFiyat;
        fisNumarasi++;
    }
    cout << "\nKalan halıların Toplam fiyatları: " << toplamFiyat <<endl<< endl;

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
        cout << "----------- Halı Otomasyonu -----------" << endl;
        cout << "|   1. Halı Ekle                      |" << endl;
        cout << "|   2. Halı Listele                   |" << endl;
        cout << "|   3. Halı Sil                       |" << endl;
        cout << "|   4. Halı Sat                       |" << endl;
        cout << "|   5. Halı Düzelt                    |" << endl;
        cout << "|   6. Halı Ara                       |" << endl;
        cout << "|   7. Satılan Halıların Fişini Göster|" << endl;
        cout << "|   8. Çıkış                          |" << endl;
        cout << "---------------------------------------" <<endl;
        cout << "Seçiminizi yapın: ";
        cin >> secim;

        switch (secim) {
            case 1:
                system("cls");
                cout << "Marka giriniz: ";
                cin >> marka;
                cout << "Fiyat giriniz: ";
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
                cout << "Silinecek halının markasını girin: ";
                cin >> marka;
                HaliSil(marka);
                break;
            case 4:
                system("cls");
                HaliListele();
                cout << "Satılacak halının markasını girin: ";
                cin >> marka;
                HaliSat(marka);
                break;
            case 5:
                system("cls");
                 HaliListele();
                cout << "Düzeltilecek halının markasını girin: ";
                cin >> marka;
                HaliDuzelt(marka);
                break;
            case 6:
                system("cls");
                cout << "Aranacak halının markasını girin: ";
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

        cout << "Devam etmek için bir tuşa basın...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
