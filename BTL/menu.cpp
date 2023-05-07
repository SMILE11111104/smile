#include "ngoai_tru.cpp"
#include "noi_tru.cpp"
#include "bac_sy.cpp"

bool ktra_dl(PS *ps){
    if (tach_cmt(ps -> getCmt(), 0) == "NB") return true;
    return false;
}

int dem_ptu(Ds *ds){
    int x = 0;
    while(ds != NULL){
        x++;
        ds = ds -> getNext();
    }
    return x;
}

PS *Tim_kiem(Ds *&ds, string a, int &x){
    Ds *tg = ds;
    x = 0;
    PS *ps;
    BN *bn;
    BS *bs;
    while(tg != NULL){
        x++;
        ps = (PS*) tg -> getData();
        if (ktra_dl(ps)){
            bn = (BN*) tg -> getData();
            if (bn -> getMbn() == a) return ps;
        }
        else {
            bs = (BS*) tg -> getData();
            if(bs -> getCmt() == a) return ps; 
        }
        tg = tg -> getNext();
    }
    return NULL;
}

string tach_ten(string a, int k){
    string b;
    while(a[a.length() - 1] != ' ' and a.length() > 0){
        b = a[a.length() - 1] + b;
        a.pop_back();
    }
    if (k == 1) return b;
    return a;
}

bool ktra_ten(string a, string b){
    if (tach_ten(a, 1) == tach_ten(b, 1)){
        if (tach_ten(a, 0) > tach_ten(b, 0)) return true;
        else return false;
    }
    if (tach_ten(a, 1) > tach_ten(b, 1)) return true;
    return false;
}

void xuat(Ds *&ds, int x, int k){
    PS *ps;
    BN *bn;
    string mhs;
    while (ds != NULL){
        ps = (PS*) ds -> getData();
        if(ktra_dl(ps) and k == 1){
            bn = (BN*) ds -> getData();
            mhs = bn -> getMhs();
            if (tach_mahs(mhs) and x == 1) cout << bn;
            if (!tach_mahs(mhs) and x == 2) cout << bn;
            if (x == 0) cout << bn;
        }
        else if (!ktra_dl(ps) and k == 0) cout << (BS*) ds -> getData();
        if (k == 2){
            cout << (PS*) ds -> getData();
        }
        ds = ds -> getNext();
    }
}

void xuat_thuoc(BN *bn){
    Ds *dt;
    bool x = true;
    cout << '|' << setw(20) << bn -> getHt();
    cout << '|' << setw(15) << bn -> getMbn();
    cout << '|' << setw(15) << bn -> getMhs();
    x = true;
    dt = bn -> getDs_dt();
    if (dt == NULL) dong_trang_dt();
    while(dt != NULL){
        if (x) {
            cout << (DT*) dt -> getData();
            x = false;
        }
        else {
            dong_trang();
            cout << '|' << setfill('=') << setw(90) << '|' << setfill(' ') << endl;
            dong_trang();
            cout << (DT*) dt -> getData();
        }
        dt = dt -> getNext();
    }
    cout << '|' << setfill('=') << setw(143) << '|' << setfill(' ') << endl;
}

void xuat_dv1(BN *bn){
    Ds *dv;
    bool x = true;
    cout << '|' << setw(20) << bn -> getHt();
    cout << '|' << setw(15) << bn -> getMbn();
    cout << '|' << setw(15) << bn -> getMhs();
    x = true;
    dv = bn -> getDs_dv();
    if (dv == NULL) dong_trang_dv();
    while(dv != NULL){
        if (x) {
            cout << (DV*) dv -> getData();
            x = false;
        }
        else {
            dong_trang();
            cout << '|' << setfill('=') << setw(41) << '|' << setfill(' ') << endl;
            dong_trang();
            cout << (DV*) dv -> getData();
        }
        dv = dv -> getNext();
    }
    cout << '|' << setfill('=') << setw(94) << '|' << setfill(' ') << endl;
}

void xuat_dt(Ds *&ds){
    BN *bn;
    PS *ps;
    Ds *dt;
    bool x = true;
    while(ds != NULL){
        ps = (PS*) ds -> getData();
        if (ktra_dl(ps)){
            bn = (BN*) ds -> getData();
            xuat_thuoc(bn);
        }
        ds = ds -> getNext();
    }
}

void xuat_dv(Ds *&ds){
    BN *bn;
    PS *ps;
    Ds *dv;
    bool x = true;
    while(ds != NULL){
        ps = (PS*) ds -> getData();
        if (ktra_dl(ps)){
            bn = (BN*) ds -> getData();
            xuat_dv1(bn);
        }
        ds = ds -> getNext();
    }
}

