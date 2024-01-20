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
    cout << "Hal� ba�ar�yla eklendi!" << endl;
    dosyaYaz.close();
}

void HaliListele() {
    ifstream dosyaOku("hali_otomasyonu.txt");
    string marka;
    float fiyat;
    	int i =0;
	cout << "--------listenen hal�lar--------"  << endl<<endl;
    while (dosyaOku >> marka >> fiyat) {
    
    	cout <<i+1<< ".hal�"  << endl;

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
        cout << "Hal� ba�ar�yla silindi!" << endl;
    } else {
        remove("temp.txt");
        cout << "Hal� bulunamad�!" << endl;
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
        cout << "Hal� ba�ar�yla sat�ld�!" << endl;
        cout << "Toplam fiyat: " << toplamFiyat << endl;
    } else {
        remove("temp.txt");
        cout << "Hal� bulunamad�!" << endl;
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
        cout << "Hal� ba�ar�yla d�zeltildi!" << endl;
    } else {
        remove("temp.txt");
        cout << "Hal� bulunamad�!" << endl;
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
        cout << "Hal� bulunamad�!" << endl;
    }
}
void FisleriGoster(const string& marka) {
    ifstream dosyaOku("hali_otomasyonu.txt");
    string tempMarka;
    float tempFiyat;
    float toplamFiyat = 0.0;
    int fisNumarasi = 1;
cout << "--------Kalan hal�lar�n fi�leri-------- "<< endl;
    while (dosyaOku >> tempMarka >> tempFiyat) {
    	
        cout << "Fi� Numaras�: " << fisNumarasi << endl;
        cout << "Marka: " <<tempMarka << ", Fiyat: " << tempFiyat<< endl;
        toplamFiyat += tempFiyat;
        fisNumarasi++;
    }
    cout << "\nKalan hal�lar�n Toplam fiyatlar�: " << toplamFiyat <<endl<< endl;

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
        cout << "----------- Hal� Otomasyonu -----------" << endl;
        cout << "|   1. Hal� Ekle                      |" << endl;
        cout << "|   2. Hal� Listele                   |" << endl;
        cout << "|   3. Hal� Sil                       |" << endl;
        cout << "|   4. Hal� Sat                       |" << endl;
        cout << "|   5. Hal� D�zelt                    |" << endl;
        cout << "|   6. Hal� Ara                       |" << endl;
        cout << "|   7. Sat�lan Hal�lar�n Fi�ini G�ster|" << endl;
        cout << "|   8. ��k��                          |" << endl;
        cout << "---------------------------------------" <<endl;
        cout << "Se�iminizi yap�n: ";
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
                cout << "Silinecek hal�n�n markas�n� girin: ";
                cin >> marka;
                HaliSil(marka);
                break;
            case 4:
                system("cls");
                cout << "Sat�lacak hal�n�n markas�n� girin: ";
                cin >> marka;
                HaliSat(marka);
                break;
            case 5:
                system("cls");
                cout << "D�zeltilecek hal�n�n markas�n� girin: ";
                cin >> marka;
                HaliDuzelt(marka);
                break;
            case 6:
                system("cls");
                cout << "Aranacak hal�n�n markas�n� girin: ";
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
                cout << "Ge�ersiz se�im!" << endl;
        }

        cout << "Devam etmek i�in bir tu�a bas�n...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
