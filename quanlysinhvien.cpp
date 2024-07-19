#include<iostream>
#include<stdbool.h>
#include<string.h>
#include <cstdio>
#include<fstream>
using namespace std;
class person { // khai báo lớp person
	public:
		string MK;
		string name;
		string dob;
		string CCCD;
		string sdt;
		string email;
		person();
		~person();
		void  hienthiql();
		void hienthi();
		void chinhsua();

};
person::~person() { //hàm hủy
}
person::person() { // hàm khởi tạo
	MK ="00";
	name = "no name";
	dob = "00/00/0000";
	CCCD = "0000";
	sdt = "000000";
	email = "no email";
}
void person::chinhsua() { // hàm chỉnh sửa thông tin person
	cout<<"name:";
	getline(cin,name);
	cout<<"\n";
	fflush(stdin);
	cout<<"CCCD:";
	getline(cin,CCCD);
	cout<<"\n";
	fflush(stdin);
	cout<<"dob:";
	getline(cin,dob);
	cout<<"\n";
	fflush(stdin);
	cout<<"sdt:";
	getline(cin,sdt);
	cout<<"\n";
	fflush(stdin);
	cout<<"email:";
	getline(cin,email);
	cout<<"\n";
	fflush(stdin);
}
void person::hienthiql() { // hàm hiển thị thông tin person
	cout <<"ten:" << name <<"___";
	cout <<"ngaythangnamsinh:" <<dob<<"___"<<"CCCD:"<<CCCD<<"___";
	cout <<"sdt:" <<sdt<<"___";
	cout <<"email:" <<email<<"___";
}
void person::hienthi() {// hiển thị thông tin cơ bản cho việc tìm kiếm
	cout <<"ten:" << name <<"___";
	cout <<"ngaythangnamsinh:" <<dob<<"___";
	cout <<"sdt:" <<sdt<<"___";
	cout <<"email:" <<email<<"___";
}
class diemhocphan {
	public:
		int mahocphan;
		string tenhocphan;
		int malop;
		double diemqt;
		double diemck;
		double diemhp = (double)0.3*diemqt+(double)0.7*diemck;
		diemhocphan() {
			mahocphan=11;
			tenhocphan="xx";
			diemqt = -1;
			diemck = -1;
		}
		~diemhocphan() {
		};
		void nhapdiem() {
//			cout<<"nhap diem cho sinh vien:\n";
			cout<<"diem qua trinh:"<<endl;
			cin>>diemqt;
			cout<<"\ndiem cuoi ki:"<<endl;
			cin>>diemck;
			diemhp = (double)0.3*diemqt+(double)0.7*diemck;
			cout<<"\ndiem ket thuc hoc phan:"<<endl<<diemhp;
			system("pause");
			system("cls");
		}
		void xemdiem() {
			cout<<"hoc phan: "<<tenhocphan<<"---ma lop :"<<malop;
			cout<<"diem hoc phan cua sinh vien \n";
			cout<<"diem qua trinh:";
			cout<<diemqt;
			cout<<"\n diem cuoi ki:";
			cin>>diemck;
			cout<<"diem ket thuc hoc phan:"<<diemhp;
		}


};

class sinhvien: public person, public diemhocphan {//khai báo lớp sinh viên
	public:
		int key1;
		int MSSV;
		int n =1;
		diemhocphan* dhp = new diemhocphan[n];
		string lopsv;
		string k;
		string khoa;
		string truong;
		sinhvien();
		~sinhvien();
		void xoadiemhocphan(int &a,int &b);
		void themdiemhocphan();
		void chinhsua();
		void chinhsuattllsv();
		void hienthiql();
		void hienthisv();
		double GPA();
};
void sinhvien::xoadiemhocphan(int &a,int &b) {
	for(int i=1; i<=n-1; i++) {
		if((a==dhp[i].mahocphan)&&(b==dhp[i].malop)) {
			for(int x = i; x<=n-2; x++) {
				dhp[x]=dhp[x+1];
			}
			diemhocphan *ndhp = new diemhocphan[--n];
			for(int j=0; j<=n-1; j++) {
				ndhp[j]=dhp[j];
			}
			delete[]dhp;
			dhp = ndhp;
			break;
		} else if((dhp[i].mahocphan==dhp[n-1].mahocphan)&&(dhp[i].malop==dhp[n-1].malop)) {
			cout<<"sinh vien chua dang ky hoc phan nay";
			system("pause");
			system("cls");
		};
	}
}
void sinhvien::themdiemhocphan() {
	diemhocphan* ndhp = new diemhocphan[++n];
	for(int i = 0; i<=n-2; i++) {
		ndhp[i]=dhp[i];
	}
	delete[] dhp;
	dhp=ndhp;
	dhp[n-1]=dhp[0];
}
sinhvien::sinhvien():person::person() { // hàm tạo
	MSSV = 0;
	lopsv = "khong";
	k = "khong";
	khoa = "khong";
	truong = "khong";
}
sinhvien::~sinhvien() { // hàm hủy
}
void sinhvien::chinhsua() { //hàm chỉnh sửa thông tin sinh viên của quản lí
	cout<<"nhap thong tin sinh vien: \n";
	cout<<"MSSV:  ";
	cin>>MSSV;
	cout<<"MK:";
	cin>>MK;
	fflush(stdin);
	person::chinhsua();
	cout<<"k: ";
	getline(cin,k);
	fflush(stdin);
	cout<<"lop: ";
	getline(cin,lopsv);
	fflush(stdin);
	cout<<"khoa: ";
	getline(cin,khoa);
	fflush(stdin);
	cout<<"truong: ";
	getline(cin,truong);
	fflush(stdin);
}
void sinhvien::chinhsuattllsv() { // chỉnh sửa thông tin liên lạc cho sinh viên thực hiện
	cout<<"MOI BAN NHAP LAI THONG TIN\n";
	fflush(stdin);
	cout<<"sdt:";
	getline(cin,sdt);
	cout<<"\n";
	fflush(stdin);
	cout<<"email:";
	getline(cin,email);
	cout<<"\n";
	fflush(stdin);
}
void sinhvien::hienthiql() { // hàm hiển thị thông tin sinh viên của quản lí hoặc chính đối tượng sinh viên đó
	cout<<"thong tin sinh vien: \n";

	cout<<"MSSV: "<<MSSV<<"___";
	cout<<"MK: "<<MK<<"___";
	person::hienthiql();
	cout<<"lop: "<<lopsv<<"___";
	cout<<"k: "<<k<<"___";
	cout<<"khoa: "<<khoa<<"___";
	cout<<"truong: "<<truong<<"\n";
}
void sinhvien::hienthisv() { // hàm hiển thị thông tin sinh viên cho sinh viên hoặc cán bộ
	cout<<"thong tin sinh vien: \n";
	cout<<"MSSV: "<<MSSV<<"___";
	person::hienthi();
	cout<<"lop: "<<lopsv<<"___";
	cout<<"k: "<<k<<"___";
	cout<<"khoa: "<<khoa<<"___";
	cout<<"truong: "<<truong<<"\n";
}
// khai báo lớp cán bộ
class canbo: public person {
	public:
		int key2;
		int MCB;
		string truong;
		string khoa;
		string chucvu;
		string phonglamviec;
		canbo();
		~canbo();
		void chinhsuattllcb();
		void chinhsua();
		void hienthicb();
		void hienthiql();
};



// định nghĩa các hàm trong lớp cán bộ
canbo::canbo():person::person() { // hàm tạo
	MCB = 000;
	truong = "no school";
	khoa = "no khoa";
	chucvu = "khong";
	phonglamviec = "khong";
}
canbo::~canbo() {} // hàm hủy
void canbo::chinhsua() { // hàm chỉnh sửa thông tin cán bộ
	cout<<"nhap thong tin can bo: \n";
	cout<<"MCB: ";
	cin>>MCB;
	fflush(stdin);
	cout<<"MK:";
	cin>>MK;
	fflush(stdin);
	person::chinhsua();
	cout<<"khoa: ";
	getline(cin,khoa);
	fflush(stdin);
	cout<<"truong: ";
	getline(cin,truong);
	fflush(stdin);
	cout<<"chuc vu: ";
	getline(cin,chucvu);
	fflush(stdin);
	cout<<"phonglamviec: ";
	getline(cin,phonglamviec);
	fflush(stdin);
}

