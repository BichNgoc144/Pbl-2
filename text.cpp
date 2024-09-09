#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_set>

using namespace std;

// Lớp cơ sở: Person
class Person {
protected:
    string hoTen;
    string boPhan; // Khoa, lớp hoặc vị trí công tác
    int namSinh;
    string gioiTinh;
    string diaChi;
    string soDienThoai;

public:
    Person(string ten, string bp, int ns, string gt, string dc, string sdt)
        : hoTen(ten), boPhan(bp), namSinh(ns), gioiTinh(gt), diaChi(dc), soDienThoai(sdt) {}

    virtual bool xetKhenThuong() = 0; // Phương thức ảo xét khen thưởng

    string getHoTen() { return hoTen; }
    string getBoPhan() { return boPhan; }

    virtual void hienThi() = 0; // Phương thức ảo để hiển thị thông tin cá nhân

    virtual ~Person() {} // Destructor ảo
};

// Lớp dẫn xuất: SinhVien
class SinhVien : public Person {
private:
    float diemTBC; // Điểm trung bình tích lũy
    float diemRenLuyen; // Điểm rèn luyện
    int soTinChi; // Số tín chỉ đã hoàn thành
    string chuyenNganh; // Chuyên ngành của sinh viên
    string truong; // Trường đại học/cao đẳng

public:
    SinhVien(string ten, string bp, int ns, string gt, string dc, string sdt,
             float dtbc, float drl, int stc, string cn, string trg)
        : Person(ten, bp, ns, gt, dc, sdt), diemTBC(dtbc), diemRenLuyen(drl),
          soTinChi(stc), chuyenNganh(cn), truong(trg) {}

    bool xetKhenThuong() override {
        // Điều kiện khen thưởng: Điểm TBC >= 8.0 và Điểm rèn luyện >= 85
        return diemTBC >= 8.0 && diemRenLuyen >= 85;
    }

    void hienThi() override {
        cout << "Sinh Viên - Họ tên: " << hoTen << ", Năm sinh: " << namSinh << ", Giới tính: " << gioiTinh
             << ", Điểm TBC: " << diemTBC << ", Điểm rèn luyện: " << diemRenLuyen << ", Số tín chỉ: " << soTinChi 
             << ", Chuyên ngành: " << chuyenNganh << ", Trường: " << truong << endl;
    }
};

// Lớp dẫn xuất: GiangVien
class GiangVien : public Person {
private:
    string khoa; // Khoa đang công tác
    string viTri; // Vị trí công tác
    string thanhTuu; // Thành tựu nghiên cứu
    int soNamGiangDay; // Số năm giảng dạy
    string hocVi; // Học vị (Thạc sĩ, Tiến sĩ, v.v.)
    int soLuongCongTrinh; // Số lượng công trình nghiên cứu đã hoàn thành
    string truongBoMon; // Bộ môn thuộc trường

public:
    GiangVien(string ten, string bp, int ns, string gt, string dc, string sdt,
              string k, string vt, string tt, int sny, string hv, int slct, string tbm)
        : Person(ten, bp, ns, gt, dc, sdt), khoa(k), viTri(vt), thanhTuu(tt),
          soNamGiangDay(sny), hocVi(hv), soLuongCongTrinh(slct), truongBoMon(tbm) {}

    bool xetKhenThuong() override {
        // Điều kiện khen thưởng: Có ít nhất 5 công trình nghiên cứu
        return soLuongCongTrinh >= 5;
    }

    void hienThi() override {
        cout << "Giảng Viên - Họ tên: " << hoTen << ", Năm sinh: " << namSinh << ", Giới tính: " << gioiTinh
             << ", Khoa: " << khoa << ", Vị trí: " << viTri << ", Thành tựu: " << thanhTuu
             << ", Số năm giảng dạy: " << soNamGiangDay << ", Học vị: " << hocVi 
             << ", Số công trình: " << soLuongCongTrinh << ", Trường bộ môn: " << truongBoMon << endl;
    }
};

