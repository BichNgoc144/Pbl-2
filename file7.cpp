#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

const int SO_KHOA = 5;
const int SO_LOP_TRONG_KHOA = 3;


class Person {
protected:
    string id;
    string hoTen;
    string boPhan; 
    int namSinh;
    string gioiTinh;
    string diaChi;
    string soDienThoai;

public:
    Person(const string& id, const string& ten, const string& bp, int ns, const string& gt, const string& dc, const string& sdt)
        : id(id), hoTen(ten), boPhan(bp), namSinh(ns), gioiTinh(gt), diaChi(dc), soDienThoai(sdt) {}

    virtual bool xetKhenThuong() const = 0; 
    virtual void hienThi() const = 0; 
    virtual void capNhatThongTin() = 0;

    virtual ~Person() {} 

    string getId () const {
        return id;
    }
    string getHoTen () const {
        return hoTen;
    }
    string getBoPhan () const {
        return boPhan;
    }
};

class SinhVien : public Person {
private:
    float diemTBC;
    float diemRenLuyen;
    int soTinChi;
    string chuyenNganh;
    string truong;

public:
    SinhVien(const string& id, const string& ten, const string& bp, int ns, const string& gt, const string& dc, const string& sdt,
             float dtbc, float drl, int stc, const string& cn, const string& trg)
        : Person(id, ten, bp, ns, gt, dc, sdt), diemTBC(dtbc), diemRenLuyen(drl), soTinChi(stc), chuyenNganh(cn), truong(trg) {}

    bool xetKhenThuong() const override {
        return diemTBC >= 8.0 && diemRenLuyen >= 85;
    }

    void hienThi() const override {
        std::cout << id << std::setw(15) << hoTen << std::setw(25)<< boPhan  << std::setw(15)<< namSinh << std::setw(15)
             << gioiTinh << std::setw(5)<< diemTBC << std::setw(5)<< diemRenLuyen << std::setw(5)
             << soTinChi << std::setw(5)<< chuyenNganh << std::setw(20)<< truong << std::endl;
    }

    int getDiemTBC () const {
        return diemTBC;
    }

    int getDiemRenLuyen () const {
        return diemRenLuyen;
    }

    void capNhatThongTin() override {
    int choice2;
    do {
        std::cout << "\n--- Cập nhật thông tin Sinh viên ---\n";
        std::cout << "1. Tên\n";
        std::cout << "2. Khoa và lớp\n";
        std::cout << "3. Năm sinh\n";
        std::cout << "0. Thoát cập nhật\n";
        std::cout << "Chọn thông tin cần cập nhật (0-9): ";
        std::cin >> choice2;
        std::cin.ignore(); 
        switch (choice2) {
            case 1:
                std::cout << "Nhập tên mới: ";
                std::getline(std::cin, hoTen);
                break;
            case 2:
                std::cout << "Nhập khoa và lớp mới: ";
                std::getline(std::cin, boPhan);
                break;
            case 3:
                std::cout << "Nhập năm sinh mới: ";
                std::cin >> namSinh;
                std::cin.ignore();
                break;
            case 0:
                std::cout << "Thoát cập nhật thông tin.\n";
                break;
            default:
                std::cout << "Lựa chọn không hợp lệ! Vui lòng chọn lại.\n";
        }
    } while (choice2 != 0); }
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
    GiangVien(const string& id, const string& ten, const string& bp, int ns, const string& gt, const string& dc, const string& sdt,
              const string& k, const string& vt, const string& tt, int sny, const string& hv, int slct, const string& tbm)
        : Person(id, ten, bp, ns, gt, dc, sdt), khoa(k), viTri(vt), thanhTuu(tt), soNamGiangDay(sny), hocVi(hv), soLuongCongTrinh(slct), truongBoMon(tbm) {}

    bool xetKhenThuong() const override {
        return soLuongCongTrinh >= 5;
    }

    string getHocVi () const {
        return hocVi;
    }