void canbo::chinhsuattllcb() { // chỉnh sửa thông tin liên lạc do cán bộ thực hiện
	cout<<"MOI BAN NHAP LAI THONG TIN\n";
	fflush(stdin);
	cout<<"sdt:";
	getline(cin,sdt);
	cout<<"\n";
	fflush(stdin);
	cout<<"email:";
	getline(cin,email);
	cout<<"\n";
	fflush(stdin);
}
void canbo::hienthiql() { // hàm hiển thị thông tin cán bộ
	cout<<"thong tin can bo: \n"<<"___"<<"MCB: "<<MCB<<"___";
	cout<<"MK: "<<MK<<"___";
	person::hienthiql();
	cout<<"khoa: "<<khoa<<"___";
	cout<<"truong: "<<truong<<"___";
	cout<<"chuc vu: "<<chucvu<<"___";
	cout<<"phong lam viec: "<<phonglamviec<<"\n";
}
void canbo::hienthicb() { // hàm hiển thị thông tin sinh viên cho sinh viên hoặc cán bộ
	cout<<"thong tin can bo: \n";
	cout<<"MCB: "<<MCB<<"___";
	person::hienthi();
	cout<<"khoa: "<<khoa<<"___";
	cout<<"truong: "<<truong<<"___";
	cout<<"chuc vu: "<<chucvu<<"___";
	cout<<"phong lam viec: "<<phonglamviec<<"\n";
}


class lophp: public sinhvien, public canbo {
	public:
		int slsv =1;
		sinhvien * svl = new sinhvien[slsv];
		canbo cbcn;
		lophp() {
			malop = 00;
		};
		~lophp() {
		};
		void chinhsuatt();//
		void hienthitt();//
		void indanhsachsvlop();//
		void nhapdiemhocphan();//


};

void lophp::indanhsachsvlop() {
	cout<<"danh sach sinh vien lop "<<malop;
	for(int i =1; i<=slsv; i++) {
		cout<<svl[i].MSSV<<"--"<<svl[i].name;
	}
}
void lophp::chinhsuatt() {
	cout<<"nhap ma lop moi:";
	fflush(stdin);
	cin>>malop;
};
void lophp::hienthitt() {
	cout<<"thong tin lop "<<malop<<": \n";
	cout<<"can bo phu trach: "<<cbcn.name;
	cout<<"\n so luong sinh vien: "<<slsv - 1<<endl;
};
class hp: public lophp {// khai bao class hoc phan
	public:
		int pll;
		int sl = 1;
		//	int mahocphan;
		//string tenhocphan;
		lophp *lhp = new lophp[sl];
		hp() {
			mahocphan = 00;
			tenhocphan = "yy";
		}
		~hp() {}
		void chinhsuahp();
		void hienthithongtin();
		void themlop();
		void xoalop();
		void indanhsachlop();
		void timlop();
		void xoalopf();
		void chinhsuattf();
};
void hp::chinhsuattf() {
	lhp[pll].chinhsuatt();
}
void hp::xoalopf() {
	system("cls");
	for(int i=1; i<=sl-1; i++) {
		if(lhp[i].malop == lhp[pll].malop) {
			for(int x= i; x<=sl-2; x++) {
				lhp[x]=lhp[x+1];
			};
			lophp *nl = new lophp[--sl];
			for(int i=0; i<=sl-1; i++) {
				nl[i]=lhp[i];
			}
			delete[]lhp;
			lhp = nl;
			cout<<"xoa lop thanh cong /n";
			break;
		} else {
			cout<<"ma lop khong ton tai";
			system("pause");
			system("cls");
		};
	};
}
void hp::chinhsuahp() {
	cout<<"nhap ma hoc phan moi:";
	fflush(stdin);
	cin>>mahocphan;
	cout<<"\n nhap ten hoc phan can them:";
	fflush(stdin);
	getline(cin,tenhocphan);
}
void hp::hienthithongtin() {
	cout<<"thong tin hoc phan: \n"<<"ma hoc phan: "<<mahocphan<<endl<<"ten hoc phan: "<<tenhocphan<<endl;
}
void hp::themlop() {
	int n;
	cout<<"nhap so luong lop can them: ";
	cin>>n;
	fflush(stdin);
	system("cls");
	for(int i=1; i<=n; i++) {
		lophp *nl = new lophp[++sl];
		for(int i=0; i<=sl-2; i++) {
			nl[i]=lhp[i];
			nl[i].mahocphan=mahocphan;
			nl[i].tenhocphan=tenhocphan;
		};
		delete[] lhp;
		lhp = nl;
		cout<<"\n lop thu:"<<i<<"\n";
		lhp[sl-1].chinhsuatt();
	}
}
void hp::xoalop() {
	int ml;
	cout<<"nhap ma lop can xoa: ";
	cin>>ml;
	fflush(stdin);
	system("cls");
	for(int i=1; i<=sl-1; i++) {
		if(lhp[i].malop == ml) {
			if(sl==2) {
				lophp *nl = new lophp[--sl];
				for(int i=0; i<=sl-1; i++) {
					nl[i]=lhp[i];
				}
				delete[]lhp;
				lhp = nl;
				cout<<"xoa lop thanh cong /n";
				break;
			} else if(sl>2) {
				for(int x= i; x<=sl-2; x++) {
					lhp[x]=lhp[x+1];
				};
				lophp *nl = new lophp[--sl];
				for(int i=0; i<=sl-1; i++) {
					nl[i]=lhp[i];
				}
				delete[]lhp;
				lhp = nl;
				cout<<"xoa lop thanh cong /n";
				break;
			}
		} else if(lhp[i].malop==lhp[sl-1].malop) {
			cout<<"ma lop khong ton tai";
			system("pause");
			system("cls");
		};
	};
}
void hp::indanhsachlop() {
	int f;
	cout<<"from:";
	fflush(stdin);
	cin>>f;
	cout<<"\n to:"<< sl-1;
	for (f; f<=sl-1; f++) {
		lhp[f].hienthitt();
	};
}
void hp::timlop() {
	int ml;
	cout<<"nhap ma lop hoc phan can tim:";
	cin>>ml;
	fflush(stdin);
	for (int i=1; i<=sl-1; i++) {
		if(lhp[i].malop==ml) {
			pll = i;
			lhp[i].hienthitt();
			break;
		} else if(lhp[i].malop==lhp[sl-1].malop) {
			cout<<"lop khong ton tai";
		};
	}
	system("pause");
	system("cls");

}
// định nghĩa lớp quản lí
class quanli: public hp {
	public:
		fstream fs;
		int keys,lp;
		int key;
		int a=1,b=1,c=1;
		int id,pass;
		hp *hps = new hp[c];
		sinhvien *sv = new sinhvien[a];
		canbo *cb = new canbo[b];
		void dangnhapchosinhvien();//
		void dangnhapchocanbo();//
		void themsinhvien();//
		void themcanbo();//
		void xoasinhvien();//
		void xoacanbo();//
		void indanhsachsinhvien();//
		void indanhsachcanbo();//
		void hienthithongtinforsv();//
		void hienthithongtinforcb();//
		void findinfosv();//
		void findinfocb();//
		void chinhsuasv();//
		void chinhsuacb();//
		void chinhsuahp();//
		void csttllsv();//
		void csttllcb();//
		void chinhsuacbf();//
		void chinhsuasvf();//
		void xoasvf();//
		void xoacbf();//
		void themhocphan();//
		void xoahocphan();//
		void chinhsuatthp();//
		void indanhsachhocphan();//
		void findhp();//
		void chinhsuahpf();//
		void xoahpf();//
		void indanhsachlophpf();//
		void danglylop();//
		void huydangkylop();//
		void dangkygiangdayf();//
		void huydangkygiangday();//
		void indanhsachlopgiangday();
		void nhapdiemhocphancb();//
		void indanhsachlopdangky();
		void themlophocphanf();//
		void xoalophocphanf();//
		void timlophpf();//
		void xoalophpf();//
		void chinhsualophpf();//
		void addifsv();//
		void addifcb();//
		void addifhp();//
		void ttllsv();
		void ttllcb();
};

// định nghĩa các hàm trong lớp quản lí
void quanli::ttllsv() {
	sv[key].chinhsuattllsv();
}
void quanli::ttllcb() {
	cb[key].chinhsuattllcb();
}
void quanli::addifsv() {
	int n;
	fs.open("danhsachsinhvien.txt",ios::in);
	fflush(stdin);
	fs>>n;
	for(int i=1; i<=n; i++) {
		sinhvien *nsv = new sinhvien[++a];
		for(int i=0; i<=a-2; i++) {
			nsv[i]=sv[i];
		};
		delete[] sv;
		sv = nsv;
		fflush(stdin);
		fs>>sv[a-1].MSSV;
		fs.ignore(1);
		getline(fs,sv[a-1].MK);
		getline(fs,sv[a-1].name);
		getline(fs,sv[a-1].CCCD);
		getline(fs,sv[a-1].dob);
		getline(fs,sv[a-1].sdt);
		getline(fs,sv[a-1].email);
		getline(fs,sv[a-1].k);
		getline(fs,sv[a-1].lopsv);
		getline(fs,sv[a-1].khoa);
		getline(fs,sv[a-1].truong);
		fs.ignore(0);
	}
	fs.close();
}
void quanli::addifcb() {
	int n;
	fs.open("danhsachcanbo.txt",ios::in);
	fflush(stdin);
	fs>>n;
	for(int i=1; i<=n; i++) {
		canbo *ncb = new canbo[++b];
		for(int i=0; i<=b-2; i++) {
			ncb[i]=cb[i];
		};
		delete[] cb;
		cb = ncb;
		fflush(stdin);
		fs>>cb[b-1].MCB;
		fs.ignore(1);
		getline(fs,cb[b-1].MK);
		getline(fs,cb[b-1].name);
		getline(fs,cb[b-1].CCCD);
		getline(fs,cb[b-1].dob);
		getline(fs,cb[b-1].sdt);
		getline(fs,cb[b-1].email);
		getline(fs,cb[b-1].khoa);
		getline(fs,cb[b-1].truong);
		getline(fs,cb[b-1].chucvu);
		getline(fs,cb[b-1].phonglamviec);
		fs.ignore(0);
	}
	fs.close();
}
void quanli::addifhp() {
	int n;
	fs.open("danhsachhocphan.txt",ios::in);
	fflush(stdin);
	fs>>n;
	for(int i=1; i<=n; i++) {
		hp *nhp = new hp[++c];
		for(int i=0; i<=c-2; i++) {
			nhp[i]=hps[i];
		};
		delete[] hps;
		hps = nhp;
		fs>>hps[c-1].mahocphan;
		fs.ignore(1);
		getline(fs,hps[c-1].tenhocphan);
		fs.ignore(0);
	}
}
void quanli::themlophocphanf() {
	hps[keys].themlop();
}
void quanli::xoalophocphanf() {
	hps[keys].xoalop();
}
void quanli::timlophpf() {
	hps[keys].timlop();
}
void quanli::xoalophpf() {
	hps[keys].xoalopf();
}
void quanli::chinhsualophpf() {
	hps[keys].chinhsuattf();
}

