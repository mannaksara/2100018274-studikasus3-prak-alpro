#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include"kalkulator.h"
using namespace std;

int main(){
	int diskon,total,buy,jarak,jumlah,ongkir,tot,byr,kembalian,i,kurang,potongan,tot2,totalb;
	int harga[5]={21000,17000,19000,20000,25000};
	char nama[50],menu[30];
	bool saldo;
	cout<<"Masukkan Nama : ";cin>>nama;
	cout<<"Masukkan Jarak Rumah : ";cin>>jarak;
	
	ifstream sd;
			sd.open("menu.txt");
			string haha;
			while(!sd.eof()){
				getline(sd,haha);
				cout<<haha<<endl;
				};
				sd.close();

	cout<<"Silahkan pilih makanan anda : ";cin>>buy;
	
		if(buy==1){
		strcpy(menu,"Ayam Geprek");
		i=0;
		}
		else if(buy==2){
		strcpy(menu,"Ayam Goreng");
		i=1;
		}
		else if(buy==3){
		strcpy(menu,"Udang Goreng");
		i=2;
		}
		else if(buy==4){
		strcpy(menu,"Cumi Goreng");
		i=3;
		}
		else if(buy==5){
		strcpy(menu,"Ayam Bakar");
		i=4;
		}
		
		cout<<"Anda Memilih "<<menu<<endl;
		cout<<"Jumlah Makanan yang dibeli : ";cin>>jumlah;
		total=perkalian(jumlah,harga[i]);
				
		if(jarak<=3){
		ongkir=15000;
		tot=tambah(total,ongkir);
		}
		else{
		ongkir=25000;
		tot=tambah(total,ongkir);
		}
				
		if(tot==25000 || tot<50000){
		potongan=3000;
		tot2=tot-3000;	
		}
		else if(tot==50000 || tot<150000){
		potongan=5000;
		tot2=tot-5000;
		diskon=tot*15/100;
		}
		else if(tot>=150000){
		potongan=8000;
		tot2=tot-8000;
		diskon=tot*35/100;
		}
		else{
		potongan=0;
		}
			
			cout<<endl;
			cout<<"---------------------------------------------------------------------"<<endl;
			cout<<"|				GO-FOOD					|"<<endl;
			cout<<"---------------------------------------------------------------------"<<endl;
			cout<<"\tNama Pemesan		: "<<nama<<endl;
			cout<<"\tMenu Makanan		: "<<menu<<endl;
			cout<<"\tJumlah Makanan		: "<<jumlah<<" Porsi"<<endl;
			cout<<"\tHarga Makanan		: Rp."<<harga[i]<<" x "<<jumlah<<" = Rp."<<total<<endl;
			cout<<"\tOngkir			: Rp."<<ongkir<<endl;
			cout<<"\t			--------------- +"<<endl;
			cout<<"\t			  Rp."<<tot<<endl;
			cout<<"\tPotongan Harga		: Rp."<<potongan<<endl;
			cout<<"\tPotongan Diskon		: Rp."<<diskon<<endl;
			cout<<"\t			--------------- -"<<endl;
			cout<<"\tTotal Pembayaran	: Rp."<<tot2-diskon<<endl;
			cout<<"---------------------------------------------------------------------"<<endl;
			cout<<"Silahkan bayar disini	: Rp.";cin>>byr;
			cout<<"---------------------------------------------------------------------"<<endl;
				
			totalb=tot2-diskon;
			while(saldo=byr<totalb){
			cout<<"Uang anda kurang, Silahkan bayar lagi : Rp.";cin>>kurang;
			byr+=kurang;
			};
				
			kembalian=byr-totalb;
			cout<<"Uang yang anda bayar : Rp."<<byr<<endl;
			cout<<"Uang Kembalian : Rp."<<kembalian<<endl;
			cout<<"\n";

			ofstream ofs;
  			ofs.open("struk.txt");
  			ofs << "==========================================" << endl;
  			ofs << "Nama Pembeli      : " << nama << endl;
  			ofs << "Menu Makanan Anda : " << menu << endl;
  			ofs << "Harga Makanan     : Rp." << harga[i] << " x " << jumlah << endl;
  			ofs << "Jarak Rumah Anda  : " << jarak << " km" << endl;
 			ofs << "Ongkos Kirim Anda : Rp." << ongkir << endl;
  			ofs << "\t	--------------- +" << endl;
  			ofs << "                    Rp." << totalb << endl;
  			ofs << "Uang Pembayaran : Rp." << byr << endl;
  			ofs << "Uang Kembalian  : Rp." << kembalian << endl;
  			ofs << "==========================================" << endl;
  			ofs.close();
			
			ifstream jd;
			jd.open("struk.txt");
			string strd;
			while(!jd.eof()){
				getline(jd,strd);
				cout<<strd<<endl;
				};
				jd.close();
			return 0;
	}
