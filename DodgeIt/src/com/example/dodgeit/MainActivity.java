package com.example.dodgeit;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import com.bsac.dodgeit.R;

public class MainActivity extends Activity 
{
	private Button howtoplay;
	private Button play;

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		howtoplay = (Button) findViewById(R.id.howtoplay);
		play = (Button) findViewById(R.id.play);
		
/////////////////////////////////////////////////////////////////////////////////////////
		howtoplay.setOnClickListener(new View.OnClickListener()
		{
			@Override
			public void onClick(View v) 
			{
				Intent myIntent = new Intent(MainActivity.this, HowToActivity.class);
				MainActivity.this.startActivity(myIntent);
			}	
		});
/////////////////////////////////////////////////////////////////////////////////////////
		play.setOnClickListener(new View.OnClickListener()
		{
			@Override
			public void onClick(View v) 
			{
				Intent myIntent = new Intent(MainActivity.this, GameActivity.class);
				MainActivity.this.startActivity(myIntent);				
			}	
		});
/////////////////////////////////////////////////////////////////////////////////////////
	}
}