void quanli::xoahpf() {
	system("cls");
	for(int i=1; i<=c-1; i++) {
		if(hps[i].mahocphan == hps[keys].mahocphan) {
			if(c==2) {
				hp *nhp = new hp[--c];
				for(int i=0; i<=c-1; i++) {
					nhp[i]=hps[i];
				}
				delete[]hps;
				lhp = nhp;
				cout<<"xoa hoc phan thanh cong /n";
				break;
			} else if(c>2) {
				for(int x= i; x<=c-2; x++) {
					hps[x]=hps[x+1];
				};
				hp *nhp = new hp[--c];
				for(int i=0; i<=c-1; i++) {
					nhp[i]=hps[i];
				}
				delete[]hps;
				lhp = nhp;
				cout<<"xoa hoc phan thanh cong /n";
				break;
			}
		} else if(hps[i].mahocphan==hps[c-1].mahocphan) {
			cout<<"hoc phan khong ton tai";
			system("pause");
			system("cls");
		};
	};
}

void quanli::xoacbf() { // hàm xóa cán bộ được tìm kiếm
	system("cls");
	for(int i=1; i<=b-1; i++) {
		if(cb[i].MCB == cb[keys].MCB) {
			if(b==2) {
				canbo *ncb = new canbo[--b];
				for(int i=0; i<=b-1; i++) {
					ncb[i]=cb[i];
				}
				delete[]cb;
				cb = ncb;
				cout<<"xoa can bo thanh cong";
				break;
			} else if(b>2) {
				for(int x= i; x<=b-2; x++) {
					cb[x]=cb[x+1];
				};
				canbo *ncb = new canbo[--b];
				for(int i=0; i<=b-1; i++) {
					ncb[i]=cb[i];
				}
				delete[]cb;
				cb = ncb;
				cout<<"xoa can bo thanh cong";
				break;
			}
		} else if(cb[i].MCB==cb[b-1].MCB) {
			cout<<"can bo khong ton tai";
			system("pause");
			system("cls");
		};
	};
}
void quanli::xoasvf() { // hàm xóa sinh viên được tìm kiếm
	system("cls");
	for(int i=1; i<=a-1; i++) {
		if(sv[i].MSSV == sv[keys].MSSV) {
			if(a==2) {
				sinhvien *nsv = new sinhvien[--a];
				for(int i=0; i<=a-1; i++) {
					nsv[i]=sv[i];
				}
				delete[]sv;
				sv = nsv;
				cout<<"xoa sinh vien thanh cong";
				break;
			} else if(a>2) {
				for(int x= i; x<=a-2; x++) {
					sv[x]=sv[x+1];
				};
				sinhvien *nsv = new sinhvien[--a];
				for(int i=0; i<=a-1; i++) {
					nsv[i]=sv[i];
				}
				delete[]sv;
				sv = nsv;
				cout<<"xoa sinh vien thanh cong";
				break;
			}
		} else if(sv[i].MSSV==sv[a-1].MSSV) {
			cout<<"sinh vien khong ton tai";
			system("pause");
			system("cls");
		};
	};
}
void quanli::indanhsachlopdangky() {
	int slll=0;
	for(int i=1; i<=sv[key].n-1; i++) {
		cout<<i<<":";
		cout<<"MHP: "<<sv[key].dhp[i].mahocphan<<"---THP: "<<sv[key].dhp[i].tenhocphan<<"---"<<"ma lop: "<<sv[key].dhp[i].malop<<endl;
		cout<<"QT: "<<sv[key].dhp[i].diemqt<<"---CK: "<<sv[key].dhp[i].diemck<<"---KTHP: "<<sv[key].dhp[i].diemhp<<endl;
		slll++;
	}
	if(slll==0) {
		cout<<"SINH VIEN CHUA DANG KY LOP HOC PHAN NAO"<<endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}
void quanli::huydangkylop() {
	int a,b;
	cout<<"nhap ma hoc phan can huy dang ki:";
	fflush(stdin);
	cin>>a;
	cout<<"\nnhap ma lop hoc phan can huy dang ki";
	fflush(stdin);
	cin>>b;
	for(int i = 0; i<=c-1; i++) {
		if(hps[i].mahocphan==a) {
			for(int lp=0; lp<=hps[i].sl-1; lp++) {
				if(hps[i].lhp[lp].malop==b) {
					for(int k = 1; k<=hps[i].lhp[lp].slsv-1 ; k++) {
						if(hps[i].lhp[lp].svl[k].MSSV==sv[key].MSSV) {
							for(int as=k; as<=hps[i].lhp[lp].slsv-2; as++) {
								hps[i].lhp[lp].svl[as]=hps[i].lhp[lp].svl[as+1];
							}
							sinhvien *s=new sinhvien[--hps[i].lhp[lp].slsv];
							for(int z=0; z<=hps[i].lhp[lp].slsv-1; z++) {
								s[z]=hps[i].lhp[lp].svl[z];
							}
							delete[] hps[i].lhp[lp].svl;
							hps[i].lhp[lp].svl=s;// xoa sinh vien o lop sinh vien thanh cong
							// xoa diem hoc phan cua hoc phan do trong sinh vien[key]
							cout<<sv[key].n;
							system("pause");
							for(int tri=0; tri<=sv[key].n-1; tri++) {
								if((sv[key].dhp[tri].mahocphan==hps[i].mahocphan)&&(sv[key].dhp[tri].malop==hps[i].lhp[lp].malop)) {
									for(int aa=tri; aa<=sv[key].n-2; aa++) {
										sv[key].dhp[aa]=sv[key].dhp[aa+1];
									}
									diemhocphan *tu=new diemhocphan[--sv[key].n];
									for(int cvv=0; cvv<=sv[key].n-1; cvv++) {
										tu[cvv]=sv[key].dhp[cvv];
									}
									delete[] sv[key].dhp;
									sv[key].dhp=tu;
									cout<<" huy dang ky thanh cong";
									system("pause");
									system("cls");
									break;
								}
							}
							break;
						} else if(k==hps[i].lhp[lp].slsv-1) {
							cout<<"sinh vien chua dang ki lop nay \n";
							break;
						}
					}


					break;
				} else if(lp==hps[i].sl-1) {
					cout<<"lop hoc phan khong ton tai \n";
				}
			}
			break;
		} else if(i==c-1) {
			cout<<"hoc phan khong ton tai \n";
		}
	}
}
void quanli::danglylop() {
	int a,b;
	cout<<"nhap ma hoc phan can dang ky: \n";
	fflush(stdin);
	cin>>a;
	cout<<"\nnhap ma lop hoc phan can dang ky: \n ";
	fflush(stdin);
	cin>>b;
	for(int i =0; i<=c-1; i++) {
		if(hps[i].mahocphan==a) {
			for(lp=0; lp<=hps[i].sl-1; lp++) {
				if(hps[i].lhp[lp].malop==b) {
					for(int pl=0; pl<=hps[i].lhp[lp].slsv-1; pl++) {
						if(sv[key].MSSV==hps[i].lhp[lp].svl[pl].MSSV) {
							cout<<"sinh vien da dang ky lop nay roi"<<endl;
							break;
						} else if(pl==hps[i].lhp[lp].slsv-1) {
							sv[key].themdiemhocphan();
							sinhvien *nsvll = new sinhvien[++hps[i].lhp[lp].slsv];
							for(int k = 0; k<=hps[i].lhp[lp].slsv-2; k++) {
								nsvll[k]=hps[i].lhp[lp].svl[k];
							}
							delete[] hps[i].lhp[lp].svl;
							hps[i].lhp[lp].svl=nsvll;

							hps[i].lhp[lp].svl[hps[i].lhp[lp].slsv-1]=sv[key];
							hps[i].lhp[lp].svl[hps[i].lhp[lp].slsv-1].dhp[hps[i].lhp[lp].svl[hps[i].lhp[lp].slsv-1].n-1].tenhocphan=hps[i].tenhocphan;
							hps[i].lhp[lp].svl[hps[i].lhp[lp].slsv-1].dhp[hps[i].lhp[lp].svl[hps[i].lhp[lp].slsv-1].n-1].malop=hps[i].lhp[lp].malop;
							hps[i].lhp[lp].svl[hps[i].lhp[lp].slsv-1].dhp[hps[i].lhp[lp].svl[hps[i].lhp[lp].slsv-1].n-1].mahocphan=hps[i].mahocphan;
							sv[key].dhp[sv[key].n-1]=hps[i].lhp[lp].svl[hps[i].lhp[lp].slsv-1].dhp[hps[i].lhp[lp].svl[hps[i].lhp[lp].slsv-1].n-1];

							cout<<"dang ky thanh cong \n";
							break;
						}
					}
					break;
				} else if(hps[i].lhp[lp].malop==hps[i].lhp[hps[i].sl-1].malop) {
					cout<<"lop khong ton tai \n";
				};
			};
			break;
		} else if(hps[i].mahocphan==hps[c-1].mahocphan) {
			cout<<"hoc phan khong ton tai \n";
		};
	};
}
void quanli::nhapdiemhocphancb() {
	int a,b;
	cout<<"nhap ma hoc phan can nhap diem:";
	fflush(stdin);
	cin>>a;
	cout<<"\nnhap ma lop hoc phan can nhap diem: ";
	fflush(stdin);
	cin>>b;
	for(int i =0; i<=c-1; i++) {
		if(hps[i].mahocphan==a) {
			for(int lp=0; lp<=hps[i].sl-1; lp++) {
				if(hps[i].lhp[lp].malop==b) {
					if(hps[i].lhp[lp].cbcn.MCB==cb[key].MCB) {
						if(hps[i].lhp[lp].slsv<=1) {
							cout<<"lop chua co sinh vien dang ky"<<endl;
							break;
						} else {
							for(int dj=0; dj<=hps[i].lhp[lp].slsv-1; dj++) {
								for(int dg=0; dg<=hps[i].lhp[lp].svl[dj].n-1; dg++) {
									if((hps[i].lhp[lp].svl[dj].dhp[dg].mahocphan==a)&&(hps[i].lhp[lp].svl[dj].dhp[dg].malop==b)) {
										cout<<"sinh vien: "<<hps[i].lhp[lp].svl[dj].MSSV<<"  "<<hps[i].lhp[lp].svl[dj].name<<endl;
										hps[i].lhp[lp].svl[dj].dhp[dg].nhapdiem();
										for(int v = 0; v<=a-1; v++) {
											if(hps[i].lhp[lp].svl[dj].MSSV==sv[v].MSSV) {
//												cout<<"da duyet toi";
//												system("pause");
												for(int we = 1; we<=sv[v].n-1; we++) {
//													cout<<"da duyet toi";
//													system("pause");
													if((sv[v].dhp[we].mahocphan==hps[i].lhp[lp].svl[dj].dhp[dg].mahocphan)&&(sv[v].dhp[we].malop==hps[i].lhp[lp].svl[dj].dhp[dg].malop)) {
														sv[v].dhp[we].diemqt==hps[i].lhp[lp].svl[dj].dhp[dg].diemqt;
														sv[v].dhp[we].diemck==hps[i].lhp[lp].svl[dj].dhp[dg].diemck;
														sv[v].dhp[we].diemhp==hps[i].lhp[lp].svl[dj].dhp[dg].diemhp;
														break;
													}
												}
												break;
											}

										}
									}
								}
							}
							break;
						}
					} else if(hps[i].lhp[lp].malop==hps[i].lhp[hps[i].sl-1].malop) {
						cout<<"ban khong phu trach lop hoc phan nay \n";
						break;
					}
					break;
				} else if(lp==hps[i].sl-1) {
					cout<<"lop khong ton tai";
				};
			}
			break;
		} else if(i==c-1) {
			cout<<"hoc phan khong ton tai";
		};
	}
}
void quanli::indanhsachlopgiangday() {
	int a=0;
	for(int i = 1; i<=c-1; i++) {
		for(int lp =0; lp<=hps[i].sl-1; lp++) {
			if(cb[key].MCB==hps[i].lhp[lp].cbcn.MCB) {
				cout<<"hoc phan:"<<hps[i].mahocphan<<"=="<<hps[i].tenhocphan<<endl;
				hps[i].lhp[lp].hienthitt();
				a++;
			} else if((i==c-1)&&((a==0)&&(lp==sl-1))) {
				cout<<"giang vien khong phu trach lop nao \n";

			}
		}
	}
}

void quanli::indanhsachlophpf() {
	cout<<"danh sach lop hoc phan"<<hps[keys].mahocphan<<" \n";
	hps[keys].indanhsachlop();
	system("pause");
	system("cls");

}
void quanli::chinhsuahpf() {
	hps[keys].chinhsuahp();
	cout<<"chinh sua hoc phan thanh cong";
	system("pause");
	system("cls");
}
void quanli::findhp() {
	int ml;
	cout<<"nhap ma hoc phan can tim: \n";
	cin>>ml;
	fflush(stdin);
	for (int i=1; i<=c-1; i++) {
		if(hps[i].mahocphan==ml) {
			system("cls");
			hps[i].hienthithongtin();
			keys = i;
			break;
		} else if(hps[i].mahocphan==hps[c-1].mahocphan) {
			system("cls");
			cout<<"hoc phan khong ton tai \n";
		};
	}
	system("pause");
	system("cls");
}
void quanli::indanhsachhocphan() {
	int f;
	cout<<"danh sach hoc phan"<<" \n";
	cout<<"from:";
	fflush(stdin);
	cin>>f;
	cout<<"\n to:"<< c-1;
	for (f; f<=c-1; f++) {
		hps[f].hienthithongtin();
		cout<<endl;
	};
}
void quanli::xoahocphan() {
	int ml;
	cout<<"nhap ma hoc phan can xoa: ";
	cin>>ml;
	fflush(stdin);
	system("cls");
	for(int i=1; i<=c-1; i++) {
		if(hps[i].mahocphan == ml) {
			if(c==2) {
				hp *nhp = new hp[--c];
				for(int i=0; i<=c-1; i++) {
					nhp[i]=hps[i];
				}
				delete[]hps;
				lhp = nhp;
				cout<<"xoa hoc phan thanh cong /n";
				break;
			} else if(c>2) {
				for(int x= i; x<=c-2; x++) {
					hps[x]=hps[x+1];
				};
				hp *nhp = new hp[--c];
				for(int i=0; i<=c-1; i++) {
					nhp[i]=hps[i];
				}
				delete[]hps;
				lhp = nhp;
				cout<<"xoa hoc phan thanh cong /n";
				break;
			}
		} else if(hps[i].mahocphan==hps[c-1].mahocphan) {
			cout<<"hoc phan khong ton tai";
			system("pause");
			system("cls");
		};
	};
}

void quanli::themhocphan() {
	int n;
	cout<<"nhap so luong lop can them: ";
	cin>>n;
	fflush(stdin);
	system("cls");
	for(int i=1; i<=n; i++) {
		hp *nhp = new hp[++c];
		for(int i=0; i<=c-2; i++) {
			nhp[i]=hps[i];
		};
		delete[] hps;
		hps = nhp;
		cout<<"\n hoc phan thu:"<<i<<"\n";
		hps[c-1].chinhsuahp();
	}
}
void quanli::chinhsuacbf() {
	cb[keys].chinhsua();
	cout<<"\n chinh sua thong tin can bo thanh cong";
	system("pause");
	system("cls");
}
void quanli::chinhsuasvf() {
	sv[keys].chinhsua();
	cout<<"\n chinh sua thong tin sinh vien thanh cong";
	system("pause");
	system("cls");
}
void quanli::csttllcb() {
	cb[key].chinhsuattllcb();
	system("cls");
	cout<<"chinh sua thong tin lien lac thanh cong";
	system("pause");
	system("cls");
}
void quanli::csttllsv() {
	sv[key].chinhsuattllsv();
	system("cls");
	cout<<"chinh sua thong tin lien lac thanh cong";
	system("pause");
	system("cls");
}
void quanli::chinhsuacb() {
	int mcb;
	cout<<"nhap can bo can chinh sua: ";
	cin>>mcb;
	fflush(stdin);
	system("cls");
	for(int i=1; i<=b-1; i++) {
		if(cb[i].MCB == mcb) {
			cb[i].chinhsua();
			cout<<"\n chinh sua thong tin can bo thanh cong";
			break;
		} else if(cb[i].MCB==cb[b-1].MCB) {
			cout<<"can bo khong ton tai";
			system("pause");
			system("cls");
		};
	};

}
void quanli::chinhsuasv() {
	int mssv;
	cout<<"nhap ma so sinh vien can chinh sua: ";
	cin>>mssv;
	fflush(stdin);
	system("cls");
	for(int i=1; i<=a-1; i++) {
		if(sv[i].MSSV == mssv) {
			sv[i].chinhsua();
			cout<<"\n chinh sua thong tin sinh vien thanh cong";
			break;
		} else if(sv[i].MSSV==sv[a-1].MSSV) {
			cout<<"sinh vien khong ton tai";
			system("pause");
			system("cls");
		};
	};
}
void quanli::chinhsuahp() {
	int a;
	cout<<"nhap ma hoc phan can chinh sua:";
	cin>>a;
	fflush(stdin);
	for(int i=1; i<=c-1; i++) {
		if(hps[i].mahocphan==a) {
			hps[i].chinhsuahp();
			break;
		} else if(hps[i].mahocphan==hps[c-1].mahocphan) {
			cout<<"\n ma hoc phan khong chinh xac hoac hoc phan khong ton tai";
		};
	};

}
void quanli::huydangkygiangday() {
	int a,b;
	cout<<"nhap ma hoc phan dang giang day: ";
	fflush(stdin);
	cin>>a;
	cout<<endl<<"nhap ma lop hoc phan dang giang day: ";
	fflush(stdin);
	cin>>b;
	for(int i =1; i<=c-1; i++) {
		if(hps[i].mahocphan==a) {
			for(int lp=0; lp<=hps[i].sl-1; lp++) {
				if((hps[i].lhp[lp].malop==b)&&(hps[i].lhp[lp].cbcn.MCB==cb[key].MCB)) {
					hps[i].lhp[lp].cbcn=cb[0];
					cout<<"huy dang ky thanh cong";
					break;
				} else if(hps[i].lhp[lp].malop==hps[i].lhp[hps[i].sl-1].malop) {
					cout<<"ban khong phu trach lop nay";
				};
			};
			break;
		} else if(hps[i].mahocphan==hps[c-1].mahocphan) {
			cout<<"hoc phan khong ton tai";
		};
	};
}
void quanli::dangkygiangdayf() {
	int a,b;
	cout<<"nhap ma hoc phan dang ky: ";
	fflush(stdin);
	cin>>a;
	cout<<"\nnhap ma lop hoc phan dang ky giang day: ";
	fflush(stdin);
	cin>>b;
	for(int i =1; i<=c-1; i++) {
		if(hps[i].mahocphan==a) {
			for(lp=0; lp<=hps[i].sl-1; lp++) {
				if(hps[i].lhp[lp].malop==b) {
					hps[i].lhp[lp].cbcn=cb[key2];
					cout<<"dang ky thanh cong"<<endl;
					break;
				} else if(hps[i].lhp[lp].malop==hps[i].lhp[hps[i].sl-1].malop) {
					cout<<"lop khong ton tai"<<endl;
				};
			};
			break;
		} else if(hps[i].mahocphan==hps[c-1].mahocphan) {
			cout<<"hoc phan khong ton tai"<<endl;
		};
	};
}


void quanli::dangnhapchosinhvien() {
	string pw;
	cout<<"NHAP MSSV: ";
	cin>>id;
	fflush(stdin);
	cout<<endl<<"NHAP MK: ";
	getline(cin,pw);
	fflush(stdin);
	for(int i =1; i<=a-1; i++) {
		if(sv[i].MSSV==id) {
			if(sv[i].MK==pw) {
				key = i;
				key1 = i;
				pass = 1;
				break;
			};
		} else {
			pass = 0;
		};
	};
}

void quanli::dangnhapchocanbo() {
	string pw;
	cout<<"NHAP MCB: ";
	cin>>id;
	fflush(stdin);
	cout<<endl<<"NHAP MK: ";
	getline(cin,pw);
	fflush(stdin);
	for(int i =1; i<=b-1; i++) {
		if(cb[i].MCB==id) {
			if(cb[i].MK==pw) {
				key = i;
				key2 = i;
				pass = 1;
				break;
			};
		} else {
			pass = 0;
		};
	};
}
void quanli::themsinhvien() { //hàm thêm sinh viên
	int n;
	cout<<"nhap so luong sinh vien can them: ";
	cin>>n;
	fflush(stdin);
	system("cls");
	for(int i=1; i<=n; i++) {
		sinhvien *nsv = new sinhvien[++a];
		for(int i=0; i<=a-2; i++) {
			nsv[i]=sv[i];
		};
		delete[] sv;
		sv = nsv;
		cout<<"\n sinh vien thu:"<<i<<"\n";
		sv[a-1].chinhsua();
		system("pause");
		system("cls");
	}
}
void quanli::themcanbo() {
	int n;
	cout<<"nhap so luong can bo can them: ";
	cin>>n;
	fflush(stdin);
	system("cls");
	for(int i=1; (i<=n); i++) {
		canbo *ncb = new canbo[++b];
		for(int i=0; i<=b-2; i++) {
			ncb[i]=cb[i];
		}
		delete[]cb;
		cb = ncb;
		cout<<endl<<"can bo thu: "<<i<<"\n";
		cb[b-1].chinhsua();
		system("pause");
		system("cls");
	};
}
void quanli::xoasinhvien() { // hàm xóa sinh viên
	int mssv;
	cout<<"nhap ma so sinh vien can xoa: ";
	cin>>mssv;
	fflush(stdin);
	system("cls");
	for(int i=1; i<=a-1; i++) {
		if(sv[i].MSSV == mssv) {
			if(a==2) {
				sinhvien *nsv = new sinhvien[--a];
				for(int i=0; i<=a-1; i++) {
					nsv[i]=sv[i];
				}
				delete[]sv;
				sv = nsv;
				cout<<"xoa sinh vien thanh cong";
				break;
			} else if(a>2) {
				for(int x= i; x<=a-2; x++) {
					sv[x]=sv[x+1];
				};
				sinhvien *nsv = new sinhvien[--a];
				for(int i=0; i<=a-1; i++) {
					nsv[i]=sv[i];
				}
				delete[]sv;
				sv = nsv;
				cout<<"xoa sinh vien thanh cong";
				break;
			}
		} else if(sv[i].MSSV==sv[a-1].MSSV) {
			cout<<"sinh vien khong ton tai";
			system("pause");
			system("cls");
		};
	};
}
void quanli::xoacanbo() { //hàm xóa cán bộ
	int mcb;
	cout<<"nhap ma so can bo can xoa: ";
	cin>>mcb;
	fflush(stdin);
	system("cls");
	for(int i=0; i<=b-1; i++) {
		if(cb[i].MCB == mcb) {
			if(b==2) {
				canbo *ncb = new canbo[--b];
				for(int i=0; i<=b-1; i++) {
					ncb[i]=cb[i];
				}
				delete[]cb;
				cb = ncb;
				cout<<"xoa can bo thanh cong /n";
				break;
			} else if(b>2) {
				for(int x= i; x<=b-2; x++) {
					cb[x]=cb[x+1];
				};
				canbo *ncb = new canbo[--b];
				for(int i=0; i<=b-1; i++) {
					ncb[i]=cb[i];
				}
				delete[]cb;
				cb = ncb;
				cout<<"xoa can bo thanh cong /n";
				break;
			}
		} else if(cb[i].MCB==cb[b-1].MCB)  {
			cout<<"ma so can bo khong ton tai";
			system("pause");
			system("cls");
		};
	};
}
void quanli::indanhsachsinhvien() { // hàm in danh sách sinh viên
	int f;
	cout<<"nhap so luong sinh vien can hien thi:\n";
	cout<<"from:";
	fflush(stdin);
	cin>>f;
	cout<<"\n to:"<< a-1;
	for (f; f<=a-1; f++) {
		sv[f].hienthiql();
	};
};

void quanli::indanhsachcanbo() { // hàm in danh sách cán bộ
	int f;
	cout<<"nhap so luong can bo can hien thi:\n";
	cout<<"from:";
	fflush(stdin);
	cin>>f;
	cout<<"\n to:"<< b-1;
	for (f; f<=b-1; f++) {
		cb[f].hienthiql();
	};
};
void quanli::hienthithongtinforcb() {
	cout<<"thong tin ca nhan cua can bo "<<cb[key].MCB<<": \n";
	cb[key].hienthiql();
	system("pause");
	system("cls");

};
void quanli::hienthithongtinforsv() {
	cout<<"thong tin ca nhan cua sinh vien "<<sv[key].MSSV<<": \n";
	sv[key].hienthiql();
	system("pause");
	system("cls");
};
void quanli::findinfosv() {
	int mssv;
	cout<<"nhap ma so sinh vien can tim:"<<endl;
	cin>>mssv;
	fflush(stdin);
	for (int i=1; i<=a-1; i++) {
		if(sv[i].MSSV==mssv) {
			sv[i].hienthisv();
			keys = i;
			break;
		} else if(sv[i].MSSV==sv[a-1].MSSV) {
			cout<<endl<<"sinh vien khong ton tai"<<endl;
		};
	}
	system("pause");
	system("cls");
}
void quanli::findinfocb() {
	int mcb;
	cout<<"nhap ma so can bo can tim:"<<endl;
	cin>>mcb;
	fflush(stdin);
	for (int i=1; i<=b-1; i++) {
		if(cb[i].MCB==mcb) {
			cb[i].hienthicb();
			keys = i;
			break;
		} else if(cb[i].MCB==cb[b-1].MCB) {
			cout<<endl<<"can bo khong ton tai"<<endl;
		};
	}
	system("pause");
	system("cls");
}
int main() {
	int chiso;
	quanli HUST;
	HUST.addifsv();
	HUST.addifcb();
	HUST.addifhp();
t :
	cout<<"||||||||------HUST------||||||||\n";
	cout<<"|==PHAN MEM QUAN LI SINH VIEN==|\n";
	cout<<"|============BAN LA============|\n";
	cout<<"|---------1.SINH VIEN----------|\n";
	cout<<"|---------2.CAN BO GIANG VIEN--|\n";
	cout<<"|---------3.QUAN LI------------|\n";
	cout<<"|       CHON 0 DE THOAT        |\n";
	cout<<"====> NHAP SO DE LUA CHON : ";
	cin>>chiso;
	system("cls");
	switch(chiso) {
		case 1:// Sử dụng chức năng sinh viên

			HUST.dangnhapchosinhvien();
			system("cls");
			if(HUST.pass==1) {
tacvu:
				int tacvu;
				cout<<"||||----MENU SINH VIEN----|||\n";
				cout<<"|1.QUAN LI THONG TIN CA NHAN|\n";
				cout<<"|2.HOC PHAN SINH VIEN       |\n";
				cout<<"|3.TIM KIEM                 |\n";
				cout<<"|4.IN DANH SACH             |\n";
				cout<<"|CHON 0 DE QUAY LAI         |\n";
				cout<<"==> NHAP SO DE CHON TAC VU: ";
				cin>>tacvu;
				system("cls");
				switch(tacvu) {
					case 1://quản lí thông tin cá nhân
tv :
						int tvsv;
						cout<<"|||=====QUAN LY THONG TIN CA NHAN=====|||\n";
						cout<<"|----1.XEM THONG TIN CA NHAN------------|\n";
						cout<<"|----2.XEM BANG DIEM HOC TAP------------|\n";
						cout<<"|----3.CHINH SUA THONG TIN LIEN LAC-----|\n";
						cout<<"|====CHON 0 DE QUAY TRO LAI=============|\n";
						cout<<"==> NHAP SO DE CHON TAC VU: ";
						cin>>tvsv;
						switch(tvsv) {
							case 1://xem thông tin cá nhân
								system("cls");
								HUST.hienthithongtinforsv();
								system("pause");
								system("cls");
								goto tv;
								break;
							case 2://xem bảng điểm học tập
								system("cls");
								HUST.indanhsachlopdangky();
								system("pause");
								system("cls");
								goto tv;
								break;
							case 3:// chỉnh sửa thông tin liên lạc
								system("cls");
								HUST.ttllsv();
								system("pause");
								system("cls");
								goto tv;
								break;
							case 0:// trở lại trang trước
								system("cls");
								goto tacvu;
								break;
							default:// nhập sai tác vụ
								system("cls");
								cout<<"MOI BAN CHON LAI TAC VU\n";
								system("pause");
								system("cls");
								goto tv;
						}
						break;
					case 2://quản lí lớp học phần đang học
qll:
						system("cls");
						int qll;
						cout<<"|||==========HOC PHAN SINH VIEN==========|||\n";
						cout<<"|-----1.DANG KY LOP HOC PHAN---------------|\n";
						cout<<"|-----2.HUY DANG KY LOP HOC PHAN-----------|\n";
						cout<<"|-----3.DANH SACH HOC PHAN DA DANG KY------|\n";
						cout<<"|=====CHON 0 DE QUAY TRO LAI===============|\n";
						cout<<"==> NHAP SO DE CHON TAC VU: ";
						cin>>qll;
						system("cls");
						switch(qll) {
							case 1:// đăng ký lớp học phần
								system("cls");
								HUST.danglylop();
								system("pause");
								system("cls");
								goto qll;
								break;
							case 2:// Hủy đăng kí lớp học phần
								system("cls");
								HUST.huydangkylop();
								system("pause");
								system("cls");
								goto qll;
								break;
							case 3:// In ra danh sách học phần đã đăng kí
								system("cls");
								HUST.indanhsachlopdangky();
								system("pause");
								system("cls");
								goto qll;
								break;
							case 0:// trở lại trang trước
								system("cls");
								goto tacvu;
								break;
							default:// nhập sai tác vụ
								system("cls");
								cout<<"MOI BAN CHON LAI TAC VU\n";
								system("pause");
								system("cls");
								goto qll;
						}
						break;
					case 3://tìm kiếm
tks:
						int tks;
						cout<<"|||=========TIM KIEM===============|||\n";
						cout<<"|-----1.TIM KIEM SINH VIEN-----------|\n";
						cout<<"|-----2.TIM KIEM CAN BO--------------|\n";
						cout<<"|-----3.TIM KIEM HOC PHAN------------|\n";
						cout<<"|=====CHON 0 DE QUAY TRO LAI=========|\n";
						cout<<"==> NHAP SO DE CHON TAC VU: ";
						cin>>tks;
						system("cls");
						switch(tks) {
							case 1:// tìm kiếm sinh viên
								HUST.findinfosv();
								system("pause");
								system("cls");
								goto tks;
								break;
							case 2:// tìm kiếm cán bộ
								HUST.findinfocb();
								system("pause");
								system("cls");
								goto tks;
								break;
							case 3:// tìm kiếm học phần
								HUST.findhp();
								system("pause");
								system("cls");
								goto tks;
								break;
							case 0:
								system("cls");
								goto tacvu;
								break;
							default:// nhập sai tác vụ
								system("cls");
								cout<<"MOI BAN CHON LAI TAC VU\n";
								system("pause");
								system("cls");
								goto tks;
						}
						break;
					case 4:// In ra
ir:
						int ir;
						cout<<"|||==========IN DANH SACH==========|||\n";
						cout<<"|-----1.IN DANH SACH SINH VIEN-------|\n";
						cout<<"|-----2.IN DANH SACH CAN BO----------|\n";
						cout<<"|-----3.IN DANH SACH HOC PHAN--------|\n";
						cout<<"|-----4.IN DANH SACH LOP HOC PHAN----|\n";
						cout<<"|-----5.IN DANH SACH SINH VIEN LOP---|\n";
						cout<<"|======CHON 0 DE QUAY TRO LAI========|\n";
						cout<<"==> NHAP SO DE CHON TAC VU: ";
						cin>>ir;
						system("cls");
						switch(ir) {
							case 1:// in danh sách sinh viên
								HUST.indanhsachsinhvien();
								system("pause");
								system("cls");
								goto tacvu;
								break;
							case 2://in danh sách cán bộ
								HUST.indanhsachcanbo();
								system("pause");
								system("cls");
								goto tacvu;
								break;
							case 3:// in danh sách học phần
								HUST.indanhsachhocphan();
								system("pause");
								system("cls");
								goto tacvu;
								break;
							case 4://tìm học phần và in ra danh sách lớp học phần đó
								HUST.findhp();
								system("pause");
								system("cls");
								HUST.indanhsachlophpf();
								system("pause");
								system("cls");
								goto tacvu;
								break;
							case 5:
								system("cls");
								goto tacvu;
								break;
							case 0:// quay trở lại trang trước
								system("cls");
								goto tacvu;
								break;
							default:// nhập sai tác vụ
								system("cls");
								cout<<"MOI BAN CHON LAI TAC VU\n";
								system("pause");
								system("cls");
								goto ir;


						}
						break;
					case 0:// quay trở lại menu HUST
						system("cls");
						goto t;
						break;
					default:// nhập sai số mời bạn nhập lại
						system("cls");
						cout<<"MOI BAN CHON LAI TAC VU\n";
						system("pause");
						system("cls");
						goto tacvu;
				}
			} else if(HUST.pass == 0) {
				cout<<"TAI KHOAN HOAC MAT KHAU KHONG CHINH XAC\n";
				system("pause");
				system("cls");
				goto t;
			}
			break;
		case 2:// sử dụng chức năng của cán bộ
			HUST.dangnhapchocanbo();
			system("cls");
			if(HUST.pass==1) {
tacvucb:
				int tacvucb;
				cout<<"||||------MENU CAN BO-----|||\n";
				cout<<"|1.QUAN LI THONG TIN CA NHAN|\n";
				cout<<"|2.HOC PHAN CAN BO          |\n";
				cout<<"|3.TIM KIEM                 |\n";
				cout<<"|4.IN DANH SACH             |\n";
				cout<<"|CHON 0 DE QUAY LAI         |\n";
				cout<<"==> NHAP SO DE CHON TAC VU: ";

				cin>>tacvucb;
				system("cls");
				switch(tacvucb) {
					case 1:// quán lí thông tin cá nhân cán bộ
tvs :
						int tvs;
						cout<<"|||=====QUAN LY THONG TIN CA NHAN=====|||\n";
						cout<<"|----1.XEM THONG TIN CA NHAN------------|\n";
						cout<<"|----2.CHINH SUA THONG TIN LIEN LAC-----|\n";
						cout<<"|====CHON 0 DE QUAY TRO LAI=============|\n";
						cout<<"==> NHAP SO DE CHON TAC VU: ";
						cin>>tvs;
						switch(tvs) {
							case 1://xem thông tin cá nhân
								HUST.hienthithongtinforcb();
								system("pause");
								system("cls");
								goto tvs;
								break;
							case 2:// chỉnh sửa thông tin liên lạc
								HUST.ttllcb();
								system("pause");
								system("cls");
								goto tvs;
								break;
							case 0:// trở lại trang trước
								system("cls");
								goto tacvucb;
								break;
							default:// nhập sai tác vụ
								system("cls");
								cout<<"MOI BAN CHON LAI TAC VU\n";
								system("pause");
								system("cls");
								goto tvs;
						}
						break;
					case 2:// quản lí lớp học phần giảng dạy
qlc:
						int qlc;
						cout<<"|||=====QUAN LI LOP HOC PHAN CAN BO=====|||\n";
						cout<<"|-----1.DANG KY GIANG DAY-----------------|\n";
						cout<<"|-----2.HUY DANG KY GIANG DAY-------------|\n";
						cout<<"|-----3.DANH SACH LOP GIANG DAY-----------|\n";
						cout<<"|-----4.NHAP DIEM SINH VIEN---------------|\n";
						cout<<"|=====CHON 0 DE QUAY TRO LAI==============|\n";
						cout<<"==> NHAP SO DE CHON TAC VU: ";
						cin>>qlc;
						system("cls");
						switch(qlc) {
							case 1:// đăng ký giảng dạy
								HUST.dangkygiangdayf();
								system("pause");
								system("cls");
								goto qlc;
								break;
							case 2:// Hủy đăng ký lớp giảng dạy
								HUST.huydangkygiangday();
								system("pause");
								system("cls");
								goto qlc;
								break;
							case 3:// In ra danh sách lớp đang giảng dạy
								HUST.indanhsachlopgiangday();
								system("pause");
								system("cls");
								goto qlc;
								break;
							case 4://nhập điểm sinh viên
								HUST.nhapdiemhocphancb();
								system("pause");
								system("cls");
								goto qlc;
								break;
							case 0:// trở lại trang trước
								system("cls");
								goto tacvucb;
								break;
							default:// nhập sai tác vụ
								system("cls");
								cout<<"MOI BAN CHON LAI TAC VU\n";
								system("pause");
								system("cls");
								goto qlc;
						}
						break;
					case 3:// tìm kiếm
tksc:
						int tksc;
						cout<<"|||=========TIM KIEM===============|||\n";
						cout<<"|-----1.TIM KIEM SINH VIEN-----------|\n";
						cout<<"|-----2.TIM KIEM CAN BO--------------|\n";
						cout<<"|-----3.TIM KIEM HOC PHAN------------|\n";
						cout<<"|=====CHON 0 DE QUAY TRO LAI=========|\n";
						cout<<"==> NHAP SO DE CHON TAC VU: ";
						cin>>tksc;
						system("cls");
						switch(tksc) {
							case 1:// tìm kiếm sinh viên
								HUST.findinfosv();
								system("pause");
								system("cls");
								goto tksc;
								break;
							case 2:// tìm kiếm cán bộ
								HUST.findinfocb();
								system("pause");
								system("cls");
								goto tksc;
								break;
							case 3:// tìm kiếm học phần
								HUST.findhp();
								system("pause");
								system("cls");
								goto tksc;
								break;
							case 0:
								system("cls");
								goto tacvucb;
								break;
							default:// nhập sai tác vụ
								system("cls");
								cout<<"MOI BAN CHON LAI TAC VU\n";
								system("pause");
								system("cls");
								goto tksc;
						}
						break;
					case 4:// in danh sách
is:
						int is;
						cout<<"|||==========IN DANH SACH==========|||\n";
						cout<<"|-----1.IN DANH SACH SINH VIEN-------|\n";
						cout<<"|-----2.IN DANH SACH CAN BO----------|\n";
						cout<<"|-----3.IN DANH SACH HOC PHAN--------|\n";
						cout<<"|-----4.IN DANH SACH LOP HOC PHAN----|\n";
						cout<<"|-----5.IN DANH SACH SINH VIEN LOP---|\n";
						cout<<"|======CHON 0 DE QUAY TRO LAI========|\n";
						cout<<"==> NHAP SO DE CHON TAC VU: ";
						cin>>is;
						system("cls");
						switch(is) {
							case 1:// in danh sách sinh viên
								HUST.indanhsachsinhvien();
								system("pause");
								system("cls");
								goto tacvu;
								break;
							case 2://in danh sách cán bộ
								HUST.indanhsachcanbo();
								system("pause");
								system("cls");
								goto tacvucb;
								break;
							case 3:// in danh sách học phần
								HUST.indanhsachhocphan();
								system("pause");
								system("cls");
								goto tacvucb;
								break;
							case 4://tìm học phần và in ra danh sách lớp học phần đó
								HUST.findhp();
								system("pause");
								system("cls");
								HUST.indanhsachlophpf();
								system("pause");
								system("cls");
								goto tacvucb;
								break;
							case 5:
								system("cls");
								goto tacvucb;
								break;
							case 0:// quay trở lại trang trước
								system("cls");
								goto tacvucb;
								break;
							default:// nhập sai tác vụ
								system("cls");
								cout<<"MOI BAN CHON LAI TAC VU\n";
								system("pause");
								system("cls");
								goto is;


						}
						break;
					case 0://quay trở lại menu HUST
						system("cls");
						goto t;
						break;
					default:// nhập số khác, yêu cầu nhập lại để chọn tác vụ
						system("cls");
						cout<<"MOI BAN CHON LAI TAC VU\n";
						system("pause");
						system("cls");
						goto tacvucb;
				}
			} else if(HUST.pass==0) {
				cout<<"TAI KHOAN HOAC MAT KHAU KHONG CHINH XAC\n";
				goto t;
			};
			break;
		case 3:// sử dụng chức năng của quản lí
rt:
			int a;
			cout<<"=====MOI BAN NHAP MA QUAN LI=====\n";// cần mã quản lí để sử dụng
			cout<<"(neu ban nhap sai thi se phai nhap toi luc dung)"<<endl;
			cin>>a;
			switch(a) {
				case 8888:// mã đúng là 8888
					system("cls");
tacvuql:
					int tacvuql;
					cout<<"==============*MENU QUAN LI*=============\n";
					cout<<"***********|1.QUAN LY SINH VIEN|*********\n";
					cout<<"***********|2.QUAN LY CAN BO|************\n";
					cout<<"***********|3.QUAN LY HOC PHAN|**********\n";
					cout<<"***********|4.QUAN LY LOP HOC PHAN|******\n";
					cout<<"============CHON 0 DE QUAY TRO LAI=======\n";
					cout<<"==> NHAP SO DE CHON TAC VU: ";
					cin>>tacvuql;
					system("cls");
					switch(tacvuql) {
						case 1:// QUẢN LÝ SINH VIÊN
qlsv:
							int qlsv;
							cout<<"======QUAN LY SINH VIEN======\n";
							cout<<"------1.THEM SINH VIEN-------\n";
							cout<<"------2.XOA SINH VIEN--------\n";
							cout<<"------3.TIM SINH VIEN--------\n";
							cout<<"------4. IN DANH SACH--------\n";
							cout<<"====CHON 0 DE QUAY TRO LAI===\n";
							cout<<"==> NHAP SO DE CHON TAC VU: ";
							cin>>qlsv;
							system("cls");
							switch(qlsv) {
								case 1:
									HUST.themsinhvien();
									system("pause");
									system("cls");
									goto qlsv;
									break;
								case 2:
									HUST.xoasinhvien();
									system("pause");
									system("cls");
									goto qlsv;
									break;
								case 3:
									HUST.findinfosv();
									system("pause");
qq:
									int qq;
									cout<<"1. CHINH SUA THONG TIN SINH VIEN \n";
									cout<<"2. XOA SINH VIEN NAY \n";
									cout<<"===CHON 0 DE QUAY TRO LAI=======\n";
									cout<<"==> NHAP SO DE CHON TAC VU: ";
									cin>>qq;
									system("cls");
									switch(qq) {
										case 1:
											HUST.chinhsuasvf();
											cout<<"CHINH SUA THONG TIN SINH VIEN THANH CONG"<<endl;
											system("pause");
											system("cls");
											goto qq;
											break;

										case 2:
											HUST.xoasvf();
											cout<<"XOA SINH VIEN THANH CONG"<<endl;
											system("pause");
											system("cls");
											goto qlsv;
										case 0:
											system("cls");// dọn màn hình
											goto qlsv;// quay lạ
											break;
										default:
											system("cls");
											cout<<"MOI BAN CHON LAI TAC VU\n";
											system("pause");
											system("cls");
											goto qq;
									}
									break;
								case 4:// IN RA DANH SÁCH SINH VIÊN
									HUST.indanhsachsinhvien();
									system("pause");
									system("cls");
									goto qlsv;
									break;
								case 0:
									system("cls");// dọn màn hình
									goto tacvuql;// quay lạ
									break;
								default:
									system("cls");
									cout<<"MOI BAN CHON LAI TAC VU\n";
									system("pause");
									system("cls");
									goto qlsv;
							}
							break;
						case 2:// QUẢN LÝ CÁN BỘ
qlcb:
							int qlcb;
							cout<<"========QUAN LY CAN BO=======\n";
							cout<<"---------1.THEM CAN BO-------\n";
							cout<<"---------2.XOA CAN BO--------\n";
							cout<<"---------3.TIM CAN BO--------\n";
							cout<<"---------4. IN DANH SACH-----\n";
							cout<<"====CHON 0 DE QUAY TRO LAI===\n";
							cout<<"==> NHAP SO DE CHON TAC VU: ";
							cin>>qlcb;
							switch(qlcb) {
								case 1:// thêm cán bộ
									HUST.themcanbo();
									system("pause");
									system("cls");
									goto qlcb;
									break;
								case 2:
									HUST.xoacanbo();
									system("pause");
									system("cls");
									goto qlcb;
									break;
								case 3:
									HUST.findinfocb();
									system("pause");
qp:
									int qp;
									cout<<"1. CHINH SUA THONG TIN CAN BO \n";
									cout<<"2. XOA CAN BO NAY \n";
									cout<<"=CHON 0 DE QUAY TRO LAI=======\n";
									cout<<"==> NHAP SO DE CHON TAC VU: ";
									cin>>qp;
									system("cls");
									switch(qp) {
										case 1:
											HUST.chinhsuacbf();
											cout<<"CHINH SUA THONG TIN CAN BO THANH CONG"<<endl;
											system("pause");
											system("cls");
											goto qp;
											break;
										case 2:
											HUST.xoacbf();
											cout<<"XOA CAN BO THANH CONG"<<endl;
											system("pause");
											system("cls");
											goto qp;
										case 0:
											system("cls");// dọn màn hình
											goto qlcb;// quay lạ
											break;
										default:
											system("cls");
											cout<<"MOI BAN CHON LAI TAC VU\n";
											system("pause");
											system("cls");
											goto qp;
									}
									break;
								case 4:// in danh sách cán bộ
									HUST.indanhsachcanbo();
									system("pause");
									system("cls");
									goto qlcb;
									break;
								case 0:
									system("pause");
									system("cls");
									goto tacvuql;
									break;
								default:
									system("cls");
									cout<<"MOI BAN CHON LAI TAC VU\n";
									system("pause");
									system("cls");
									goto qlcb;
							}

							break;
						case 3:// QUẢN LÝ HỌC PHẦN
qlhp:
							int qlhp;
							cout<<"======QUAN LY HOC PHAN======\n";
							cout<<"------1. THEM HOC PHAN------\n";
							cout<<"------2. XOA HOC PHAN-------\n";
							cout<<"------3. TIM HOC PHAN-------\n";
							cout<<"------4. IN DANN SACH-------\n";
							cout<<"===CHON 0 DE QUAY TRO LAI===\n";
							cout<<"==> NHAP SO DE CHON TAC VU: ";
							cin>>qlhp;
							switch(qlhp) {
								case 1:
									HUST.themhocphan();
									system("pause");
									system("cls");
									goto qlhp;
									break;
								case 2:
									HUST.xoahocphan();
									system("pause");
									system("cls");
									goto qlhp;
									break;
								case 3:
									HUST.findhp();
									system("pause");
hpa:
									int hpa;
									cout<<"1. CHINH SUA THONG TIN HOC PHAN \n";
									cout<<"2. XOA HOC PHAN NAY------------ \n";
									cout<<"=CHON 0 DE QUAY TRO LAI========\n";
									cout<<"==> NHAP SO DE CHON TAC VU: ";
									cin>>hpa;
									system("cls");
									switch(hpa) {
										case 1:
											HUST.chinhsuahpf();
											cout<<"CHINH SUA THONG TIN HOC PHAN THANH CONG"<<endl;
											system("pause");
											system("cls");
											goto hpa;
											break;
										case 2:
											HUST.xoahpf();
											cout<<"XOA HOC PHAN THANH CONG"<<endl;
											system("pause");
											system("cls");
											goto qlhp;
										case 0:
											system("cls");// dọn màn hình
											goto qlhp;// quay lạ
											break;
										default:
											system("cls");
											cout<<"MOI BAN CHON LAI TAC VU\n";
											system("pause");
											system("cls");
											goto hpa;
									}
									break;
								case 4:
									HUST.indanhsachhocphan();
									system("pause");
									system("cls");
									goto qlhp;
									break;
								case 0:
									system("pause");
									system("cls");
									goto tacvuql;
									break;
								default:
									system("cls");
									cout<<"MOI BAN CHON LAI TAC VU\n";
									system("pause");
									system("cls");
									goto qlhp;
							}
							break;
						case 4:// QUẢN LÝ LỚP HỌC PHẦN
qllhp:
							int qllhp;
							cout<<"======QUAN LY LOP HOC PHAN======\n";
							cout<<"-------1.LUA CHON HOC PHAN------\n";
							cout<<"====CHON 0 DE QUAY TRO LAI======\n";
							cout<<"==> NHAP SO DE CHON TAC VU: ";
							cin>>qllhp;
							switch(qllhp) {
								case 1:
									HUST.findhp();
ppp:
									int ppp;
									cout<<"-----1. THEM LOP--------\n";
									cout<<"-----2. XOA LOP---------\n";
									cout<<"-----3. TIM LOP---------\n";
									cout<<"-----4. IN DANH SACH----\n";
									cout<<"=CHON 0 DE QUAY TRO LAI=\n";
									cout<<"==> NHAP SO DE CHON TAC VU: ";
									cin>>ppp;
									system("cls");
									switch(ppp) {
										case 1:
											HUST.themlophocphanf();
											system("pause");
											system("cls");
											goto ppp;
											break;
										case 2:
											HUST.xoalophocphanf();
											system("pause");
											system("cls");
											goto ppp;
											break;
										case 3:
											HUST.timlophpf();
											system("pause");
lhpa:
											int lhpa;
											cout<<"1. CHINH SUA THONG TIN LOP HOC PHAN \n";
											cout<<"2. XOA LOP HOC PHAN NAY------------ \n";
											cout<<"=CHON 0 DE QUAY TRO LAI========\n";
											cout<<"==> NHAP SO DE CHON TAC VU: ";
											cin>>lhpa;
											system("cls");
											switch(lhpa) {
												case 1:
													HUST.chinhsualophpf();
													system("pause");
													system("cls");
													goto lhpa;
													break;
												case 2:
													HUST.xoalophocphanf();
													system("pause");
													system("cls");
													goto ppp;
												case 0:
													system("cls");// dọn màn hình
													goto ppp;// quay lạ
													break;
												default:
													system("cls");
													cout<<"MOI BAN CHON LAI TAC VU\n";
													system("pause");
													system("cls");
													goto lhpa;
											}
											break;
										case 4:// in danh sách lop của học phần đang tìm
											HUST.indanhsachlophpf();
											system("pause");
											system("cls");
											goto ppp;
											break;
										case 0:
											system("cls");// dọn màn hình
											goto qllhp;// quay lạ
											break;
										default:
											system("cls");
											cout<<"MOI BAN CHON LAI TAC VU\n";
											system("pause");
											system("cls");
											goto ppp;
									}
									break;
								case 0:
									system("cls");// dọn màn hình
									goto tacvuql;// quay lạ
									break;
								default:
									goto qllhp;
							}
							break;
						case 0:
							//quay lai trang truoc
							system("cls");// dọn màn hình
							goto t;// quay lạ
							break;
						default:
							//hien thi yeu cau nhap lai tac vu
							system("cls");
							cout<<"MOI BAN CHON LAI TAC VU\n";
							system("pause");
							system("cls");
							goto tacvuql;
					}

					break;
				default:// khi nhập sai mã quản lí
					cout<<"MA QUAN LI KHONG CHINH XAC YEU CAU NHAP LAI!";
					system("pause");
					system("cls");
					goto rt;
			}
			break;
		case 0://thoat chuong trinh
			cout<<"CAM ON BAN DA SU DUNG"<<endl;
			system("pause");

			break;
		default:// nhập sai số, yêu cầu nhập lại
			cout<<"MOI BAN CHON LAI TAC VU \n";
			system("pause");
			system("cls");
			goto t;
	}
	return 0;
}