void xuat_hd(Ds *&ds){
    BN *bn;
    Ds *tg;
    DV *dv;
    DT *dt;
    string mbn;
    long int t1 = 0, t2 = 0;
    int x;
    cout << "\n\tMa benh nhan: "; getline(cin, mbn);
    bn = (BN*) Tim_kiem(ds, mbn, x);
    if (bn == NULL) {
        cout << "\n\tKhong ton tai ma benh nhan nay!!!" << endl;
        return;
    }

    else{
        tg = bn -> getDs_dt();
        while(tg != NULL){
            dt = (DT*) tg -> getData();
            t1 += dt -> tong_tien();
            tg = tg -> getNext();
        }

        tg = bn -> getDs_dv();
        while(tg != NULL){
            dv = (DV*) tg -> getData();
            t2 += dv -> getDg();
            tg = tg -> getNext();
        }
    }
    tieu_de_hd();
    cout << '|' << setw(20) << bn -> getHt();
    cout << '|' << setw(15) << bn -> getMbn();
    cout << '|' << setw(15) << bn -> getMhs();
    cout << '|' << setw(15) << bn -> getVp();
    cout << '|' << setw(15) << t1;
    cout << '|' << setw(15) << t2;
    cout << '|' << setw(14) << bn -> thanh_tien() << '|' << endl;
    cout << '|' << setfill('=') << setw(116) << '|' << setfill(' ') << endl;
}

void nhap(Ds *&ds){
    int x;
    bool c[3] = {true, true, true};
    while(1){
        hoi_bs_bn();
        cin >> x;
        cin.ignore();
        
        if (x == 0 or (!c[0] and !c[1] and !c[2])) break;
        else if (x == 1){
            if (c[0]) {
                ds_bs(ds);
                c[0] = false;
            }
            else cout << "\nDa nhap danh sach truoc do!!!" << endl;
        }
        else if ( x == 2){
            nhap_bn();
            cin >> x;
            cin.ignore();
            if (x == 0 or (!c[1] and !c[2])) break;

            else if (x == 1){
                if (c[1]) {
                    ds_nt(ds);
                    c[1] = false;
                }
                else cout << "\nDa nhap danh sach truoc do!!!" << endl;
            }

            else if (x == 2){
                if (c[2]) {
                    ds_not(ds);
                    c[2] = false;
                }
                else cout << "\nDa nhap danh sach truoc do!!!" << endl; 
            }
        }
    }
}

void them_tt(Ds *&ds){
    PS *ps;
    Ds *dt, *dv;
    BN *bn;
    int k, x;
    hoi_bs_bn();
    cin >> x;

    do{
        if (dem_ptu(ds) > 1) cout << "\n\tThem thong tin vao vi tri (1 - " << dem_ptu(ds) << "): ";
        else{
            k = 2;
            break;
        }
        cin >> k;
    }while(k > dem_ptu(ds));

    cin.ignore();
    if (x == 1){
        ps = new BS;
        cout << "\n\tThong tin bac sy can them" << endl;
        cin >> (BS*&) ps;
    }

    else if ( x == 2){
        nhap_bn();
        cin >> x;
        cin.ignore();
        if (x == 1){
            bn = new NT;
            cout << "\n\tThong tin benh nhan noi tru can them" << endl;
            cin >> (NT*&) bn;
        }
        else if (x == 2){
            bn = new NOT;
            cout << "\n\tThong tin benh nhan ngoai tru can them" << endl;
            cin >> (NOT*&) bn;
        }
        else return;

        ds_dthuoc(dt);
        ds_dvu(dv);
        bn -> setDs_dt(dt);
        bn -> setDs_dv(dv);
        ps = (PS*) bn;
    }
    else return;
    if (ds == NULL){
        last_list(ds, ps);
    }
    ds = add_ds(ds, ps, k);
}



void them_dt(Ds *&ds){
    string mbn;
    int x;
    DT *dt;
    Ds *ds_dt_them;
    BN *bn;
    bool c = true;

    cout << "\n\tMa benh nhan: "; getline(cin, mbn);

    bn = (BN*) Tim_kiem(ds, mbn, x);
    if (bn == NULL) cout << "\n\tKhong ton tai ma benh nhan nay!!!" << endl;
    else{
        ds_dt_them = bn -> getDs_dt();
        do{
            dt = new DT;
            cout << "\n\tThuoc can them" << endl;
            cin >> (DT*&) dt;
            last_list(ds_dt_them, dt);
            hoi_nhap();
            cin >> x;
            cin.ignore();
        }while(x == 1);
        bn -> setDs_dt(ds_dt_them);
    }
}