    void hienThi() const override {
        std::cout << id << std::setw(10) << hoTen << std::setw(25)<< boPhan  << std::setw(10)<< namSinh << std::setw(5)
             << gioiTinh << std::setw(5)<< khoa << std::setw(20)<< viTri << std::setw(15)
             << soNamGiangDay << std::setw(5)<< hocVi << std::setw(15)<< soLuongCongTrinh << std::setw(5)<< truongBoMon << std::endl;
    }

    int getSoNamGiangDay () {
        return soNamGiangDay;
    }

    int getSoLuongCongTrinh () {
        return soLuongCongTrinh;
    }
    
    void capNhatThongTin() override {
    int choice3;
    do {
        std::cout << "\n--- Cập nhật thông tin Giảng viên ---\n";
        std::cout << "1. Tên\n";
        std::cout << "2. Năm sinh\n";
        std::cout << "3. Khoa\n";
        std::cout << "4. Vị trí\n";
        std::cout << "5. Thành tựu\n";
        std::cout << "0. Thoát cập nhật\n";
        std::cout << "Chọn thông tin cần cập nhật (0-10): ";
        std::cin >> choice3;
        std::cin.ignore(); 
        switch (choice3) {
            case 1:
                std::cout << "Nhập tên mới: ";
                std::getline(std::cin, hoTen);
                break;
            case 2:
                std::cout << "Nhập năm sinh mới: ";
                std::cin >> namSinh;
                std::cin.ignore();
                break;
            case 3:
                std::cout << "Nhập khoa mới: ";
                std::getline(std::cin, khoa);
                break;
            case 4:
                std::cout << "Nhập vị trí mới: ";
                std::getline(std::cin, viTri);
                break;
            case 5:
                std::cout << "Nhập thành tựu mới: ";
                std::getline(std::cin, thanhTuu);
                break;
            case 0:
                std::cout << "Thoát cập nhật thông tin.\n";
                break;
            default:
                std::cout << "Lựa chọn không hợp lệ! Vui lòng chọn lại.\n";
        }
    } while (choice3 != 0);
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
    QuanLy(const string& id, const string& ten, const string& bp, int ns, const string& gt, const string& dc, const string& sdt,
           const string& vt, const string& nl, int snct, const string& pb, const string& td, int slda)
        : Person(id, ten, bp, ns, gt, dc, sdt), viTri(vt), noLuc(nl), soNamCongTac(snct), phongBan(pb), trinhDo(td), soLuongDuAn(slda) {}

    bool xetKhenThuong() const override {
        return soLuongDuAn >= 3 && soNamCongTac >= 10;
    }

    string getViTri () const {
        return viTri;
    }
    string getPhongBan () const {
        return phongBan;
    }

    string getNoLuc () const {
        return noLuc;
    }

    int getSoLuongDuAn () const {
        return soLuongDuAn;
    }

    void hienThi() const override {
        std::cout << id << std::setw(7) << hoTen << std::setw(20)<< boPhan  << std::setw(7)<< namSinh << std::setw(5)
             << gioiTinh << std::setw(5)<< viTri << std::setw(5)<< noLuc << std::setw(5)
             << soNamCongTac << std::setw(3)<< phongBan << std::setw(7)<< trinhDo << std::setw(7)<< soLuongDuAn << std::endl;
    }

    void capNhatThongTin() override {
    int choice4;
    do {
        std::cout << "\n--- Cập nhật thông tin Quan Ly---\n";
        std::cout << "1. Tên\n";
        std::cout << "2. Năm sinh\n";
        std::cout << "3. Phòng Ban\n";
        std::cout << "4. Vị trí\n";
        std::cout << "5. Trình Độ\n";
        std::cout << "0. Thoát cập nhật\n";
        std::cout << "Chọn thông tin cần cập nhật (0-10): ";
        std::cin >> choice4;
        std::cin.ignore(); 
        switch (choice4) {
            case 1:
                std::cout << "Nhập tên mới: ";
                std::getline(std::cin, hoTen);
                break;
            case 2:
                std::cout << "Nhập năm sinh mới: ";
                std::cin >> namSinh;
                std::cin.ignore();
                break;
            case 3:
                std::cout << "Nhập khoa mới: ";
                std::getline(std::cin, phongBan);
                break;
            case 4:
                std::cout << "Nhập vị trí mới: ";
                std::getline(std::cin, viTri);
                break;
            case 5:
                std::cout << "Nhập thành tựu mới: ";
                std::getline(std::cin, trinhDo);
                break;
            case 0:
                std::cout << "Thoát cập nhật thông tin.\n";
                break;
            default:
                std::cout << "Lựa chọn không hợp lệ! Vui lòng chọn lại.\n";
        }
    } while (choice4 != 0);
}
};

void docDuLieuTuFile(const string& tenFile, vector<Person*>& danhSach, int loaiNguoi) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        std::cout << "Không thể mở file " << tenFile << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, hoTen, boPhan, gioiTinh, diaChi, soDienThoai;
        int namSinh;
        getline(ss, id, '|');
        getline(ss, hoTen, '|');
        getline(ss, boPhan, '|');
        ss >> namSinh;
        ss.ignore();
        getline(ss, gioiTinh, '|');
        getline(ss, diaChi, '|');
        getline(ss, soDienThoai, '|');

