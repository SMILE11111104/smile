package com.example.baitaptrenlop;

import static android.Manifest.permission.CALL_PHONE;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class ActivityPhone extends AppCompatActivity {
    private EditText edtPhone;
    private Button btnDial, btnCall;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_phone);
        Init();
        //xử lý nút dial
        btnDial.setOnClickListener(v -> {
            PhoneDial(edtPhone.getText().toString());
        });

        btnCall.setOnClickListener(v -> {
            PhoneCall(edtPhone.getText().toString());
        });
    }

    private void PhoneCall(String sdt) {
        Intent intent = new Intent(Intent.ACTION_CALL, Uri.parse("tel: " + sdt));
        //kiểm tra dịch vụ
        if (ContextCompat.checkSelfPermission(this, CALL_PHONE) == getPackageManager().PERMISSION_GRANTED){
            startActivity(intent);
        }
        else {
            requestPermissions(new String[] {CALL_PHONE}, 1);
        }
    }

    private void PhoneDial(String sdt) {
        Intent intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel: " + sdt));
        startActivity(intent);
    }

    private void Init() {
        edtPhone = findViewById(R.id.edtSdt);
        btnDial = findViewById(R.id.btnDial);
        btnCall = findViewById(R.id.btnCall);
    }
}