void them_dv(Ds *&ds){
    string mbn;
    int x;
    BN *bn;
    Ds *ds_dv_them;
    DV *dv;

    cout << "\n\tMa benh nhan: "; getline(cin, mbn);

    bn = (BN*) Tim_kiem(ds, mbn, x);
    if (bn == NULL) cout << "\n\tKhong ton tai ma benh nhan nay!!!" << endl;
    else{
        ds_dv_them = bn -> getDs_dv();
        do{
            dv = new DV;
            cout << "\n\tDich vu can them" << endl;
            cin >> (DV*&) dv;
            last_list(ds_dv_them, dv);
            hoi_nhap();
            cin >> x;
            cin.ignore();
        }while(x == 1);
        bn -> setDs_dv(ds_dv_them);
    }
}

void xoa_tt(Ds *&ds){
    string b;
    int x;
    BN *bn;
    BS *bs;
    hoi_bs_bn();
    cin >> x;
    cin.ignore();

    if (x == 1){
        do{
            cout << "\n\tSo cmt/cccd cua bac sy: "; getline(cin, b);
            bs = (BS*) Tim_kiem(ds, "SB" + b, x);

            if (bs == NULL) cout << "\n\tKhong ton tai so cmt/cccd nay!!!" << endl;
            else ds = delete_ds(ds, x);

            hoi_nhap();
            cin >> x;
            cin.ignore();
        }while(x == 1);
    }

    else if(x == 2){
        do{
            cout << "\n\tMa benh nhan can xoa: "; getline(cin, b);
            bn = (BN*) Tim_kiem(ds, b, x);

            if (bn == NULL) cout << "\n\tKhong ton tai ma benh nhan nay!!!" << endl;
            else ds = delete_ds(ds, x);

            hoi_nhap();
            cin >> x;
            cin.ignore();
        }while(x == 1);
    }
    else return; 
}
 
void xoa_dt_dv(Ds *&ds){
    string b;
    int x;
    Ds *dv, *dt;
    BN *bn;

    cout << "\n\tMa benh nhan can xoa don thuoc hoac dich vu: "; getline(cin, b);
    bn = (BN*) Tim_kiem(ds, b, x);

    if (bn == NULL) cout << "\n\tKhong ton tai ma benh nhan nay!!!" << endl;
    else{
        dv = bn -> getDs_dv();
        dt = bn -> getDs_dt();
        hoi_dtdv();
        cin >> x;

        if (x == 1){
            if (dt == NULL) {
                cout << "\n\tChua co don thuoc nao!!!" << endl;
                return;
            }

            do{
                do {
                    if (dem_ptu(dt) > 1)cout << "\n\tVi tri thuoc can xoa (1 - " << dem_ptu(dt) << "): ";
                    else {
                        x = 1;
                        break;
                    }
                    cin >> x;
                } while(x > dem_ptu(dt));

                dt = delete_ds(dt, x);
                bn -> setDs_dt(dt);
                hoi_nhap();
                cin >> x;
            }while(x == 1);
        }

        else if(x == 2){
            if (dv == NULL) {
                cout << "\n\tChua co dich vu nao!!!" << endl;
                return;
            }

            do{
                do {
                    if (dem_ptu(dv) > 1)cout << "\n\tVi tri thuoc can xoa (1 - " << dem_ptu(dv) << " ): ";
                    else {
                        x = 1;
                        break;
                    }
                    cin >> x;
                } while(x > dem_ptu(dv));

                dv = delete_ds(dv, x);
                bn -> setDs_dv(dv);
                hoi_nhap();
                cin >> x;
            }while(x == 1);
        }
        else return;
    }
}

void sx_bs(Ds *&ds){
    Ds *ds_bs;
    BS *bs, *bs1;
    PS *ps;
    init(ds_bs);

    while (ds != NULL){//luu ra 1 ds moi
        ps = (PS*) ds -> getData();
        if (!ktra_dl(ps)){
            bs = (BS*) ds -> getData();
            last_list(ds_bs, bs);
        }
        ds = ds -> getNext();
    }

    if (ds_bs == NULL) {
        cout << "\n\tKhong co bac sy nao trong danh sach!!!" << endl;
        return;
    }

    for (Ds *i = ds_bs; i != NULL; i = i -> getNext()){
        for (Ds *j = i -> getNext(); j != NULL; j = j -> getNext()){
            bs = (BS*) i -> getData();
            bs1 = (BS*) j -> getData();
            if(ktra_ten(bs -> getHt(), bs1 -> getHt())){
                i -> setData(bs1);
                j -> setData(bs);
            }
        }
    }

    tieu_de_bs();
    while (ds_bs != NULL){
        cout << (BS*) ds_bs -> getData();
        ds_bs = ds_bs -> getNext();
    }
}