        if (loaiNguoi == 1) {
            float diemTBC, diemRenLuyen;
            int soTinChi;
            string chuyenNganh, truong;
            ss >> diemTBC;
            ss.ignore();
            ss >> diemRenLuyen;
            ss.ignore();
            ss>> soTinChi;
            ss.ignore();
            getline(ss, chuyenNganh, '|');
            getline(ss, truong, '|');
            danhSach.push_back(new SinhVien(id, hoTen, boPhan, namSinh, gioiTinh, diaChi, soDienThoai,
                                             diemTBC, diemRenLuyen, soTinChi, chuyenNganh, truong));
        } else if (loaiNguoi == 2) {
            string khoa, viTri, thanhTuu, hocVi, truongBoMon;
            int soNamGiangDay, soLuongCongTrinh;
            ss.ignore();
            getline(ss, khoa, '|');
            getline(ss, viTri, '|');
            getline(ss, thanhTuu, '|');
            ss >> soNamGiangDay;
            ss.ignore();
            getline(ss, hocVi, '|');
            ss >> soLuongCongTrinh;
            ss.ignore();
            getline(ss, truongBoMon, '|');
            danhSach.push_back(new GiangVien(id, hoTen, boPhan, namSinh, gioiTinh, diaChi, soDienThoai,
                                              khoa, viTri, thanhTuu, soNamGiangDay, hocVi, soLuongCongTrinh, truongBoMon));
        } else if (loaiNguoi == 3) {
            string viTri, noLuc, phongBan, trinhDo;
            int soNamCongTac, soLuongDuAn;
            ss.ignore();
            getline(ss, viTri, '|');
            getline(ss, noLuc, '|');
            ss >> soNamCongTac;
            ss.ignore();
            getline(ss, phongBan, '|');
            getline(ss, trinhDo, '|');
            ss >> soLuongDuAn;
            ss.ignore();
            danhSach.push_back(new QuanLy(id, hoTen, boPhan, namSinh, gioiTinh, diaChi, soDienThoai,
                                           viTri, noLuc, soNamCongTac, phongBan, trinhDo, soLuongDuAn));
        }
    }
    file.close();
}

Person* timKiemTheoID(const vector<Person*>& danhSach, const string& id) {
    for (Person* p : danhSach) {
        if (p->getId() == id) {
            return p;
        }
    }
    return nullptr;
}

