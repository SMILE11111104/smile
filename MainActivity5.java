package com.example.de4;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity5 extends AppCompatActivity {

    Button btnphat;
    MediaPlayer media;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main5);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        btnphat = findViewById(R.id.btnphat);
        btnphat.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(media == null){
                    media = MediaPlayer.create(MainActivity5.this, R.raw.audio);
                    media.start();
                }
            }
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
    }
}