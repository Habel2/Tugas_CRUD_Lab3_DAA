#include<iostream>
#include<conio.h>
using namespace std;

struct mahasiswa{
	string nama,tgl,mk;
	char nim[9];
};

mahasiswa isi_data[100];
int a,b,c;

int menu(){
	int opsi;
	system("cls");
	cout<<"+ ======== PROGRAM CRUD ======== +"<<endl;
	cout<<"  Tentukan pilihan anda : "<<endl;
	cout<<"  1. Create"<<endl;
	cout<<"  2. Read"<<endl;
	cout<<"  3. Update"<<endl;
	cout<<"  4. Delete"<<endl;
	cout<<"  5. Selesai"<<endl;
	cout<<"+ ============================== +"<<endl;
	cout<<"  Menu yang ingin anda gunakan : ";
	cin>> opsi;
	return opsi;
}

void create_data(){
	int matkul;
    cout<<"  Banyak data yang akan diinput : ";cin>>b;
	for(int i=0;i<b;i++){
		c+=1;
		system("cls");
		cout<<"Data ("<<i+1<<"/"<<b<<")"<<endl;
		cout<<c<<". Nama          : ";cin.ignore();getline(cin,isi_data[a].nama);
		cout<<"   NIM           : ";cin>>isi_data[a].nim;
		cout<<"   Tanggal lahir : ";cin.ignore();getline(cin,isi_data[a].tgl);
		cout<<"  +===============================+"<<endl;
		cout<<"   Matakuliah yang tersedia :"<<endl;
		cout<<"\t1. Desain dan Analisis Algoritma\n\t2. Komputasi Numerik\n\t3. Basis Data\n\t4. Pemograman Web\n\t5. Wirausaha Digital"<<endl;
		mat_kul:
		cout<<"   Nomor matakuliah   : ";cin>>matkul;
		if(matkul == 1){isi_data[a].mk = "Desain dan Analisi Algoritma";}
		else if(matkul == 2){isi_data[a].mk = "Komputasi Numerik";}
		else if(matkul == 3){isi_data[a].mk = "Basis Data";}
		else if(matkul == 4){isi_data[a].mk = "Pemograman Web";}
		else if(matkul == 5){isi_data[a].mk = "Wirausaha Digital";}
		else{cout<<" --- Harap masukkan nomor matakuliah yang benar ---"<<endl;goto mat_kul;}
		a++;
	}
}

void read_data(){
    int i,j;
	j=0;
	for(i=0;i<a;i++){
		j+=1;
		cout<<j<<". Nama          : "<<isi_data[i].nama<<endl;
		cout<<"   NIM           : "<<isi_data[i].nim<<endl;
		cout<<"   Tanggal Lahir : "<<isi_data[i].tgl<<endl;
		cout<<"   Mata Kuliah   : "<<isi_data[i].mk<<endl;
	}	
}

void update_data(){
	int x,y,z,matkul;
	char n;
	read_data();
	cout<<"Nomor data yang ingin diedit : ";cin>>x;
	y=x-1;
	update:
	system("cls");
	cout<<"1. Nama          : "<<isi_data[y].nama<<endl;
	cout<<"2. NIM           : "<<isi_data[y].nim<<endl;
	cout<<"3. Tanggal Lahir : "<<isi_data[y].tgl<<endl;
	cout<<"4. Mata Kuliah   : "<<isi_data[y].mk<<endl;
	cout<<"Data "<<isi_data[y].nama<<" yang ingin di edit :";cin>>z;
	if (z==1){
		cout<<"Nama          : ";cin.ignore();getline(cin, isi_data[y].nama);
	}
	else if(z==2){
		cout<<"NIM           : ";cin>>isi_data[y].nim;
	}
	else if(z==3){
		cout<<"Tanggal Lahir : ";cin.ignore();getline(cin, isi_data[y].tgl);
	}
	else if(z==4){
		cout<<"Matakuliah yang tersedia :"<<endl;
		cout<<"\t1. Desain dan Analisis Algoritma\n\t2. Komputasi Numerik\n\t3. Basis Data\n\t4. Pemograman Web\n\t5. Wirausaha Digital"<<endl;
		mat_kul:
		cout<<"   Nomor matakuliah   : ";cin>>matkul;
		if(matkul == 1){isi_data[a].mk = "Desain dan Analisi Algoritma";}
		else if(matkul == 2){isi_data[a].mk = "Komputasi Numerik";}
		else if(matkul == 3){isi_data[a].mk = "Basis Data";}
		else if(matkul == 4){isi_data[a].mk = "Pemograman Web";}
		else if(matkul == 5){isi_data[a].mk = "Wirausaha Digital";}
		else{cout<<" --- Harap masukkan nomor matakuliah yang benar ---"<<endl;goto mat_kul;}
	}
	else{cout<<" --- Harap pilih data dengan benar --- "<<endl;}
	cout<<"Edit data "<<isi_data[y].nama<<" lagi? (y/n) : ";cin>>n;
	if(n=='y'||n=='Y'){goto update;}
	cout<<"----- Data sudah di update -----";
}

void Delete_data(){
	int x,y;
	read_data();
	cout<<"Nomor data yang ingin dihapus : ";cin>>x;
	y=x-1;
	cout<<"----- Data "<<isi_data[y].nama<<" telah dihapus -----";		
	a--;
	for(int i=y;i<a;i++){
		isi_data[i]=isi_data[i+1];
	}

}

int main(){
	char kembali_menu;
	enum option {create = 1, read, update, Delete, selesai};
	int pilihan = menu();
	while(pilihan != selesai){
		switch(pilihan){
			case create:
				create_data();
				break;
			case read:
				read_data();
				break;
			case update:
				update_data();
				break;
			case Delete:
				Delete_data();
				break;
			default:
				cout<<" -- Harap pilih dengan benar -- ";
				break;
		}
		lanjut:
		cout<<endl<<"Kembali ke menu?(y/n) : ";cin>>kembali_menu;	
		if((kembali_menu == 'y')||(kembali_menu == 'Y')){
			pilihan = menu();
		}
		else if((kembali_menu =='n')||(kembali_menu =='N')){
			break;
		}
		else{
			cout<<" -- Harap pilih dengan benar -- ";
			goto lanjut;}
	}
	system("pause");
	return 0;
}