void xoaTheoID(vector<Person*>& danhSach, const string& id) {
    for (auto it = danhSach.begin(); it != danhSach.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            danhSach.erase(it);
            cout << "Đã xóa người với ID " << id << endl;
            return;
        }
    }
    cout << "Không tìm thấy người với ID " << id << endl;
}

void hienThiDanhSach(const vector<Person*>& danhSach) {
    int choice1;
    int loai;
    
    cout << "Nhập đối tượng :"<<endl;
    cout << "1.SinhVien"<<endl;
    cout << "2.GiangVien"<<endl;
    cout << "3.QuanLy"<<endl;
    
    cin >> loai;

    if (loai == 1 ) {
        cout << "Chọn chức năng:\n";
        cout << "1. In toàn bộ danh sách\n";
        cout << "2. In danh sách theo khoa\n";
        cout << "3. In danh sách theo lớp\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice1;
        cin.ignore(); 

        switch (choice1) {
            case 1: {
                cout << "Sinh Viên - ID" << ", Họ tên " << ", Khoa và lớp " << ", Năm sinh "<< ", Giới tính " 
                << ", Điểm TBC "<< ", Điểm rèn luyện "<< ", Số tín chỉ "<< ", Chuyên ngành "<< ", Trường ";
                cout<<endl;     
                for (const Person* p : danhSach) {
                    p->hienThi();
                }
                break;
            }
            case 2: {
                string khoa;
                cout << "Nhập tên khoa: ";
                getline(cin, khoa);
                for (const Person* p : danhSach) {
                    if (p->getBoPhan() == khoa) {
                        p->hienThi();
                    }
                }
                break;
            }
            case 3: {
                string lop;
                cout << "Nhập tên lớp: ";
                getline(cin, lop);
                for (const Person* p : danhSach) {
                    if (p->getBoPhan().find(lop) != string::npos) {
                        p->hienThi();
                    }
                }
                break;
            }
            default:
                cout << "Lựa chọn không hợp lệ!\n";
                break;
        }
    } else if (loai == 2) {
        cout << "Chọn chức năng:\n";
        cout << "1. In toàn bộ danh sách\n";
        cout << "2. In danh sách theo khoa\n";
        cout << "3. In danh sách theo học vị\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice1;
        cin.ignore(); 

        switch (choice1) {
            case 1: {
                cout << "Sinh Viên - ID" << ", Họ tên " << ", Khoa và lớp " << ", Năm sinh "<< ", Giới tính " 
             << ", Điểm TBC "<< ", Điểm rèn luyện "<< ", Số tín chỉ "<< ", Chuyên ngành "<< ", Trường ";     
               
                for (const Person* p : danhSach) {
                    p->hienThi();
                }
                break;
            }
            case 2: {
                string khoa;
                cout << "Nhập tên khoa: ";
                getline(cin, khoa);
                for (const Person* p : danhSach) {
                    if (p->getBoPhan() == khoa) {
                        p->hienThi();
                    }
                }
                break;
            }
            case 3: {
                string hocVi;
                cout << "Nhập học vị: ";
                getline(cin, hocVi);
                for (const Person* p : danhSach) {
                    const GiangVien* gv = dynamic_cast<const GiangVien*>(p);
                    if (gv && gv->getHocVi() == hocVi) {
                        gv->hienThi();
                    }
                }
                break;
            }
            default:
                cout << "Lựa chọn không hợp lệ!\n";
                break;
        }
    } else if (loai == 3) {
        cout << "Chọn chức năng:\n";
        cout << "1. In toàn bộ danh sách\n";
        cout << "2. In danh sách theo vị trí\n";
        cout << "3. In danh sách theo phòng ban\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice1;
        cin.ignore(); 

        switch (choice1) {
            case 1: {
                for (const Person* p : danhSach) {
                    p->hienThi();
                }
                break;
            }
            case 2: {
                string viTri;
                cout << "Nhập vị trí: ";
                getline(cin, viTri);
                for (const Person* p : danhSach) {
                    const QuanLy* ql = dynamic_cast<const QuanLy*>(p);
                    if (ql && ql->getViTri() == viTri) {
                        ql->hienThi();
                    }
                }
                break;
            }
            case 3: {
                string phongBan;
                cout << "Nhập trình độ: ";
                getline(cin, phongBan);
                for (const Person* p : danhSach) {
                    const QuanLy* ql = dynamic_cast<const QuanLy*>(p);
                    if (ql && ql->getPhongBan() == phongBan) {
                        ql->hienThi();
                    }
                }
                break;
            }
            default:
                cout << "Lựa chọn không hợp lệ!\n";
                break;
        }
    } else {
        cout << "Lựa chọn không hợp lệ!\n";
    }
}

