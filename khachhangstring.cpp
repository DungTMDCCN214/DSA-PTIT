#include<bits/stdc++.h>

using namespace std;

class KhachHang {
	private:
		string ma,ten,dc,sdt,email;
	public:
		KhachHang(string ma, string ten, string dc, string sdt, string email){
			this->ma = ma;
			this->ten = ten;
			this->dc = dc;
			this->sdt = sdt;
			this->email = email;
		}
		void in(){
			cout<<ma<<" "<<ten<<" "<<dc<<" "<<sdt<<" "<<email<<endl;
		}
};

int main() {
	string ma, ten, dc, sdt, email;
	getline(cin,ma);
	getline(cin,ten);
	getline(cin,dc);
	getline(cin,sdt);
	getline(cin,email);
	KhachHang s(ma,ten,dc,sdt,email);
	s.in();
	return 0;
}