void sx_bn(Ds *&ds){
    Ds *ds_bn;
    BN *bn, *bn1;
    PS *ps;
    init(ds_bn);

    while (ds != NULL){
        ps = (PS*) ds -> getData();
        if (ktra_dl(ps)){
            bn = (BN*) ds -> getData();
            last_list(ds_bn, bn);
        }
        ds = ds -> getNext();
    }

    if (ds_bn == NULL) {
        cout << "\n\tKhong co benh nhan nao trong danh sach!!!" << endl;
        return;
    }

    for (Ds *i = ds_bn; i != NULL; i = i -> getNext()){
        for (Ds *j = i -> getNext(); j != NULL; j = j -> getNext()){
            bn = (BN*) i -> getData();
            bn1 = (BN*) j -> getData();
            if(ktra_ten(bn -> getMhs(), bn1 -> getMhs())){
                i -> setData(bn1);
                j -> setData(bn);
            }
        }
    }
    
    tieu_de_bn();
    while (ds_bn != NULL){
        cout << (BN*) ds_bn -> getData();
        ds_bn = ds_bn -> getNext();
    }
}

void sua_tt(Ds *&ds){
    PS *ps;
    Ds *dt, *dv, *ds1 = ds;
    BN *bn;
    int x, y = 0;
    string a;

    hoi_bs_bn();
    cin >> x;
    cin.ignore();
       
    if (x == 1){
        cout << "\n\tSo cmt/cccd bac sy can sua: ";
        getline(cin, a);
        ps = Tim_kiem(ds1, "SB" + a, x);

        if (ps == NULL) {
            cout << "\n\tKhong ton tai bac sy co so cmt/cccd da nhap!!!" << endl;
            return;
        }
        
        ps = new BS;
        cout << "\n\tThong tin sua lai cua bac sy" << endl;
        cin >> (BS*&) ps;
    }

    else if ( x == 2){
        cout << "\n\tMa benh nhan can sua: ";
        getline(cin, a);
        ps = Tim_kiem(ds1, a, x);

        if (ps == NULL) {
            cout << "\n\tKhong ton tai ma benh nhan nay!!!" << endl;
            return;
        }
        
        bn = (BN*) ds -> getData();
        if (tach_mahs(bn -> getMhs())){
            bn = new NT;
            cout << "\n\tThong tin sua lai cua benh nhan noi tru" << endl;
            cin >> (NT*&) bn;
        }

        else {
            bn = new NOT;
            cout << "\n\tThong tin sua lai cua benh nhan ngoai tru" << endl;
            cin >> (NOT*&) bn;
        }

        ds_dthuoc(dt);
        ds_dvu(dv);
        bn -> setDs_dt(dt);
        bn -> setDs_dv(dv);
        ps = (PS*) bn;
        
    }

    while(ds1 != NULL){
        if (x - 1 == y){
            ds1 -> setData(ps);
            break;
        }
        y++;
        ds1 = ds1 -> getNext();
    }
}

void sua_dt_dv(Ds *&ds){
    Ds *dt, *dv;
    BN *bn;
    DT *dt1;
    DV *dv1;
    string mbn;
    int x, y = 0;

    cout << "\n\tMa benh nhan can sua don thuoc hoac dich vu: "; getline(cin, mbn);
    bn = (BN*) Tim_kiem(ds, mbn, x);

    if (bn == NULL) cout << "\n\tKhong ton tai ma benh nhan nay!!!" << endl;
    else{
        dv = bn -> getDs_dv();
        dt = bn -> getDs_dt();
        bn -> setDs_dt(dt);
        bn -> setDs_dv(dv);

        hoi_dtdv();
        cin >> x;

        if (x == 1){
            if (dt == NULL) {
                cout << "\n\tChua co don thuoc nao!!!" << endl;
                return;
            }

            do {
                if (dem_ptu(dt) > 1)cout << "\n\tVi tri thuoc can sua (1 - " << dem_ptu(dt) << " ): ";
                else {
                    x = 1;
                    break;
                }
                cin >> x;
                
            } while(x > dem_ptu(dt));

            cin.ignore();
            cout << "\n\tThong tin thuoc can sua" << endl;
            dt1 = new DT;
            cin >> (DT*&) dt1;

            while(dt != NULL){
                if (x - 1 == y){
                    dt -> setData(dt1);
                    break;
                }
                y++;
                dt = dt -> getNext();
            }
        }

        else if(x == 2){
            if (dv == NULL) {
                cout << "\n\tChua co dich vu nao!!!" << endl;
                return;
            }

            do {
                if (dem_ptu(dt) > 1)cout << "\n\tVi tri dich vu can sua (1 - " << dem_ptu(dv) << " ): ";
                else {
                    x = 1;
                    break;
                }
                cin >> x;
            } while(x > dem_ptu(dv));

            cin.ignore();
            cout << "\n\tThong tin dich vu can sua" << endl;
            dv1 = new DV;
            cin >> (DV*&) dv1;

            while(dv != NULL){
                if (x - 1 == y){
                    dv -> setData(dv1);
                    break;
                }
                y++;
                dv = dv -> getNext();
            }
        }
        else return;
    }
}

