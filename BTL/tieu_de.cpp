#include "person.cpp"

void menu_chon(){
    cout << endl;
    cout << '|' << setfill('=') << setw(29) << "MENU" << setw(26) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(48) << "\t1. Nhap danh sach benh nhan va bac sy" << '|' << endl;
    cout << '|' << setw(48) << "\t2. Xuat danh sach benh nhan da nhap" << '|' << endl;
    cout << '|' << setw(48) << "\t3. Xuat danh sach bac sy da nhap" << '|' << endl;
    cout << '|' << setw(48) << "\t4. Xuat danh sach benh nhan noi tru" << '|' << endl;
    cout << '|' << setw(48) << "\t5. Xuat danh sach benh nhan ngoai tru" << '|' << endl;
    cout << '|' << setw(48) << "\t6. Xuat danh sach don thuoc cua moi benh nhan" << '|' << endl;
    cout << '|' << setw(48) << "\t7. Xuat danh sach dich vu benh nhan da dung" << '|' << endl;
    cout << '|' << setw(48) << "\t8. Xuat hoa don thanh toan" << '|' << endl;
    cout << '|' << setw(48) << "\t9. Them benh nhan hoac bac sy" << '|' << endl;
    cout << '|' << setw(48) << "\t10. Them don thuoc cua benh nhan" << '|' << endl;
    cout << '|' << setw(48) << "\t11. Them dich vu cua benh nhan" << '|' << endl;
    cout << '|' << setw(48) << "\t12. Xoa benh nhan hoac bac sy" << '|' << endl;
    cout << '|' << setw(48) << "\t13. Xoa don thuoc hoac dich vu" << '|' << endl;
    cout << '|' << setw(48) << "\t14. Sap xep danh sach bac sy" << '|' << endl;
    cout << '|' << setw(48) << "\t15. Sap xep danh sach benh nhan" << '|' << endl;
    cout << '|' << setw(48) << "\t16. Sua thong tin benh nhan hoac bac sy" << '|' << endl;
    cout << '|' << setw(48) << "\t17. Sua thong tin don thuoc va dich vu" << '|' << endl;
    cout << '|' << setw(48) << "\t18. Tim kiem bac sy hoac benh nhan" << '|' << endl;
    cout << '|' << setw(48) << "\t19. Tim kiem don thuoc hoac dich vu" << '|' << endl;
    cout << '|' << setw(48) << "\t0. Thoat" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(55) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void lay_du_lieu(){
    cout << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(39) << "\t\tLay du lieu" << '|' << endl;
    cout << '|' << setw(46) << "\t1.Lay tu file cho san" << '|' << endl;
    cout << '|' << setw(46) << "\t2.Nhap tu ban phim" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void hoi_bs_bn(){
    cout << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(25) << "\t1. Bac sy" << '|' << endl;
    cout << '|' << setw(25) << "\t2. Benh nhan" << '|' << endl;
    cout << '|' << setw(25) << "\t0.Thoat nhap" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void nhap_bn(){
    cout << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(25) << "\t1.Benh nhan noi tru" << '|' << endl;
    cout << '|' << setw(25) << "\t2.Benh nhan ngoai tru" << '|' << endl;
    cout << '|' << setw(25) << "\t0.Thoat nhap" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void hoi_nhap(){
    cout << endl;
    cout << '|' << setfill('=') << setw(22) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(15) << "\t1.Nhap tiep" << '|' << endl;
    cout << '|' << setw(15) << "\t0.Thoat nhap" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(22) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void hoi_don_thuoc(){
    cout << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(39) << "\t\tBenh nhan co don thuoc chua" << '|' << endl;
    cout << '|' << setw(46) << "\t1.Da co, tien hanh nhap" << '|' << endl;
    cout << '|' << setw(46) << "\t0.Chua co" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void hoi_dvu(){
    cout << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(39) << "\t\tBenh nhan co dung them dich vu khong" << '|' << endl;
    cout << '|' << setw(46) << "\t1.Co, tien hanh nhap" << '|' << endl;
    cout << '|' << setw(46) << "\t0.Chua co" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(53) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void hoi_dtdv(){
    cout << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << '|' << left << setw(25) << "\t1. Don thuoc" << '|' << endl;
    cout << '|' << setw(25) << "\t2. Dich vu" << '|' << endl;
    cout << '|' << setw(25) << "\t0.Thoat nhap" << '|' << right << endl;
    cout << '|' << setfill('=') << setw(32) << '|' << setfill(' ') << endl;
    cout << "\n\t\tLUA CHON: ";
}

void tieu_de_person(){
    cout << '|' << setw(20) << "Ho ten";
    cout << '|' << setw(13) << "Nam sinh";
    cout << '|' << setw(15) << "Cmt/cccd";
    cout << '|' << setw(10) << "Gioi tinh";
    cout << '|' << setw(20) << "Dia chi";
}

void tieu_de_bs(){
    cout << endl;
    cout << '|' << setfill('=') << setw(152) << '|' << setfill(' ') << endl;
    tieu_de_person();
    cout << '|' << setw(25) << "Chuyen khoa";
    cout << '|' << setw(15) << "So phong";
    cout << '|' << setw(10) << "Bac luong";
    cout << '|' << setw(16) << "Tong luong|" << endl;
    cout << '|' << setfill('=') << setw(152) << '|' << setfill(' ') << endl;
}

void tieu_de_bn(){
    cout << endl;
    cout << '|' << setfill('=') << setw(203) << '|' << setfill(' ') << endl;
    tieu_de_person();
    cout << '|' << setw(15) << "Ma benh nhan";
    cout << '|' << setw(15) << "Ma ho so";
    cout << '|' << setw(25) << "Tien su benh";
    cout << '|' << setw(25) << "Chan doan benh";
    cout << '|' << setw(13) << "Ngay chuyen";
    cout << '|' << setw(10) << "Vien phi";
    cout << '|' << setw(11) << "Thanh tien|" << endl;
    cout << '|' << setfill('=') << setw(203) << '|' << setfill(' ') << endl;
}

void tieu_de_dt(){
    cout << endl;
    cout << '|' << setfill('=') << setw(143) << '|' << setfill(' ') << endl;
    cout << '|' << setw(20) << "Ho ten";
    cout << '|' << setw(15) << "Ma benh nhan";
    cout << '|' << setw(15) << "Ma ho so";
    cout << '|' << setw(25) << "Ten thuoc";
    cout << '|' << setw(20) << "Cach dung";
    cout << '|' << setw(10) << "So luong";
    cout << '|' << setw(15) << "Don gia";
    cout << '|' << setw(16) << "Tong tien|" << endl;
    cout << '|' << setfill('=') << setw(143) << '|' << setfill(' ') << endl;
}

void tieu_de_dv(){
    cout << endl;
    cout << '|' << setfill('=') << setw(94) << '|' << setfill(' ') << endl;
    cout << '|' << setw(20) << "Ho ten";
    cout << '|' << setw(15) << "Ma benh nhan";
    cout << '|' << setw(15) << "Ma ho so";
    cout << '|' << setw(25) << "Ten dich vu";
    cout << '|' << setw(15) << "Don gia|" << endl;
    cout << '|' << setfill('=') << setw(94) << '|' << setfill(' ') << endl;
}

void dong_trang(){
    cout << '|' << setw(20) << ' ';
    cout << '|' << setw(15) << ' ';
    cout << '|' << setw(15) << ' ';
}

void dong_trang_dt(){
    cout << '|' << setw(25) << ' ';
    cout << '|' << setw(20) << ' ';
    cout << '|' << setw(10) << ' ';
    cout << '|' << setw(15) << ' ';
    cout << '|' << setw(16) << " |" << endl;
}

void dong_trang_dv(){
    cout << '|' << setw(25) << ' ';
    cout << '|' << setw(15) << " |" << endl;
}

void tieu_de_hd(){
    cout << endl;
    cout << '|' << setfill('=') << setw(116) << '|' << setfill(' ') << endl;
    cout << '|' << setw(20) << "Ho ten";
    cout << '|' << setw(15) << "Ma benh nhan";
    cout << '|' << setw(15) << "Ma ho so";
    cout << '|' << setw(15) << "Vien phi";
    cout << '|' << setw(15) << "Tien thuoc";
    cout << '|' << setw(15) << "Tien dich vu";
    cout << '|' << setw(15) << "Tong tien|" << endl;
    cout << '|' << setfill('=') << setw(116) << '|' << setfill(' ') << endl;
}