// Lớp dẫn xuất: QuanLy
class QuanLy : public Person {
private:
    string viTri; // Vị trí công tác
    string noLuc; // Nỗ lực được ghi nhận
    int soNamCongTac; // Số năm công tác trong ngành
    string phongBan; // Phòng ban trực thuộc
    string trinhDo; // Trình độ chuyên môn
    int soLuongDuAn; // Số lượng dự án đã hoàn thành hoặc đang quản lý

public:
    QuanLy(string ten, string bp, int ns, string gt, string dc, string sdt,
           string vt, string nl, int snct, string pb, string td, int slda)
        : Person(ten, bp, ns, gt, dc, sdt), viTri(vt), noLuc(nl), soNamCongTac(snct),
          phongBan(pb), trinhDo(td), soLuongDuAn(slda) {}

    bool xetKhenThuong() override {
        // Điều kiện khen thưởng: Có ít nhất 3 dự án thành công và trên 10 năm công tác
        return soLuongDuAn >= 3 && soNamCongTac >= 10;
    }

    void hienThi() override {
        cout << "Quản Lý - Họ tên: " << hoTen << ", Năm sinh: " << namSinh << ", Giới tính: " << gioiTinh
             << ", Vị trí: " << viTri << ", Nỗ lực: " << noLuc << ", Số năm công tác: " << soNamCongTac
             << ", Phòng ban: " << phongBan << ", Trình độ: " << trinhDo 
             << ", Số dự án: " << soLuongDuAn << endl;
    }
};

// Danh sách khen thưởng
vector<Person*> danhSachKhenThuong;

// Hàm thêm người vào danh sách khen thưởng
void themNguoiKhenThuong(Person* person) {
    if (person->xetKhenThuong()) {
        danhSachKhenThuong.push_back(person);
    }
}

// Hàm thống kê mức thưởng từng cá nhân
void thongKeMucThuong() {
    cout << "Danh sách cá nhân được khen thưởng:" << endl;
    for (Person* person : danhSachKhenThuong) {
        person->hienThi(); // Hiển thị thông tin cá nhân
    }
}

// Hàm đọc dữ liệu từ file cho SinhVien
void docDuLieuTuFileSinhVien(const string& tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cerr << "Không thể mở file: " << tenFile << endl;
        return;
    }

    string line;
    unordered_set<string> daXem; // Tập hợp để kiểm tra dữ liệu đã được xử lý

    while (getline(file, line)) {
        stringstream ss(line);
        string stt, ten, gt, ns_str, bp, drl_str, dtbc_str, stc_str, lop, khoa;
        float dtbc, drl;
        int ns, stc;

        // Đọc dữ liệu từ dòng và phân tách bằng ký tự '|'
        getline(ss, stt, '|');
        ss.ignore();
        getline(ss, ten, '|');
        ss.ignore();
        getline(ss, gt, '|');
        ss.ignore();
        getline(ss, ns_str, '|');
        ss.ignore();
        ss >> dtbc >> drl >> stc;
        ss.ignore(); // Bỏ qua ký tự phân cách
        getline(ss, lop, '|');
        ss.ignore();
        getline(ss, khoa);

        // Chuyển đổi ngày sinh từ chuỗi sang số nguyên
        ns = stoi(ns_str);
        dtbc = stof(dtbc_str);
        drl = stof(drl_str);
        stc = stoi(stc_str);

        // Tạo đối tượng SinhVien
        SinhVien* sv = new SinhVien(ten, lop, ns, gt, "", "", dtbc, drl, stc, "", khoa);

        // Kiểm tra xem dữ liệu đã được xử lý chưa
        if (daXem.find(ten) == daXem.end()) {
            daXem.insert(ten);
            sv->hienThi(); // Hiển thị thông tin sinh viên
            themNguoiKhenThuong(sv);
        } else {
            delete sv; // Xóa đối tượng nếu đã được xử lý
        }
    }

    file.close();
}