void capNhatThongTinTheoID(vector<Person*>& danhSach, const string& id) {
    Person* p = timKiemTheoID(danhSach, id);
    if (p) {
        p->capNhatThongTin();
    } else {
        cout << "Không tìm thấy người với ID " << id << endl;
    }
}

bool idHopLe(const vector<Person*>& danhSach, const string& id) {
    return timKiemTheoID(danhSach, id) == nullptr;
}

void themNguoiMoi(vector<Person*>& danhSach) {
    string id, hoTen, boPhan, gioiTinh, diaChi, soDienThoai;
    int namSinh;
    string loai;
    cout << "Nhập đối tượng (SinhVien/GiangVien/QuanLy): ";
    getline(cin, loai);
    cout << "Nhập ID: ";
    getline(cin, id);

    if (!idHopLe(danhSach, id)) {
        cout << "ID đã tồn tại. Vui lòng nhập lại.\n";
        return;
    }

    cout << "Nhập tên: ";
    getline(cin, hoTen);
    cout << "Nhập lớp: ";
    getline(cin, boPhan);
    cout << "Nhập năm sinh: ";
    cin >> namSinh;
    cin.ignore(); 
    cout << "Nhập giới tính: ";
    getline(cin, gioiTinh);
    cout << "Nhập địa chỉ: ";
    getline(cin, diaChi);
    cout << "Nhập số điện thoại: ";
    getline(cin, soDienThoai);

    if (loai == "SinhVien"|| loai == "sv") {
        float diemTBC, diemRenLuyen;
        int soTinChi;
        string chuyenNganh, truong;
        cout << "Nhập điểm TBC: ";
        cin >> diemTBC;
        cout << "Nhập điểm rèn luyện: ";
        cin >> diemRenLuyen;
        cout << "Nhập số tín chỉ: ";
        cin >> soTinChi;
        cin.ignore(); 
        cout << "Nhập chuyên ngành: ";
        getline(cin, chuyenNganh);
        cout << "Nhập trường: ";
        getline(cin, truong);
        danhSach.push_back(new SinhVien(id, hoTen, boPhan, namSinh, gioiTinh, diaChi, soDienThoai,
                                         diemTBC, diemRenLuyen, soTinChi, chuyenNganh, truong));
    } else if (loai == "GiangVien"|| loai == "gv") {
        string khoa, viTri, thanhTuu, hocVi, truongBoMon;
        int soNamGiangDay, soLuongCongTrinh;
        cout << "Nhập khoa: ";
        getline(cin, khoa);
        cout << "Nhập vị trí: ";
        getline(cin, viTri);
        cout << "Nhập thành tựu: ";
        getline(cin, thanhTuu);
        cout << "Nhập số năm giảng dạy: ";
        cin >> soNamGiangDay;
        cout << "Nhập học vị: ";
        cin.ignore(); 
        getline(cin, hocVi);
        cout << "Nhập số công trình: ";
        cin >> soLuongCongTrinh;
        cin.ignore(); 
        cout << "Nhập trưởng bộ môn: ";
        getline(cin, truongBoMon);
        danhSach.push_back(new GiangVien(id, hoTen, boPhan, namSinh, gioiTinh, diaChi, soDienThoai,
                                          khoa, viTri, thanhTuu, soNamGiangDay, hocVi, soLuongCongTrinh, truongBoMon));
    } else if (loai == "QuanLy"|| loai == "ql") {
        string viTri, noLuc, phongBan, trinhDo;
        int soNamCongTac, soLuongDuAn;
        cout << "Nhập vị trí: ";
        getline(cin, viTri);
        cout << "Nhập nỗ lực: ";
        getline(cin, noLuc);
        cout << "Nhập số năm công tác: ";
        cin >> soNamCongTac;
        cout << "Nhập phòng ban: ";
        cin.ignore(); 
        getline(cin, phongBan);
        cout << "Nhập trình độ: ";
        getline(cin, trinhDo);
        cout << "Nhập số dự án: ";
        cin >> soLuongDuAn;
        danhSach.push_back(new QuanLy(id, hoTen, boPhan, namSinh, gioiTinh, diaChi, soDienThoai,
                                       viTri, noLuc, soNamCongTac, phongBan, trinhDo, soLuongDuAn));
    } else {
        cout << "Đối tượng không hợp lệ.\n";
    }
}

