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