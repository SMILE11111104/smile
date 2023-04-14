#include "bac_sy.cpp"

void hoi_nhap(){
    cout << "\n\t1.Nhap tiep" << endl;
    cout << "\t0.Thoat nhap" << endl;
}

void hoi_don_thuoc(){
    cout << "\n\tBenh nhan co don thuoc chua" << endl;
    cout << "1.Da co, tien hanh nhap" << endl;
    cout << "0.Chua co" << endl;
}

void hoi_dvu(){
    cout << "\n\tBenh nhan co su dung dich vu them khong" << endl;
    cout << "1.Co, tien hanh nhap" << endl;
    cout << "0.Khong" << endl;
}

void dong_trang_dt(){
    cout << '|' << setw(25) << ' ';
    cout << '|' << setw(20) << ' ';
    cout << '|' << setw(10) << ' ';
    cout << '|' << setw(15) << ' ';
    cout << '|' << setw(15) << ' ';
}

void dong_trang_dv(){
    cout << setw(25) << ' ';
    cout << '|' << setw(16) << '|' << endl;
}

void nhap_bn(){
    cout << "\n1.Benh nhan noi tru" << endl;
    cout << "\n2.Benh nhan ngoai tru" << endl;
    cout << "\n0.Thoat nhap" << endl;
}

void menu_chon(){
    cout << "1. Nhap danh sach benh nhan va bac sy" << endl;
    cout << "2. Xuat danh sach benh nhan da nhap" << endl;
    cout << "3. Xuat danh sach bac sy da nhap" << endl;
    cout << "4. Xuat danh sach benh nhan noi tru" << endl;
    cout << "5. Xuat danh sach benh nhan ngoai tru" << endl;
    cout << "6. Xuat danh sach don thuoc cua moi benh nhan" << endl;
    cout << "7. Xuat danh sach dich vu benh nhan da dung" << endl;
    cout << "8. Xuat hoa don thanh toan" << endl;
    cout << "9. Them benh nhan" << endl;
    cout << "10. Them bac sy" << endl;
    cout << "11. Them don thuoc" << endl;
    cout << "12. Them dich vu" << endl;
    cout << "13. Xoa benh nhan" << endl;
    cout << "14. Xoa bac sy" << endl;
    cout << "15. Xoa don thuoc" << endl;
    cout << "16. Xoa dich vu" << endl;
    cout << "17. Sua thong tin benh nhan" << endl;
    cout << "18. Sua thong tin bac sy" << endl;
    cout << "19. Sua thong tin don thuoc" << endl;
    cout << "20. Sua thong tin dich vu" << endl;
}