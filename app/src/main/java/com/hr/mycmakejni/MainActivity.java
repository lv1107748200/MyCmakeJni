package com.hr.mycmakejni;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.Image;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("opencv_java3");
        System.loadLibrary("native-lib");
    }

    private Button btn;
    private ImageView imageView;
    private Bitmap bmp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn = (Button) findViewById(R.id.btn);
        imageView = (ImageView) findViewById(R.id.image);


        bmp = BitmapFactory.decodeResource(getResources(), R.drawable.tupian);
        imageView.setImageBitmap(bmp);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int w = bmp.getWidth();
                int h = bmp.getHeight();
                int[] pixels = new int[w*h];
                bmp.getPixels(pixels, 0, w, 0, 0, w, h);
                int[] resultInt = grayProc(pixels, w, h);
                Bitmap resultImg = Bitmap.createBitmap(w, h, Bitmap.Config.RGB_565);
                resultImg.setPixels(resultInt, 0, w, 0, 0, w, h);
                imageView.setImageBitmap(resultImg);
            }
        });



    }

    public native String stringFromJNI();
    public  native  int[] grayProc(
            int[] pixels,
            int w,
            int h
    );
}
