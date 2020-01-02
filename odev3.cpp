#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//GÜNCE DEMİREL ÖZER -2017280052
int main()
{
    ifstream dosya;
    ofstream puanlarDosya;
    string oku;
    int soruSayisi;
    bool ilkSatir = false;
    bool ikinciSatir = false;
    string cevapAnahtari;
    int puan=0;
    int i;
    int j;
    int ji;
    int minPuan = 100;
    int maxPuan = 0;
    float ortalama=0;
    int puanlar[5];
    
    puanlarDosya.open("output.txt");
    
   
    dosya.open("input.txt");
    while(getline(dosya,oku))
    {
        if(!ilkSatir){
            soruSayisi = stoi(oku);
            ilkSatir = true;
        }

        else if(ilkSatir == true && ikinciSatir == false){
            cevapAnahtari = oku;
            ikinciSatir = true;
        }

        else{
            for(ji=0;ji<11;ji++){
                puanlarDosya<<oku[ji];
            }
            puanlarDosya<<" ";
            for(i=0;i<soruSayisi;i++){
                if(oku[i+11]==cevapAnahtari[i]){
                    puan+=4;
                }
                else if(oku[i+11]== ' '){
                    puan+=0;
                }
                else{
                    puan-=1;
                }

                
                cout<<oku[i+11];
            }
            
            if(puan<0){
                puan=0;
            }
            puanlarDosya<<puan<<endl;
            puanlar[j] = puan;
            j++;
            cout<<" "<<puan<<endl;
            ortalama += puan;
            if(puan < minPuan){
                minPuan = puan;
            }
            if(puan > maxPuan){
                maxPuan = puan;
            }
            puan = 0;
            

        }
        

        
    }
    
    int temp;

    for(i=0;i<5-1;i++){
        for(j=0;j<5-1;j++){
            if(puanlar[j]>puanlar[j+1]){
                temp = puanlar[j];
                puanlar[j] = puanlar[j+1];
                puanlar[j+1] = temp;
            }
        }

    }

    for(i=0;i<5;i++){
        cout<<puanlar[i]<<endl;
    }

    ortalama = ortalama/5;
    cout<<"Min: "<<minPuan<<endl;
    cout<<"Max: "<<maxPuan<<endl;
    cout<<"Acikilik: "<<maxPuan-minPuan<<endl;
    cout<<"Medyan: "<<puanlar[2]<<endl;
    cout<<soruSayisi<<endl;
    cout<<cevapAnahtari<<endl;
    cout<<ortalama<<endl;
    puanlarDosya<<"Min: "<<minPuan<<endl;
    puanlarDosya<<"Max: "<<maxPuan<<endl;
    puanlarDosya<<"Ort: "<<ortalama<<endl;
    puanlarDosya<<"Acikilik: "<<maxPuan-minPuan<<endl;
    puanlarDosya<<"Medyan: "<<puanlar[2]<<endl;

    
    puanlarDosya.close();
    dosya.close();

    return 0;
}
//https://stackoverflow.com/questions/3436125/comparing-array-elements-in-c
//BİL1001 -slayt 13.hafta slayt 1
//http://www.cplusplus.com/forum/general/179626/
//https://www.techiedelight.com/convert-string-to-int-cpp/