#include<bits/stdc++.h>

using namespace std;


class SinhVien{
	private:
		string id, ten, ns;
		double gpa;
	public:
		SinhVien(); //Ham khoi tao;
		SinhVien(string, string, string, double);
		void xinchao();
		void dihoc();
};

SinhVien::SinhVien(string ma, string name, string birth, double diem){
	cout<<"Ham khoi tao co tham so duoc goi\n";
	id=ma;
	ten=name;
	ns=birth;
	gpa=diem;
}

SinhVien::SinhVien(){
	id=ten=ns="";
	gpa=0;
}
void SinhVien::xinchao(){
	cout<<"Hello !\n";
}

void SinhVien::dihoc(){
	cout<<"Di hoc !\n";
}
int main() {
	SinhVien x("123", "Nguyen Van A", "23/12/2003", 3.14);
	x.dihoc();
	x.xinchao();
	return 0;
}