void thongKeMucThuong(const std::vector<Person*>& danhSachKhenThuong, const std::string& fileName) {
    double tongTienThuong = 0;
    ofstream outFile(fileName);  
    if (!outFile) {
        cerr << "Không thể mở tệp để ghi: " << fileName << std::endl;
        return;
    }

    outFile << "--- Thống kê mức thưởng ---\n";

    cout << "\n--- Thống kê mức thưởng ---\n";
    
    for (const auto& person : danhSachKhenThuong) {
        double mucThuong = 0;
        
        if (SinhVien* sv = dynamic_cast<SinhVien*>(person)) {
            if (sv->getDiemTBC() >= 8.0 && sv->getDiemRenLuyen() >= 8.5) {
                mucThuong = 5; 
            } else if (sv->getDiemTBC() >= 7.0 && sv->getDiemRenLuyen() >= 7.0) {
                mucThuong = 3; 
            }
            outFile << "Sinh viên: " << sv->getHoTen() 
                     << " - Mức thưởng: " << fixed << setprecision(0) << mucThuong << " trieu VND\n";
            cout << "Sinh viên: " << sv->getHoTen() 
                      << " - Mức thưởng: " << mucThuong << " trieu VND\n";
        }
        
        else if (GiangVien* gv = dynamic_cast<GiangVien*>(person)) {
            if (gv->getSoNamGiangDay() > 5 && gv->getSoLuongCongTrinh() >= 3) {
                mucThuong = 10; 
            } else if (gv->getSoNamGiangDay() <= 5 && gv->getSoLuongCongTrinh() >= 2) {
                mucThuong = 7; 
            }
            outFile << "Giảng viên: " << gv->getHoTen() 
                     << " - Mức thưởng: " << fixed << setprecision(0) << mucThuong << " trieu VND\n";
            cout << "Giảng viên: " << gv->getHoTen() 
                      << " - Mức thưởng: " << mucThuong << " trieu VND\n";
        }

        else if (QuanLy* ql = dynamic_cast<QuanLy*>(person)) {
            if (ql->getNoLuc() == "Xuất sắc" && ql->getSoLuongDuAn() >= 5) {
                mucThuong = 10; 
            } else if (ql->getNoLuc() == "Tốt" && ql->getSoLuongDuAn()>= 3) {
                mucThuong = 7; 
            }
            outFile << "Quản lý: " << ql->getHoTen() 
                     << " - Mức thưởng: " << fixed << setprecision(0) << mucThuong << " trieu VND\n";
            std::cout << "Quản lý: " << ql->getHoTen() 
                      << " - Mức thưởng: " << mucThuong << " trieu VND\n";
        }

        tongTienThuong += mucThuong;
    }

    outFile << "Tổng tiền thưởng: " << fixed << setprecision(0) << tongTienThuong << " trieu VND\n"; 
    outFile.close();
    
    std::cout << "\nTổng số tiền thưởng: " << tongTienThuong << " trieu VND\n";
}


