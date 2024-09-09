#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Person {
protected:
    string hoTen;
    string boPhan; 
    int namSinh;
    string gioiTinh;
    string diaChi;
    string soDienThoai;

public:
    Person(string ten, string bp, int ns, string gt, string dc, string sdt)
        : hoTen(ten), boPhan(bp), namSinh(ns), gioiTinh(gt), diaChi(dc), soDienThoai(sdt) {}

    virtual bool xetKhenThuong() = 0;

    string getHoTen() { return hoTen; }
    string getBoPhan() { return boPhan; }

    virtual ~Person() {} 
};

class SinhVien : public Person {
private:
    float diemTBC; 
    float diemRenLuyen; 
    int soTinChi; 
    string chuyenNganh; 
    string truong; 
public:
    SinhVien(string ten, string bp, int ns, string gt, string dc, string sdt,
             float dtbc, float drl, int stc, string cn, string trg)
        : Person(ten, bp, ns, gt, dc, sdt), diemTBC(dtbc), diemRenLuyen(drl),
          soTinChi(stc), chuyenNganh(cn), truong(trg) {}

    bool xetKhenThuong() override {
        return diemTBC >= 8.0 && diemRenLuyen >= 85;
    }
};

class GiangVien : public Person {
private:
    string khoa; 
    string viTri; 
    string thanhTuu; 
    int soNamGiangDay; 
    string hocVi; 
    int soLuongCongTrinh; 
    string truongBoMon; 

public:
    GiangVien(string ten, string bp, int ns, string gt, string dc, string sdt,
              string k, string vt, string tt, int sny, string hv, int slct, string tbm)
        : Person(ten, bp, ns, gt, dc, sdt), khoa(k), viTri(vt), thanhTuu(tt),
          soNamGiangDay(sny), hocVi(hv), soLuongCongTrinh(slct), truongBoMon(tbm) {}

    bool xetKhenThuong() override {
        return soLuongCongTrinh >= 5;
    }
};

class QuanLy : public Person {
private:
    string viTri;
    string noLuc; 
    int soNamCongTac; 
    string phongBan; 
    string trinhDo; 
    int soLuongDuAn; 

public:
    QuanLy(string ten, string bp, int ns, string gt, string dc, string sdt,
           string vt, string nl, int snct, string pb, string td, int slda)
        : Person(ten, bp, ns, gt, dc, sdt), viTri(vt), noLuc(nl), soNamCongTac(snct),
          phongBan(pb), trinhDo(td), soLuongDuAn(slda) {}

    bool xetKhenThuong() override {
        return soLuongDuAn >= 3 && soNamCongTac >= 10;
    }
};

vector<Person*> danhSachKhenThuong;

void themNguoiKhenThuong(Person* person) {
    if (person->xetKhenThuong()) {
        danhSachKhenThuong.push_back(person);
    }
}

void thongKeMucThuong() {
    cout << "Danh sách các cá nhân được khen thưởng:" << endl;
    for (Person* person : danhSachKhenThuong) {
        cout << "Họ tên: " << person->getHoTen() << ", Bộ phận: " << person->getBoPhan() << endl;
    }
}

void nhap(char filename[]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Không thể mở file. Vui lòng kiểm tra tên file và thử lại." << endl;
        return;
    }

    string ten, bp, gt, dc, sdt, chuyenNganh, truong, khoa, viTri, thanhTuu, hocVi, truongBoMon, noLuc, phongBan, trinhDo;
    int ns, stc, sny, slct, slda, soNamCongTac;
    float dtbc, drl;

    while (file >> ten >> bp >> ns >> gt >> dc >> sdt >> dtbc >> drl >> stc >> chuyenNganh)  {
        SinhVien* sv = new SinhVien(ten, bp, ns, gt, dc, sdt, dtbc, drl, stc, chuyenNganh);
        themNguoiKhenThuong(sv);
    }

    while (file >> ten >> bp >> ns >> gt >> dc >> sdt >> khoa >> viTri >> thanhTuu >> sny >> hocVi >> slct >> truongBoMon) {
        GiangVien* gv = new GiangVien(ten, bp, ns, gt, dc, sdt, khoa, viTri, thanhTuu, sny, hocVi, slct, truongBoMon);
        themNguoiKhenThuong(gv);
    }

    while (file >> ten >> bp >> ns >> gt >> dc >> sdt >> viTri >> noLuc >> soNamCongTac >> phongBan >> trinhDo >> slda) {
        QuanLy* ql = new QuanLy(ten, bp, ns, gt, dc, sdt, viTri, noLuc, soNamCongTac, phongBan, trinhDo, slda);
        themNguoiKhenThuong(ql);
    }

    file.close();
}

int main() {
    char filename[100];
    cout << "Nhập tên tập tin: ";
    cin >> filename;

    nhap(filename);
    thongKeMucThuong();

    // Giải phóng bộ nhớ
    for (Person* person : danhSachKhenThuong) {
        delete person;
    }
    danhSachKhenThuong.clear();

    return 0;
}