void tim_tt(Ds *&ds){
    string a;
    PS *ps;
    int x;

    hoi_bs_bn();
    cin >> x;
    cin.ignore();

    if (x == 1){
        cout << "\n\tSo cmt/cccd bac sy can tim kiem: "; getline(cin, a);
        ps =  Tim_kiem(ds, "SB" + a, x);

        if (ps == NULL) {
            cout << "\n\tKhong ton tai bac sy co so cmt/cccd da nhap!!!" << endl;
            return;
        }

        tieu_de_bs();
        cout << (BS*) ps;
    }

    else if (x == 2){
        cout << "\n\tMa benh nhan can tim kiem: "; getline(cin, a);
        ps = Tim_kiem(ds, a, x);
        
        if (ps == NULL) {
            cout << "\n\tKhong ton tai ma benh nhan nay!!!" << endl;
            return;
        }

        tieu_de_bn();
        cout << (BN*) ps;
    }
    else return;
}

void tim_dt_dv(Ds *&ds){
    string a;
    BN *bn;
    Ds *dt, *dv;
    int x;

    cout << "\n\tMa benh nhan can tim kiem: "; getline(cin, a);
    bn = (BN*) Tim_kiem(ds, a, x);

    if (bn == NULL) {
        cout << "\n\tKhong ton tai ma benh nhan nay!!!" << endl;
        return;
    }

    dt = bn -> getDs_dt();
    dv = bn -> getDs_dv();
    hoi_dtdv();
    cin >> x;

    if (x == 1){
        if (dt == NULL) {
            cout << "\n\tChua co don thuoc nao!!!" << endl;
            return;
        }

        tieu_de_dt();
        xuat_thuoc(bn);
    }
    else if (x == 2){
        if (dv == NULL) {
            cout << "\n\tChua co dich vu nao!!!" << endl;
            return;
        }

        tieu_de_dv();
        xuat_dv1(bn);
    }
    else return;
}

void menu(){
    int x;
    Ds *ds;
    init(ds);
    bool c = true;

    nhaplai:
    
    menu_chon();
    cin >> x;
    cin.ignore();
    Ds *tg = ds;

    switch (x)
    {
        case 1:
            if(x == 1){
                if (c) {
                    nhap(ds);
                    c = false;
                }
                else cout << "\nDa nhap danh sach truoc do!!!" << endl;
            }
            goto nhaplai;
        case 2:
            tieu_de_bn();
            xuat(tg, 0, 1);
            goto nhaplai;
        case 3:
            tieu_de_bs();
            xuat(tg, 0, 0);
            goto nhaplai;
        case 4:
            tieu_de_bn();
            xuat(tg, 1, 1);
            goto nhaplai;
        case 5:
            tieu_de_bn();
            xuat(tg, 2, 1);
            goto nhaplai;
        case 6:
            tieu_de_dt();
            xuat_dt(tg);
            goto nhaplai;
        case 7:
            tieu_de_dv();
            xuat_dv(tg);
            goto nhaplai;
        case 8:
            xuat_hd(tg);
            goto nhaplai;
        case 9:
            them_tt(ds);
            goto nhaplai;
        case 10:
            them_dt(ds);
            goto nhaplai;
        case 11:
            them_dv(ds);
            goto nhaplai;
        case 12:
            xoa_tt(ds);
            goto nhaplai;
        case 13:
            xoa_dt_dv(ds);
            goto nhaplai;
        case 14:
            sx_bs(tg);
            goto nhaplai;
        case 15:
            sx_bn(tg);
            goto nhaplai;  
        case 16:
            sua_tt(ds);
            goto nhaplai; 
        case 17:
            sua_dt_dv(ds);
            goto nhaplai;   
        case 18:
            tim_tt(ds);
            goto nhaplai;   
        case 19:
            tim_dt_dv(ds);
            goto nhaplai;   
        case 0:
            break;
    }
}