void menu(){
        cout << "1. Đọc dữ liệu từ file \n";
        cout << "2. Tìm người theo ID\n";
        cout << "3. Xóa người theo ID\n";
        cout << "4. Cập nhật thông tin người theo ID\n";
        cout << "5. Hiển thị danh sách người\n";
        cout << "6. Thêm người mới\n";
        cout << "7. In ra menu\n";
        cout << "8. Thống kê mức thưởng\n";
        cout << "9. Thoát chương trình\n";
}

int main() {
    vector<Person*> danhSach;
    int choice;int choice1;int choice2;int choice3;int choice4;
    string tenFile;
    cout<<setw(5) << "Chương trình xét học bổng và giải thưởng:\n";
        cout << "1. Đọc dữ liệu từ file \n";
        cout << "2. Tìm người theo ID\n";
        cout << "3. Xóa người theo ID\n";
        cout << "4. Cập nhật thông tin người theo ID\n";
        cout << "5. Hiển thị danh sách người\n";
        cout << "6. Thêm người mới\n";
        cout << "7. In ra menu\n";
        cout << "8. Thống kê mức thưởng\n";
        cout << "9. Thoát chương trình\n";

    while (true) {
        cout << "Chọn chức năng :";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: 
                int loaiNguoi;
                cout << "1.Sinh Viên"<<endl;
                cout << "2.Giảng Viên" <<endl;
                cout << "3.Quản Lý" <<endl;
                cout << "Chọn đối tượng :";
                cin >> loaiNguoi;
                cin.ignore ();
                cout << "Nhập tên file đầu vào: ";
                getline(cin, tenFile);
                cin.ignore ();
                docDuLieuTuFile(tenFile, danhSach, loaiNguoi);
                break;
            case 2: 
                cout << "Nhập ID để tìm: ";
                getline(cin, tenFile);
                {
                    Person* p = timKiemTheoID(danhSach, tenFile);
                    if (p) {
                        p->hienThi();
                    } else {
                        cout << "Không tìm thấy người với ID " << tenFile << endl;
                    }
                }
                break;

            case 3: 
                cout << "Nhập ID để xóa: ";
                getline(cin, tenFile); 
                xoaTheoID(danhSach, tenFile);
                break;
  
            case 4: 
                cout << "Nhập ID để cập nhật: ";
                getline(cin, tenFile); 
                capNhatThongTinTheoID(danhSach, tenFile);
                break;

            case 5: 
                hienThiDanhSach(danhSach);
                break;

            case 6: 
                themNguoiMoi(danhSach);
                break;
            case 7:
                menu();
                break;
            case 8 :
                thongKeMucThuong(danhSach, "kq.txt");
                break;
            case 9: 
                for (Person* p : danhSach) {
                    delete p;
                }
                danhSach.clear();
                cout << "Đã thoát chương trình.\n";
                return 0;
            default:
                cout << "Lựa chọn không hợp lệ, vui lòng chọn lại.\n";
                break;
        }
    }
}

// các lỗi trong chương trình:
// - Chưa check được dữ liệu khi cập nhật lại thông tin và khi thêm người mới.
// (nhập dữ liệu sai vẫn chấp nhận-> cần có exception)
//-> phải có ràng buộc khi nhập dữ liệu đặc biệt là id
// - Cần định dạng lại dữ liệu khi in ra danh sách
// - Chức năng thống kê khi đọc vào file gv nhưng khi thống kê dữ liệu sv vẫn in ra 


/*
- Chưa in ra theo phân loại(không theo khoa nhưng theo được lớp).
- Hàm thống kê khen thưởng.
- Check lỗi với dữ liệu.
- Chưa đọc file của giảng viên,quản lý.
- Coi lại chức năng số 6.
- Chua co ham xuat file.    
*/