// Hàm đọc dữ liệu từ file cho GiangVien
void docDuLieuTuFileGiangVien(const string& tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cerr << "Không thể mở file: " << tenFile << endl;
        return;
    }

    string line;
    unordered_set<string> daXem; // Tập hợp để kiểm tra dữ liệu đã được xử lý

    while (getline(file, line)) {
        stringstream ss(line);
        string stt, ten, bp, gt, dc, sdt, khoa, vt, tt, hv, tbm;
        int ns, sny, slct;

        // Đọc dữ liệu từ dòng và phân tách bằng ký tự '|'
        getline(ss, stt, '|');
        getline(ss, ten, '|');
        getline(ss, bp, '|');
        getline(ss, gt, '|');
        getline(ss, dc, '|');
        getline(ss, sdt, '|');
        getline(ss, khoa, '|');
        getline(ss, vt, '|');
        getline(ss, tt, '|');
        ss >> sny;
        ss.ignore(); // Bỏ qua ký tự phân cách
        getline(ss, hv, '|');
        ss >> slct;
        ss.ignore();
        getline(ss, tbm);

        // Tạo đối tượng GiangVien
        GiangVien* gv = new GiangVien(ten, bp, ns, gt, dc, sdt, khoa, vt, tt, sny, hv, slct, tbm);

        // Kiểm tra xem dữ liệu đã được xử lý chưa
        if (daXem.find(ten) == daXem.end()) {
            daXem.insert(ten);
            gv->hienThi(); // Hiển thị thông tin giảng viên
            themNguoiKhenThuong(gv);
        } else {
            delete gv; // Xóa đối tượng nếu đã được xử lý
        }
    }

    file.close();
}

// Hàm đọc dữ liệu từ file cho QuanLy
void docDuLieuTuFileQuanLy(const string& tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cerr << "Không thể mở file: " << tenFile << endl;
        return;
    }

    string line;
    unordered_set<string> daXem; // Tập hợp để kiểm tra dữ liệu đã được xử lý

    while (getline(file, line)) {
        stringstream ss(line);
        string stt, ten, bp, gt, dc, sdt, vt, noLuc, phongBan, trinhDo;
        int ns, snct, slda;

        // Đọc dữ liệu từ dòng và phân tách bằng ký tự '|'
        getline(ss, stt, '|');
        getline(ss, ten, '|');
        getline(ss, bp, '|');
        getline(ss, gt, '|');
        getline(ss, dc, '|');
        getline(ss, sdt, '|');
        getline(ss, vt, '|');
        getline(ss, noLuc, '|');
        ss >> snct >> slda;
        ss.ignore(); // Bỏ qua ký tự phân cách
        getline(ss, phongBan, '|');
        getline(ss, trinhDo);

        // Tạo đối tượng QuanLy
        QuanLy* ql = new QuanLy(ten, bp, ns, gt, dc, sdt, vt, noLuc, snct, phongBan, trinhDo, slda);

        // Kiểm tra xem dữ liệu đã được xử lý chưa
        if (daXem.find(ten) == daXem.end()) {
            daXem.insert(ten);
            ql->hienThi(); // Hiển thị thông tin quản lý
            themNguoiKhenThuong(ql);
        } else {
            delete ql; // Xóa đối tượng nếu đã được xử lý
        }
    }

    file.close();
}

// Hàm chọn loại đối tượng và đọc file tương ứng
void chonLoaiDoiTuong() {
    int choice;
    string tenFile;
    cout << "Chọn loại đối tượng cần nhập:\n";
    cout << "1. Sinh viên\n";
    cout << "2. Giảng viên\n";
    cout << "3. Quản lý\n";
    cout << "Nhập lựa chọn: ";
    cin >> choice;

    cout << "Nhập tên file chứa dữ liệu: ";
    cin >> tenFile;

    int retries = 3;
    while (retries > 0) {
        if (choice == 1) {
            docDuLieuTuFileSinhVien(tenFile);
            break;
        } else if (choice == 2) {
            docDuLieuTuFileGiangVien(tenFile);
            break;
        } else if (choice == 3) {
            docDuLieuTuFileQuanLy(tenFile);
            break;
        } else {
            cout << "Lựa chọn không hợp lệ. Hãy thử lại." << endl;
        }
        retries--;
        if (retries > 0) {
            cout << "Nhập tên file chứa dữ liệu: ";
            cin >> tenFile;
        }
    }
    if (retries == 0) {
        cout << "Bạn đã hết lượt nhập." << endl;
    }
}

int main() {
    // Cho phép người dùng chọn loại đối tượng và nhập dữ liệu
    chonLoaiDoiTuong();

    // Hiển thị danh sách khen thưởng
    thongKeMucThuong();

    return 0;
}
