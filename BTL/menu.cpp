#include "ngoai_tru.cpp"
#include "noi_tru.cpp"

void xuat(Ds *ds){
    while (ds != NULL){
        cout << ds -> getData();
        ds = ds -> getNext(); 
    }
}

void nhap(Ds *&ds){
    int x;
    PS *ps;
    while(1){
        nhap_bn();
        cout << "\n\tLua chon: ";
        cin >> x;
        cin.ignore();

        if (x == 0) break;

        if (x == 1){
            ps = new NT;
            cin >> (NT*&) ps;
        }

        if (x == 2){
            ps = new NOT;
            cin >> (NOT*&) ps;
        }

        last_list(ds, ps);
    }
}

void menu(){
    int x;
    Ds *ds;
    init(ds);

    while(1){
        
        if(x == 1){
            nhap(ds);
            continue;
        }
        Ds *tg = ds;
        if(x == 2){
            
        }
        if(x == 3){
            
        }
        if(x == 4){
            
        }
        if(x == 5){
            
        }
        if(x == 6){
            
        }
        if(x == 7){
            
        }
        if(x == 0) break;
    }
}