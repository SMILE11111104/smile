package com.example.baitaptrenlop;

import static android.Manifest.permission.CALL_PHONE;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;

public class ActivityMessage extends AppCompatActivity {
    private EditText edtPhone, edtMessage;
    private Button btnSend;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_message);
        Init();
        String sdt = edtPhone.getText().toString();
        String sms = edtMessage.getText().toString();
        btnSend.setOnClickListener(v -> {
           SendSms(sdt, sms);
        });
    }

    private void SendSms(String sdt, String sms) {
        Intent intent = new Intent(Intent.ACTION_SENDTO, Uri.parse("sms:" + sdt));
        intent.putExtra("sms_body", sms);

        try {
            startActivity(intent);
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }

    private void Init() {
        edtPhone = findViewById(R.id.edtSdt);
        edtMessage = findViewById(R.id.edtMessage);
        btnSend = findViewById(R.id.btnSend);
    }
}